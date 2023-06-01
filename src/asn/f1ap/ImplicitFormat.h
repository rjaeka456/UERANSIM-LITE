/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_ImplicitFormat_H_
#define	_ImplicitFormat_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DUFSlotformatIndex.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* ImplicitFormat */
typedef struct ImplicitFormat {
	DUFSlotformatIndex_t	 dUFSlotformatIndex;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ImplicitFormat_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ImplicitFormat;
extern asn_SEQUENCE_specifics_t asn_SPC_ImplicitFormat_specs_1;
extern asn_TYPE_member_t asn_MBR_ImplicitFormat_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _ImplicitFormat_H_ */
#include <asn_internal.h>
