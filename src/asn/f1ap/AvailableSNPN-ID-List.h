/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_AvailableSNPN_ID_List_H_
#define	_AvailableSNPN_ID_List_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct AvailableSNPN_ID_List_Item;

/* AvailableSNPN-ID-List */
typedef struct AvailableSNPN_ID_List {
	A_SEQUENCE_OF(struct AvailableSNPN_ID_List_Item) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AvailableSNPN_ID_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AvailableSNPN_ID_List;

#ifdef __cplusplus
}
#endif

#endif	/* _AvailableSNPN_ID_List_H_ */
#include <asn_internal.h>
