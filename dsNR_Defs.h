/*--------------------------------------------------------------------------
// Global Header File for 5G NR Library
*/
#ifndef __DS_NR_DEFS_H__
#define __DS_NR_DEFS_H__

#ifndef __DS_ALG_DEFS_H__
#include "dsALG_Defs.h"
#endif

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

	//#pragma pack(push, 1)

		//#define HIGH_SPEED_ACC
#if defined(WIN32) & defined(HIGH_SPEED_ACC)
#pragma comment(lib, "ippcorel.lib")
#pragma comment(lib, "ippsmerged.lib")
#pragma comment(lib, "ippsemerged.lib")
#endif

	//#define DEBUG_PRINT
	//#define DEBUG_MSG

	//#define INPUT_32BIT
#define NEW_POLAR_DECODE

#define GLOBAL_FEATURE

// GPS Processing Delay : 100 ns x 100
#define GPS_1PPS_DELAY						10000

// Unit : Sample @ 30.72MHz. 42 -> AD9361 filter delay(64 sample @ 61.44) + 0.36us RF path delay + FPGA Delay (67 sample)
#define SYS_RF_DELAY						109
#define SYS_RF_DELAY_15p36					55

#define NONE_MEAS_RESULT					-999999

#define SYSTEM_DELAY						0
#define FILTER_DELAY						0

#define SYS_SAMPLE_RATE						30720000
// FFT Size
#define MAX_FFT_SIZE						4096
#define MIN_FFT_SIZE						256
#define MAX_1ST_CP							544
#define MAX_NORMAL_CP						288

#define MAX_FRAME_LEN						4915200

#define FRAME_LEN							1228800

// PCI Parameters
#define NUM_OF_PCI							1008
#define NUM_OF_N2_ID						3
#define NUM_OF_N1_ID						336

// SSB Parameters
#define NUM_GSCN_S3GHz						2079
#define NUM_GSCN_A3GHz						2084

#define MAX_SSB_BEAM						64

#define NUM_PSS_SEQ							127
#define NUM_SSS_SEQ							127

#define NUM_RB_OF_SSB						20
#define NUM_SC_OF_SSB						240
#define NUM_SYMB_OF_SSB						4

#define NUM_SC_OF_PBCH_DMRS					144
#define NUM_SC_OF_1ST_SYMB_PBCH_DMRS		60
#define NUM_SC_OF_2ND_SYMB_PBCH_DMRS		24
#define NUM_SC_OF_3RD_SYMB_PBCH_DMRS		60

#define NUM_SC_OF_1ST_SYMB_PBCH				180
#define NUM_SC_OF_2ND_SYMB_PBCH				72
#define NUM_SC_OF_3RD_SYMB_PBCH				180

#define SSB_15kHz_SCS_BW					3600000
#define SSB_30kHz_SCS_BW					7200000

// PBCH Parameters
#define MIB_MSG_LEN							24
#define PBCH_PAYLOAD_LEN					8
#define BCH_CRC_LEN							24
#define PBCH_BIT_SIZE						MIB_MSG_LEN + PBCH_PAYLOAD_LEN + BCH_CRC_LEN
#define BCH_RM_OUT_LEN						864
#define NUM_SC_OF_PBCH						432
// 864 * 8
#define PBCH_SCRMB_LEN						6912
#define PBCH_MOD_LEN						BCH_RM_OUT_LEN / 2

// Scale Parameters
#define SCALE_FACTOR						10
#define INV_SCALE_FACTOR					1.0 / SCALE_FACTOR
#define SCALE_CONSTEL						10000
#define	INV_SCALE_CONSTEL					1.0 / SCALE_CONSTEL
#define MOD_SCALE							1000
#define QPSK_MOD_SCALE						7071 //2048/sqrt(2)
//#define QAM16_MOD_SCALE					500 // 2048/sqrt(4)
//#define QAM64_MOD_SCALE					316 // 2048/sqrt(42)
//#define QAM256_MOD_SCALE				157 // 2048/sqrt(170)

// Polar interleaving parameters
#define N_max								1024
#define K_IL_MAX							164
#define MAX_POLAR_IN_LEN					1730
#define SUBBLK_INTLV_LEN					32

// SLOT Related parameters
#define NUM_SUBFRAME						10
#define NUM_HALF_FRAME						2
#define NUM_SF_PER_HF						5
#define NUM_SYMB_PER_SLOT					14
#define MAX_NUM_SLOT_PER_SF					8
#define MAX_NUM_SLOT_PER_FRAME				NUM_SUBFRAME * MAX_NUM_SLOT_PER_SF
#define MAX_NUM_SYMB_PER_FRAME				MAX_NUM_SLOT_PER_FRAME * NUM_SYMB_PER_SLOT

