#include "__cf_machinelab.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "machinelab_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "machinelab.h"
#include "machinelab_capi.h"
#include "machinelab_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"machinelab/E_Torque" ) , TARGET_STRING ( "E_Torque" ) , 0 , 0 , 0 , 0 , 0 }
, { 1 , 0 , TARGET_STRING ( "machinelab/Gain1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "machinelab/RPM" ) ,
TARGET_STRING ( "RPM" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"machinelab/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0
, TARGET_STRING ( "machinelab/Product1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 5 , 0 , TARGET_STRING (
"machinelab/Voltage Measurement/do not delete this gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"machinelab/Voltage Measurement1/do not delete this gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"machinelab/ 200V/Model/DC" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 8 , 0 , TARGET_STRING ( "machinelab/200V/Model/DC" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"machinelab/DC Machine/Electrical model/Gain2" ) , TARGET_STRING ( "A" ) , 0
, 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"machinelab/DC Machine/Electrical model/Integrator" ) , TARGET_STRING ( "w" )
, 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"machinelab/DC Machine/Electrical model/Product" ) , TARGET_STRING ( "E fcem"
) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"machinelab/DC Machine/iA/do not delete this gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"machinelab/DC Machine/iF/do not delete this gain" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"machinelab/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"machinelab/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"machinelab/DC Machine/Electrical model/Voltage constant KE/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 17 , TARGET_STRING ( "machinelab/ 200V" ) ,
TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING (
"machinelab/200V" ) , TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 19 ,
TARGET_STRING ( "machinelab/DC Machine" ) , TARGET_STRING ( "Ifinit" ) , 0 ,
0 , 0 } , { 20 , TARGET_STRING ( "machinelab/E_Torque" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING ( "machinelab/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING (
"machinelab/RPM" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 23 ,
TARGET_STRING ( "machinelab/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"machinelab/Voltage Measurement1/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
 "machinelab/DC Machine/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques"
) , TARGET_STRING ( "offset" ) , 0 , 0 , 0 } , { 26 , TARGET_STRING (
 "machinelab/DC Machine/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques"
) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING (
"machinelab/DC Machine/Electrical model/Gain2" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 28 , TARGET_STRING (
"machinelab/DC Machine/Electrical model/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"machinelab/DC Machine/iA/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 30 , TARGET_STRING (
"machinelab/DC Machine/iF/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"machinelab/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P1" )
, 0 , 2 , 0 } , { 32 , TARGET_STRING (
"machinelab/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P2" )
, 0 , 3 , 0 } , { 33 , TARGET_STRING (
"machinelab/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P3" )
, 0 , 0 , 0 } , { 34 , TARGET_STRING (
"machinelab/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P4" )
, 0 , 4 , 0 } , { 35 , TARGET_STRING (
"machinelab/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P1" )
, 0 , 5 , 0 } , { 36 , TARGET_STRING (
"machinelab/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P2" )
, 0 , 3 , 0 } , { 37 , TARGET_STRING (
"machinelab/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P3" )
, 0 , 0 , 0 } , { 38 , TARGET_STRING (
"machinelab/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P4" )
, 0 , 6 , 0 } , { 39 , TARGET_STRING (
 "machinelab/DC Machine/Electrical model/Voltage constant KE/Field-armature mutual inductance"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"machinelab/DC Machine/Electrical model/Voltage constant KE/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 41 ,
TARGET_STRING ( "torque_in" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } }
;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . hqeqn5dkli , & rtB . ernhz1ryas ,
& rtB . gqonqebseb , & rtB . lyw0ltjhfd , & rtB . oz2lj4bjyl , & rtB .
i24zaqcf4y , & rtB . fu5d2eko22 , & rtB . b4jg5qsci2 , & rtB . fq1a4cq0jk , &
rtB . hdkxcatxsn , & rtB . ktalma0oac , & rtB . b30kdd5lyw , & rtB .
axnznxzwpp , & rtB . jwfyf5irzt , & rtB . bs0ibbwun2 [ 0 ] , & rtB .
au052vs3tz [ 0 ] , & rtB . faqpvtnhw1 , & rtP . u00V_Amplitude , & rtP .
u00V_Amplitude_e2esohy1ez , & rtP . DCMachine_Ifinit , & rtP . E_Torque_Gain
, & rtP . Gain1_Gain , & rtP . RPM_Gain , & rtP . donotdeletethisgain_Gain ,
& rtP . donotdeletethisgain_Gain_apk3shealt , & rtP .
CoulombTfViscousBmwFrictionTorques_offset , & rtP .
CoulombTfViscousBmwFrictionTorques_gain , & rtP . Gain2_Gain , & rtP .
Integrator_IC , & rtP . donotdeletethisgain_Gain_pkhopsoosh , & rtP .
donotdeletethisgain_Gain_cd1x1ng35r , & rtP . StateSpace_P1 [ 0 ] , & rtP .
StateSpace_P2 [ 0 ] , & rtP . StateSpace_P3 , & rtP . StateSpace_P4 [ 0 ] , &
rtP . StateSpace_P1_dkwwqo4but [ 0 ] , & rtP . StateSpace_P2_bxxikatvaj [ 0 ]
, & rtP . StateSpace_P3_jszlhufy1b , & rtP . StateSpace_P4_gpsr2nnnp1 [ 0 ] ,
& rtP . Fieldarmaturemutualinductance_Gain , & rtP . Gain1_Gain_pgyo0kriob ,
& rtP . torque_in , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) }
;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 7 , 3 , 1 , 4 , 7 , 22 , 6 , 3 , 6 ,
23 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 17 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters ,
24 , rtModelParameters , 1 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 769218363U , 1447883138U , 927670333U ,
3409417459U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
machinelab_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void machinelab_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void machinelab_host_InitializeDataMapInfo ( machinelab_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
