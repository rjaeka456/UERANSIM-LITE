/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "PRSResource-QCLSourceSSB.h"

#include "ProtocolExtensionContainer.h"
static int
memb_pCI_NR_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 1007)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_pCI_NR_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 10,  10,  0,  1007 }	/* (0..1007) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_PRSResource_QCLSourceSSB_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PRSResource_QCLSourceSSB, pCI_NR),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_pCI_NR_constr_2,  memb_pCI_NR_constraint_1 },
		0, 0, /* No default value */
		"pCI-NR"
		},
	{ ATF_POINTER, 2, offsetof(struct PRSResource_QCLSourceSSB, sSB_Index),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SSB_Index,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sSB-Index"
		},
	{ ATF_POINTER, 1, offsetof(struct PRSResource_QCLSourceSSB, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_10676P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_PRSResource_QCLSourceSSB_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_PRSResource_QCLSourceSSB_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PRSResource_QCLSourceSSB_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pCI-NR */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sSB-Index */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_PRSResource_QCLSourceSSB_specs_1 = {
	sizeof(struct PRSResource_QCLSourceSSB),
	offsetof(struct PRSResource_QCLSourceSSB, _asn_ctx),
	asn_MAP_PRSResource_QCLSourceSSB_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_PRSResource_QCLSourceSSB_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PRSResource_QCLSourceSSB = {
	"PRSResource-QCLSourceSSB",
	"PRSResource-QCLSourceSSB",
	&asn_OP_SEQUENCE,
	asn_DEF_PRSResource_QCLSourceSSB_tags_1,
	sizeof(asn_DEF_PRSResource_QCLSourceSSB_tags_1)
		/sizeof(asn_DEF_PRSResource_QCLSourceSSB_tags_1[0]), /* 1 */
	asn_DEF_PRSResource_QCLSourceSSB_tags_1,	/* Same as above */
	sizeof(asn_DEF_PRSResource_QCLSourceSSB_tags_1)
		/sizeof(asn_DEF_PRSResource_QCLSourceSSB_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PRSResource_QCLSourceSSB_1,
	3,	/* Elements count */
	&asn_SPC_PRSResource_QCLSourceSSB_specs_1	/* Additional specs */
};

