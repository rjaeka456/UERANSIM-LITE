/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP-Containers"
 * 	found in "./f1ap-16.8.0.asn1"
 * 	`asn1c -fcompound-names -pdu=all -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D f1ap`
 */

#ifndef	_ProtocolIE_Field_H_
#define	_ProtocolIE_Field_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ProtocolIE-ID.h"
#include "Criticality.h"
#include <ANY.h>
#include <asn_ioc.h>
#include <OPEN_TYPE.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>
#include "Presence.h"
#include "TransactionID.h"
#include "GNB-DU-ID.h"
#include "GNB-DU-Name.h"
#include "GNB-DU-Served-Cells-List.h"
#include "RRC-Version.h"
#include "Transport-Layer-Address-Info.h"
#include "BAPAddress.h"
#include "Extended-GNB-DU-Name.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ProtocolIE_Field_10645P0__value_PR {
	ProtocolIE_Field_10645P0__value_PR_NOTHING,	/* No components present */
	
} ProtocolIE_Field_10645P0__value_PR;

typedef enum F1SetupRequestIEs__value_PR {
    F1SetupRequestIEs__value_PR_NOTHING,	/* No components present */
    F1SetupRequestIEs__value_PR_TransactionID,
    F1SetupRequestIEs__value_PR_gNB_DU_ID,
    F1SetupRequestIEs__value_PR_gNB_DU_Name,
    F1SetupRequestIEs__value_PR_gNB_DU_Served_Cells_List,
    F1SetupRequestIEs__value_PR_GNB_DU_RRC_Version,
    F1SetupRequestIEs__value_PR_Transport_Layer_Address_Info,
    F1SetupRequestIEs__value_PR_BAPAddress,
    F1SetupRequestIEs__value_PR_Extended_GNB_DU_Name,
} F1SetupRequestIEs__value_PR;

/* ProtocolIE-Field */
typedef struct ProtocolIE_Field_10645P0 {
	ProtocolIE_ID_t	 id;
	Criticality_t	 criticality;
	struct ProtocolIE_Field_10645P0__value {
		ProtocolIE_Field_10645P0__value_PR present;
		union ProtocolIE_Field_10645P0__value_u {
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} value;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProtocolIE_Field_10645P0_t;

typedef struct F1SetupRequestIEs {
    ProtocolIE_ID_t	 id;
    Criticality_t	 criticality;
    struct F1SetupRequestIEs__value {
        F1SetupRequestIEs__value_PR present;
        union F1SetupRequestIEs__value_u {
            TransactionID_t TransactionID;
            GNB_DU_ID_t gNB_DU_ID;
            GNB_DU_Name_t gNB_DU_Name;
            GNB_DU_Served_Cells_List_t gNB_DU_Served_Cells_List;
            RRC_Version_t GNB_DU_RRC_Version;
            Transport_Layer_Address_Info_t Transport_Layer_Address_Info;
            BAPAddress_t BAPAdress;
            Extended_GNB_DU_Name_t Extended_GNB_DU_Name;
        } choice;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } value;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} NGSetupRequestIEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_Field_10645P0;
extern asn_SEQUENCE_specifics_t asn_SPC_ProtocolIE_Field_10645P0_specs_1;
extern asn_TYPE_member_t asn_MBR_ProtocolIE_Field_10645P0_1[3];

extern asn_TYPE_descriptor_t asn_DEF_F1SetupRequestIEs;
extern asn_SEQUENCE_specifics_t asn_SPC_F1SetupRequestIEs_specs_5;
extern asn_TYPE_member_t asn_MBR_F1SetupRequestIEs_5[3];

#ifdef __cplusplus
}
#endif

#endif	/* _ProtocolIE_Field_H_ */
#include <asn_internal.h>
