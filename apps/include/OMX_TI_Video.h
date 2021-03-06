/*
 *  Copyright (c) 2010-2011, Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  Contact information for paper mail:
 *  Texas Instruments
 *  Post Office Box 655303
 *  Dallas, Texas 75265
 *  Contact information:
 *  http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
 *  DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
 *  ============================================================================
 *
 */


/* -------------------------------------------------------------------------- */
/*
 * @file:Omx_ti_video.h
 * This header defines the structures specific to the param or config indices of Openmax Video Component.
 *
 * @path:
 * \ti\omx\interfaces\openMaxv11\
 * -------------------------------------------------------------------------- */


#ifndef OMX_TI_VIDEO_H
#define OMX_TI_VIDEO_H
#define H264ENC_MAXNUMSLCGPS 2

#include "OMX_Core.h"

#ifdef _VIDEO_M3_DYNAMIC_CONFIG
#include <ti/sdo/ce/video2/videnc2.h>
#include <ti/sdo/ce/video3/viddec3.h>
#ifdef CODEC_H264ENC
#include "ih264enc.h"
//#include <ti/sdo/codecs/h264enc/ih264enc.h>
#endif
#ifdef CODEC_H264DEC
#include "ih264vdec.h"
#endif
#ifdef CODEC_MPEG2DEC
#include "impeg2vdec.h"
#endif
#ifdef CODEC_MPEG2ENC
#include <ittiam/codecs/mpeg2enc/impeg2enc_ittiam.h>
#endif
#ifdef CODEC_MPEG4DEC
#include "impeg4vdec.h"
#endif
#ifdef CODEC_MPEG4ENC
#include "impeg4enc.h"
#endif
#ifdef CODEC_VC1DEC
#include "ivc1vdec.h"
#endif 
#ifdef CODEC_MJPEGDEC
#include "ijpegvdec.h"
#endif 
#endif

/** 
 *	@brief	mode selection for the data that is given to the Codec
 */

typedef enum OMX_VIDEO_DATASYNCMODETYPE {
    OMX_Video_FixedLength,	//!<  Interms of multiples of 4K 
    OMX_Video_SliceMode,		//!<  Slice mode 
    OMX_Video_NumMBRows,	//!< Number of rows, each row is 16 lines of video 
    OMX_Video_EntireFrame,  	//!< Processing of entire frame data 
    OMX_Video_DataSyncModeType_Max  	= 0x7FFFFFFF
} OMX_VIDEO_DATASYNCMODETYPE;


/* ========================================================================== */
/*!
 @brief OMX_TI_VIDEO_PARAM_DATAMODE  :to configure how the input and output data is fed to the Codec 
 @param  nPortIndex  to specify the index of the port
 @param  eDataMode 	to specify the data mode	
 						@sa  OMX_VIDEO_DATASYNCMODETYPE
 @param  nNumDataUnits	 to specify the number of data units (where units are of type defined by eDataMode) 
 */
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_DATASYNCMODETYPE{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_VIDEO_DATASYNCMODETYPE eDataMode;
	OMX_U32 nNumDataUnits;	
} OMX_VIDEO_PARAM_DATASYNCMODETYPE;

/** 
 *	@brief	Aspect Ratio type selection for the encoded bit stream 
 */
typedef enum OMX_VIDEO_ASPECTRATIOTYPE{		
	OMX_Video_AR_Unspecified,  //!< Unspecified aspect ratio
	OMX_Video_AR_Square ,  //!< 1:1 (square) aspect ratio
	OMX_Video_AR_12_11  ,  //!<  12:11  aspect ratio
	OMX_Video_AR_10_11  ,  //!<  10:11  aspect ratio
	OMX_Video_AR_16_11  ,  //!<  16:11  aspect ratio
	OMX_Video_AR_40_33  ,  //!<  40:33  aspect ratio
	OMX_Video_AR_24_11  ,  //!<  24:11  aspect ratio
	OMX_Video_AR_20_11  ,  //!<  20:11  aspect ratio
	OMX_Video_AR_32_11  ,  //!<  32:11  aspect ratio
	OMX_Video_AR_80_33  ,  //!<  80:33  aspect ratio
	OMX_Video_AR_18_11  ,  //!<  18:11  aspect ratio
	OMX_Video_AR_15_15  ,  //!<  15:15  aspect ratio
	OMX_Video_AR_64_33  ,  //!<  64:33  aspect ratio
	OMX_Video_AR_160_99 ,  //!<  160:99 aspect ratio
	OMX_Video_AR_4_3    ,  //!<  4:3    aspect ratio
	OMX_Video_AR_3_2    ,  //!<  3:2    aspect ratio
	OMX_Video_AR_2_1    ,  //!<  2:1    aspect ratio  
	OMX_Video_AR_Extended = 255,       //!<  Extended aspect ratio 
  OMX_Video_AR_Max = 0x7FFFFFFF
}OMX_VIDEO_ASPECTRATIOTYPE;


