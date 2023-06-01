/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_PathlossReferenceInfo_H_
#define	_PathlossReferenceInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PathlossReferenceSignal.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* PathlossReferenceInfo */
typedef struct PathlossReferenceInfo {
	PathlossReferenceSignal_t	 pathlossReferenceSignal;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PathlossReferenceInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PathlossReferenceInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_PathlossReferenceInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_PathlossReferenceInfo_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _PathlossReferenceInfo_H_ */
#include <asn_internal.h>
