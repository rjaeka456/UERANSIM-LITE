//
// Created by Hoonyong Park on 8/9/23.
//

#include <iostream>
#include <stdexcept>
#include <unordered_map>

#include <unistd.h>

#include <FBS/FBS.hpp>
#include <lib/app/base_app.hpp>
#include <lib/app/cli_base.hpp>
#include <lib/app/cli_cmd.hpp>
#include <lib/app/proc_table.hpp>
#include <utils/constants.hpp>
#include <utils/io.hpp>
#include <utils/options.hpp>
#include <utils/yaml_utils.hpp>
#include <yaml-cpp/yaml.h>

static app::CliServer *g_cliServer = nullptr;
static nr::FBS::FBSConfig *g_refConfig = nullptr;
static std::unordered_map<std::string, nr::FBS::FalseBaseStation *> g_FBSMap{};
static app::CliResponseTask *g_cliRespTask = nullptr;

static struct Options
{
    std::string configFile{};
    bool disableCmd{};
} g_options{};

static nr::FBS::FBSConfig *ReadConfigYaml()
{
    auto *result = new nr::FBS::FBSConfig();
    auto config = YAML::LoadFile(g_options.configFile);

    result->plmn.mcc = yaml::GetInt32(config, "mcc", 1, 999);
    yaml::GetString(config, "mcc", 3, 3);
    result->plmn.mnc = yaml::GetInt32(config, "mnc", 0, 999);
    result->plmn.isLongMnc = yaml::GetString(config, "mnc", 2, 3).size() == 3;

    result->nci = yaml::GetInt64(config, "FBS_ID", 0, 0xFFFFFFFFFll);
    result->FBSIdLength = yaml::GetInt32(config, "idLength", 22, 32);
    result->tac = yaml::GetInt32(config, "tac", 0, 0xFFFFFF);

    result->linkIp = yaml::GetIp(config, "linkIp");

    result->ignoreStreamIds = yaml::GetBool(config, "ignoreStreamIds");
    result->pagingDrx = EPagingDrx::V128;
    result->name = "UERANSIM-FBS-" + std::to_string(result->plmn.mcc) + "-" + std::to_string(result->plmn.mnc) + "-" +
                   std::to_string(result->getFBSId()); // NOTE: Avoid using "/" dir separator character.

    yaml::AssertHasField(config, "position");
    {
        result->phyLocation.x = std::stod(yaml::GetString(config["position"], "x"));
        result->phyLocation.y = std::stod(yaml::GetString(config["position"], "y"));
        result->phyLocation.z = std::stod(yaml::GetString(config["position"], "z"));
    }

    return result;
}

static void ReadOptions(int argc, char **argv)
{
    opt::OptionsDescription desc{cons::Project,
                                 cons::Tag,
                                 "5G-SA nr-FBS implementation",
                                 cons::Owner,
                                 "nr-FBS",
                                 {"-c <config-file> [option...]"},
                                 {},
                                 true,
                                 false};

    opt::OptionItem itemConfigFile = {'c', "config", "Use specified configuration file for nr-FBS", "config-file"};
    opt::OptionItem itemDisableCmd = {'l', "disable-cmd", "Disable command line functionality for this instance",
                                      std::nullopt};

    desc.items.push_back(itemConfigFile);
    desc.items.push_back(itemDisableCmd);

    opt::OptionsResult opt{argc, argv, desc, false, nullptr};

    if (opt.hasFlag(itemDisableCmd))
        g_options.disableCmd = true;
    g_options.configFile = opt.getOption(itemConfigFile);

    try
    {
        g_refConfig = ReadConfigYaml();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        exit(1);
    }
}

static void Loop()
{
    if (!g_cliServer)
    {
        ::pause();
        return;
    }

    auto msg = g_cliServer->receiveMessage();
    if (msg.type == app::CliMessage::Type::ECHO)
    {
        g_cliServer->sendMessage(msg);
        return;
    }

    if (msg.type != app::CliMessage::Type::COMMAND)
        return;

    if (msg.value.size() > 0xFFFF)
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, "Command is too large"));
        return;
    }

    if (msg.nodeName.size() > 0xFFFF)
    {
        g_cliServer->sendMessage(app::CliMessage::Error(msg.clientAddr, "Node name is too large"));
        return;
    }

}

int main(int argc, char **argv)
{
    app::Initialize();
    ReadOptions(argc, argv);

    std::cout << cons::Name << std::endl;

    if (!g_options.disableCmd)
    {
        g_cliServer = new app::CliServer{};
        g_cliRespTask = new app::CliResponseTask(g_cliServer);
    }

    auto *FBS = new nr::FBS::FalseBaseStation(g_refConfig, nullptr, g_cliRespTask);
    g_FBSMap[g_refConfig->name] = FBS;

    if (!g_options.disableCmd)
    {
        app::CreateProcTable(g_FBSMap, g_cliServer->assignedAddress().getPort());
        g_cliRespTask->start();
    }

    FBS->start();

    while (true)
        Loop();
}