/* ========================================================================== */
/*!
 @brief OMX_TI_VIDEO_PARAM_VUI_SELECT  :to select the VUI Settings
 @param  bAspectRatioPresent flag to indicate the insertion of aspect ratio information in VUI part of bit-stream
 @param  ePixelAspectRatio to specify the Aspect Ratio
 @param  bFullRange to indicate whether pixel value range is specified as full range or not (0 to 255)
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_VUIINFOTYPE {			
	OMX_U32	 nSize;	
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;	
	OMX_BOOL bAspectRatioPresent;
	OMX_VIDEO_ASPECTRATIOTYPE ePixelAspectRatio;
	OMX_BOOL bFullRange;	
}OMX_VIDEO_PARAM_VUIINFOTYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_CONFIG_PIXELINFOTYPE  :to specify the information related to the input pixel data (aspect ratio & range) to the Codec
 										so that codec can incorporate this info in the coded bit stream
 @param  nWidth 	 to specify the Aspect ratio: width of the pixel	 						
 @param  nHeight 	 to specify the Aspect ratio: height of the pixel 					 	
 */
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_CONFIG_PIXELINFOTYPE  {
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_U32 nWidth;
	OMX_U32 nHeight;	
} OMX_VIDEO_CONFIG_PIXELINFOTYPE;

/** 
 *	@brief	bit stream format type selection for the encoded bit stream 
 */
typedef enum OMX_VIDEO_AVCBITSTREAMFORMATTYPE{		
	OMX_Video_BitStreamFormatByte=0,	//!<  BYTE stream Format
	OMX_Video_BitStreamFormatNAL=1,	//!<  NAL Unit Format
  OMX_Video_BitStreamFormat = 0x7FFFFFFF
}OMX_VIDEO_AVCBITSTREAMFORMATTYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_PARAM_BITSTREAMFORMATTYPE  :to select the bit stream format for the encoded data
 @param  eStreamFormat 	 to specify bit stream format type 
 							@sa  OMX_VIDEO_AVCBITSTREAMFORMATTYPE
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_AVCBITSTREAMFORMATTYPE {			
	OMX_U32	 nSize;	
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;	
	OMX_VIDEO_AVCBITSTREAMFORMATTYPE	eStreamFormat;	
}OMX_VIDEO_PARAM_AVCBITSTREAMFORMATTYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_PARAM_AVCNALUCONTROLTYPE : to configure what NALU  need to send along the frames of different types (Intra,IDR...etc)
 @param  nStartofSequence 	to configure the different NALU (specified via enabling/disabling (1/0) the bit positions) that need to send along with the Start of sequence frame 	 						
 @param  nEndofSequence	 	to to configure the different NALU (specified via enabling/disabling (1/0) the bit positions) that need to send along with the End of sequence frame 	 										 	
 @param  nIDR 				to to configure the different NALU (specified via enabling/disabling (1/0) the bit positions) that need to send along with the IDR frame 	 						
 @param  nIntraPicture	  		to to configure the different NALU (specified via enabling/disabling (1/0) the bit positions) that need to send along with the Intra frame 	 						
 @param  nNonIntraPicture	  	to to configure the different NALU (specified via enabling/disabling (1/0) the bit positions) that need to send along with the Non Intra frame 	 						

