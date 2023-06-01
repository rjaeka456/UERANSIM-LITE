/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_AggressorgNBSetID_H_
#define	_AggressorgNBSetID_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GNBSetID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* AggressorgNBSetID */
typedef struct AggressorgNBSetID {
	GNBSetID_t	 aggressorgNBSetID;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AggressorgNBSetID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AggressorgNBSetID;

#ifdef __cplusplus
}
#endif

#endif	/* _AggressorgNBSetID_H_ */
#include <asn_internal.h>
