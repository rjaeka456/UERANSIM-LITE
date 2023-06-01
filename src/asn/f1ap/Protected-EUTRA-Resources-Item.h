/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_Protected_EUTRA_Resources_Item_H_
#define	_Protected_EUTRA_Resources_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SpectrumSharingGroupID.h"
#include "EUTRACells-List.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* Protected-EUTRA-Resources-Item */
typedef struct Protected_EUTRA_Resources_Item {
	SpectrumSharingGroupID_t	 spectrumSharingGroupID;
	EUTRACells_List_t	 eUTRACells_List;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Protected_EUTRA_Resources_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Protected_EUTRA_Resources_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _Protected_EUTRA_Resources_Item_H_ */
#include <asn_internal.h>
