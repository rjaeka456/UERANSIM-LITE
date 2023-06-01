/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_Neighbour_Cell_Information_Item_H_
#define	_Neighbour_Cell_Information_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRCGI.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct IntendedTDD_DL_ULConfig;
struct ProtocolExtensionContainer;

/* Neighbour-Cell-Information-Item */
typedef struct Neighbour_Cell_Information_Item {
	NRCGI_t	 nRCGI;
	struct IntendedTDD_DL_ULConfig	*intendedTDD_DL_ULConfig	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Neighbour_Cell_Information_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Neighbour_Cell_Information_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _Neighbour_Cell_Information_Item_H_ */
#include <asn_internal.h>