Bit Position:   13|       12|      11|           10|      9|    8|    7|   6|      5|         4|              3|              2|              1|          0
NALU TYPE:  SPS_VUI|FILLER|EOSTREAM|EOSEQ|AUD|PPS|SPS|SEI|IDR_SLICE|SLICE_DP_C|SLICE_DP_B|SLICE_DP_A|SLICE|UNSPECIFIED \n 
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_AVCNALUCONTROLTYPE {			
	OMX_U32	 nSize;	
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 	nPortIndex;		
	OMX_U32 	nStartofSequence;	
	OMX_U32 	nEndofSequence;	
	OMX_U32 	nIDR;
	OMX_U32 	nIntraPicture;
	OMX_U32 	nNonIntraPicture;	
}OMX_VIDEO_PARAM_AVCNALUCONTROLTYPE;


/* ========================================================================== */
/*!
 @brief OMX_VIDEO_CONFIG_MESEARCHRANGETYPE : to configure Motion Estimation Parameters
 @param  eMVAccuracy 		to specify the Motion Vector Accuracy
 							@sa OMX_VIDEO_MOTIONVECTORTYPE
 @param  sHorSearchRangeP	 	to Specify the Horizontal Search range for P Frame
 @param  sVerSearchRangeP		to Specify the Vertical Search range for P Frame
 @param  sHorSearchRangeB	  	to Specify the Horizontal Search range for B Frame
 @param  sVerSearchRangeB	  	to Specify the Vertical Search range for B Frame
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_CONFIG_MESEARCHRANGETYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;
	OMX_VIDEO_MOTIONVECTORTYPE eMVAccuracy;
	OMX_U32	 nHorSearchRangeP;
	OMX_U32	 nVerSearchRangeP;
	OMX_U32	 nHorSearchRangeB;
	OMX_U32	 nVerSearchRangeB;
}OMX_VIDEO_CONFIG_MESEARCHRANGETYPE;

/** 
 *	@brief	Block size specification 
 */
typedef enum OMX_VIDEO_BLOCKSIZETYPE {	
	OMX_Video_Block_Size_16x16=0,	
	OMX_Video_Block_Size_8x8,
	OMX_Video_Block_Size_8x4,
	OMX_Video_Block_Size_4x8,	
	OMX_Video_Block_Size_4x4,	
  OMX_Video_Block_Size_Max = 0x7FFFFFFF
}OMX_VIDEO_BLOCKSIZETYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_PARAM_MEBLOCKSIZETYPE : to configure the Min Motion Estimation block size for P and B frames
 @param  eMinBlockSizeP 		to specify the Min Block size used for Motion Estimation incase of P Frames
 							@sa OMX_VIDEO_BLOCKSIZETYPE
 @param  eMinBlockSizeB	 	to specify the Min Block size used for Motion Estimation incase of B Frames
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_MEBLOCKSIZETYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;
	OMX_VIDEO_BLOCKSIZETYPE eMinBlockSizeP;
	OMX_VIDEO_BLOCKSIZETYPE eMinBlockSizeB;
}OMX_VIDEO_PARAM_MEBLOCKSIZETYPE;

/** 
 *	@brief	to select the chroma component used for Intra Prediction 
 */
typedef enum OMX_VIDEO_CHROMACOMPONENTTYPE {	
	OMX_Video_Chroma_Component_Cr_Only=0,	//!< consider only Cr chroma component for Intra prediction
	OMX_Video_Chroma_Component_Cb_Cr_Both,  //!< consider both (Cb & Cr) chroma components for Intra prediction		
  OMX_Video_Chroma_Component_Max = 0x7FFFFFFF
}OMX_VIDEO_CHROMACOMPONENTTYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_PARAM_INTRAPREDTYPE : to configure the Modes for the different block sizes during Intra Prediction
 @param  nLumaIntra4x4Enable 	 	to configure the Modes for 4x4 block size during luma intra prediction: bit position specifies the modes that are enabled/disabled
								 HOR_UP|VERT_LEFT|HOR_DOWN|VERT_RIGHT|DIAG_DOWN_RIGHT|DIAG_DOWN_LEFT|DC|HOR|VER
 @param  nLumaIntra8x8Enable	 	to configure the Modes for 4x4 block size during luma intra prediction
 								HOR_UP|VERT_LEFT|HOR_DOWN|VERT_RIGHT|DIAG_DOWN_RIGHT|DIAG_DOWN_LEFT|DC|HOR|VER
 @param  nLumaIntra16x16Enable	 	to configure the Modes for 4x4 block size during luma intra prediction
								 PLANE|DC|HOR|VER
 @param  nChromaIntra8x8Enable	 	to configure the Modes for 4x4 block size during luma intra prediction
								 PLANE|DC|HOR|VER
 @param  eChromaComponentEnable	to select the chroma components used for the intra prediction
 								@sa OMX_VIDEO_CHROMACOMPONENTTYPE
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_INTRAPREDTYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;
	OMX_U32	 nLumaIntra4x4Enable;	
	OMX_U32 nLumaIntra8x8Enable;	
	OMX_U32 nLumaIntra16x16Enable; 
	OMX_U32 nChromaIntra8x8Enable;
	OMX_VIDEO_CHROMACOMPONENTTYPE eChromaComponentEnable;
}OMX_VIDEO_PARAM_INTRAPREDTYPE;


