/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "L839Info.h"

#include "ProtocolExtensionContainer.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_rootSequenceIndex_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 837)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_restrictedSetConfig_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_rootSequenceIndex_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 10,  10,  0,  837 }	/* (0..837) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_restrictedSetConfig_value2enum_3[] = {
	{ 0,	15,	"unrestrictedSet" },
	{ 1,	18,	"restrictedSetTypeA" },
	{ 2,	18,	"restrictedSetTypeB" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_restrictedSetConfig_enum2value_3[] = {
	1,	/* restrictedSetTypeA(1) */
	2,	/* restrictedSetTypeB(2) */
	0	/* unrestrictedSet(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_restrictedSetConfig_specs_3 = {
	asn_MAP_restrictedSetConfig_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_restrictedSetConfig_enum2value_3,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_restrictedSetConfig_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_restrictedSetConfig_3 = {
	"restrictedSetConfig",
	"restrictedSetConfig",
	&asn_OP_NativeEnumerated,
	asn_DEF_restrictedSetConfig_tags_3,
	sizeof(asn_DEF_restrictedSetConfig_tags_3)
		/sizeof(asn_DEF_restrictedSetConfig_tags_3[0]) - 1, /* 1 */
	asn_DEF_restrictedSetConfig_tags_3,	/* Same as above */
	sizeof(asn_DEF_restrictedSetConfig_tags_3)
		/sizeof(asn_DEF_restrictedSetConfig_tags_3[0]), /* 2 */
	{ 0, &asn_PER_type_restrictedSetConfig_constr_3, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_restrictedSetConfig_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_L839Info_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct L839Info, rootSequenceIndex),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_rootSequenceIndex_constr_2,  memb_rootSequenceIndex_constraint_1 },
		0, 0, /* No default value */
		"rootSequenceIndex"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct L839Info, restrictedSetConfig),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_restrictedSetConfig_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"restrictedSetConfig"
		},
	{ ATF_POINTER, 1, offsetof(struct L839Info, iE_Extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extension"
		},
};
static const int asn_MAP_L839Info_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_L839Info_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_L839Info_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rootSequenceIndex */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* restrictedSetConfig */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extension */
};
asn_SEQUENCE_specifics_t asn_SPC_L839Info_specs_1 = {
	sizeof(struct L839Info),
	offsetof(struct L839Info, _asn_ctx),
	asn_MAP_L839Info_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_L839Info_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_L839Info = {
	"L839Info",
	"L839Info",
	&asn_OP_SEQUENCE,
	asn_DEF_L839Info_tags_1,
	sizeof(asn_DEF_L839Info_tags_1)
		/sizeof(asn_DEF_L839Info_tags_1[0]), /* 1 */
	asn_DEF_L839Info_tags_1,	/* Same as above */
	sizeof(asn_DEF_L839Info_tags_1)
		/sizeof(asn_DEF_L839Info_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_L839Info_1,
	3,	/* Elements count */
	&asn_SPC_L839Info_specs_1	/* Additional specs */
};

