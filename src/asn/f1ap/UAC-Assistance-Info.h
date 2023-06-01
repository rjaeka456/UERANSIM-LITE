/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_UAC_Assistance_Info_H_
#define	_UAC_Assistance_Info_H_


#include <asn_application.h>

/* Including external dependencies */
#include "UACPLMN-List.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* UAC-Assistance-Info */
typedef struct UAC_Assistance_Info {
	UACPLMN_List_t	 uACPLMN_List;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UAC_Assistance_Info_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UAC_Assistance_Info;

#ifdef __cplusplus
}
#endif

#endif	/* _UAC_Assistance_Info_H_ */
#include <asn_internal.h>
