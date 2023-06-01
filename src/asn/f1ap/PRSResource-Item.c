/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "PRSResource-Item.h"

#include "PRSResource-QCLInfo.h"
#include "ProtocolExtensionContainer.h"
static int
memb_sequenceID_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 4095)) {
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
memb_rEOffset_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 11)) {
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
memb_resourceSlotOffset_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 511)) {
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
memb_resourceSymbolOffset_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 12)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_sequenceID_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 12,  12,  0,  4095 }	/* (0..4095) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_rEOffset_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  4,  4,  0,  11 }	/* (0..11,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_resourceSlotOffset_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 9,  9,  0,  511 }	/* (0..511) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_resourceSymbolOffset_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  12 }	/* (0..12) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_PRSResource_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PRSResource_Item, pRSResourceID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PRS_Resource_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"pRSResourceID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PRSResource_Item, sequenceID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_sequenceID_constr_3,  memb_sequenceID_constraint_1 },
		0, 0, /* No default value */
		"sequenceID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PRSResource_Item, rEOffset),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_rEOffset_constr_4,  memb_rEOffset_constraint_1 },
		0, 0, /* No default value */
		"rEOffset"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PRSResource_Item, resourceSlotOffset),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_resourceSlotOffset_constr_5,  memb_resourceSlotOffset_constraint_1 },
		0, 0, /* No default value */
		"resourceSlotOffset"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PRSResource_Item, resourceSymbolOffset),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_resourceSymbolOffset_constr_6,  memb_resourceSymbolOffset_constraint_1 },
		0, 0, /* No default value */
		"resourceSymbolOffset"
		},
	{ ATF_POINTER, 2, offsetof(struct PRSResource_Item, qCLInfo),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_PRSResource_QCLInfo,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qCLInfo"
		},
	{ ATF_POINTER, 1, offsetof(struct PRSResource_Item, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_PRSResource_Item_oms_1[] = { 5, 6 };
static const ber_tlv_tag_t asn_DEF_PRSResource_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PRSResource_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pRSResourceID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sequenceID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* rEOffset */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* resourceSlotOffset */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* resourceSymbolOffset */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* qCLInfo */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_PRSResource_Item_specs_1 = {
	sizeof(struct PRSResource_Item),
	offsetof(struct PRSResource_Item, _asn_ctx),
	asn_MAP_PRSResource_Item_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_PRSResource_Item_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PRSResource_Item = {
	"PRSResource-Item",
	"PRSResource-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_PRSResource_Item_tags_1,
	sizeof(asn_DEF_PRSResource_Item_tags_1)
		/sizeof(asn_DEF_PRSResource_Item_tags_1[0]), /* 1 */
	asn_DEF_PRSResource_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_PRSResource_Item_tags_1)
		/sizeof(asn_DEF_PRSResource_Item_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PRSResource_Item_1,
	7,	/* Elements count */
	&asn_SPC_PRSResource_Item_specs_1	/* Additional specs */
};