/** 
 *	@brief	Encoding Mode Preset 
 */
typedef enum OMX_VIDEO_ENCODING_MODE_PRESETTYPE {	
	OMX_Video_Enc_Default=0, 	//!<  for all the params default values are taken
	OMX_Video_Enc_High_Quality, //!<  todo: mention the parameters that takes specific values depending on this selection
	OMX_Video_Enc_User_Defined,
	OMX_Video_Enc_High_Speed_Med_Quality,
	OMX_Video_Enc_Med_Speed_Med_Quality,
	OMX_Video_Enc_Med_Speed_High_Quality,
	OMX_Video_Enc_High_Speed,
  OMX_Video_Enc_Max = 0x7FFFFFFF
}OMX_VIDEO_ENCODING_MODE_PRESETTYPE;

/** 
 *	@brief	Rate Control Preset 
 */
typedef enum OMX_VIDEO_RATECONTROL_PRESETTYPE {	
	OMX_Video_RC_Low_Delay,	//!<todo:  mention the parameters that takes specific values depending on this selection
	OMX_Video_RC_Storage,
	OMX_Video_RC_Twopass,
	OMX_Video_RC_None,
	OMX_Video_RC_User_Defined,
  OMX_Video_RC_Max = 0x7FFFFFFF
}OMX_VIDEO_RATECONTROL_PRESETTYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_PARAM_ENCODER_PRESETTYPE : to select the preset for Encoding Mode & Rate Control
 @param  eEncodingModePreset		to specify Encoding Mode Preset
 							@sa OMX_VIDEO_ENCODING_MODE_PRESETTYPE
 @param  eRateControlPreset	to specify Rate Control Preset
 							@sa OMX_VIDEO_RATECONTROL_PRESETTYPE
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_ENCODER_PRESETTYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;	
	OMX_VIDEO_ENCODING_MODE_PRESETTYPE eEncodingModePreset;	
	OMX_VIDEO_RATECONTROL_PRESETTYPE eRateControlPreset;
}OMX_VIDEO_PARAM_ENCODER_PRESETTYPE;


/** 
 *	@brief	 input content type 
 */
typedef enum OMX_VIDEO_FRAMECONTENTTYPE {		
	OMX_Video_Progressive=0,//!<Progressive frame
	OMX_Video_Interlaced=1,//!<Interlaced frame
	OMX_Video_Interlaced_Topfield=2,//!<Interlaced picture, top field
	OMX_Video_Interlaced_Bottomfield=3,	//!<Interlaced picture, bottom field	
  OMX_Video_FrameContentType_Max = 0x7FFFFFFF
}OMX_VIDEO_FRAMECONTENTTYPE;

/** 
 *	@brief	 Specifies the type of interlace content 
 */