// RB Related parameters
#define MAX_NUM_RB							273
#define MIN_NUM_RB							11
#define NUM_SC_OF_RB						12
#define MAX_USED_SC							MAX_NUM_RB * NUM_SC_OF_RB
#define MAX_PDSCH_MOD_LEN					MAX_USED_SC * MAX_NUM_SYMB_PER_FRAME

// Parameters related to TBS : We support only (1 CodeWord and Max 4 layers)
#define MAX_TBS								1213032 // Table 5.1.3.1-2 256QAM MCS 27 @ 400 MHz BW
#define MAX_NUM_CB							144		// Table 5.1.3.1-2 256QAM MCS 27 @ 400 MHz BW
#define MAX_CB_B_PRIME						1216488 // MAX_TBS + MAX_NUM_CB * 24
#define	MAX_CB_K_PRIME						8447	// K' = B' / C
#define MAX_CB_K							8448    // K = 22 x Zc = 22 * 384 = 8448

// Parameters related to PDCCH
#define NUM_REG_PER_CCE						6
#define MAX_REG_BUNDLE_SIZE					6
#define NUM_RE_PER_CCE						72
#define MAX_SET_DCI_NUM						3
#define MAX_NUM_CORESET						3		// max number of CORESET within 1 BWP
#define MAX_CORESET_BITMAP					45
#define MAX_NUM_CORESET_SYMB				3

// Parameters related to LDPC
#define NULL_BIT							-1
#define BG1_ROW_NUM							46
#define BG1_COL_NUM							68
#define BG2_ROW_NUM							42
#define BG2_COL_NUM							52
#define MAX_Zc								384
#define MAX_PARITY_W						17667	// 46 x 384(Max_Zc)
#define MAX_LDPC_OUT_LEN					25344	// 66 x 384(Max_Zc)

#define MAX_NUM_BWP							5
#define MAX_NUM_PDCCH						3
#define MAX_NUM_PDSCH						3
#define MAX_NUM_PDSCH_DMRS					4

#define CONSTELLATION_SCALE					10000

