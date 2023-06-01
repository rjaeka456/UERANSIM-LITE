/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-Containers"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "ProtocolExtensionField.h"

static const asn_ioc_cell_t asn_IOS_SemipersistentSRS_ExtIEs_1_rows[] = {
	
};
static const asn_ioc_set_t asn_IOS_SemipersistentSRS_ExtIEs_1[] = {
	0, 0, asn_IOS_SemipersistentSRS_ExtIEs_1_rows
};
static int
memb_id_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_criticality_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

static int
memb_extensionValue_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

static asn_per_constraints_t asn_PER_memb_id_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 16,  16,  0,  65535 }	/* (0..65535) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_criticality_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_extensionValue_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_CHOICE_specifics_t asn_SPC_extensionValue_specs_4 = {
	sizeof(struct ProtocolExtensionField_10679P0__extensionValue),
	offsetof(struct ProtocolExtensionField_10679P0__extensionValue, _asn_ctx),
	offsetof(struct ProtocolExtensionField_10679P0__extensionValue, present),
	sizeof(((struct ProtocolExtensionField_10679P0__extensionValue *)0)->present),
	0,	/* No top level tags */
	0,	/* No tags in the map */
	0, 0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_extensionValue_4 = {
	"extensionValue",
	"extensionValue",
	&asn_OP_OPEN_TYPE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, 0, OPEN_TYPE_constraint },
	0, 0,	/* No members */
	&asn_SPC_extensionValue_specs_4	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_ProtocolExtensionField_10679P0_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ProtocolExtensionField_10679P0, id),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionID,
		0,
		{ 0, &asn_PER_memb_id_constr_2,  memb_id_constraint_1 },
		0, 0, /* No default value */
		"id"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ProtocolExtensionField_10679P0, criticality),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Criticality,
		0,
		{ 0, &asn_PER_memb_criticality_constr_3,  memb_criticality_constraint_1 },
		0, 0, /* No default value */
		"criticality"
		},
	{ ATF_OPEN_TYPE | ATF_NOFLAGS, 0, offsetof(struct ProtocolExtensionField_10679P0, extensionValue),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_extensionValue_4,
		0,
		{ 0, &asn_PER_memb_extensionValue_constr_4,  memb_extensionValue_constraint_1 },
		0, 0, /* No default value */
		"extensionValue"
		},
};
static const ber_tlv_tag_t asn_DEF_ProtocolExtensionField_10679P0_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ProtocolExtensionField_10679P0_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* id */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* criticality */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* extensionValue */
};
asn_SEQUENCE_specifics_t asn_SPC_ProtocolExtensionField_10679P0_specs_1 = {
	sizeof(struct ProtocolExtensionField_10679P0),
	offsetof(struct ProtocolExtensionField_10679P0, _asn_ctx),
	asn_MAP_ProtocolExtensionField_10679P0_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ProtocolExtensionField_10679P0 = {
	"ProtocolExtensionField",
	"ProtocolExtensionField",
	&asn_OP_SEQUENCE,
	asn_DEF_ProtocolExtensionField_10679P0_tags_1,
	sizeof(asn_DEF_ProtocolExtensionField_10679P0_tags_1)
		/sizeof(asn_DEF_ProtocolExtensionField_10679P0_tags_1[0]), /* 1 */
	asn_DEF_ProtocolExtensionField_10679P0_tags_1,	/* Same as above */
	sizeof(asn_DEF_ProtocolExtensionField_10679P0_tags_1)
		/sizeof(asn_DEF_ProtocolExtensionField_10679P0_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ProtocolExtensionField_10679P0_1,
	3,	/* Elements count */
	&asn_SPC_ProtocolExtensionField_10679P0_specs_1	/* Additional specs */
};

