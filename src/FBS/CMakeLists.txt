file(GLOB_RECURSE HDR_FILES *.hpp)
file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(FBS ${HDR_FILES} ${SRC_FILES})

target_compile_options(FBS PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter)

target_link_libraries(FBS asn-rrc)
target_link_libraries(FBS common-lib)

