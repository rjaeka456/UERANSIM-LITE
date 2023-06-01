/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-Containers"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_ProtocolIE_Container_H_
#define	_ProtocolIE_Container_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolIE_Field;

/* ProtocolIE-Container */
typedef struct ProtocolIE_Container_10639P0 {
	A_SEQUENCE_OF(struct ProtocolIE_Field) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Container_10639P0_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Container_10639P0;
extern asn_SET_OF_specifics_t asn_SPC_ProtocolIE_Container_10639P0_specs_1;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Container_10639P0_1[1];
extern asn_per_constraints_t asn_PER_type_ProtocolIE_Container_10639P0_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _ProtocolIE_Container_H_ */
#include <asn_internal.h>