typedef enum OMX_VIDEO_INTERLACE_CODINGTYPE {	
	OMX_Video_Interlace_PICAFF	= 0 ,   //!< PicAFF type of interlace coding
	OMX_Video_Interlace_MBAFF,			//!< MBAFF type of interlace coding	    
	OMX_Video_Interlace_Fieldonly,   //!< Field only coding 
	OMX_Video_Interlace_Fieldonly_MRF=OMX_Video_Interlace_Fieldonly,
	OMX_Video_Interlace_Fieldonly_ARF,
	OMX_Video_Interlace_Fieldonly_SPF, 	 //!< Field only coding where codec decides the partiy of the field to be used based upon content									   		
  OMX_Video_Interlace_Max = 0x7FFFFFFF
}OMX_VIDEO_INTERLACE_CODINGTYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_PARAM_FRAMEDATACONTENTTYPE : to configure the data content
 @param  eContentType		to specify Content type
 							@sa OMX_VIDEO_FRAMECONTENTTYPE
 @param  eInterlaceCodingType	to specify the settings of interlace content
 							@sa OMX_VIDEO_INTERLACE_CODINGTYPE
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_FRAMEDATACONTENTTYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;	
	OMX_VIDEO_FRAMECONTENTTYPE eContentType;	
	OMX_VIDEO_INTERLACE_CODINGTYPE eInterlaceCodingType; 
}OMX_VIDEO_PARAM_FRAMEDATACONTENTTYPE;

/** 
 *	@brief	 Specifies Transform Block Size
 */
typedef enum OMX_VIDEO_TRANSFORMBLOCKSIZETYPE {	
	OMX_Video_Transform_Block_Size_4x4 =0,	//!< Transform blocks size is 8x8 : Valid for only High Profile
	OMX_Video_Transform_Block_Size_8x8,	//!< Transform blocks size is 4x4 
	OMX_Video_Transform_Block_Size_Adaptive , //!< Adaptive transform block size : encoder decides as per content
  OMX_Video_Transform_Block_Size_Max = 0x7FFFFFFF
}OMX_VIDEO_TRANSFORMBLOCKSIZETYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_PARAM_TRANSFORM_BLOCKSIZETYPE : to select the Block Size used for transformation
 @param  eTransformBlocksize	to specify Block size used for transformation
 							@sa OMX_VIDEO_TRANSFORMBLOCKSIZETYPE
*/
/* ==========================================================================*/ 

typedef struct OMX_VIDEO_PARAM_TRANSFORM_BLOCKSIZETYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;	
	OMX_VIDEO_TRANSFORMBLOCKSIZETYPE eTransformBlocksize;	
}OMX_VIDEO_PARAM_TRANSFORM_BLOCKSIZETYPE;


/* ========================================================================== */
/*!
 @brief OMX_VIDEO_CONFIG_SLICECODINGTYPE : to configure the Slice Settings 
 @param  eSliceMode	to specify the Slice mode
 							@sa OMX_VIDEO_AVCSLICEMODETYPE
 @param  nSlicesize to specify the sliceSize
*/
/* ==========================================================================*/ 

typedef struct OMX_VIDEO_CONFIG_SLICECODINGTYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;
	OMX_VIDEO_AVCSLICEMODETYPE eSliceMode;
	OMX_U32	 nSlicesize;	
}OMX_VIDEO_CONFIG_SLICECODINGTYPE;

/** 
 *	@brief	 Specifies Slice Group Change Direction Flag
 */
typedef enum OMX_VIDEO_SLIGRPCHANGEDIRTYPE{
  OMX_Video_Raster_Scan             = 0 , //!< 0 : Raster scan order
  OMX_Video_Clockwise              = 0 , //!< 0 : Clockwise (used for BOX OUT FMO Params)
  OMX_Video_Right                   = 0 , //!< 0 : RIGHT (Used for Wipe FMO type)
  OMX_Video_Reverse_Raster_Scan= 1 , //!< 1 : Reverse Raster Scan Order
  OMX_Video_Counter_Clockwise       = 1 , //!< 1 : Counter Clockwise (used for BOX OUT FMO Params)
  OMX_Video_Left                    = 1 ,  //!< 1 : LEFT (Used for Wipe FMO type)
  OMX_Video_SliceGrpcChangedIrType_Max = 0x7FFFFFFF
} OMX_VIDEO_SLICEGRPCHANGEDIRTYPE;

/* ========================================================================== */
/*!
 @brief OMX_TI_VIDEO_PARAM_FMO_ADVANCEDSETTINGS : to configure the FMO Settings
 @param  
*/
/* ==========================================================================*/ 
typedef struct OMX_VIDEO_PARAM_AVCADVANCEDFMOTYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;	
	OMX_U8 nNumSliceGroups;
	OMX_U8 nSliceGroupMapType; 
	OMX_VIDEO_SLICEGRPCHANGEDIRTYPE eSliceGrpChangeDir; 
	OMX_U32 nSliceGroupChangeRate; 
	OMX_U32 nSliceGroupChangeCycle; 
	OMX_U32 nSliceGroupParams[H264ENC_MAXNUMSLCGPS] ;  
}OMX_VIDEO_PARAM_AVCADVANCEDFMOTYPE;

