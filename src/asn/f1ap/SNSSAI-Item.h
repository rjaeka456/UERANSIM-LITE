/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_SNSSAI_Item_H_
#define	_SNSSAI_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SNSSAI.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* SNSSAI-Item */
typedef struct SNSSAI_Item {
	SNSSAI_t	 sNSSAI;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SNSSAI_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SNSSAI_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_SNSSAI_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_SNSSAI_Item_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _SNSSAI_Item_H_ */
#include <asn_internal.h>
