/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_CauseTransport_H_
#define	_CauseTransport_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CauseTransport {
	CauseTransport_unspecified	= 0,
	CauseTransport_transport_resource_unavailable	= 1,
	/*
	 * Enumeration is extensible
	 */
	CauseTransport_unknown_TNL_address_for_IAB	= 2,
	CauseTransport_unknown_UP_TNL_information_for_IAB	= 3
} e_CauseTransport;

/* CauseTransport */
typedef long	 CauseTransport_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_CauseTransport_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_CauseTransport;
extern const asn_INTEGER_specifics_t asn_SPC_CauseTransport_specs_1;
asn_struct_free_f CauseTransport_free;
asn_struct_print_f CauseTransport_print;
asn_constr_check_f CauseTransport_constraint;
ber_type_decoder_f CauseTransport_decode_ber;
der_type_encoder_f CauseTransport_encode_der;
xer_type_decoder_f CauseTransport_decode_xer;
xer_type_encoder_f CauseTransport_encode_xer;
per_type_decoder_f CauseTransport_decode_uper;
per_type_encoder_f CauseTransport_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _CauseTransport_H_ */
#include <asn_internal.h>
