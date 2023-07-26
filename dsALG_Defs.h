/*--------------------------------------------------------------------------
// Global Header File for Algorithm Library
*/
#ifndef __DS_ALG_DEFS_H__
#define __DS_ALG_DEFS_H__

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#include <math.h>

#define DS_PI    ( 3.14159265358979323846 )  /* ANSI C does not support M_PI */
#define DS_2PI   ( 6.28318530717958647692 )  /* 2*pi                         */
#define DS_4PI	 ( 12.566370614359172 )		 /* 4*pi                         */
#define DS_6PI	 ( 18.849555921538759 )		 /* 6*pi                         */
#define DS_PI2   ( 1.57079632679489661923 )  /* pi/2                         */
#define DS_PI4   ( 0.78539816339744830961 )  /* pi/4                         */
#define DS_PI180 ( 0.01745329251994329577 )  /* pi/180                       */
#define DS_RPI   ( 0.31830988618379067154 )  /* 1/pi                         */
#define DS_R_SQRT2	( 0.70710678118654752440 )  /* 1/sqrt(2)                    */
#define DS_SQRT2 ( 1.41421356237309504880 )  /* sqrt(2)                      */
#define DS_SQRT3 ( 1.73205080756887729353 )  /* sqrt(3)                      */
#define DS_SQRT10 (3.16227766016837933199)
#define DS_SQRT42 (6.48074069840786023096)
#define DS_INV_SQRT2 (0.7071067811865475244)
#define DS_LN2   ( 0.69314718055994530942 )  /* ln(2)                        */
#define DS_LN3   ( 1.09861228866810969139 )  /* ln(3)                        */
#define DS_E     ( 2.71828182845904523536 )  /* e                            */
#define DS_RE    ( 0.36787944117144232159 )  /* 1/e                          */
#define DS_EPS23 ( 1.19209289e-07f )
#define DS_EPS52 ( 2.2204460492503131e-016 )

#define DS_MAX_8U     ( 0xFF )
#define DS_MAX_16U    ( 0xFFFF )
#define DS_MAX_32U    ( 0xFFFFFFFF )
#define DS_MIN_8U     ( 0 )
#define DS_MIN_16U    ( 0 )
#define DS_MIN_32U    ( 0 )
#define DS_MIN_8S     (-128 )
#define DS_MAX_8S     ( 127 )
#define DS_MIN_16S    (-32768 )
#define DS_MAX_16S    ( 32767 )
#define DS_MIN_32S    (-2147483647 - 1 )
#define DS_MAX_32S    ( 2147483647 )
#define DS_MAX_31	  ( 2147483648 )

#if defined( _WIN32 ) || defined ( _WIN64 )
#define DS_MAX_64S  ( 9223372036854775807i64 )
#define DS_MIN_64S  (-9223372036854775807i64 - 1 )
#else
#define DS_MAX_64S  ( 9223372036854775807LL )
#define DS_MIN_64S  (-9223372036854775807LL - 1 )
#endif

#define DS_MINABS_32F ( 1.175494351e-38f )
#define DS_MAXABS_32F ( 3.402823466e+38f )
#define DS_EPS_32F    ( 1.192092890e-07f )
#define DS_MINABS_64F ( 2.2250738585072014e-308 )
#define DS_MAXABS_64F ( 1.7976931348623158e+308 )
#define DS_EPS_64F    ( 2.2204460492503131e-016 )

#define DS_DEG_TO_RAD( deg ) ( (deg)/180.0 * DS_PI )
#define DS_COUNT_OF( obj )  (sizeof(obj)/sizeof(obj[0]))

#define DS_MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define DS_MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )

#define ROUNDING(x, dig)	( floor((x) * pow(10.0, (double)dig) + 0.5) / pow(10.0, (double)dig) )

#define DS_Log_Default		0.000000000001

#define ERROR_VALUE			-999999999

	//------------------------------------------------
	// Define Data Type
	//------------------------------------------------
	typedef signed char			ds8s;
	typedef unsigned  char		ds8u;
	typedef signed short				ds16s;
	typedef unsigned short		ds16u;
	typedef signed int					ds32s;
	typedef unsigned int		ds32u;
#if defined(_WIN32) || defined(_WIN64)
	typedef __int64				ds64s;
	typedef unsigned __int64	ds64u;
#else
	typedef long long			ds64s;
	typedef unsigned long long	ds64u;
#endif
	typedef float				ds32f;
	typedef double				ds64f;

	typedef struct
	{
		ds8s re;
		ds8s im;
	} ds8sc;

	typedef struct
	{
		ds16s re;
		ds16s im;
	} ds16sc;

	typedef struct
	{
		ds32s re;
		ds32s im;
	} ds32sc;

	typedef struct
	{
		ds32f re;
		ds32f im;
	} ds32fc;

	typedef struct
	{
		ds64f re;
		ds64f im;
	} ds64fc;

	//------------------------------------------------
	// Define Error Type
	//------------------------------------------------
	typedef enum
	{
		dsALG_eNoErr = 0,
		dsALG_eInvalidInputErr = -1,
		dsALG_eMemAllocErr = -2,
		dsALG_eDividedZeroErr = -3,
		dsALG_eSyncErr = -4,
		dsALG_eDTF_InvalidInput = -5,
		dsALG_eFFTErr = -6
	} dsALG_Error_Type;

	//------------------------------------------------
	// Define On/Off Type
	//------------------------------------------------
	enum
	{
		ds_OFF = 0,
		ds_ON = 1,
		NUL = 2
	};

	//------------------------------------------------
	// Define Pass/Fail Type
	//------------------------------------------------
	enum
	{
		ds_FAIL = 0,
		ds_PASS = 1
	};

	//------------------------------------------------
	// Define Auto/Manual Type
	//------------------------------------------------
	enum
	{
		ds_Manual = 0,
		ds_Auto = 1
	};

	//------------------------------------------------
	// Define FALSE/TRUE Type
	//------------------------------------------------
	enum
	{
		ds_FALSE = 0,
		ds_TRUE = 1
	};

	//------------------------------------------------
	// Define Cordic Type
	//------------------------------------------------
	typedef enum
	{
		ds_Cordic_VectorMode = 0,
		ds_Cordic_RotateMode = 1
	} dsALG_Cordic_Type;

	//------------------------------------------------
	// Define Cordic Type
	//------------------------------------------------
	typedef enum
	{
		ds_Trigg_Internal = 0,
		ds_Trigg_GPS = 1
	} dsALG_Trigg_Type;
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif // #ifndef __DS_ALG_DEFS_H__
