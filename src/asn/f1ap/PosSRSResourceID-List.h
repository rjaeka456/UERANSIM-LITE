/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_PosSRSResourceID_List_H_
#define	_PosSRSResourceID_List_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SRSPosResourceID.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PosSRSResourceID-List */
typedef struct PosSRSResourceID_List {
	A_SEQUENCE_OF(SRSPosResourceID_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PosSRSResourceID_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PosSRSResourceID_List;
extern asn_SET_OF_specifics_t asn_SPC_PosSRSResourceID_List_specs_1;
extern asn_TYPE_member_t asn_MBR_PosSRSResourceID_List_1[1];
extern asn_per_constraints_t asn_PER_type_PosSRSResourceID_List_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _PosSRSResourceID_List_H_ */
#include <asn_internal.h>
