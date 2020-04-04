#include "__cf_machinelab.h"
#ifndef RTW_HEADER_machinelab_h_
#define RTW_HEADER_machinelab_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef machinelab_COMMON_INCLUDES_
#define machinelab_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "machinelab_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME machinelab
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (17) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ktalma0oac ; real_T b30kdd5lyw ; real_T bs0ibbwun2 [
2 ] ; real_T au052vs3tz [ 2 ] ; real_T i24zaqcf4y ; real_T axnznxzwpp ;
real_T hqeqn5dkli ; real_T oz2lj4bjyl ; real_T lyw0ltjhfd ; real_T ernhz1ryas
; real_T jwfyf5irzt ; real_T gqonqebseb ; real_T hdkxcatxsn ; real_T
faqpvtnhw1 ; real_T fu5d2eko22 ; real_T b4jg5qsci2 ; real_T fq1a4cq0jk ; } B
; typedef struct { real_T cth5x4xh3p [ 2 ] ; real_T gncxnacjsz [ 2 ] ; void *
nwzbaefmky [ 22 ] ; void * cskemfc4uv [ 22 ] ; struct { void * AQHandles ;
void * SlioLTF ; } dkgr2cddwe ; struct { void * AQHandles ; void * SlioLTF ;
} hhtkb2ohjl ; int_T kwzynvnzgb [ 23 ] ; int_T pmruhnakvl [ 23 ] ; } DW ;
typedef struct { real_T cwkwmzg3kn ; real_T coaul5w2sn ; real_T bwn3gsxr5c ;
real_T jck5l4tuso ; } X ; typedef struct { real_T cwkwmzg3kn ; real_T
coaul5w2sn ; real_T bwn3gsxr5c ; real_T jck5l4tuso ; } XDot ; typedef struct
{ boolean_T cwkwmzg3kn ; boolean_T coaul5w2sn ; boolean_T bwn3gsxr5c ;
boolean_T jck5l4tuso ; } XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi
; } DataMapInfo ; struct P_ { real_T torque_in ; real_T u00V_Amplitude ;
real_T u00V_Amplitude_e2esohy1ez ; real_T DCMachine_Ifinit ; real_T
CoulombTfViscousBmwFrictionTorques_gain ; real_T
CoulombTfViscousBmwFrictionTorques_offset ; real_T Integrator_IC ; real_T
StateSpace_P1_Size [ 2 ] ; real_T StateSpace_P1 [ 21 ] ; real_T
StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2 [ 4 ] ; real_T
StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P3 ; real_T StateSpace_P4_Size [
2 ] ; real_T StateSpace_P4 [ 154 ] ; real_T StateSpace_P1_Size_adoog3rqvr [ 2
] ; real_T StateSpace_P1_dkwwqo4but [ 18 ] ; real_T
StateSpace_P2_Size_paopbwwf1f [ 2 ] ; real_T StateSpace_P2_bxxikatvaj [ 4 ] ;
real_T StateSpace_P3_Size_go4kcbs35n [ 2 ] ; real_T StateSpace_P3_jszlhufy1b
; real_T StateSpace_P4_Size_pxbc5xkidw [ 2 ] ; real_T
StateSpace_P4_gpsr2nnnp1 [ 138 ] ; real_T donotdeletethisgain_Gain ; real_T
donotdeletethisgain_Gain_pkhopsoosh ; real_T E_Torque_Gain ; real_T
Gain1_Gain ; real_T donotdeletethisgain_Gain_cd1x1ng35r ; real_T RPM_Gain ;
real_T Gain2_Gain ; real_T Fieldarmaturemutualinductance_Gain ; real_T
Gain1_Gain_pgyo0kriob ; real_T donotdeletethisgain_Gain_apk3shealt ; } ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX
; extern DW rtDW ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo
* machinelab_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
