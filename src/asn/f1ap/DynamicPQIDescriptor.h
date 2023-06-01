/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_DynamicPQIDescriptor_H_
#define	_DynamicPQIDescriptor_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include "PacketDelayBudget.h"
#include "PacketErrorRate.h"
#include "AveragingWindow.h"
#include "MaxDataBurstVolume.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DynamicPQIDescriptor__resourceType {
	DynamicPQIDescriptor__resourceType_gbr	= 0,
	DynamicPQIDescriptor__resourceType_non_gbr	= 1,
	DynamicPQIDescriptor__resourceType_delay_critical_grb	= 2
	/*
	 * Enumeration is extensible
	 */
} e_DynamicPQIDescriptor__resourceType;

/* Forward declarations */
struct ProtocolExtensionContainer;

/* DynamicPQIDescriptor */
typedef struct DynamicPQIDescriptor {
	long	*resourceType	/* OPTIONAL */;
	long	 qoSPriorityLevel;
	PacketDelayBudget_t	 packetDelayBudget;
	PacketErrorRate_t	 packetErrorRate;
	AveragingWindow_t	*averagingWindow	/* OPTIONAL */;
	MaxDataBurstVolume_t	*maxDataBurstVolume	/* OPTIONAL */;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DynamicPQIDescriptor_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_resourceType_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_DynamicPQIDescriptor;
extern asn_SEQUENCE_specifics_t asn_SPC_DynamicPQIDescriptor_specs_1;
extern asn_TYPE_member_t asn_MBR_DynamicPQIDescriptor_1[7];

#ifdef __cplusplus
}
#endif

#endif	/* _DynamicPQIDescriptor_H_ */
#include <asn_internal.h>
