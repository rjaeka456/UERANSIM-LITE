/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_SItype_List_H_
#define	_SItype_List_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SItype_Item;

/* SItype-List */
typedef struct SItype_List {
	A_SEQUENCE_OF(struct SItype_Item) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SItype_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SItype_List;

#ifdef __cplusplus
}
#endif

#endif	/* _SItype_List_H_ */
#include <asn_internal.h>
