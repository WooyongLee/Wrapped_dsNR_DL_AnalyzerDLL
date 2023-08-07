#include <stdio.h>
#include "pch.h"
#include "dsALG_Defs.h"
#include "dsNR_Defs.h"
#include "dsNR_DL_AnalyzerDll.h"
#include "wrapped.h"

#include <cstdio>
#include <string>
#include <iostream>
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
//#pragma comment(lib, "dsNR_Dl_AnalyzerDll.lib")

ds32s w_ds5G_nr_Close_lib()
{
	return ds5G_nr_Close_lib();
}


ds32s w_ds5G_nr_dl_analyze(ds16s* input_re, ds16s* input_im, ds32s capture_len)
{
	return ds5G_nr_dl_analyze(input_re, input_im, capture_len);
}

ds32s w_ds5G_nr_get_IQConstel_Data(ds32s* const_re, ds32s* const_im, ds32s ch_type)
{
	return ds5G_nr_get_IQConstel_Data(const_re, const_im, ch_type);
}

ds32s w_ds5G_nr_get_IQConstel_Length(ds32s* len, ds32s ch_type)
{
	return ds5G_nr_get_IQConstel_Length(len, ch_type);
}

ds32s w_ds5G_nr_get_EVS_Data(ds32s* evs)
{
	return ds5G_nr_get_EVS_Data(evs);
}

ds32s w_ds5G_nr_get_EVS_Length(ds32s* len)
{
	return ds5G_nr_get_EVS_Length(len);
}

ds32s w_ds5G_nr_init_param() {
	return ds5G_nr_init_param();
}

ds32s w_ds5G_nr_get_CellInfoRst(
	ds32s* Cell_ID,
	ds32s* Sector_ID,
	ds32s* Group_ID,
	ds32s* SCS,
	ds32s* SSB_Freq,
	ds32s* SS_Corr)
{
	ds_NR_Cell_Info_Rst cell_info;
	int r = ds5G_nr_get_CellInfoRst(&cell_info);
	*Cell_ID = cell_info.Cell_ID;
	*Sector_ID = cell_info.Sector_ID;
	*Group_ID = cell_info.Group_ID;
	*SCS = cell_info.SCS;
	*SSB_Freq = cell_info.SSB_Freq;
	*SS_Corr = cell_info.SS_Corr;

	return r;
}

ds32s w_ds5G_nr_get_PwrInfoRst(ds32s* Chpwr,
	ds32s* SS_RSRP,
	ds32s* SS_RSRQ,
	ds32s* SS_SINR,
	ds32s* beam_pwr,
	ds32s* beam_idx,
	ds32s* Exp_TxPwr
) {
	ds_NR_PwrInfo_Rst pwrinfor;
	int r = ds5G_nr_get_PwrInfoRst(&pwrinfor);

	*Chpwr = pwrinfor.Chpwr;
	*SS_RSRP = pwrinfor.SS_RSRP;
	*SS_RSRQ = pwrinfor.SS_RSRQ;
	*SS_SINR = pwrinfor.SS_SINR;
	*beam_pwr = pwrinfor.beam_pwr;
	*beam_idx = pwrinfor.beam_idx;
	*Exp_TxPwr = pwrinfor.Exp_TxPwr;

	return r;
}

ds32s w_ds5G_nr_get_Symb_PwrSpec_param(ds32s* rbw,
	ds32s* span,
	ds32s* num_data
) {
	return ds5G_nr_get_Symb_PwrSpec_param(rbw, span, num_data);
}

ds32s w_ds5G_nr_get_Symb_PwrSpectrum(ds32s* pwr_spectrum) {
	return ds5G_nr_get_Symb_PwrSpectrum(pwr_spectrum);
}

ds32s w_ds5G_nr_get_SigQualityRst(
	ds32s* PSS_EVM,
	ds32s* SSS_EVM,
	ds32s* PBCH_EVM,
	ds32s* PBCH_DMRS_EVM,

	ds32s* PDCCH_EVM,
	ds32s* PDCCH_DMRS_EVM,

	ds32s* PDSCH_EVM,
	ds32s* PDSCH_DMRS_EVM,
	ds32s* PDSCH_PTRS_EVM,

	ds32s* PSS_Pwr,
	ds32s* SSS_Pwr,
	ds32s* PBCH_Pwr,
	ds32s* PBCH_DMRS_Pwr,

	ds32s* PDCCH_Pwr,
	ds32s* PDCCH_DMRS_Pwr,

	ds32s* PDSCH_Pwr,
	ds32s* PDSCH_DMRS_Pwr,
	ds32s* PDSCH_PTRS_Pwr,

	ds32s* PSS_NumRB,
	ds32s* SSS_NumRB,
	ds32s* PBCH_NumRB,
	ds32s* PBCH_DMRS_NumRB,

	ds32s* PDCCH_NumRB,
	ds32s* PDCCH_DMRS_NumRB,

	ds32s* PDSCH_NumRB,
	ds32s* PDSCH_DMRS_NumRB,
	ds32s* PDSCH_PTRS_NumRB)
{
	ds_NR_SigQuality_Rst sigqualinfo;
	int r = ds5G_nr_get_SigQualityRst(&sigqualinfo);
	if (r == 0)
	{
		*PSS_EVM = sigqualinfo.PSS_EVM;
		*SSS_EVM = sigqualinfo.SSS_EVM;
		*PBCH_EVM = sigqualinfo.PBCH_EVM;
		*PBCH_DMRS_EVM = sigqualinfo.PBCH_DMRS_EVM;
		*PDCCH_EVM = sigqualinfo.PDCCH_EVM;
		*PDCCH_DMRS_EVM = sigqualinfo.PDCCH_DMRS_EVM;
		*PDSCH_EVM = sigqualinfo.PDSCH_EVM;
		*PDSCH_DMRS_EVM = sigqualinfo.PDSCH_DMRS_EVM;
		*PDSCH_PTRS_EVM = sigqualinfo.PDSCH_PTRS_EVM;

		*PSS_Pwr = sigqualinfo.PSS_Pwr;
		*SSS_Pwr = sigqualinfo.SSS_Pwr;
		*PBCH_Pwr = sigqualinfo.PBCH_Pwr;
		*PBCH_DMRS_Pwr = sigqualinfo.PBCH_DMRS_Pwr;
		*PDCCH_Pwr = sigqualinfo.PDCCH_Pwr;
		*PDCCH_DMRS_Pwr = sigqualinfo.PDCCH_DMRS_Pwr;
		*PDSCH_Pwr = sigqualinfo.PDSCH_Pwr;
		*PDSCH_DMRS_Pwr = sigqualinfo.PDSCH_DMRS_Pwr;
		*PDSCH_PTRS_Pwr = sigqualinfo.PDSCH_PTRS_Pwr;

		*PSS_NumRB = sigqualinfo.PSS_NumRB;
		*SSS_NumRB = sigqualinfo.SSS_NumRB;
		*PBCH_NumRB = sigqualinfo.PBCH_NumRB;
		*PBCH_DMRS_NumRB = sigqualinfo.PBCH_DMRS_NumRB;
		*PDCCH_NumRB = sigqualinfo.PDCCH_NumRB;
		*PDCCH_DMRS_NumRB = sigqualinfo.PDCCH_DMRS_NumRB;

		*PDSCH_NumRB = sigqualinfo.PDSCH_NumRB;
		*PDSCH_DMRS_NumRB = sigqualinfo.PDSCH_DMRS_NumRB;
		*PDSCH_PTRS_NumRB = sigqualinfo.PDSCH_PTRS_NumRB;
	}
	return r;
}

