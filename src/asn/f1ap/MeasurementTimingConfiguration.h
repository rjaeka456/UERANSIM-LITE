/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_MeasurementTimingConfiguration_H_
#define	_MeasurementTimingConfiguration_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MeasurementTimingConfiguration */
typedef OCTET_STRING_t	 MeasurementTimingConfiguration_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasurementTimingConfiguration;
asn_struct_free_f MeasurementTimingConfiguration_free;
asn_struct_print_f MeasurementTimingConfiguration_print;
asn_constr_check_f MeasurementTimingConfiguration_constraint;
ber_type_decoder_f MeasurementTimingConfiguration_decode_ber;
der_type_encoder_f MeasurementTimingConfiguration_encode_der;
xer_type_decoder_f MeasurementTimingConfiguration_decode_xer;
xer_type_encoder_f MeasurementTimingConfiguration_encode_xer;
per_type_decoder_f MeasurementTimingConfiguration_decode_uper;
per_type_encoder_f MeasurementTimingConfiguration_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _MeasurementTimingConfiguration_H_ */
#include <asn_internal.h>
