/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_DL_PRS_H_
#define	_DL_PRS_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "PRS-Resource-Set-ID.h"
#include "PRS-Resource-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* DL-PRS */
typedef struct DL_PRS {
	long	 prsid;
	PRS_Resource_Set_ID_t	 dl_PRSResourceSetID;
	PRS_Resource_ID_t	*dl_PRSResourceID	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DL_PRS_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DL_PRS;
extern asn_SEQUENCE_specifics_t asn_SPC_DL_PRS_specs_1;
extern asn_TYPE_member_t asn_MBR_DL_PRS_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _DL_PRS_H_ */
#include <asn_internal.h>