/* ========================================================================== */
/*!
 @brief OMX_TI_VIDEO_CONFIG_QPSETTINGS : to configure the Qp Settings of I, P &B Frames
 @param  nQpI	
*/
/* ==========================================================================*/ 

typedef struct OMX_VIDEO_CONFIG_QPSETTINGSTYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32	 nPortIndex;
	OMX_U32	 nQpI;
	OMX_U32	 nQpMaxI;
	OMX_U32	 nQpMinI;
	OMX_U32	 nQpP;
	OMX_U32	 nQpMaxP;
	OMX_U32	 nQpMinP;
	OMX_U32	 nQpOffsetB;
	OMX_U32	 nQpMaxB;
	OMX_U32	 nQpMinB;
}OMX_VIDEO_CONFIG_QPSETTINGSTYPE;

#ifdef _VIDEO_M3_DYNAMIC_CONFIG
/** 
 * Custom Param for Codec Static Params (Create-time parameters)
 * NOTE: This will be used in OMX_SetParameter
 * STRUCT MEMBERS:
 *  nSize      : Size of the structure in bytes
 *  nVersion   : OMX specification version information
 *  nPortIndex : Port that this structure applies to
 *  videoStaticParams : Specifies the create time parameters for the codecs
 */
typedef union videoStaticParams {
#ifdef CODEC_H264ENC
    IH264ENC_Params h264EncStaticParams;
#endif
#ifdef CODEC_H264DEC
    IH264VDEC_Params h264DecStaticParams;
#endif
#ifdef CODEC_MPEG2DEC
    IMPEG2VDEC_Params mpeg2DecStaticParams;
#endif
#ifdef CODEC_MPEG2ENC
    impeg2enc_itt_params mpeg2EncStaticParams;
#endif
#ifdef CODEC_MPEG4ENC
    IMPEG4ENC_Params mpeg4EncStaticParams;
#endif
#ifdef CODEC_MPEG4DEC
    IMPEG4VDEC_Params mpeg4DecStaticParams;
#endif
#ifdef CODEC_MJPEGDEC
    IJPEGVDEC_Params mjpegDecStaticParams;
#endif
#ifdef CODEC_VC1DEC
    IVC1VDEC_Params  vc1DecStaticParams;
#endif

} uVideoStaticParams;
typedef struct OMX_VIDEO_PARAM_STATICPARAMS {
    OMX_U32 nSize; 
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    uVideoStaticParams videoStaticParams;
} OMX_VIDEO_PARAM_STATICPARAMS;
/* To allow CONFIG/PARAM to be used interchangeably */
#define OMX_VIDEO_CONFIG_STATICPARAMS OMX_VIDEO_PARAM_STATICPARAMS

/** 
 * Custom Param for Codec Dynamic Params (Run-time parameters)
 * NOTE: This will be used in OMX_SetParameter
 * STRUCT MEMBERS:
 *  nSize      : Size of the structure in bytes
 *  nVersion   : OMX specification version information
 *  nPortIndex : Port that this structure applies to
 *  videoDynamicParams : Specifies the run time parameters for the codecs
 */
