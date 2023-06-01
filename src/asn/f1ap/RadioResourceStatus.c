/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "RadioResourceStatus.h"

#include "ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_RadioResourceStatus_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceStatus, sSBAreaRadioResourceStatusList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SSBAreaRadioResourceStatusList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sSBAreaRadioResourceStatusList"
		},
	{ ATF_POINTER, 1, offsetof(struct RadioResourceStatus, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_RadioResourceStatus_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_RadioResourceStatus_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RadioResourceStatus_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* sSBAreaRadioResourceStatusList */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_RadioResourceStatus_specs_1 = {
	sizeof(struct RadioResourceStatus),
	offsetof(struct RadioResourceStatus, _asn_ctx),
	asn_MAP_RadioResourceStatus_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_RadioResourceStatus_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RadioResourceStatus = {
	"RadioResourceStatus",
	"RadioResourceStatus",
	&asn_OP_SEQUENCE,
	asn_DEF_RadioResourceStatus_tags_1,
	sizeof(asn_DEF_RadioResourceStatus_tags_1)
		/sizeof(asn_DEF_RadioResourceStatus_tags_1[0]), /* 1 */
	asn_DEF_RadioResourceStatus_tags_1,	/* Same as above */
	sizeof(asn_DEF_RadioResourceStatus_tags_1)
		/sizeof(asn_DEF_RadioResourceStatus_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RadioResourceStatus_1,
	2,	/* Elements count */
	&asn_SPC_RadioResourceStatus_specs_1	/* Additional specs */
};

