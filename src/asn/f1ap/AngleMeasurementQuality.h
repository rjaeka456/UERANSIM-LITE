/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-IEs"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_AngleMeasurementQuality_H_
#define	_AngleMeasurementQuality_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AngleMeasurementQuality__resolution {
	AngleMeasurementQuality__resolution_deg0dot1	= 0
	/*
	 * Enumeration is extensible
	 */
} e_AngleMeasurementQuality__resolution;

/* Forward declarations */
struct ProtocolExtensionContainer;

/* AngleMeasurementQuality */
typedef struct AngleMeasurementQuality {
	long	 azimuthQuality;
	long	*zenithQuality	/* OPTIONAL */;
	long	 resolution;
	struct ProtocolExtensionContainer	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AngleMeasurementQuality_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_resolution_4;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_AngleMeasurementQuality;
extern asn_SEQUENCE_specifics_t asn_SPC_AngleMeasurementQuality_specs_1;
extern asn_TYPE_member_t asn_MBR_AngleMeasurementQuality_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _AngleMeasurementQuality_H_ */
#include <asn_internal.h>
