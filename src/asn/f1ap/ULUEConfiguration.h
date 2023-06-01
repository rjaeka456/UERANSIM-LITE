/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_ULUEConfiguration_H_
#define	_ULUEConfiguration_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ULUEConfiguration {
	ULUEConfiguration_no_data	= 0,
	ULUEConfiguration_shared	= 1,
	ULUEConfiguration_only	= 2
	/*
	 * Enumeration is extensible
	 */
} e_ULUEConfiguration;

/* ULUEConfiguration */
typedef long	 ULUEConfiguration_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ULUEConfiguration_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ULUEConfiguration;
extern const asn_INTEGER_specifics_t asn_SPC_ULUEConfiguration_specs_1;
asn_struct_free_f ULUEConfiguration_free;
asn_struct_print_f ULUEConfiguration_print;
asn_constr_check_f ULUEConfiguration_constraint;
ber_type_decoder_f ULUEConfiguration_decode_ber;
der_type_encoder_f ULUEConfiguration_encode_der;
xer_type_decoder_f ULUEConfiguration_decode_xer;
xer_type_encoder_f ULUEConfiguration_encode_xer;
per_type_decoder_f ULUEConfiguration_decode_uper;
per_type_encoder_f ULUEConfiguration_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _ULUEConfiguration_H_ */
#include <asn_internal.h>
