/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_MultiplexingInfo_H_
#define	_MultiplexingInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "IAB-MT-Cell-List.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* MultiplexingInfo */
typedef struct MultiplexingInfo {
	IAB_MT_Cell_List_t	 iAB_MT_Cell_List;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MultiplexingInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MultiplexingInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_MultiplexingInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_MultiplexingInfo_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _MultiplexingInfo_H_ */
#include <asn_internal.h>
