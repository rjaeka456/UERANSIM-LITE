/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_RequestedFeatureSetEntryIndex_H_
#define	_RequestedFeatureSetEntryIndex_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RequestedFeatureSetEntryIndex */
typedef OCTET_STRING_t	 RequestedFeatureSetEntryIndex_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RequestedFeatureSetEntryIndex;
asn_struct_free_f RequestedFeatureSetEntryIndex_free;
asn_struct_print_f RequestedFeatureSetEntryIndex_print;
asn_constr_check_f RequestedFeatureSetEntryIndex_constraint;
ber_type_decoder_f RequestedFeatureSetEntryIndex_decode_ber;
der_type_encoder_f RequestedFeatureSetEntryIndex_encode_der;
xer_type_decoder_f RequestedFeatureSetEntryIndex_decode_xer;
xer_type_encoder_f RequestedFeatureSetEntryIndex_encode_xer;
per_type_decoder_f RequestedFeatureSetEntryIndex_decode_uper;
per_type_encoder_f RequestedFeatureSetEntryIndex_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _RequestedFeatureSetEntryIndex_H_ */
#include <asn_internal.h>
