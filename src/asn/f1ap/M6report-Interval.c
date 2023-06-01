/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "M6report-Interval.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
asn_per_constraints_t asn_PER_type_M6report_Interval_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  4,  4,  0,  12 }	/* (0..12,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_M6report_Interval_value2enum_1[] = {
	{ 0,	5,	"ms120" },
	{ 1,	5,	"ms240" },
	{ 2,	5,	"ms640" },
	{ 3,	6,	"ms1024" },
	{ 4,	6,	"ms2048" },
	{ 5,	6,	"ms5120" },
	{ 6,	7,	"ms10240" },
	{ 7,	7,	"ms20480" },
	{ 8,	7,	"ms40960" },
	{ 9,	4,	"min1" },
	{ 10,	4,	"min6" },
	{ 11,	5,	"min12" },
	{ 12,	5,	"min30" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_M6report_Interval_enum2value_1[] = {
	9,	/* min1(9) */
	11,	/* min12(11) */
	12,	/* min30(12) */
	10,	/* min6(10) */
	3,	/* ms1024(3) */
	6,	/* ms10240(6) */
	0,	/* ms120(0) */
	4,	/* ms2048(4) */
	7,	/* ms20480(7) */
	1,	/* ms240(1) */
	8,	/* ms40960(8) */
	5,	/* ms5120(5) */
	2	/* ms640(2) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_M6report_Interval_specs_1 = {
	asn_MAP_M6report_Interval_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_M6report_Interval_enum2value_1,	/* N => "tag"; sorted by N */
	13,	/* Number of elements in the maps */
	14,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_M6report_Interval_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_M6report_Interval = {
	"M6report-Interval",
	"M6report-Interval",
	&asn_OP_NativeEnumerated,
	asn_DEF_M6report_Interval_tags_1,
	sizeof(asn_DEF_M6report_Interval_tags_1)
		/sizeof(asn_DEF_M6report_Interval_tags_1[0]), /* 1 */
	asn_DEF_M6report_Interval_tags_1,	/* Same as above */
	sizeof(asn_DEF_M6report_Interval_tags_1)
		/sizeof(asn_DEF_M6report_Interval_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_M6report_Interval_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_M6report_Interval_specs_1	/* Additional specs */
};

