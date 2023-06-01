/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "NRPRACHConfig.h"

#include "NRPRACHConfigList.h"
#include "ProtocolExtensionContainer.h"
static asn_TYPE_member_t asn_MBR_NRPRACHConfig_1[] = {
	{ ATF_POINTER, 3, offsetof(struct NRPRACHConfig, ulPRACHConfigList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPRACHConfigList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ulPRACHConfigList"
		},
	{ ATF_POINTER, 2, offsetof(struct NRPRACHConfig, sulPRACHConfigList),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPRACHConfigList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sulPRACHConfigList"
		},
	{ ATF_POINTER, 1, offsetof(struct NRPRACHConfig, iE_Extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extension"
		},
};
static const int asn_MAP_NRPRACHConfig_oms_1[] = { 0, 1, 2 };
static const ber_tlv_tag_t asn_DEF_NRPRACHConfig_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NRPRACHConfig_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ulPRACHConfigList */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sulPRACHConfigList */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extension */
};
static asn_SEQUENCE_specifics_t asn_SPC_NRPRACHConfig_specs_1 = {
	sizeof(struct NRPRACHConfig),
	offsetof(struct NRPRACHConfig, _asn_ctx),
	asn_MAP_NRPRACHConfig_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_NRPRACHConfig_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NRPRACHConfig = {
	"NRPRACHConfig",
	"NRPRACHConfig",
	&asn_OP_SEQUENCE,
	asn_DEF_NRPRACHConfig_tags_1,
	sizeof(asn_DEF_NRPRACHConfig_tags_1)
		/sizeof(asn_DEF_NRPRACHConfig_tags_1[0]), /* 1 */
	asn_DEF_NRPRACHConfig_tags_1,	/* Same as above */
	sizeof(asn_DEF_NRPRACHConfig_tags_1)
		/sizeof(asn_DEF_NRPRACHConfig_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NRPRACHConfig_1,
	3,	/* Elements count */
	&asn_SPC_NRPRACHConfig_specs_1	/* Additional specs */
};

