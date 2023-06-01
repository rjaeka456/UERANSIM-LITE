/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_ShortDRXCycleLength_H_
#define	_ShortDRXCycleLength_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ShortDRXCycleLength {
	ShortDRXCycleLength_ms2	= 0,
	ShortDRXCycleLength_ms3	= 1,
	ShortDRXCycleLength_ms4	= 2,
	ShortDRXCycleLength_ms5	= 3,
	ShortDRXCycleLength_ms6	= 4,
	ShortDRXCycleLength_ms7	= 5,
	ShortDRXCycleLength_ms8	= 6,
	ShortDRXCycleLength_ms10	= 7,
	ShortDRXCycleLength_ms14	= 8,
	ShortDRXCycleLength_ms16	= 9,
	ShortDRXCycleLength_ms20	= 10,
	ShortDRXCycleLength_ms30	= 11,
	ShortDRXCycleLength_ms32	= 12,
	ShortDRXCycleLength_ms35	= 13,
	ShortDRXCycleLength_ms40	= 14,
	ShortDRXCycleLength_ms64	= 15,
	ShortDRXCycleLength_ms80	= 16,
	ShortDRXCycleLength_ms128	= 17,
	ShortDRXCycleLength_ms160	= 18,
	ShortDRXCycleLength_ms256	= 19,
	ShortDRXCycleLength_ms320	= 20,
	ShortDRXCycleLength_ms512	= 21,
	ShortDRXCycleLength_ms640	= 22
	/*
	 * Enumeration is extensible
	 */
} e_ShortDRXCycleLength;

/* ShortDRXCycleLength */
typedef long	 ShortDRXCycleLength_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ShortDRXCycleLength_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ShortDRXCycleLength;
extern const asn_INTEGER_specifics_t asn_SPC_ShortDRXCycleLength_specs_1;
asn_struct_free_f ShortDRXCycleLength_free;
asn_struct_print_f ShortDRXCycleLength_print;
asn_constr_check_f ShortDRXCycleLength_constraint;
ber_type_decoder_f ShortDRXCycleLength_decode_ber;
der_type_encoder_f ShortDRXCycleLength_encode_der;
xer_type_decoder_f ShortDRXCycleLength_decode_xer;
xer_type_encoder_f ShortDRXCycleLength_encode_xer;
per_type_decoder_f ShortDRXCycleLength_decode_uper;
per_type_encoder_f ShortDRXCycleLength_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _ShortDRXCycleLength_H_ */
#include <asn_internal.h>
