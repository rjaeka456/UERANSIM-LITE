/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "UAC-Assistance-Info.h"

#include "ProtocolExtensionContainer.h"
static asn_TYPE_member_t asn_MBR_UAC_Assistance_Info_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UAC_Assistance_Info, uACPLMN_List),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UACPLMN_List,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"uACPLMN-List"
		},
	{ ATF_POINTER, 1, offsetof(struct UAC_Assistance_Info, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_UAC_Assistance_Info_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_UAC_Assistance_Info_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_UAC_Assistance_Info_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* uACPLMN-List */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_UAC_Assistance_Info_specs_1 = {
	sizeof(struct UAC_Assistance_Info),
	offsetof(struct UAC_Assistance_Info, _asn_ctx),
	asn_MAP_UAC_Assistance_Info_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_UAC_Assistance_Info_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_UAC_Assistance_Info = {
	"UAC-Assistance-Info",
	"UAC-Assistance-Info",
	&asn_OP_SEQUENCE,
	asn_DEF_UAC_Assistance_Info_tags_1,
	sizeof(asn_DEF_UAC_Assistance_Info_tags_1)
		/sizeof(asn_DEF_UAC_Assistance_Info_tags_1[0]), /* 1 */
	asn_DEF_UAC_Assistance_Info_tags_1,	/* Same as above */
	sizeof(asn_DEF_UAC_Assistance_Info_tags_1)
		/sizeof(asn_DEF_UAC_Assistance_Info_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_UAC_Assistance_Info_1,
	2,	/* Elements count */
	&asn_SPC_UAC_Assistance_Info_specs_1	/* Additional specs */
};

