/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#include "GNB-CU-NameVisibleString.h"

static int check_permitted_alphabet_1(const void *sptr) {
	/* The underlying type is VisibleString */
	const VisibleString_t *st = (const VisibleString_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	for(; ch < end; ch++) {
		uint8_t cv = *ch;
		if(!(cv >= 32 && cv <= 126)) return -1;
	}
	return 0;
}

int
GNB_CU_NameVisibleString_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const VisibleString_t *st = (const VisibleString_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 150)
		 && !check_permitted_alphabet_1(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

/*
 * This type is implemented using VisibleString,
 * so here we adjust the DEF accordingly.
 */
asn_per_constraints_t asn_PER_type_GNB_CU_NameVisibleString_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  32,  126 }	/* (32..126) */,
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  8,  8,  1,  150 }	/* (SIZE(1..150,...)) */,
	0, 0	/* No PER character map necessary */
};
static const ber_tlv_tag_t asn_DEF_GNB_CU_NameVisibleString_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (26 << 2))
};
asn_TYPE_descriptor_t asn_DEF_GNB_CU_NameVisibleString = {
	"GNB-CU-NameVisibleString",
	"GNB-CU-NameVisibleString",
	&asn_OP_VisibleString,
	asn_DEF_GNB_CU_NameVisibleString_tags_1,
	sizeof(asn_DEF_GNB_CU_NameVisibleString_tags_1)
		/sizeof(asn_DEF_GNB_CU_NameVisibleString_tags_1[0]), /* 1 */
	asn_DEF_GNB_CU_NameVisibleString_tags_1,	/* Same as above */
	sizeof(asn_DEF_GNB_CU_NameVisibleString_tags_1)
		/sizeof(asn_DEF_GNB_CU_NameVisibleString_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_GNB_CU_NameVisibleString_constr_1, GNB_CU_NameVisibleString_constraint },
	0, 0,	/* No members */
	0	/* No specifics */
};

