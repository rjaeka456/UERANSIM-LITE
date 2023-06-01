/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_QosMonitoringRequest_H_
#define	_QosMonitoringRequest_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum QosMonitoringRequest {
	QosMonitoringRequest_ul	= 0,
	QosMonitoringRequest_dl	= 1,
	QosMonitoringRequest_both	= 2,
	/*
	 * Enumeration is extensible
	 */
	QosMonitoringRequest_stop	= 3
} e_QosMonitoringRequest;

/* QosMonitoringRequest */
typedef long	 QosMonitoringRequest_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_QosMonitoringRequest;
asn_struct_free_f QosMonitoringRequest_free;
asn_struct_print_f QosMonitoringRequest_print;
asn_constr_check_f QosMonitoringRequest_constraint;
ber_type_decoder_f QosMonitoringRequest_decode_ber;
der_type_encoder_f QosMonitoringRequest_encode_der;
xer_type_decoder_f QosMonitoringRequest_decode_xer;
xer_type_encoder_f QosMonitoringRequest_encode_xer;
per_type_decoder_f QosMonitoringRequest_decode_uper;
per_type_encoder_f QosMonitoringRequest_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _QosMonitoringRequest_H_ */
#include <asn_internal.h>