ds32s w_ds5G_nr_get_ErrSummary_Rst(ds32s* ChPwr,
	ds32s* ChPwr_Rst,
	ds32s* EVM,
	ds32s* EVM_Rst,
	ds32s* EVM_Peak,
	ds32s* Peak_Symb_idx,
	ds32s* Peak_SC,
	ds32s* FreqErr,
	ds32s* FreqErr_Rst,
	ds32s* TimingOffset,
	ds32s* TimingOffset_Rst
) {
	ds_NR_Err_Summary_Rst errsummary_info;
	int r = ds5G_nr_get_ErrSummary_Rst(&errsummary_info);

	*ChPwr = errsummary_info.ChPwr;
	*ChPwr_Rst = errsummary_info.ChPwr_Rst;
	*EVM = errsummary_info.EVM;
	*EVM_Rst = errsummary_info.EVM_Rst;
	*EVM_Peak = errsummary_info.EVM_Peak;
	*Peak_Symb_idx = errsummary_info.Peak_Symb_idx;
	*Peak_SC = errsummary_info.Peak_SC;
	*FreqErr = errsummary_info.FreqErr;
	*FreqErr_Rst = errsummary_info.FreqErr_Rst;
	*TimingOffset = errsummary_info.TimingOffset;
	*TimingOffset_Rst = errsummary_info.TimingOffset_Rst;

	return r;
}

ds_NR_SetAPI input_data() {
	ds_NR_SetAPI NR_SetAPI;

#if 0
	NR_SetAPI.View_symb_idx = 0;
	NR_SetAPI.fc = 3600000000;
	NR_SetAPI.Duplex_type = ds_NR_TDD;
	NR_SetAPI.FR_type = ds_NR_FR1;
	NR_SetAPI.Profile_type = ds_NR_CBW_FR1_100MHz;
	NR_SetAPI.Cell_ID_Auto = ds_Manual;
	NR_SetAPI.Cell_ID = 1;
	NR_SetAPI.Numerology = ds_NR_Single_Numerology;
	NR_SetAPI.SCS = ds_NR_SCS_30kHz;
	NR_SetAPI.Sync_type = ds_NR_Sync_PDSCH_DMRS;
	NR_SetAPI.Meas_Start_slot = 0;
	NR_SetAPI.Meas_Stop_slot = 19;
	NR_SetAPI.Symb_PhaseCorrect = 1;
	// TDD Frame Structure
	NR_SetAPI.FrameInfo.dl_ul_TransPeriod = ds_NR_dl_ul_Period_5ms;
	NR_SetAPI.FrameInfo.DL_slots = 7;
	NR_SetAPI.FrameInfo.DL_symbs = 6;
	NR_SetAPI.FrameInfo.UL_slots = 2;
	NR_SetAPI.FrameInfo.UL_symbs = 4;
	// BWP Information
	// Initial BWP
	NR_SetAPI.BwpInfo[0].state = ds_OFF;
	// BWP 1
	NR_SetAPI.BwpInfo[1].state = ds_ON;
	NR_SetAPI.BwpInfo[1].SCS = NR_SetAPI.SCS; // Single Numerology
	NR_SetAPI.BwpInfo[1].N_RB_Start = 0;
	NR_SetAPI.BwpInfo[1].N_RB_Size = 273;
	NR_SetAPI.BwpInfo[1].Num_Coreset = 1;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].state = ds_ON;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].RB_Offset = -1; // Not Configured
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].RB_Number = 0x100000000000;// 0x111111110000;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].Symb_Number = 2;// 1;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].CCE_to_REG_Map = ds_NR_CCE_to_REG_NonInterleave;// ds_NR_CCE_to_REG_Interleave;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].REG_BundleSize = 6;// 2; // Only Interleaved mode
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].InterleaveSize = 2; // Only Interleaved mode
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].Shift_Index = 0; //160; // Only Interleaved mode
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].Precoder_Granul = ds_NR_PrecoderGran_REG_BundleSize;
	NR_SetAPI.BwpInfo[1].Coreset_Info[1].state = ds_OFF;
	NR_SetAPI.BwpInfo[1].Coreset_Info[2].state = ds_OFF;
	// BWP 2
	NR_SetAPI.BwpInfo[2].state = ds_OFF;
	// BWP 3
	NR_SetAPI.BwpInfo[3].state = ds_OFF;
	// BWP 4
	NR_SetAPI.BwpInfo[4].state = ds_OFF;
	// SSB Info
	NR_SetAPI.SSBInfo.state = ds_OFF;
	NR_SetAPI.SSBInfo.SCS = ds_NR_SCS_30kHz;
	NR_SetAPI.SSBInfo.SSB_Pos_type = ds_NR_SSB_PosType_RB;
	NR_SetAPI.SSBInfo.SSB_Config = ds_Auto;
	NR_SetAPI.SSBInfo.RB_Offset = 253;
	NR_SetAPI.SSBInfo.k_SSB = 0;
	NR_SetAPI.SSBInfo.GSCN = 22256;
	// PDCCH Info
	NR_SetAPI.PDCCHInfo[0].state = ds_ON;
	NR_SetAPI.PDCCHInfo[0].RNTI = 0;
	NR_SetAPI.PDCCHInfo[0].C_RNTI = 0;
	NR_SetAPI.PDCCHInfo[0].BWP = 1;
	NR_SetAPI.PDCCHInfo[0].CORESET_ID = 1;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[0] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[1] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[2] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[3] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[4] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[5] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[6] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[7] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[8] = ds_OFF;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[9] = ds_OFF; NR_SetAPI.PDCCHInfo[0].Alloc_slot[10] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[11] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[12] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[13] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[14] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[15] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[16] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[17] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[18] = ds_OFF; NR_SetAPI.PDCCHInfo[0].Alloc_slot[19] = ds_OFF;
	NR_SetAPI.PDCCHInfo[0].First_symb = 0;
	NR_SetAPI.PDCCHInfo[0].Search_space = ds_NR_SearchSpace_USS;
	NR_SetAPI.PDCCHInfo[0].Aggreg_level = ds_NR_CCE_AggregationLevel_1;// ds_NR_CCE_AggregationLevel_2;
	NR_SetAPI.PDCCHInfo[0].Num_of_PDCCH_Candidate = 4;
	NR_SetAPI.PDCCHInfo[0].Candidate_index = 0;// 2;
	NR_SetAPI.PDCCHInfo[0].DCI_Size = 20;
	NR_SetAPI.PDCCHInfo[0].PDCCH_DMRS_Scrmb_ID = -1; // -1 : Not Configured
	NR_SetAPI.PDCCHInfo[0].Pwr_boost = 0;
	NR_SetAPI.PDCCHInfo[0].DMRS_Pwr_boost = 0;
	NR_SetAPI.PDCCHInfo[1].state = ds_OFF;
	NR_SetAPI.PDCCHInfo[2].state = ds_OFF;
	// PDSCH Info
	NR_SetAPI.PDSCHInfo[0].state = ds_ON;
	NR_SetAPI.PDSCHInfo[0].general_param.RNTI = 0;
	NR_SetAPI.PDSCHInfo[0].general_param.n_ID = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[0].general_param.Pwr_boost = 0;
	NR_SetAPI.PDSCHInfo[0].ra_param.BWP = 1;
	//NR_SetAPI.PDSCHInfo[0].ra_param.num_alloc_slot = 16;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[0] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[1] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[2] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[3] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[4] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[5] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[6] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[7] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[8] = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[9] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[10] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[11] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[12] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[13] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[14] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[15] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[16] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[17] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[18] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[19] = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].ra_param.first_symb = 0; NR_SetAPI.PDSCHInfo[0].ra_param.last_symb = 13;
	NR_SetAPI.PDSCHInfo[0].ra_param.RA_type = ds_NR_PDSCH_RA_Type_1;
	NR_SetAPI.PDSCHInfo[0].ra_param.RB_offset = 3;
	NR_SetAPI.PDSCHInfo[0].ra_param.RB_Num = 270;
	NR_SetAPI.PDSCHInfo[0].ra_param.VRB_to_PRB_Mapping = ds_NR_PDSCH_VRB_to_PRB_NonInterleave;
	NR_SetAPI.PDSCHInfo[0].ra_param.VRB_to_PRB_Interleave = 2; // Only Interleave mode
	NR_SetAPI.PDSCHInfo[0].ra_param.PRB_BundleSize = ds_NR_PDSCH_PRB_BundleSize_WideBand;
	NR_SetAPI.PDSCHInfo[0].mcs_param.Channel_coding = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].mcs_param.Mod_type = ds_NR_Mod_QPSK;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.dmrs_Downlink_r16 = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.N_ID_0 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[0].dmrs_param.N_ID_1 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[0].dmrs_param.n_SCID = 0;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_Config = ds_NR_PDSCH_DMRS_Config_Type1;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_Duration = ds_NR_PDSCH_DMRS_Duration_Single;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_add_pos = 1;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.PDSCH_Mapping = ds_NR_PDSCH_Mapping_Type_A;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_typeA_pos = ds_NR_dmrs_TypeA_Pos2;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_Mapping_Ref = ds_NR_PDSCH_DMRS_Map_ref_CRB0;
	NR_SetAPI.PDSCHInfo[0].transm_param.Num_of_DMRS_CDM_grp_without_data = 1;
	NR_SetAPI.PDSCHInfo[0].transm_param.DMRS_port = ds_NR_PDSCH_Ant_port_1000;

	NR_SetAPI.PDSCHInfo[1].state = ds_ON;
	NR_SetAPI.PDSCHInfo[1].general_param.RNTI = 2;
	NR_SetAPI.PDSCHInfo[1].general_param.n_ID = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[1].general_param.Pwr_boost = 0;
	NR_SetAPI.PDSCHInfo[1].ra_param.BWP = 1;
	//NR_SetAPI.PDSCHInfo[1].ra_param.num_alloc_slot = 16;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[0] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[1] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[2] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[3] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[4] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[5] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[6] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[7] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[8] = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[9] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[10] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[11] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[12] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[13] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[14] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[15] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[16] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[17] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[18] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[19] = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].ra_param.first_symb = 2; NR_SetAPI.PDSCHInfo[1].ra_param.last_symb = 13;
	NR_SetAPI.PDSCHInfo[1].ra_param.RA_type = ds_NR_PDSCH_RA_Type_1;
	NR_SetAPI.PDSCHInfo[1].ra_param.RB_offset = 0;
	NR_SetAPI.PDSCHInfo[1].ra_param.RB_Num = 3;
	NR_SetAPI.PDSCHInfo[1].ra_param.VRB_to_PRB_Mapping = ds_NR_PDSCH_VRB_to_PRB_NonInterleave;
	NR_SetAPI.PDSCHInfo[1].ra_param.VRB_to_PRB_Interleave = 2; // Only Interleave mode
	NR_SetAPI.PDSCHInfo[1].ra_param.PRB_BundleSize = ds_NR_PDSCH_PRB_BundleSize_WideBand;
	NR_SetAPI.PDSCHInfo[1].mcs_param.Channel_coding = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].mcs_param.Mod_type = ds_NR_Mod_QPSK;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.dmrs_Downlink_r16 = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.N_ID_0 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[1].dmrs_param.N_ID_1 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[1].dmrs_param.n_SCID = 0;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_Config = ds_NR_PDSCH_DMRS_Config_Type1;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_Duration = ds_NR_PDSCH_DMRS_Duration_Single;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_add_pos = 1;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.PDSCH_Mapping = ds_NR_PDSCH_Mapping_Type_A;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_typeA_pos = ds_NR_dmrs_TypeA_Pos2;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_Mapping_Ref = ds_NR_PDSCH_DMRS_Map_ref_CRB0;
	NR_SetAPI.PDSCHInfo[1].transm_param.Num_of_DMRS_CDM_grp_without_data = 1;
	NR_SetAPI.PDSCHInfo[1].transm_param.DMRS_port = ds_NR_PDSCH_Ant_port_1000;

	NR_SetAPI.PDSCHInfo[2].state = ds_OFF;

	// Limit
	NR_SetAPI.LimitInfo.target_pwr = 24;
	NR_SetAPI.LimitInfo.pwr_thrshld = 2;
	NR_SetAPI.LimitInfo.freq_offset = 0.05;
	NR_SetAPI.LimitInfo.evm = 2.5;
	NR_SetAPI.LimitInfo.target_pwr = 2300;
