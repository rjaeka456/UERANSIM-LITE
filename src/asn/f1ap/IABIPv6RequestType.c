/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "IABIPv6RequestType.h"

#include "IABTNLAddressesRequested.h"
#include "ProtocolIE-SingleContainer.h"
static asn_per_constraints_t asn_PER_type_IABIPv6RequestType_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_IABIPv6RequestType_1[] = {
	{ ATF_POINTER, 0, offsetof(struct IABIPv6RequestType, choice.iPv6Address),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IABTNLAddressesRequested,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iPv6Address"
		},
	{ ATF_POINTER, 0, offsetof(struct IABIPv6RequestType, choice.iPv6Prefix),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IABTNLAddressesRequested,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iPv6Prefix"
		},
	{ ATF_POINTER, 0, offsetof(struct IABIPv6RequestType, choice.choice_extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_SingleContainer_10642P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice-extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_IABIPv6RequestType_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* iPv6Address */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* iPv6Prefix */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* choice-extension */
};
static asn_CHOICE_specifics_t asn_SPC_IABIPv6RequestType_specs_1 = {
	sizeof(struct IABIPv6RequestType),
	offsetof(struct IABIPv6RequestType, _asn_ctx),
	offsetof(struct IABIPv6RequestType, present),
	sizeof(((struct IABIPv6RequestType *)0)->present),
	asn_MAP_IABIPv6RequestType_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_IABIPv6RequestType = {
	"IABIPv6RequestType",
	"IABIPv6RequestType",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_IABIPv6RequestType_constr_1, CHOICE_constraint },
	asn_MBR_IABIPv6RequestType_1,
	3,	/* Elements count */
	&asn_SPC_IABIPv6RequestType_specs_1	/* Additional specs */
};

