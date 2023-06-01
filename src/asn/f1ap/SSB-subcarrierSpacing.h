/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_SSB_subcarrierSpacing_H_
#define	_SSB_subcarrierSpacing_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SSB_subcarrierSpacing {
	SSB_subcarrierSpacing_kHz15	= 0,
	SSB_subcarrierSpacing_kHz30	= 1,
	SSB_subcarrierSpacing_kHz120	= 2,
	SSB_subcarrierSpacing_kHz240	= 3,
	SSB_subcarrierSpacing_spare3	= 4,
	SSB_subcarrierSpacing_spare2	= 5,
	SSB_subcarrierSpacing_spare1	= 6
	/*
	 * Enumeration is extensible
	 */
} e_SSB_subcarrierSpacing;

/* SSB-subcarrierSpacing */
typedef long	 SSB_subcarrierSpacing_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_SSB_subcarrierSpacing_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_SSB_subcarrierSpacing;
extern const asn_INTEGER_specifics_t asn_SPC_SSB_subcarrierSpacing_specs_1;
asn_struct_free_f SSB_subcarrierSpacing_free;
asn_struct_print_f SSB_subcarrierSpacing_print;
asn_constr_check_f SSB_subcarrierSpacing_constraint;
ber_type_decoder_f SSB_subcarrierSpacing_decode_ber;
der_type_encoder_f SSB_subcarrierSpacing_encode_der;
xer_type_decoder_f SSB_subcarrierSpacing_decode_xer;
xer_type_encoder_f SSB_subcarrierSpacing_encode_xer;
per_type_decoder_f SSB_subcarrierSpacing_decode_uper;
per_type_encoder_f SSB_subcarrierSpacing_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _SSB_subcarrierSpacing_H_ */
#include <asn_internal.h>
