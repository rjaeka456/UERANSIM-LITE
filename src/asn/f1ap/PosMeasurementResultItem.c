/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "PosMeasurementResultItem.h"

#include "TRPMeasurementQuality.h"
#include "MeasurementBeamInfo.h"
#include "ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_PosMeasurementResultItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PosMeasurementResultItem, measuredResultsValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_MeasuredResultsValue,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measuredResultsValue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosMeasurementResultItem, timeStamp),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeStamp,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"timeStamp"
		},
	{ ATF_POINTER, 3, offsetof(struct PosMeasurementResultItem, measurementQuality),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TRPMeasurementQuality,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measurementQuality"
		},
	{ ATF_POINTER, 2, offsetof(struct PosMeasurementResultItem, measurementBeamInfo),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasurementBeamInfo,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measurementBeamInfo"
		},
	{ ATF_POINTER, 1, offsetof(struct PosMeasurementResultItem, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_PosMeasurementResultItem_oms_1[] = { 2, 3, 4 };
static const ber_tlv_tag_t asn_DEF_PosMeasurementResultItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PosMeasurementResultItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* measuredResultsValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* timeStamp */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* measurementQuality */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* measurementBeamInfo */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_PosMeasurementResultItem_specs_1 = {
	sizeof(struct PosMeasurementResultItem),
	offsetof(struct PosMeasurementResultItem, _asn_ctx),
	asn_MAP_PosMeasurementResultItem_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_PosMeasurementResultItem_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PosMeasurementResultItem = {
	"PosMeasurementResultItem",
	"PosMeasurementResultItem",
	&asn_OP_SEQUENCE,
	asn_DEF_PosMeasurementResultItem_tags_1,
	sizeof(asn_DEF_PosMeasurementResultItem_tags_1)
		/sizeof(asn_DEF_PosMeasurementResultItem_tags_1[0]), /* 1 */
	asn_DEF_PosMeasurementResultItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_PosMeasurementResultItem_tags_1)
		/sizeof(asn_DEF_PosMeasurementResultItem_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PosMeasurementResultItem_1,
	5,	/* Elements count */
	&asn_SPC_PosMeasurementResultItem_specs_1	/* Additional specs */
};

