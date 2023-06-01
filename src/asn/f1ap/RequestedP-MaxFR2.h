/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_RequestedP_MaxFR2_H_
#define	_RequestedP_MaxFR2_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RequestedP-MaxFR2 */
typedef OCTET_STRING_t	 RequestedP_MaxFR2_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RequestedP_MaxFR2;
asn_struct_free_f RequestedP_MaxFR2_free;
asn_struct_print_f RequestedP_MaxFR2_print;
asn_constr_check_f RequestedP_MaxFR2_constraint;
ber_type_decoder_f RequestedP_MaxFR2_decode_ber;
der_type_encoder_f RequestedP_MaxFR2_encode_der;
xer_type_decoder_f RequestedP_MaxFR2_decode_xer;
xer_type_encoder_f RequestedP_MaxFR2_encode_xer;
per_type_decoder_f RequestedP_MaxFR2_decode_uper;
per_type_encoder_f RequestedP_MaxFR2_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _RequestedP_MaxFR2_H_ */
#include <asn_internal.h>
