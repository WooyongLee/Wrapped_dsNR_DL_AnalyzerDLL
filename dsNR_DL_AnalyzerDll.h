///////////////////////////////////////////////////////////////////////////////////////
// @file		: dsNR_DL_AnalyzerDll.h
// @author		: BK Jang
// @date		: 2023.05
// @copyright	 (c) 2023 Dabin systems Corporation, All rights reserved.
// @purpose		: Main header file for the 'dsNR_DL_Analyzer' Dynamic Link Library
// @comment		: 'dsNR_DL_Analyzer' - Library file for 5G NR Analyzer of Dabin systems

#ifdef NRDLANALYZEDLL_EXPORTS
#define NR_DL_API __declspec(dllexport)
#else
#define NR_DL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_Open_5G_lib
	//  Purpose:    Open 5G Library
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//
	//  Notes:      This function must be called for using 5G NR DLL.
	//              If you doesn't this function, you can't 5G DLL.
	*/
	NR_DL_API ds32s ds5G_nr_Open_5G_lib();
	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_Close_lib
	//  Purpose:    Close 5G Library
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//
	//  Notes:      This function must be called if you finish 5G DLL.
	//              If you doesn't call this function when you finish 5G DLL, memory leak occurs.
	*/
	NR_DL_API ds32s ds5G_nr_Close_lib();

	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_set_All_API
	//  Purpose:    Set parameters received from GUI to interal parameters
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    set_info  pointer for acquiring parameters from GUI menu tree
	//
	//  Notes:      This function must be called before calling analyzer function.
	//              If the user doesn't change menu, we don't need to this function again.
	//				But, It's OKay even if we call every time.
	*/
	NR_DL_API ds32s ds5G_nr_set_All_API(ds_NR_SetAPI* set_info);
	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_init_param
	//  Purpose:    Initiate internal parameters for analyzing 5G NR using GUI Menu
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//
	//
	//  Notes:      This function must be called after calling ds5G_nr_set_All_API
	//				and before calling analyzer function
	*/
	NR_DL_API ds32s ds5G_nr_init_param();
	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_dl_analyze
	//  Purpose:    Analyze 5G NR Downlink Signal using captured I/Q data
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//	  input_re	pointer for captured I data
	//	  input_im  pointer for captured Q data
	//    capture_len
	//				capture length for I/Q data
	//
	//
	//  Notes:      This function must be called after calling ds5G_nr_set_All_API
	//				& ds5G_nr_init_param
	*/
	NR_DL_API ds32s ds5G_nr_dl_analyze(ds16s* input_re, ds16s* input_im, ds32s capture_len);

	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_CellInfoRst
	//  Purpose:    Get measurement results for Cell Information
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    cel_info	pointer for getting Cell Information results
	//
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_CellInfoRst(ds_NR_Cell_Info_Rst* cell_info);


	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_CellInfoRst
	//  Purpose:    Get measurement results for Power Information
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    pwr_info	pointer for getting Power Information results
	//
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_PwrInfoRst(ds_NR_PwrInfo_Rst* pwr_info);

	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_Symb_PwrSpec_param
	//  Purpose:    Get parameters for Symbol Power Spectrum
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    rbw		pointer for getting RBW value to display at screen
	//    span		pointer for getting Span value to display at screen
	//    num_data  pointer for getting length of spectrum data
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_Symb_PwrSpec_param(ds32s* rbw, ds32s* span, ds32s* num_data);

	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_Symb_PwrSpec_param
	//  Purpose:    Get measurement data for Symbol Power Spectrum
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    pwr_spectrum
	//				pointer for symbol power spectrum data
	//				length is acquired from ds5G_nr_get_Symb_PwrSpec_param()
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_Symb_PwrSpectrum(ds32s* pwr_spectrum);
	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_EVS_Length
	//  Purpose:    Get length parameters for Error Vector Spectrum
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    len		pointer for getting data length of Error Vector Specturm
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_EVS_Length(ds32s* len);

	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_EVS_Data
	//  Purpose:    Get measurement data for Error Vector Spectrum
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    evs		pointer for getting data of Error Vector Specturm
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_EVS_Data(ds32s* evs);
	

	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_SigQualityRst
	//  Purpose:    Get measurement data for Signal Quality
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    sig_info	pointer for getting measurement results of signal quality
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_SigQualityRst(ds_NR_SigQuality_Rst* sig_info);
	
	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_ErrSummary_Rst
	//  Purpose:    Get measurement data for Error Summary
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    err_rst	pointer for getting measurement results of Error Summary
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_ErrSummary_Rst(ds_NR_Err_Summary_Rst* err_rst);
	
	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_IQConstel_Length
	//  Purpose:    Get length of I/Q data for I/Q Constellation of the specific Channel
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    len		pointer for getting data length of the specific channel
	//    ch_type   Channel type to get I/Q constellation data
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_IQConstel_Length(ds32s* len, ds32s ch_type);

	/* /////////////////////////////////////////////////////////////////////////////
	//  Name:       ds5G_nr_get_IQConstel_Data
	//  Purpose:    Get I/Q data for I/Q Constellation of the specific Channel
	//  Returns:
	//   0       -  Normal
	//   Negative - any error
	//
	//  Parameter:
	//    const_re	pointer for getting I data of the specific channel
	//	  const_im	pointer for getting Q data of the specific channel
	//    ch_type   Channel type to get I/Q constellation data
	//
	//  Notes:      This function must be called after calling ds5G_nr_dl_analyze.
	*/
	NR_DL_API ds32s ds5G_nr_get_IQConstel_Data(ds32s* const_re, ds32s* const_im, ds32s ch_type);

#ifdef __cplusplus
}
#endif