#endif
#if 1
	NR_SetAPI.View_symb_idx = 0;
	NR_SetAPI.fc = 3600000000;
	NR_SetAPI.Duplex_type = ds_NR_TDD;
	NR_SetAPI.FR_type = ds_NR_FR1;
	NR_SetAPI.Profile_type = ds_NR_CBW_FR1_100MHz;
	NR_SetAPI.Cell_ID_Auto = ds_Manual;
	NR_SetAPI.Cell_ID = 1;
	NR_SetAPI.Numerology = ds_NR_Single_Numerology;
	NR_SetAPI.SCS = ds_NR_SCS_30kHz;
	NR_SetAPI.Sync_type = ds_NR_Sync_PDSCH_DMRS;
	NR_SetAPI.Meas_Start_slot = 0;
	NR_SetAPI.Meas_Stop_slot = 19;
	NR_SetAPI.Symb_PhaseCorrect = 1;
	// TDD Frame Structure
	NR_SetAPI.FrameInfo.dl_ul_TransPeriod = ds_NR_dl_ul_Period_5ms;
	NR_SetAPI.FrameInfo.DL_slots = 7;
	NR_SetAPI.FrameInfo.DL_symbs = 6;
	NR_SetAPI.FrameInfo.UL_slots = 2;
	NR_SetAPI.FrameInfo.UL_symbs = 4;
	// BWP Information
	// Initial BWP
	NR_SetAPI.BwpInfo[0].state = ds_OFF;
	// BWP 1
	NR_SetAPI.BwpInfo[1].state = ds_ON;
	NR_SetAPI.BwpInfo[1].SCS = NR_SetAPI.SCS; // Single Numerology
	NR_SetAPI.BwpInfo[1].N_RB_Start = 0;
	NR_SetAPI.BwpInfo[1].N_RB_Size = 273;
	NR_SetAPI.BwpInfo[1].Num_Coreset = 1;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].state = ds_ON;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].RB_Offset = -1; // Not Configured
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].RB_Number = 0x100000000000;// 0x111111110000;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].Symb_Number = 2;// 1;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].CCE_to_REG_Map = ds_NR_CCE_to_REG_NonInterleave;// ds_NR_CCE_to_REG_Interleave;
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].REG_BundleSize = 6;// 2; // Only Interleaved mode
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].InterleaveSize = 2; // Only Interleaved mode
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].Shift_Index = 0; //160; // Only Interleaved mode
	NR_SetAPI.BwpInfo[1].Coreset_Info[0].Precoder_Granul = ds_NR_PrecoderGran_REG_BundleSize;
	NR_SetAPI.BwpInfo[1].Coreset_Info[1].state = ds_OFF;
	NR_SetAPI.BwpInfo[1].Coreset_Info[2].state = ds_OFF;
	// BWP 2
	NR_SetAPI.BwpInfo[2].state = ds_OFF;
	// BWP 3
	NR_SetAPI.BwpInfo[3].state = ds_OFF;
	// BWP 4
	NR_SetAPI.BwpInfo[4].state = ds_OFF;
	// SSB Info
	NR_SetAPI.SSBInfo.state = ds_OFF;
	NR_SetAPI.SSBInfo.SCS = ds_NR_SCS_30kHz;
	NR_SetAPI.SSBInfo.SSB_Pos_type = ds_NR_SSB_PosType_RB;
	NR_SetAPI.SSBInfo.SSB_Config = ds_Auto;
	NR_SetAPI.SSBInfo.RB_Offset = 253;
	NR_SetAPI.SSBInfo.k_SSB = 0;
	NR_SetAPI.SSBInfo.GSCN = 22256;
	// PDCCH Info
	NR_SetAPI.PDCCHInfo[0].state = ds_ON;
	NR_SetAPI.PDCCHInfo[0].RNTI = 0;
	NR_SetAPI.PDCCHInfo[0].C_RNTI = 0;
	NR_SetAPI.PDCCHInfo[0].BWP = 1;
	NR_SetAPI.PDCCHInfo[0].CORESET_ID = 1;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[0] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[1] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[2] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[3] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[4] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[5] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[6] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[7] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[8] = ds_OFF;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[9] = ds_OFF; NR_SetAPI.PDCCHInfo[0].Alloc_slot[10] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[11] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[12] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[13] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[14] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[15] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[16] = ds_ON; NR_SetAPI.PDCCHInfo[0].Alloc_slot[17] = ds_ON;
	NR_SetAPI.PDCCHInfo[0].Alloc_slot[18] = ds_OFF; NR_SetAPI.PDCCHInfo[0].Alloc_slot[19] = ds_OFF;
	NR_SetAPI.PDCCHInfo[0].First_symb = 0;
	NR_SetAPI.PDCCHInfo[0].Search_space = ds_NR_SearchSpace_USS;
	NR_SetAPI.PDCCHInfo[0].Aggreg_level = ds_NR_CCE_AggregationLevel_1;// ds_NR_CCE_AggregationLevel_2;
	NR_SetAPI.PDCCHInfo[0].Num_of_PDCCH_Candidate = 4;
	NR_SetAPI.PDCCHInfo[0].Candidate_index = 0;// 2;
	NR_SetAPI.PDCCHInfo[0].DCI_Size = 20;
	NR_SetAPI.PDCCHInfo[0].PDCCH_DMRS_Scrmb_ID = -1; // -1 : Not Configured
	NR_SetAPI.PDCCHInfo[0].Pwr_boost = 0;
	NR_SetAPI.PDCCHInfo[0].DMRS_Pwr_boost = 0;
	NR_SetAPI.PDCCHInfo[1].state = ds_OFF;
	NR_SetAPI.PDCCHInfo[2].state = ds_OFF;
	// PDSCH Info
	NR_SetAPI.PDSCHInfo[0].state = ds_ON;
	NR_SetAPI.PDSCHInfo[0].general_param.RNTI = 0;
	NR_SetAPI.PDSCHInfo[0].general_param.n_ID = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[0].general_param.Pwr_boost = 0;
	NR_SetAPI.PDSCHInfo[0].ra_param.BWP = 1;
	//NR_SetAPI.PDSCHInfo[0].ra_param.num_alloc_slot = 16;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[0] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[1] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[2] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[3] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[4] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[5] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[6] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[7] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[8] = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[9] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[10] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[11] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[12] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[13] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[14] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[15] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[16] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[17] = ds_ON;
	NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[18] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[19] = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].ra_param.first_symb = 0; NR_SetAPI.PDSCHInfo[0].ra_param.last_symb = 13;
	NR_SetAPI.PDSCHInfo[0].ra_param.RA_type = ds_NR_PDSCH_RA_Type_1;
	NR_SetAPI.PDSCHInfo[0].ra_param.RB_offset = 3;
	NR_SetAPI.PDSCHInfo[0].ra_param.RB_Num = 270;
	NR_SetAPI.PDSCHInfo[0].ra_param.VRB_to_PRB_Mapping = ds_NR_PDSCH_VRB_to_PRB_NonInterleave;
	NR_SetAPI.PDSCHInfo[0].ra_param.VRB_to_PRB_Interleave = 2; // Only Interleave mode
	NR_SetAPI.PDSCHInfo[0].ra_param.PRB_BundleSize = ds_NR_PDSCH_PRB_BundleSize_WideBand;
	NR_SetAPI.PDSCHInfo[0].mcs_param.Channel_coding = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].mcs_param.Mod_type = ds_NR_Mod_QPSK;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.dmrs_Downlink_r16 = ds_OFF;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.N_ID_0 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[0].dmrs_param.N_ID_1 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[0].dmrs_param.n_SCID = 0;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_Config = ds_NR_PDSCH_DMRS_Config_Type1;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_Duration = ds_NR_PDSCH_DMRS_Duration_Single;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_add_pos = 1;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.PDSCH_Mapping = ds_NR_PDSCH_Mapping_Type_A;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_typeA_pos = ds_NR_dmrs_TypeA_Pos2;
	NR_SetAPI.PDSCHInfo[0].dmrs_param.DMRS_Mapping_Ref = ds_NR_PDSCH_DMRS_Map_ref_CRB0;
	NR_SetAPI.PDSCHInfo[0].transm_param.Num_of_DMRS_CDM_grp_without_data = 1;
	NR_SetAPI.PDSCHInfo[0].transm_param.DMRS_port = ds_NR_PDSCH_Ant_port_1000;

	NR_SetAPI.PDSCHInfo[1].state = ds_ON;
	NR_SetAPI.PDSCHInfo[1].general_param.RNTI = 2;
	NR_SetAPI.PDSCHInfo[1].general_param.n_ID = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[1].general_param.Pwr_boost = 0;
	NR_SetAPI.PDSCHInfo[1].ra_param.BWP = 1;
	//NR_SetAPI.PDSCHInfo[1].ra_param.num_alloc_slot = 16;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[0] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[1] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[2] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[3] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[4] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[5] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[6] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[7] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[8] = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[9] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[10] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[11] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[12] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[13] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[14] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[15] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[16] = ds_ON; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[17] = ds_ON;
	NR_SetAPI.PDSCHInfo[1].ra_param.alloc_slot[18] = ds_OFF; NR_SetAPI.PDSCHInfo[0].ra_param.alloc_slot[19] = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].ra_param.first_symb = 2; NR_SetAPI.PDSCHInfo[1].ra_param.last_symb = 13;
	NR_SetAPI.PDSCHInfo[1].ra_param.RA_type = ds_NR_PDSCH_RA_Type_1;
	NR_SetAPI.PDSCHInfo[1].ra_param.RB_offset = 0;
	NR_SetAPI.PDSCHInfo[1].ra_param.RB_Num = 3;
	NR_SetAPI.PDSCHInfo[1].ra_param.VRB_to_PRB_Mapping = ds_NR_PDSCH_VRB_to_PRB_NonInterleave;
	NR_SetAPI.PDSCHInfo[1].ra_param.VRB_to_PRB_Interleave = 2; // Only Interleave mode
	NR_SetAPI.PDSCHInfo[1].ra_param.PRB_BundleSize = ds_NR_PDSCH_PRB_BundleSize_WideBand;
	NR_SetAPI.PDSCHInfo[1].mcs_param.Channel_coding = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].mcs_param.Mod_type = ds_NR_Mod_QPSK;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.dmrs_Downlink_r16 = ds_OFF;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.N_ID_0 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[1].dmrs_param.N_ID_1 = -1; // -1 : Cell ID
	NR_SetAPI.PDSCHInfo[1].dmrs_param.n_SCID = 0;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_Config = ds_NR_PDSCH_DMRS_Config_Type1;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_Duration = ds_NR_PDSCH_DMRS_Duration_Single;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_add_pos = 1;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.PDSCH_Mapping = ds_NR_PDSCH_Mapping_Type_A;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_typeA_pos = ds_NR_dmrs_TypeA_Pos2;
	NR_SetAPI.PDSCHInfo[1].dmrs_param.DMRS_Mapping_Ref = ds_NR_PDSCH_DMRS_Map_ref_CRB0;
	NR_SetAPI.PDSCHInfo[1].transm_param.Num_of_DMRS_CDM_grp_without_data = 1;
	NR_SetAPI.PDSCHInfo[1].transm_param.DMRS_port = ds_NR_PDSCH_Ant_port_1000;

	NR_SetAPI.PDSCHInfo[2].state = ds_OFF;


	// Limit
	NR_SetAPI.LimitInfo.target_pwr = 24;
	NR_SetAPI.LimitInfo.pwr_thrshld = 2;
	NR_SetAPI.LimitInfo.freq_offset = 0.05;
	NR_SetAPI.LimitInfo.evm = 2.5;
	NR_SetAPI.LimitInfo.target_pwr = 2300;
