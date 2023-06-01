/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_IABTNLAddressUsage_H_
#define	_IABTNLAddressUsage_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum IABTNLAddressUsage {
	IABTNLAddressUsage_f1_c	= 0,
	IABTNLAddressUsage_f1_u	= 1,
	IABTNLAddressUsage_non_f1	= 2
	/*
	 * Enumeration is extensible
	 */
} e_IABTNLAddressUsage;

/* IABTNLAddressUsage */
typedef long	 IABTNLAddressUsage_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_IABTNLAddressUsage_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_IABTNLAddressUsage;
extern const asn_INTEGER_specifics_t asn_SPC_IABTNLAddressUsage_specs_1;
asn_struct_free_f IABTNLAddressUsage_free;
asn_struct_print_f IABTNLAddressUsage_print;
asn_constr_check_f IABTNLAddressUsage_constraint;
ber_type_decoder_f IABTNLAddressUsage_decode_ber;
der_type_encoder_f IABTNLAddressUsage_encode_der;
xer_type_decoder_f IABTNLAddressUsage_decode_xer;
xer_type_encoder_f IABTNLAddressUsage_encode_xer;
per_type_decoder_f IABTNLAddressUsage_decode_uper;
per_type_encoder_f IABTNLAddressUsage_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _IABTNLAddressUsage_H_ */
#include <asn_internal.h>
