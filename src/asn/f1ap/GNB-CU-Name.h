/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_GNB_CU_Name_H_
#define	_GNB_CU_Name_H_


#include <asn_application.h>

/* Including external dependencies */
#include <PrintableString.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GNB-CU-Name */
typedef PrintableString_t	 GNB_CU_Name_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GNB_CU_Name;
asn_struct_free_f GNB_CU_Name_free;
asn_struct_print_f GNB_CU_Name_print;
asn_constr_check_f GNB_CU_Name_constraint;
ber_type_decoder_f GNB_CU_Name_decode_ber;
der_type_encoder_f GNB_CU_Name_encode_der;
xer_type_decoder_f GNB_CU_Name_decode_xer;
xer_type_encoder_f GNB_CU_Name_encode_xer;
per_type_decoder_f GNB_CU_Name_decode_uper;
per_type_encoder_f GNB_CU_Name_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _GNB_CU_Name_H_ */
#include <asn_internal.h>