#endif
	return NR_SetAPI;
}
ds32s w_ds5G_nr_Open_5G_lib()
{
	return ds5G_nr_Open_5G_lib();
}

ds32s ds5G_nr_TM_Set_All_API(ds32s mode) {
	FILE* fp;
	fp = 0;
	char file_name[256];
	ds32s i, j, pss_len, sss_len, pbch_len, pbch_dmrs_len, pdcch_len, pdcch_dmrs_len, pdsch_len, pdsch_dmrs_len;
	ds_NR_SetAPI NR_SetAPI = { 0, };

	switch (mode)
	{
	case 0:
		fopen_s(&fp, "set_param/parameter_set_TM1p1.txt", "r");
		break;
	case 1:
		fopen_s(&fp, "set_param/parameter_set_TM1p2.txt", "r");
		break;
	case 2:
		fopen_s(&fp, "set_param/parameter_set_TM2.txt", "r");
		break;
	case 3:
		fopen_s(&fp, "set_param/parameter_set_TM2a.txt", "r");
		break;
	case 4:
		fopen_s(&fp, "set_param/parameter_set_TM3p1.txt", "r");
		break;
	case 5:
		fopen_s(&fp, "set_param/parameter_set_TM3p1a.txt", "r");
		break;
	case 6:
		fopen_s(&fp, "set_param/parameter_set_TM3p2.txt", "r");
		break;
	case 7:
		fopen_s(&fp, "set_param/parameter_set_TM3p3.txt", "r");
		break;
	case 8:
		fopen_s(&fp, "set_param/parameter_set_TM1p1_FR2.txt", "r");
		break;
	case 9:
		fopen_s(&fp, "set_param/parameter_set_TM2_FR2.txt", "r");
		break;
	case 10:
		fopen_s(&fp, "set_param/parameter_set_TM2a_FR2.txt", "r");
		break;
	case 11:
		fopen_s(&fp, "set_param/parameter_set_TM3p1_FR2.txt", "r");
		break;
	case 12:
		fopen_s(&fp, "set_param/parameter_set_TM3p1a_FR2.txt", "r");
		break;
	}

	if (fp == 0)
	{
		// printf("Fail to read File");
	}
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.View_symb_idx);
	// printf("%s %d\n", file_name, NR_SetAPI.View_symb_idx);
	fscanf_s(fp, "%[^\n] %I64u\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.fc);
	// printf("%s %I64d\n", file_name, NR_SetAPI.fc);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Duplex_type);
	// printf("%s %d\n", file_name, NR_SetAPI.Duplex_type);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Profile_type);
	// printf("%s %d\n", file_name, NR_SetAPI.Profile_type);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Cell_ID_Auto);
	// printf("%s %d\n", file_name, NR_SetAPI.Cell_ID_Auto);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Cell_ID);
	// printf("%s %d\n", file_name, NR_SetAPI.Cell_ID);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Numerology);
	// printf("%s %d\n", file_name, NR_SetAPI.Numerology);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.SCS);
	// printf("%s %d\n", file_name, NR_SetAPI.SCS);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Sync_type);
	// printf("%s %d\n", file_name, NR_SetAPI.Sync_type);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Meas_Start_slot);
	// printf("%s %d\n", file_name, NR_SetAPI.Meas_Start_slot);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Meas_Stop_slot);
	// printf("%s %d\n", file_name, NR_SetAPI.Meas_Stop_slot);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.Symb_PhaseCorrect);
	// printf("%s %d\n", file_name, NR_SetAPI.Symb_PhaseCorrect);
	// Frame Structure
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.FrameInfo.dl_ul_TransPeriod);
	// printf("%s %d\n", file_name, NR_SetAPI.FrameInfo.dl_ul_TransPeriod);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.FrameInfo.DL_slots);
	// printf("%s %d\n", file_name, NR_SetAPI.FrameInfo.DL_slots);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.FrameInfo.DL_symbs);
	// printf("%s %d\n", file_name, NR_SetAPI.FrameInfo.DL_symbs);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.FrameInfo.UL_slots);
	// printf("%s %d\n", file_name, NR_SetAPI.FrameInfo.UL_slots);
	fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.FrameInfo.UL_symbs);
	// printf("%s %d\n", file_name, NR_SetAPI.FrameInfo.UL_symbs);
	// BWP Info
	for (i = 0; i < MAX_NUM_BWP; i++)
	{
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].state);
		// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].state);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].SCS);
		// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].SCS);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].N_RB_Start);
		// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].N_RB_Start);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].N_RB_Size);
		// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].N_RB_Size);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Num_Coreset);
		// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Num_Coreset);
		for (j = 0; j < MAX_NUM_CORESET; j++)
		{
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].state);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].state);
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].RB_Offset);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].RB_Offset);
			fscanf_s(fp, "%[^\n] %I64x\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].RB_Number);
			// printf("%s %I64X, (%I64d)\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].RB_Number, NR_SetAPI.BwpInfo[i].Coreset_Info[j].RB_Number);
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].Symb_Number);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].Symb_Number);
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].CCE_to_REG_Map);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].CCE_to_REG_Map);
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].REG_BundleSize);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].REG_BundleSize);
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].InterleaveSize);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].InterleaveSize);
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].Shift_Index);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].Shift_Index);
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.BwpInfo[i].Coreset_Info[j].Precoder_Granul);
			// printf("%s %d\n", file_name, NR_SetAPI.BwpInfo[i].Coreset_Info[j].Precoder_Granul);
		}
	}
	// PDCCH Info
	for (i = 0; i < MAX_NUM_PDCCH; i++)
	{
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].state);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].state);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].RNTI);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].RNTI);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].C_RNTI);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].C_RNTI);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].BWP);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].BWP);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].CORESET_ID);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].CORESET_ID);
		//fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].Alloc_slot[j]);
		fscanf_s(fp, "%[^\n]", file_name, (ds32u)sizeof(file_name));
		// printf("%s\n", file_name);
		for (j = 0; j < 80; j++)
		{
			fscanf_s(fp, "%d\n", &NR_SetAPI.PDCCHInfo[i].Alloc_slot[j]);
			// printf("[%d] : %d ", j, NR_SetAPI.PDCCHInfo[i].Alloc_slot[j]);
			// if (j % 10 == 9) // printf("\n");
		}
		// printf("\n");
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].First_symb);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].First_symb);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].Search_space);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].Search_space);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].Aggreg_level);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].Aggreg_level);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].Num_of_PDCCH_Candidate);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].Num_of_PDCCH_Candidate);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].Candidate_index);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].Candidate_index);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].DCI_Size);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].DCI_Size);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].PDCCH_DMRS_Scrmb_ID);
		// printf("%s %d\n", file_name, NR_SetAPI.PDCCHInfo[i].PDCCH_DMRS_Scrmb_ID);
		fscanf_s(fp, "%[^\n] %lf\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].Pwr_boost);
		// printf("%s %lf\n", file_name, NR_SetAPI.PDCCHInfo[i].Pwr_boost);
		fscanf_s(fp, "%[^\n] %lf\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDCCHInfo[i].DMRS_Pwr_boost);
		// printf("%s %lf\n", file_name, NR_SetAPI.PDCCHInfo[i].DMRS_Pwr_boost);
	}
	// PDSCH Info
	for (i = 0; i < MAX_NUM_PDSCH; i++)
	{
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].state);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].state);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].general_param.RNTI);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].general_param.RNTI);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].general_param.n_ID);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].general_param.n_ID);
		fscanf_s(fp, "%[^\n] %lf\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].general_param.Pwr_boost);
		// printf("%s %lf\n", file_name, NR_SetAPI.PDSCHInfo[i].general_param.Pwr_boost);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.BWP);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.BWP);
		//fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.alloc_slot);
		fscanf_s(fp, "%[^\n]", file_name, (ds32u)sizeof(file_name));
		// printf("%s\n", file_name);
		for (j = 0; j < 80; j++)
		{
			fscanf_s(fp, "%d\n", &NR_SetAPI.PDSCHInfo[i].ra_param.alloc_slot[j]);
			// printf("[%d] : %d ", j, NR_SetAPI.PDSCHInfo[i].ra_param.alloc_slot[j]);
			// if (j % 10 == 9) // printf("\n");
		}
		// printf("\n");
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.first_symb);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.first_symb);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.last_symb);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.last_symb);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.RA_type);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.RA_type);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.RB_offset);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.RB_offset);
		if (NR_SetAPI.PDSCHInfo[i].ra_param.RA_type == ds_NR_PDSCH_RA_Type_1)
		{
			fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.RB_Num);
			// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.RB_Num);
		}
		else
		{
			fscanf_s(fp, "%[^\n] %X\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.RB_Num);
			// printf("%s %X\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.RB_Num);
		}
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.VRB_to_PRB_Mapping);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.VRB_to_PRB_Mapping);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.VRB_to_PRB_Interleave);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.VRB_to_PRB_Interleave);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ra_param.PRB_BundleSize);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ra_param.PRB_BundleSize);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].mcs_param.Channel_coding);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].mcs_param.Channel_coding);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].mcs_param.Mod_type);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].mcs_param.Mod_type);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].mcs_param.MCS_table);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].mcs_param.MCS_table);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].mcs_param.MCS);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].mcs_param.MCS);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].mcs_param.xOverhead);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].mcs_param.xOverhead);
		fscanf_s(fp, "%[^\n] %lf\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].mcs_param.TB_scaling_factor);
		// printf("%s %lf\n", file_name, NR_SetAPI.PDSCHInfo[i].mcs_param.TB_scaling_factor);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.dmrs_Downlink_r16);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.dmrs_Downlink_r16);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.N_ID_0);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.N_ID_0);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.N_ID_1);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.N_ID_1);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.n_SCID);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.n_SCID);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_Config);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_Config);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_Duration);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_Duration);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_add_pos);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_add_pos);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.PDSCH_Mapping);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.PDSCH_Mapping);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_typeA_pos);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_typeA_pos);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_Mapping_Ref);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].dmrs_param.DMRS_Mapping_Ref);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].transm_param.Num_of_DMRS_CDM_grp_without_data);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].transm_param.Num_of_DMRS_CDM_grp_without_data);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].transm_param.DMRS_port);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].transm_param.DMRS_port);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ptrs_param.state);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ptrs_param.state);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ptrs_param.K_PTRS);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ptrs_param.K_PTRS);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ptrs_param.L_PTRS);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ptrs_param.L_PTRS);
		fscanf_s(fp, "%[^\n] %d\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ptrs_param.RE_OFFSET);
		// printf("%s %d\n", file_name, NR_SetAPI.PDSCHInfo[i].ptrs_param.RE_OFFSET);
		fscanf_s(fp, "%[^\n] %lf\n", file_name, (ds32u)sizeof(file_name), &NR_SetAPI.PDSCHInfo[i].ptrs_param.Pwr_boost);
		// printf("%s %lf\n", file_name, NR_SetAPI.PDSCHInfo[i].ptrs_param.Pwr_boost);
	}
	fclose(fp);
	return ds5G_nr_set_All_API(&NR_SetAPI);
}

