/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_SIB10_message_H_
#define	_SIB10_message_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SIB10-message */
typedef OCTET_STRING_t	 SIB10_message_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SIB10_message;
asn_struct_free_f SIB10_message_free;
asn_struct_print_f SIB10_message_print;
asn_constr_check_f SIB10_message_constraint;
ber_type_decoder_f SIB10_message_decode_ber;
der_type_encoder_f SIB10_message_encode_der;
xer_type_decoder_f SIB10_message_decode_xer;
xer_type_encoder_f SIB10_message_encode_xer;
per_type_decoder_f SIB10_message_decode_uper;
per_type_encoder_f SIB10_message_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _SIB10_message_H_ */
#include <asn_internal.h>
