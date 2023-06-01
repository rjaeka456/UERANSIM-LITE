/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_IAB_TNL_Addresses_To_Remove_Item_H_
#define	_IAB_TNL_Addresses_To_Remove_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "IABTNLAddress.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* IAB-TNL-Addresses-To-Remove-Item */
typedef struct IAB_TNL_Addresses_To_Remove_Item {
	IABTNLAddress_t	 iABTNLAddress;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IAB_TNL_Addresses_To_Remove_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IAB_TNL_Addresses_To_Remove_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _IAB_TNL_Addresses_To_Remove_Item_H_ */
#include <asn_internal.h>