ds32s w_ds5G_nr_set_All_API(char json_input[])
{
	ds_NR_SetAPI* api;
	api = new ds_NR_SetAPI();
	std::string json_data;
	json_data = json_input;
	rapidjson::Document data;
	data.Parse(json_data.c_str());
	if (data.HasParseError())//파싱 실패 에러
		return 1;
	//*api = (ds_NR_SetAPI)input_data();
	/*Struct_Data_Set(data, ds_NR_SetAPI_data);*/
	if (data.IsObject())
	{
		api->View_symb_idx = data["View_symb_idx"].GetInt();
		api->Duplex_type = data["Duplex_type"].GetInt();
		api->FR_type = data["FR_type"].GetInt();
		api->Cell_ID_Auto = data["Cell_ID_Auto"].GetInt();
		api->Cell_ID = data["Cell_ID"].GetInt();
		api->Profile_type = data["Profile_type"].GetInt();
		api->Numerology = data["Numerology"].GetInt();
		api->SCS = data["SCS"].GetInt();
		api->Sync_type = data["Sync_type"].GetInt();
		api->Meas_Start_slot = data["Meas_Start_slot"].GetInt();
		api->Meas_Stop_slot = data["Meas_Stop_slot"].GetInt();
		api->Symb_PhaseCorrect = data["Symb_PhaseCorrect"].GetInt();
		api->fc = data["fc"].GetUint64();
		const rapidjson::Value& FrameInfoIndex = data["FrameInfo"];
		api->FrameInfo.dl_ul_TransPeriod = FrameInfoIndex["dl_ul_TransPeriod"].GetInt();
		api->FrameInfo.DL_slots = FrameInfoIndex["DL_slots"].GetInt();
		api->FrameInfo.DL_symbs = FrameInfoIndex["DL_symbs"].GetInt();
		api->FrameInfo.UL_slots = FrameInfoIndex["UL_slots"].GetInt();
		api->FrameInfo.UL_symbs = FrameInfoIndex["UL_symbs"].GetInt();
		const rapidjson::Value& BwpInfoArray = data["BwpInfo"];
		for (rapidjson::SizeType i = 0; i < BwpInfoArray.Size(); i++) {
			const rapidjson::Value& BwpInfo = BwpInfoArray[i];
			api->BwpInfo[i].state = BwpInfo["state"].GetInt();
			api->BwpInfo[i].SCS = BwpInfo["SCS"].GetInt();
			api->BwpInfo[i].N_RB_Start = BwpInfo["N_RB_Start"].GetInt();
			api->BwpInfo[i].N_RB_Size = BwpInfo["N_RB_Size"].GetInt();
			api->BwpInfo[i].Num_Coreset = BwpInfo["Num_Coreset"].GetInt();
			const rapidjson::Value& BwpCoresetInfoArray = BwpInfo["Coreset_Info"];
			for (rapidjson::SizeType j = 0; j < BwpCoresetInfoArray.Size(); j++) {
				const rapidjson::Value& BwpCoresetInfo = BwpCoresetInfoArray[j];
				api->BwpInfo[i].Coreset_Info[j].state = BwpCoresetInfo["state"].GetInt();
				api->BwpInfo[i].Coreset_Info[j].RB_Offset = BwpCoresetInfo["RB_Offset"].GetInt();
				api->BwpInfo[i].Coreset_Info[j].RB_Number = BwpCoresetInfo["RB_Number"].GetInt64();
				api->BwpInfo[i].Coreset_Info[j].Symb_Number = BwpCoresetInfo["Symb_Number"].GetInt();
				api->BwpInfo[i].Coreset_Info[j].CCE_to_REG_Map = BwpCoresetInfo["CCE_to_REG_Map"].GetInt();
				api->BwpInfo[i].Coreset_Info[j].REG_BundleSize = BwpCoresetInfo["REG_BundleSize"].GetInt();
				api->BwpInfo[i].Coreset_Info[j].InterleaveSize = BwpCoresetInfo["InterleaveSize"].GetInt();
				api->BwpInfo[i].Coreset_Info[j].Shift_Index = BwpCoresetInfo["Shift_Index"].GetInt();
				api->BwpInfo[i].Coreset_Info[j].Precoder_Granul = BwpCoresetInfo["Precoder_Granul"].GetInt();
			}
		}
		const rapidjson::Value& SsbInfoParam = data["SSBInfo"];
		api->SSBInfo.state = SsbInfoParam["state"].GetInt();
		api->SSBInfo.SCS = SsbInfoParam["SCS"].GetInt();
		api->SSBInfo.SSB_Pos_type = SsbInfoParam["SSB_Pos_type"].GetInt();
		api->SSBInfo.SSB_Config = SsbInfoParam["SSB_Config"].GetInt();
		api->SSBInfo.RB_Offset = SsbInfoParam["RB_Offset"].GetInt();
		api->SSBInfo.k_SSB = SsbInfoParam["k_SSB"].GetInt();
		api->SSBInfo.GSCN = SsbInfoParam["GSCN"].GetInt();
		const rapidjson::Value& PdcchInfoArray = data["PDCCHInfo"];
		for (rapidjson::SizeType i = 0; i < PdcchInfoArray.Size(); i++) {
			const rapidjson::Value& PdcchInfo = PdcchInfoArray[i];
			api->PDCCHInfo[i].state = PdcchInfo["state"].GetInt();
			api->PDCCHInfo[i].PDCCH_DMRS_Scrmb_ID = PdcchInfo["PDCCH_DMRS_Scrmb_ID"].GetInt();
			api->PDCCHInfo[i].RNTI = PdcchInfo["RNTI"].GetInt();
			api->PDCCHInfo[i].C_RNTI = PdcchInfo["C_RNTI"].GetInt();
			api->PDCCHInfo[i].BWP = PdcchInfo["BWP"].GetInt();
			api->PDCCHInfo[i].CORESET_ID = PdcchInfo["CORESET_ID"].GetInt();
			api->PDCCHInfo[i].First_symb = PdcchInfo["First_symb"].GetInt();
			api->PDCCHInfo[i].Search_space = PdcchInfo["Search_space"].GetInt();
			api->PDCCHInfo[i].Aggreg_level = PdcchInfo["Aggreg_level"].GetInt();
			api->PDCCHInfo[i].Num_of_PDCCH_Candidate = PdcchInfo["Num_of_PDCCH_Candidate"].GetInt();
			api->PDCCHInfo[i].Candidate_index = PdcchInfo["Candidate_index"].GetInt();
			api->PDCCHInfo[i].DCI_Size = PdcchInfo["DCI_Size"].GetInt();
			api->PDCCHInfo[i].Pwr_boost = PdcchInfo["Pwr_boost"].GetDouble();
			api->PDCCHInfo[i].DMRS_Pwr_boost = PdcchInfo["DMRS_Pwr_boost"].GetDouble();
			const rapidjson::Value& PdcchAllocSlotArray = PdcchInfo["Alloc_slot"];
			for (rapidjson::SizeType j = 0; j < PdcchAllocSlotArray.Size(); j++) {
				api->PDCCHInfo[i].Alloc_slot[j] = PdcchAllocSlotArray[j].GetInt();
			}
		}
		const rapidjson::Value& PdschInfoArray = data["PDSCHInfo"];
		for (rapidjson::SizeType i = 0; i < PdschInfoArray.Size(); i++) {
			const rapidjson::Value& PdschInfo = PdschInfoArray[i];
			api->PDSCHInfo[i].state = PdschInfo["state"].GetInt();
			const rapidjson::Value& PdschGeneral = PdschInfo["general_param"];
			api->PDSCHInfo[i].general_param.RNTI = PdschGeneral["RNTI"].GetInt();
			api->PDSCHInfo[i].general_param.n_ID = PdschGeneral["n_ID"].GetInt();
			api->PDSCHInfo[i].general_param.Num_of_Layer = PdschGeneral["Num_of_Layer"].GetInt();
			api->PDSCHInfo[i].general_param.Num_of_Codeword = PdschGeneral["Num_of_Codeword"].GetInt();
			api->PDSCHInfo[i].general_param.Pwr_boost = PdschGeneral["Pwr_boost"].GetDouble();
			const rapidjson::Value& PdschTransm = PdschInfo["transm_param"];
			api->PDSCHInfo[i].transm_param.DMRS_port = PdschTransm["DMRS_port"].GetInt();
			api->PDSCHInfo[i].transm_param.Num_of_DMRS_CDM_grp_without_data = PdschTransm["Num_of_DMRS_CDM_grp_without_data"].GetInt();
			const rapidjson::Value& PdschRa = PdschInfo["ra_param"];
			api->PDSCHInfo[i].ra_param.first_symb = PdschRa["first_symb"].GetInt();
			api->PDSCHInfo[i].ra_param.last_symb = PdschRa["last_symb"].GetInt();
			api->PDSCHInfo[i].ra_param.BWP = PdschRa["BWP"].GetInt();
			api->PDSCHInfo[i].ra_param.RA_type = PdschRa["RA_type"].GetInt();
			api->PDSCHInfo[i].ra_param.RB_offset = PdschRa["RB_offset"].GetInt();
			api->PDSCHInfo[i].ra_param.RB_Num = PdschRa["RB_Num"].GetInt();
			api->PDSCHInfo[i].ra_param.VRB_to_PRB_Mapping = PdschRa["VRB_to_PRB_Mapping"].GetInt();
			api->PDSCHInfo[i].ra_param.VRB_to_PRB_Interleave = PdschRa["VRB_to_PRB_Interleave"].GetInt();
			api->PDSCHInfo[i].ra_param.PRB_BundleSize = PdschRa["PRB_BundleSize"].GetInt();
			const rapidjson::Value& PdcchRaAllocSlot = PdschRa["alloc_slot"];
			for (rapidjson::SizeType j = 0; j < PdcchRaAllocSlot.Size(); j++) {
				api->PDSCHInfo[i].ra_param.alloc_slot[j] = PdcchRaAllocSlot[j].GetInt();
			}
			const rapidjson::Value& PdschMcs = PdschInfo["mcs_param"];
			api->PDSCHInfo[i].mcs_param.Channel_coding = PdschMcs["Channel_coding"].GetInt();
			api->PDSCHInfo[i].mcs_param.Mod_type = PdschMcs["Mod_type"].GetInt();
			api->PDSCHInfo[i].mcs_param.MCS_table = PdschMcs["MCS_table"].GetInt();
			api->PDSCHInfo[i].mcs_param.MCS = PdschMcs["MCS"].GetInt();
			api->PDSCHInfo[i].mcs_param.xOverhead = PdschMcs["xOverhead"].GetInt();
			api->PDSCHInfo[i].mcs_param.TB_scaling_factor = PdschMcs["TB_scaling_factor"].GetDouble();
			const rapidjson::Value& PdschHarq = PdschInfo["harq_param"];
			api->PDSCHInfo[i].harq_param.New_Data_Indicator = PdschHarq["New_Data_Indicator"].GetInt();
			api->PDSCHInfo[i].harq_param.HARQ_Process_Num = PdschHarq["HARQ_Process_Num"].GetInt();
			api->PDSCHInfo[i].harq_param.RV_Index = PdschHarq["RV_Index"].GetInt();
			api->PDSCHInfo[i].harq_param.CBG_Transmission = PdschHarq["CBG_Transmission"].GetInt();
			api->PDSCHInfo[i].harq_param.CRC_Err_Flag = PdschHarq["CRC_Err_Flag"].GetInt();
			const rapidjson::Value& PdschDmrs = PdschInfo["dmrs_param"];
			api->PDSCHInfo[i].dmrs_param.dmrs_Downlink_r16 = PdschDmrs["dmrs_Downlink_r16"].GetInt();
			api->PDSCHInfo[i].dmrs_param.n_SCID = PdschDmrs["n_SCID"].GetInt();
			api->PDSCHInfo[i].dmrs_param.N_ID_0 = PdschDmrs["N_ID_0"].GetInt();
			api->PDSCHInfo[i].dmrs_param.N_ID_1 = PdschDmrs["N_ID_1"].GetInt();
			api->PDSCHInfo[i].dmrs_param.DMRS_Config = PdschDmrs["DMRS_Config"].GetInt();
			api->PDSCHInfo[i].dmrs_param.DMRS_Duration = PdschDmrs["DMRS_Duration"].GetInt();
			api->PDSCHInfo[i].dmrs_param.DMRS_add_pos = PdschDmrs["DMRS_add_pos"].GetInt();
			api->PDSCHInfo[i].dmrs_param.PDSCH_Mapping = PdschDmrs["PDSCH_Mapping"].GetInt();
			api->PDSCHInfo[i].dmrs_param.DMRS_typeA_pos = PdschDmrs["DMRS_typeA_pos"].GetInt();
			api->PDSCHInfo[i].dmrs_param.DMRS_Mapping_Ref = PdschDmrs["DMRS_Mapping_Ref"].GetInt();
			const rapidjson::Value& PdschPtrs = PdschInfo["ptrs_param"];
			api->PDSCHInfo[i].ptrs_param.state = PdschPtrs["state"].GetInt();
			api->PDSCHInfo[i].ptrs_param.K_PTRS = PdschPtrs["K_PTRS"].GetInt();
			api->PDSCHInfo[i].ptrs_param.L_PTRS = PdschPtrs["L_PTRS"].GetInt();
			api->PDSCHInfo[i].ptrs_param.RE_OFFSET = PdschPtrs["RE_OFFSET"].GetInt();
			api->PDSCHInfo[i].ptrs_param.Pwr_boost = PdschPtrs["Pwr_boost"].GetDouble();
		}
		const rapidjson::Value& LimitInfo = data["LimitInfo"];
		api->LimitInfo.target_pwr = LimitInfo["target_pwr"].GetDouble();
		api->LimitInfo.pwr_thrshld = LimitInfo["pwr_thrshld"].GetDouble();
		api->LimitInfo.freq_offset = LimitInfo["freq_offset"].GetDouble();
		api->LimitInfo.evm = LimitInfo["evm"].GetDouble();
		api->LimitInfo.timing_offset = LimitInfo["timing_offset"].GetDouble();
	}
	std::cout << "api->fc: " << api->fc << "api->FrameInfo.dl_ul_TransPeriod: " << api->FrameInfo.dl_ul_TransPeriod
		<< "api->BwpInfo[i].state" << api->BwpInfo[0].state << "api->BwpInfo[i].Coreset_Info[j].state: " << api->BwpInfo[0].Coreset_Info[0].state
		<< "api->BwpInfo[i].Coreset_Info[j].RB_Number" << api->BwpInfo[1].Coreset_Info[0].RB_Number << "api->SSBInfo.state" << api->SSBInfo.state
		<< "api->PDCCHInfo[i].state" << api->PDCCHInfo[0].state << "api->PDCCHInfo[i].DMRS_Pwr_boost" << api->PDCCHInfo[0].DMRS_Pwr_boost
		<< "api->PDSCHInfo[i].general_param.Pwr_boost" << api->PDSCHInfo[0].general_param.Pwr_boost << "api->PDSCHInfo[i].mcs_param.TB_scaling_factor" << api->PDSCHInfo[0].mcs_param.TB_scaling_factor
		<< "api->PDSCHInfo[i].ptrs_param.Pwr_boost" << api->PDSCHInfo[0].ptrs_param.Pwr_boost << "api->LimitInfo.freq_offset" << api->LimitInfo.freq_offset
		<< std::endl;

	ds_NR_SetAPI api2 = input_data();

	//return ds5G_nr_set_All_API(api);

	return ds5G_nr_set_All_API(api);
}



ds32s helloworld() {
	// printf("Hello C World");
	return 0;
}