typedef union videoDynamicParams {
#ifdef CODEC_H264ENC
    IH264ENC_DynamicParams h264EncDynamicParams;
#endif
#ifdef CODEC_H264DEC
    IH264VDEC_DynamicParams h264DecDynamicParams;
#endif
#ifdef CODEC_MPEG2DEC
    IMPEG2VDEC_DynamicParams mpeg2DecDynamicParams;
#endif
#ifdef CODEC_MPEG2ENC
    impeg2enc_itt_dynamicparams mpeg2EncDynamicParams;
#endif
#ifdef CODEC_MPEG4ENC
    IMPEG4ENC_DynamicParams mpeg4EncDynamicParams;
#endif
#ifdef CODEC_MPEG4DEC
    IMPEG4VDEC_DynamicParams mpeg4DecDynamicParams;
#endif
#ifdef CODEC_MJPEGDEC
    IJPEGVDEC_DynamicParams mjpegDecDynamicParams;
#endif
#ifdef CODEC_VC1DEC
    IVC1VDEC_DynamicParams  vc1DecDynamicParams;
#endif

} uVideoDynamicParams;
typedef struct OMX_VIDEO_PARAM_DYNAMICPARAMS {
    OMX_U32 nSize; 
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    uVideoDynamicParams videoDynamicParams;
} OMX_VIDEO_PARAM_DYNAMICPARAMS;
/* To allow CONFIG/PARAM to be used interchangeably */
#define OMX_VIDEO_CONFIG_DYNAMICPARAMS OMX_VIDEO_PARAM_DYNAMICPARAMS

/** 
 * Custom Param for Codec Status Params (query execution parameters)
 * NOTE: This will be used in OMX_GetParameter
 * STRUCT MEMBERS:
 *  nSize      : Size of the structure in bytes
 *  nVersion   : OMX specification version information
 *  nPortIndex : Port that this structure applies to
 *  videoStatus : Used for querying run time parameters for the codecs
 */
typedef union videoStatus {
#ifdef CODEC_H264ENC
    IH264ENC_Status h264EncStatus;
#endif
#ifdef CODEC_H264DEC
    IH264VDEC_Status h264DecStatus;
#endif
#ifdef CODEC_MPEG2DEC
    IMPEG2VDEC_Status mpeg2DecStatus;
#endif
#ifdef CODEC_MPEG2ENC
    impeg2enc_itt_status mpeg2EncStatus;
#endif
#ifdef CODEC_MPEG4ENC
    IMPEG4ENC_Status mpeg4EncStatus;
#endif
} uVideoStatus;
typedef struct OMX_VIDEO_PARAM_STATUS {
    OMX_U32 nSize; 
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    uVideoStatus videoStatus;
} OMX_VIDEO_PARAM_STATUS;
/* To allow CONFIG/PARAM to be used interchangeably */
#define OMX_VIDEO_CONFIG_STATUS OMX_VIDEO_PARAM_STATUS
#endif

/** 
 * Custom Tunnel for Dynamic Params
 *
 * STRUCT MEMBERS:
 *  nSize      : Size of the structure in bytes
 *  nVersion   : OMX specification version information
 *  nPortIndex : Port that this structure applies to
 *  eCompressionFormat : Encoder compression format, i.e. encoder type
 */

typedef struct OMX_VIDEO_ENCODER_SET {
    OMX_U32 nSize; 
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_VIDEO_CODINGTYPE eCompressionFormat;
} OMX_VIDEO_ENCODER_SET;


/** OMX_PARAM_TVPSTATUS_TYPE   : valid video or not status for TVP component
 */

typedef struct OMX_PARAM_TVPSTATUS_TYPE {
    OMX_U32 nSize; /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion; /**< OMX specification version information */
    OMX_U32 nPortIndex; /**< Index of the port */
    OMX_BOOL bValidVideo; /**< Flag to enable/disable file mode operation */
    OMX_U32  frameWidth; /**< TVP reported width >**/
    OMX_U32  frameHeight; /**<TVP reported height >***/
} OMX_PARAM_TVPSTATUS_TYPE;

/* ========================================================================== */
/*!
 @brief OMX_VIDEO_CONFIG_GDRINFOTYPE : to configure the Gradual decoder refresh
 @param  enableGDR to specify to enable/disable GDR, default disable
 @param  intraRefreshRateGDRDynamic to specify number of rows to be intra 
            refresh per frame
 @param  gdrOverlapRowsBtwFramesDynamic to specify number of row overlap 
            between successive GDR frame, value less than intraRefreshRateGDRDynamic
*/
/* ==========================================================================*/ 

typedef struct OMX_VIDEO_CONFIG_GDRINFOTYPE{		
	OMX_U32	 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_U32 enableGDR;
	OMX_U32 intraRefreshRateGDRDynamic;
    OMX_U32 gdrOverlapRowsBtwFramesDynamic;	
}OMX_VIDEO_CONFIG_GDRINFOTYPE;

#endif /* OMX_TI_VIDEO_H */

