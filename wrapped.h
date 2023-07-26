#define W_NR_DL_API __declspec(dllexport)

extern "C" {

W_NR_DL_API ds32s w_ds5G_nr_get_ErrSummary_Rst(ds32s* ChPwr,
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
	);

W_NR_DL_API ds32s w_ds5G_nr_get_SigQualityRst(ds32s* PSS_EVM,
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
	ds32s* PDSCH_PTRS_NumRB);

W_NR_DL_API ds32s w_ds5G_nr_get_EVS_Data(ds32s* evs);

W_NR_DL_API ds32s w_ds5G_nr_get_EVS_Length(ds32s* len);

W_NR_DL_API ds32s w_ds5G_nr_get_Symb_PwrSpectrum(ds32s* pwr_spectrum);

W_NR_DL_API ds32s w_ds5G_nr_get_Symb_PwrSpec_param(ds32s* rbw,
	ds32s* span,
	ds32s* num_data
);

W_NR_DL_API ds32s w_ds5G_nr_get_PwrInfoRst(ds32s* Chpwr,
	ds32s* SS_RSRP,
	ds32s* SS_RSRQ,
	ds32s* SS_SINR,
	ds32s* beam_pwr,
	ds32s* beam_idx,
	ds32s* Exp_TxPwr
);

W_NR_DL_API ds32s w_ds5G_nr_get_CellInfoRst(
	ds32s* Cell_ID,
	ds32s* Sector_ID,
	ds32s* Group_ID,
	ds32s* SCS,
	ds32s* SSB_Freq,
	ds32s* SS_Corr);

W_NR_DL_API ds32s w_ds5G_nr_dl_analyze(ds16s* input_re, ds16s* input_im, ds32s capture_len);

W_NR_DL_API ds32s w_ds5G_nr_init_param();

W_NR_DL_API ds32s w_ds5G_nr_set_All_API(char[]);

W_NR_DL_API ds32s w_ds5G_nr_Close_lib();

W_NR_DL_API ds32s w_ds5G_nr_Open_5G_lib();

W_NR_DL_API ds32s w_ds5G_nr_get_IQConstel_Length(ds32s* len, ds32s ch_type);

W_NR_DL_API ds32s w_ds5G_nr_get_IQConstel_Data(ds32s* const_re, ds32s* const_im, ds32s ch_type);

W_NR_DL_API ds32s helloworld();
W_NR_DL_API ds32s ds5G_nr_TM_Set_All_API(ds32s mode);

}