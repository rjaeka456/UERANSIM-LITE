/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-Containers"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_ProtocolExtensionField_H_
#define	_ProtocolExtensionField_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ProtocolExtensionID.h"
#include "Criticality.h"
#include <ANY.h>
#include <asn_ioc.h>
#include <OPEN_TYPE.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ProtocolExtensionField_10679P0__extensionValue_PR {
	ProtocolExtensionField_10679P0__extensionValue_PR_NOTHING,	/* No components present */
	
} ProtocolExtensionField_10679P0__extensionValue_PR;

/* ProtocolExtensionField */
typedef struct ProtocolExtensionField_10679P0 {
	ProtocolExtensionID_t	 id;
	Criticality_t	 criticality;
	struct ProtocolExtensionField_10679P0__extensionValue {
		ProtocolExtensionField_10679P0__extensionValue_PR present;
		union ProtocolExtensionField_10679P0__extensionValue_u {
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} extensionValue;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolExtensionField_10679P0_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ProtocolExtensionField_10679P0;
extern asn_SEQUENCE_specifics_t asn_SPC_ProtocolExtensionField_10679P0_specs_1;
extern asn_TYPE_member_t asn_MBR_ProtocolExtensionField_10679P0_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _ProtocolExtensionField_H_ */
#include <asn_internal.h>