/*--------------------------------
// Type of Carrier
*/
	typedef enum
	{
		ds_NR_Carr_Downlink = 0,
		ds_NR_Carr_Uplink = 1,
		ds_NR_Carr_All = 2
	} ds_NR_Carrier_type;

	/*--------------------------------
	// Type of Frequency Range
	*/
	typedef enum
	{
		ds_NR_FR1 = 0,
		ds_NR_FR2 = 1
	} ds_NR_FR_type;

	/*--------------------------------
	// Type of Duplex
	*/
	typedef enum
	{
		ds_NR_FDD = 0,
		ds_NR_TDD = 1
	} ds_NR_Duplex_type;

	/*--------------------------------
	// Type of Numerology Mode
	*/
	typedef enum
	{
		ds_NR_Single_Numerology = 0,
		ds_NR_Multiple_Numerology = 1
	} ds_NR_Numerology_Mode_type;

	/*--------------------------------
	// Type of dl-ul_Transmission Period
	*/
	typedef enum
	{
		ds_NR_dl_ul_Period_0p5ms = 0,
		ds_NR_dl_ul_Period_0p625ms = 1,
		ds_NR_dl_ul_Period_1ms = 2,
		ds_NR_dl_ul_Perioid_1p25ms = 3,
		ds_NR_dl_ul_Perioid_2ms = 4,
		ds_NR_dl_ul_Perioid_2p5ms = 5,
		ds_NR_dl_ul_Period_5ms = 6,
		ds_NR_dl_ul_Period_10ms = 7,
		ds_NR_dl_ul_Period_Max = 8
	} ds_NR_dl_ul_TransPerioid_type;

	/*--------------------------------
	// Type of Slot Type
	*/
	typedef enum
	{
		ds_NR_Slot_D = 0,
		ds_NR_Slot_S = 1,
		ds_NR_Slot_U = 2
	} ds_NR_Slot_type;

	/*--------------------------------
	// Type of subcarrier spacing
	*/
	typedef enum
	{
		ds_NR_SCS_15kHz = 0,
		ds_NR_SCS_30kHz = 1,
		ds_NR_SCS_60kHz = 2,
		ds_NR_SCS_120kHz = 3,
		ds_NR_SCS_240kHz = 4,
		ds_NR_SCS_MAX = 5
	} ds_NR_DL_SCS_type;

	/*--------------------------------
	// Type of NR Band
	*/
	typedef enum
	{
		ds_NR_Band_n1 = 0,
		ds_NR_Band_n2 = 1,
		ds_NR_Band_n3 = 2,
		ds_NR_Band_n5 = 3,
		ds_NR_Band_n7 = 4,
		ds_NR_Band_n8 = 5,
		ds_NR_Band_n12 = 6,
		ds_NR_Band_n20 = 7,
		ds_NR_Band_n25 = 8,
		ds_NR_Band_n28 = 9,
		ds_NR_Band_n34 = 10,
		ds_NR_Band_n38 = 11,
		ds_NR_Band_n39 = 12,
		ds_NR_Band_n40 = 13,
		ds_NR_Band_n41 = 14,
		ds_NR_Band_n50 = 15,
		ds_NR_Band_n51 = 16,
		ds_NR_Band_n66 = 17,
		ds_NR_Band_n70 = 18,
		ds_NR_Band_n71 = 19,
		ds_NR_Band_n74 = 20,
		ds_NR_Band_n75 = 21,
		ds_NR_Band_n76 = 22,
		ds_NR_Band_n77 = 23,
		ds_NR_Band_n78 = 24,
		ds_NR_Band_n79 = 25,
		ds_NR_Band_Max = 26
	} ds_NR_Band_type;

	/*--------------------------------
	// Type of Channel Bandwidth
	*/
	typedef enum
	{
		ds_NR_CBW_FR1_5MHz = 0,
		ds_NR_CBW_FR1_10MHz = 1,
		ds_NR_CBW_FR1_15MHz = 2,
		ds_NR_CBW_FR1_20MHz = 3,
		ds_NR_CBW_FR1_25MHz = 4,
		ds_NR_CBW_FR1_30MHz = 5,
		ds_NR_CBW_FR1_40MHz = 6,
		ds_NR_CBW_FR1_50MHz = 7,
		ds_NR_CBW_FR1_60MHz = 8,
		ds_NR_CBW_FR1_70MHz = 9,
		ds_NR_CBW_FR1_80MHz = 10,
		ds_NR_CBW_FR1_90MHz = 11,
		ds_NR_CBW_FR1_100MHz = 12,
		ds_NR_CBW_FR2_50MHz = 13,
		ds_NR_CBW_FR2_100MHz = 14,
		ds_NR_CBW_FR2_200MHz = 15,
		ds_NR_CBW_FR2_400MHz = 16,
		ds_NR_CBW_MAX = 17
	} ds_NR_CBW_type;

	/*--------------------------------
	// Type of Synchronization Type
	*/
	typedef enum
	{
		ds_NR_Sync_SSB = 0,
		ds_NR_Sync_PDSCH_DMRS = 1
	} ds_NR_DL_Sync_type;

	/*--------------------------------
	// Type of downlink channel & signal
	*/
	typedef enum
	{
		ds_NR_DL_CH_None = 0,
		ds_NR_DL_CH_PSS = 1,
		ds_NR_DL_CH_SSS = 2,
		ds_NR_DL_CH_PBCH = 3,
		ds_NR_DL_CH_PBCH_DMRS = 4,
		ds_NR_DL_CH_PDCCH = 5,
		ds_NR_DL_CH_PDCCH_DMRS = 6,
		ds_NR_DL_CH_PDSCH = 7,
		ds_NR_DL_CH_PDSCH_DMRS = 8,
		ds_NR_DL_CH_PDSCH_DMRS_Null = 9,
		ds_NR_DL_CH_PDSCH_PTRS = 10,
		ds_NR_DL_CH_CSI_RS = 11,
		ds_NR_DL_CH_SSB = 12
	} ds_NR_DL_CH_type;

	/*--------------------------------
	// Type of SSB Pattern
	*/
	typedef enum
	{
		ds_NR_SSB_Patt_Case_A = 0,
		ds_NR_SSB_Patt_Case_B = 1,
		ds_NR_SSB_Patt_Case_C = 2,
		ds_NR_SSB_Patt_Case_D = 3,
		ds_NR_SSB_Patt_Case_E = 4,
		ds_NR_SSB_Patt_Case_MAX = 5
	} ds_NR_SSB_Patt_type;

	/*--------------------------------
	// Type of SSB Periodicity
	*/
	typedef enum
	{
		ds_NR_SSB_Period_5ms = 0,
		ds_NR_SSB_Period_10ms = 1,
		ds_NR_SSB_Period_20ms = 2,
		ds_NR_SSB_Period_40ms = 3,
		ds_NR_SSB_Period_80ms = 4,
		ds_NR_SSB_Period_160ms = 5,
		ds_NR_SSB_Period_NUM = 6
	} ds_NR_SSB_Period_type;

	/*--------------------------------
	// Type of SSB Position
	*/
	typedef enum
	{
		ds_NR_SSB_PosType_RB = 0,
		ds_NR_SSB_PosType_GSCN = 1
	} ds_NR_SSB_Pos_type;

	/*--------------------------------
	// Type of subcarrier spacing common
	*/
	typedef enum
	{
		ds_NR_scs_15or60 = 0,
		ds_NR_scs_30or120 = 1
	} ds_NR_scsCommon_type;

	/*--------------------------------
	// Type of CRC
	*/
	typedef enum
	{
		ds_NR_CRC_6 = 0,
		ds_NR_CRC_11 = 1,
		ds_NR_CRC_16 = 2,
		ds_NR_CRC_24A = 3,
		ds_NR_CRC_24B = 4,
		ds_NR_CRC_24C = 5
	} ds_NR_CRC_type;

	/*--------------------------------
	// Type of BWP Index
	*/
	typedef enum
	{
		ds_NR_DL_BWP_Initial = 0,
		ds_NR_DL_BWP_1 = 1,
		ds_NR_DL_BWP_2 = 2,
		ds_NR_DL_BWP_3 = 3,
		ds_NR_DL_BWP_4 = 4
	} ds_NR_DL_BWP_type;

	/*--------------------------------
	// Type of CCE Aggregation Level
	*/
	typedef enum
	{
		ds_NR_CCE_AggregationLevel_1 = 1,
		ds_NR_CCE_AggregationLevel_2 = 2,
		ds_NR_CCE_AggregationLevel_4 = 4,
		ds_NR_CCE_AggregationLevel_8 = 8,
		ds_NR_CCE_AggregationLevel_16 = 16
	} ds_NR_CCE_AggrgLvl_type;

	/*--------------------------------
	// Type of Minimum CBW
	*/
	typedef enum
	{
		ds_NR_MinCBW_5MHz_or_10MHz = 0,
		ds_NR_MinCBW_40MHz = 1
	} ds_NR_Min_CBW_type;


	/*--------------------------------
	// Type of Search Space Type
	*/
	typedef enum
	{
		ds_NR_SearchSpace_CSS = 0,
		ds_NR_SearchSpace_USS = 1
	} ds_NR_SearchSpace_type;

	/*--------------------------------
	// Type of CCE to REG mapping type
	*/
	typedef enum
	{
		ds_NR_CCE_to_REG_NonInterleave = 0,
		ds_NR_CCE_to_REG_Interleave = 1
	} ds_NR_CCE_to_REG_mapping_type;


	/*--------------------------------
	// Type of REG Bundle Size
	*/
	typedef enum
	{
		ds_NR_REG_Bundle_size_2 = 2,
		ds_NR_REG_Bundle_size_3 = 3,
		ds_NR_REG_Bundle_size_6 = 6
	} ds_NR_REG_bundle_size_type;

	/*--------------------------------
	// Type of InterLeaver Size
	*/
	typedef enum
	{
		ds_NR_CORESET_Interleave_size_2 = 2,
		ds_NR_CORESET_Interleave_size_3 = 3,
		ds_NR_CORESET_Interleave_size_6 = 6
	} ds_NR_Coreset_Interleaver_size_type;

	/*--------------------------------
	// Type of Precoder Granularity
	*/
	typedef enum
	{
		ds_NR_PrecoderGran_REG_BundleSize = 0,
		ds_NR_PrecoderGran_ContiguousRB = 1
	} ds_NR_PDCCH_Precoder_Granularity_type;

	/*--------------------------------
	// Type of Modulation
	*/
	typedef enum
	{
		ds_NR_Mod_PI_2_BPSK = 0,
		ds_NR_Mod_BPSK = 1,
		ds_NR_Mod_QPSK = 2,
		ds_NR_Mod_16QAM = 4,
		ds_NR_Mod_64QAM = 6,
		ds_NR_Mod_256QAM = 8
	} ds_NR_Modulation_type;

	/*--------------------------------
	// Type of SS/PBCH block and CORESET multiplexing pattern
	*/
	typedef enum
	{
		ds_NR_CORESET_Mux_Patt_1 = 0,
		ds_NR_CORESET_Mux_Patt_2 = 1,
		ds_NR_CORESET_Mux_Patt_3 = 2
	} ds_NR_CORESET_Mux_Patt_type;

	/*--------------------------------
	// Type of MCS Table for PDSCH
	*/
	typedef enum
	{
		ds_NR_PDSCH_MCS_Table_64QAM = 0,
		ds_NR_PDSCH_MCS_Table_256QAM = 1,
		ds_NR_PDSCH_MCS_Table_64QAM_Low = 2
	} ds_NR_PDSCH_MCS_Table_type;

	/*--------------------------------
	// Type of LDPC Base Graph
	*/
	typedef enum
	{
		ds_NR_LDPC_BaseGraph_1 = 0,
		ds_NR_LDPC_BaseGraph_2 = 1
	} ds_NR_LDPC_BaseGraph_type;

	/*--------------------------------
	// Type of Resource Allocation Type for PDSCH
	*/
	typedef enum
	{
		ds_NR_PDSCH_RA_Type_0 = 0,
		ds_NR_PDSCH_RA_Type_1 = 1
	} ds_NR_PDSCH_RA_type;

	/*--------------------------------
	// Type of VRB-to-PRB Mapping Type for PDSCH
	*/
	typedef enum
	{
		ds_NR_PDSCH_VRB_to_PRB_NonInterleave = 0,
		ds_NR_PDSCH_VRB_tp_PRB_Interleave = 1
	} ds_NR_PDSCH_VRB_to_PRB_Map_type;

	/*--------------------------------
	// Type of VRB-to-PRB Interleaver Size for PDSCH
	*/
	typedef enum
	{
		ds_NR_PDSCH_VRB_to_PRB_Interleave_2 = 2,
		ds_NR_PDSCH_VRB_to_PRB_Interleave_4 = 4
	} ds_NR_PDSCH_VRB_to_PRB_Interleave_type;

	/*--------------------------------
	// Type of PRB Bundle Size for PDSCH
	*/
	typedef enum
	{
		ds_NR_PDSCH_PRB_BundleSize_2 = 2,
		ds_NR_PDSCH_PRB_BundleSize_4 = 4,
		ds_NR_PDSCH_PRB_BundleSize_WideBand = 5
	} ds_NR_PDSCH_PRB_Bundle_Size_type;

	/*--------------------------------
	// Type of DMRS_TypeA_Position
	*/
	typedef enum
	{
		ds_NR_dmrs_TypeA_Pos2 = 2,
		ds_NR_dmrs_TypeA_Pos3 = 3
	} ds_NR_dmrs_TypeA_Pos_type;

	/*--------------------------------
	// Type of DMRS Configuration
	*/
	typedef enum
	{
		ds_NR_PDSCH_DMRS_Config_Type1 = 0,
		ds_NR_PDSCH_DMRS_Config_Type2 = 1
	} ds_NR_PDSCH_DMRS_Config_type;

	/*--------------------------------
	// Type of DMRS Duration
	*/
	typedef enum
	{
		ds_NR_PDSCH_DMRS_Duration_Single = 1,
		ds_NR_PDSCH_DMRS_Duration_Double = 2
	} ds_NR_PDSCH_DMRS_Duration_type;

	/*--------------------------------
	// Type of PDSCH Mapping type
	*/
	typedef enum
	{
		ds_NR_PDSCH_Mapping_Type_A = 0,
		ds_NR_PDSCH_Mapping_Type_B = 1
	} ds_NR_PDSCH_Mapping_type;

	/*--------------------------------
	// Type of DMRS Mapping Reference
	*/
	typedef enum
	{
		ds_NR_PDSCH_DMRS_Map_ref_CRB0 = 0,
		ds_NR_PDSCH_DMRS_Map_ref_CORSET0 = 1
	} ds_NR_PDSCH_DMRS_Map_ref_type;

	/*--------------------------------
	// Type of DMRS Mapping Reference
	*/
	typedef enum
	{
		ds_NR_PDSCH_Ant_port_1000 = 0,
		ds_NR_PDSCH_Ant_port_1001 = 1,
		ds_NR_PDSCH_Ant_port_1002 = 2,
		ds_NR_PDSCH_Ant_port_1003 = 3,
		ds_NR_PDSCH_Ant_port_1004 = 4,
		ds_NR_PDSCH_Ant_port_1005 = 5,
		ds_NR_PDSCH_Ant_port_1006 = 6,
		ds_NR_PDSCH_Ant_port_1007 = 7,
		ds_NR_PDSCH_Ant_port_1008 = 8,
		ds_NR_PDSCH_Ant_port_1009 = 9,
		ds_NR_PDSCH_Ant_port_1010 = 10,
		ds_NR_PDSCH_Ant_port_1011 = 11
	} ds_NR_PDSCH_Ant_port_type;

	/*--------------------------------
	// Type of PTRS RE OFFSET
	*/
	typedef enum
	{
		ds_NR_PDSCH_PTRS_RE_OFFSET_00 = 0,
		ds_NR_PDSCH_PTRS_RE_OFFSET_01 = 1,
		ds_NR_PDSCH_PTRS_RE_OFFSET_10 = 2,
		ds_NR_PDSCH_PTRS_RE_OFFSET_11 = 3
	} ds_NR_PDSCH_PTRS_RE_Offset_type;

	/*--------------------------------
	// Definition of TAE Measurement Type
	*/
	typedef enum
	{
		ds_TAE_Intra = 0,
		ds_TAE_Inter = 1
	} ds_NR_TAE_Meas_type;

	/*--------------------------------
	// Definition of cell specific parameters
	*/
	typedef struct
	{
		ds16s Carrier_Type;
		ds16s Cell_ID;
		ds16s CBW;
		ds16s Numerology;
		ds16s Max_RB;
		ds16s SFN_start;
		ds16s Num_Frame;
		ds64s fc;
	} ds_NR_cell_specific_param;

	/*--------------------------------
	// Definition of SSB parameters
	*/
	typedef struct
	{
		//ds16s SSB_scs;
		ds16s SSB_pattern;
		ds16s SSB_Period;
		//ds16s L_max;
		//ds16s Active_index;
		ds16s N_CRB_SSB;
		ds16s k_SSB;
	} ds_NR_SSB_param;

	/*--------------------------------
	// Definition of Frame Structure
	*/
	typedef struct
	{
		ds32s dl_ul_TransPeriod;
		ds32s DL_slots;
		ds32s DL_symbs;
		ds32s UL_slots;
		ds32s UL_symbs;
	} ds_NR_TDD_FrameStrut_param;

	/*--------------------------------
	// Definition of SSB Information
	*/
	typedef struct
	{
		ds32s state;
		ds32s SCS;
		ds32s SSB_Pos_type;
		ds32s SSB_Config;
		ds32s RB_Offset;
		ds32s k_SSB;
		ds32s GSCN;
	} ds_NR_SSB_Info_param;

	/*--------------------------------
	// Definition of CORESET
	*/
	typedef struct
	{
		ds32s state;
		ds32s RB_Offset; // -1 is not configured
		ds64s RB_Number;
		ds32s Symb_Number;
		ds32s CCE_to_REG_Map;
		ds32s REG_BundleSize;
		ds32s InterleaveSize;
		ds32s Shift_Index;
		ds32s Precoder_Granul;
	} ds_NR_CORESET_Info_param;

	/*--------------------------------
	// Definition of BWP
	*/
	typedef struct
	{
		ds32s state;
		ds32s SCS;
		ds32s N_RB_Start;
		ds32s N_RB_Size;
		ds32s Num_Coreset;
		ds_NR_CORESET_Info_param Coreset_Info[MAX_NUM_CORESET];
	} ds_NR_BWP_Info_param;

	/*--------------------------------
	// Definition of Parameters for DCI
	*/
	typedef struct
	{
		ds32s state;
		ds32s PDCCH_DMRS_Scrmb_ID; // -1 is not configured
		ds32s RNTI;
		ds32s C_RNTI;
		ds32s BWP;
		ds32s CORESET_ID;
		//ds32s Num_alloc_slot;
		ds32s Alloc_slot[MAX_NUM_SLOT_PER_FRAME];
		ds32s First_symb;
		ds32s Search_space;
		ds32s Aggreg_level;
		ds32s Num_of_PDCCH_Candidate;
		ds32s Candidate_index;
		ds32s DCI_Size;
		ds64f Pwr_boost;
		ds64f DMRS_Pwr_boost;
	} ds_NR_DCI_set_param;

	/*--------------------------------
	// Definition of General Parameters for PDSCH
	*/
	typedef struct
	{
		ds32s RNTI;
		ds32s n_ID; // -1 is Cell ID
		ds32s Num_of_Layer;		// only 1
		ds32s Num_of_Codeword;	// only 1
		ds64f Pwr_boost;
	} ds_NR_PDSCH_General_set_param;

	/*--------------------------------
	// Definition of Transmission Setting for PDSCH
	*/
	typedef struct
	{
		ds32s DMRS_port; // (range : 0 ~ 11) from DCI
		//ds32s Ant_port_generated; //p0 ~ p7(1000 + DMRS_oort), physical antenna
		ds32s Num_of_DMRS_CDM_grp_without_data;
	} ds_NR_PDSCH_Transmission_set_param;

	/*--------------------------------
	// Definition of MCS Parameters for PDSCH
	*/
	typedef struct
	{
		ds32s Channel_coding;
		ds32s Mod_type;
		ds32s MCS_table;
		ds32s MCS;
		ds32s xOverhead; // 0, 6, 12, 18
		ds64f TB_scaling_factor; // 1, 0.5, 0.25
	} ds_NR_PDSCH_MCS_set_param;

	/*--------------------------------
	// Definition of MCS Output Parameters for PDSCH
	*/
	typedef struct
	{
		ds64f Code_Rate;
		ds32s Mod_Type;
		ds32s TBS;
		ds32s Base_Graph;
		ds32s CRC_type;
		ds32s CRC_len;
	} ds_NR_MCS_out_param;

	/*--------------------------------
	// Definition of Resource Allocation Parameters for PDSCH
	*/
	typedef struct
	{
		ds32s alloc_slot[MAX_NUM_SLOT_PER_FRAME]; // temp
		//ds32s num_alloc_slot;
		ds32s first_symb;
		ds32s last_symb;
		ds32s BWP;
		ds32s RA_type;
		ds32s RB_offset; // RBG Size for Type 0, RB offset for Type 1
		ds32s RB_Num; // RBG Bit map for Type 0, RB Num for Type 1
		ds32s VRB_to_PRB_Mapping;
		ds32s VRB_to_PRB_Interleave;
		ds32s PRB_BundleSize;
		//ds32s CORESET_ID_RateMatch;
		//ds32s RateMatch_Patt;
	} ds_NR_PDSCH_RA_set_param;

	/*--------------------------------
	// Definition of HARQ Settings for PDSCH
	*/
	typedef struct
	{
		ds32s New_Data_Indicator;
		ds32s HARQ_Process_Num;
		ds32s RV_Index;
		ds32s CBG_Transmission;
		ds32s CRC_Err_Flag;
	} ds_NR_PDSCH_HARQ_set_param;

	/*--------------------------------
	// Definition of calculated LDPC Parameters
	*/
	typedef struct
	{
		ds32s C;		// Number of Coded Block
		ds32s L;		// CRC Length
		ds32s K_prime;
		ds32s K;
		ds32s i_LS;
		ds32s Z_c;
		ds32s N;
		ds32s G;		// total number of coded bit available for transmission of the TB
	} ds_NR_LDPC_Related_param;

	/*--------------------------------
	// Definition of DMRS Parameters for PDSCH
	*/
	typedef struct
	{
		ds32s dmrs_Downlink_r16;
		ds32s n_SCID;	// range : 0 ~ 1
		ds32s N_ID_0;	// range : -1 ~ 65535
		ds32s N_ID_1;	// range : -1 ~ 65535
		ds32s DMRS_Config;
		ds32s DMRS_Duration;
		ds32s DMRS_add_pos;
		ds32s PDSCH_Mapping;
		ds32s DMRS_typeA_pos;
		ds32s DMRS_Mapping_Ref;
	} ds_NR_PDSCH_DMRS_set_param;

	/*--------------------------------
	// Definition of DMRS Position for PDSCH
	*/
	typedef struct
	{
		ds32s DMRS_num[4]; // Number of DMRS per add-pos
		ds32s DMRS_AddPos_SymIdx[4][3]; // Symbol Index of Addition DMRS per add-pos
	} ds_NR_PDSCH_DMRS_Pos_Info;

	/*--------------------------------
	// Definition of PTRS Parameters for PDSCH
	*/
	typedef struct
	{
		ds32s state;
		ds32s K_PTRS;	// range : 2|4
		ds32s L_PTRS;	// range : 1|2|4
		ds32s RE_OFFSET;	// range : 00|01|10|11
		ds64f Pwr_boost;
	} ds_NR_PDSCH_PTRS_set_param;

	/*--------------------------------
	// Definition of Set parameters for PDSCH
	*/
	typedef struct
	{
		ds32s state;
		ds_NR_PDSCH_General_set_param general_param;
		ds_NR_PDSCH_Transmission_set_param transm_param;
		ds_NR_PDSCH_RA_set_param ra_param;
		ds_NR_PDSCH_MCS_set_param mcs_param;
		ds_NR_PDSCH_HARQ_set_param harq_param;
		ds_NR_PDSCH_DMRS_set_param dmrs_param;
		ds_NR_PDSCH_PTRS_set_param ptrs_param;
	} ds_NR_PDSCH_All_set_param;

	/*--------------------------------
	// Definition of Limit
	*/
	typedef struct
	{
		ds64f target_pwr;
		ds64f pwr_thrshld;
		ds64f freq_offset;
		ds64f evm;
		ds64f timing_offset; // unit : ns
	} ds_NR_Limit_Thrshld_param;

	/*--------------------------------
	// Definition of Set Parameters from GUI
	*/
	typedef struct
	{
		ds32s View_symb_idx;
		ds32s Duplex_type;
		ds32s FR_type;
		ds32s Cell_ID_Auto;
		ds32s Cell_ID;
		ds32s Profile_type;
		ds32s Numerology;
		ds32s SCS;
		ds32s Sync_type;
		ds32s Meas_Start_slot;
		ds32s Meas_Stop_slot;
		ds32s Symb_PhaseCorrect;
		ds64u fc;
		ds_NR_TDD_FrameStrut_param FrameInfo;
		ds_NR_BWP_Info_param BwpInfo[MAX_NUM_BWP];
		ds_NR_SSB_Info_param SSBInfo;
		ds_NR_DCI_set_param PDCCHInfo[MAX_NUM_PDCCH];
		ds_NR_PDSCH_All_set_param PDSCHInfo[MAX_NUM_PDSCH];
		ds_NR_Limit_Thrshld_param LimitInfo;
		//ds_NR_TAE_Info_param TAEInfo;
	} ds_NR_SetAPI;

	/*--------------------------------
	// Definition of Cell Information
	*/
	typedef struct
	{
		ds32s Cell_ID;
		ds32s Sector_ID;
		ds32s Group_ID;
		ds32s SCS;
		ds32s SSB_Freq;
		ds32s SS_Corr;
	} ds_NR_Cell_Info_Rst;

	/*--------------------------------
	// Definition of Power Information
	*/
	typedef struct
	{
		ds32s Chpwr;				// x 100
		ds32s SS_RSRP;				// x 100
		ds32s SS_RSRQ;				// x 100
		ds32s SS_SINR;				// x 100
		ds32s beam_pwr; // TBD
		ds32s beam_idx; // TBD
		ds32s Exp_TxPwr; // TBD
	} ds_NR_PwrInfo_Rst;

	/*--------------------------------
	// Definition of Signal Quality Information
	*/
	typedef struct
	{
		ds32s PSS_EVM;				// x 100
		ds32s SSS_EVM;				// x 100
		ds32s PBCH_EVM;				// x 100
		ds32s PBCH_DMRS_EVM;		// x 100

		ds32s PDCCH_EVM;			// x 100
		ds32s PDCCH_DMRS_EVM;		// x 100

		ds32s PDSCH_EVM;			// x 100
		ds32s PDSCH_DMRS_EVM;		// x 100
		ds32s PDSCH_PTRS_EVM;		// x 100

		ds32s PSS_Pwr;				// x 100
		ds32s SSS_Pwr;				// x 100
		ds32s PBCH_Pwr;				// x 100
		ds32s PBCH_DMRS_Pwr;		// x 100

		ds32s PDCCH_Pwr;			// x 100
		ds32s PDCCH_DMRS_Pwr;		// x 100

		ds32s PDSCH_Pwr;			// x 100
		ds32s PDSCH_DMRS_Pwr;		// x 100
		ds32s PDSCH_PTRS_Pwr;		// x 100

		ds32s PSS_NumRB;
		ds32s SSS_NumRB;
		ds32s PBCH_NumRB;
		ds32s PBCH_DMRS_NumRB;

		ds32s PDCCH_NumRB;
		ds32s PDCCH_DMRS_NumRB;

		ds32s PDSCH_NumRB;
		ds32s PDSCH_DMRS_NumRB;
		ds32s PDSCH_PTRS_NumRB;
	} ds_NR_SigQuality_Rst;

	/*--------------------------------
	// Definition of MIB messages
	*/
	typedef struct
	{
		ds8s choise;			// 1bit
		ds8s SFN;				// 6bit
		ds8s scs_common;		// 1bit
		ds8s ssb_scs_offset;	// 4bit
		ds8s dmrs_TypeA_Pos;	// 1bit
		ds8u pdcch_ConfigSIB1;	// 8bit
		ds8s cellBarred;		// 1bit
		ds8s intraFreqReselet;	// 1bit
		ds8s reserved;			// 1bit
	} ds_NR_MIB_msg;

	/*--------------------------------
	// Definition of PBCH Payload
	*/
	typedef struct
	{
		ds8s SFN;				// 4bit
		ds8s half_frame;		// 1bit
		ds8s remain_3bit;		// 3bit
	} ds_NR_PBCH_Payload_content;

	/*--------------------------------
	// Definition of Error Summary
	*/
	typedef struct
	{
		ds32s ChPwr;			// x 100
		ds32s ChPwr_Rst;
		ds32s EVM;				// x 100
		ds32s EVM_Rst;
		ds32s EVM_Peak;			// x 100
		ds32s Peak_Symb_idx;
		ds32s Peak_SC;
		ds32s FreqErr;			// x 100
		ds32s FreqErr_Rst;
		ds32s TimingOffset;		// x 100. unit : ns
		ds32s TimingOffset_Rst;
	} ds_NR_Err_Summary_Rst;

	//#pragma pack(pop)
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif // #ifndef __DS_5G_DEFS_H__
