/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_PRSResource_QCLSourceSSB_H_
#define	_PRSResource_QCLSourceSSB_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "SSB-Index.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ProtocolExtensionContainer;

/* PRSResource-QCLSourceSSB */
typedef struct PRSResource_QCLSourceSSB {
	long	 pCI_NR;
	SSB_Index_t	*sSB_Index	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PRSResource_QCLSourceSSB_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PRSResource_QCLSourceSSB;
extern asn_SEQUENCE_specifics_t asn_SPC_PRSResource_QCLSourceSSB_specs_1;
extern asn_TYPE_member_t asn_MBR_PRSResource_QCLSourceSSB_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _PRSResource_QCLSourceSSB_H_ */
#include <asn_internal.h>
