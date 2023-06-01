/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "PRSResource-QCLInfo.h"

#include "PRSResource-QCLSourceSSB.h"
#include "PRSResource-QCLSourcePRS.h"
#include "ProtocolIE-SingleContainer.h"
asn_per_constraints_t asn_PER_type_PRSResource_QCLInfo_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_PRSResource_QCLInfo_1[] = {
	{ ATF_POINTER, 0, offsetof(struct PRSResource_QCLInfo, choice.qCLSourceSSB),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PRSResource_QCLSourceSSB,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qCLSourceSSB"
		},
	{ ATF_POINTER, 0, offsetof(struct PRSResource_QCLInfo, choice.qCLSourcePRS),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PRSResource_QCLSourcePRS,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qCLSourcePRS"
		},
	{ ATF_POINTER, 0, offsetof(struct PRSResource_QCLInfo, choice.choice_extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_SingleContainer_10642P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice-extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_PRSResource_QCLInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* qCLSourceSSB */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* qCLSourcePRS */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* choice-extension */
};
asn_CHOICE_specifics_t asn_SPC_PRSResource_QCLInfo_specs_1 = {
	sizeof(struct PRSResource_QCLInfo),
	offsetof(struct PRSResource_QCLInfo, _asn_ctx),
	offsetof(struct PRSResource_QCLInfo, present),
	sizeof(((struct PRSResource_QCLInfo *)0)->present),
	asn_MAP_PRSResource_QCLInfo_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_PRSResource_QCLInfo = {
	"PRSResource-QCLInfo",
	"PRSResource-QCLInfo",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_PRSResource_QCLInfo_constr_1, CHOICE_constraint },
	asn_MBR_PRSResource_QCLInfo_1,
	3,	/* Elements count */
	&asn_SPC_PRSResource_QCLInfo_specs_1	/* Additional specs */
};

