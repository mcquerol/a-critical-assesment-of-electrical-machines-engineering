#include "__cf_machinelab.h"
#include "rt_logging_mmi.h"
#include "machinelab_capi.h"
#include <math.h>
#include "machinelab.h"
#include "machinelab_private.h"
#include "machinelab_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.0 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\machinelab\\machinelab_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . cwkwmzg3kn = rtP .
Integrator_IC ; rtX . coaul5w2sn = rtP . DCMachine_Ifinit ; { SimStruct * rts
= ssGetSFunction ( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlStart ( void ) {
{ void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL
) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize
= 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { void * slioCatalogue =
rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "E_Torque" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "E_Torque" )
; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "machinelab/E_Torque" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "E_Torque" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . dkgr2cddwe . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "0d0f93ef-aee6-44c0-99c8-03b7562da470" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. dkgr2cddwe . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . dkgr2cddwe
. AQHandles , "1e-07" , 1.0E-7 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime (
rtDW . dkgr2cddwe . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . dkgr2cddwe . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . dkgr2cddwe . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } } rtDW . dkgr2cddwe . SlioLTF = ( NULL ) ; {
void * treeVector = ( NULL ) ; void * accessor = ( NULL ) ; const void *
signalDescriptor = ( NULL ) ; void * loggingInterval = ( NULL ) ; char *
datasetName = "tmp_raccel_logsout" ; if ( slioCatalogue && rtwIsLoggingToFile
( slioCatalogue ) ) { treeVector = rtwGetTreeVector ( ) ; { int_T
sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode ( 0 , "E_Torque" , "linear" , 0 ,
( unsigned int * ) sigDimsArray , 1 , "double" , "" , "1e-07" , 1.0E-7 ,
ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "E_Torque" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath , "machinelab/E_Torque" , 1 , 0
, slioCatalogue , ( NULL ) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( )
) { sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"machinelab/E_Torque" , 1 , "E_Torque" ) ; } if ( rtwLoggingOverride (
signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS ( rtS ) -> mdlInfo ->
rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval ( ssGetRootSS ( rtS )
-> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . dkgr2cddwe . SlioLTF = accessor ;
} } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"RPM" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "RPM" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "machinelab/RPM" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "RPM" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . hhtkb2ohjl . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "185967a0-2522-4d50-902d-4039f7341a4d" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. hhtkb2ohjl . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . hhtkb2ohjl
. AQHandles , "1e-07" , 1.0E-7 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime (
rtDW . hhtkb2ohjl . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . hhtkb2ohjl . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . hhtkb2ohjl . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } } rtDW . hhtkb2ohjl . SlioLTF = ( NULL ) ; {
void * treeVector = ( NULL ) ; void * accessor = ( NULL ) ; const void *
signalDescriptor = ( NULL ) ; void * loggingInterval = ( NULL ) ; char *
datasetName = "tmp_raccel_logsout" ; if ( slioCatalogue && rtwIsLoggingToFile
( slioCatalogue ) ) { treeVector = rtwGetTreeVector ( ) ; { int_T
sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode ( 0 , "RPM" , "linear" , 0 , (
unsigned int * ) sigDimsArray , 1 , "double" , "" , "1e-07" , 1.0E-7 ,
ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "RPM" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath , "machinelab/RPM" , 1 , 0 ,
slioCatalogue , ( NULL ) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) )
{ sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"machinelab/RPM" , 1 , "RPM" ) ; } if ( rtwLoggingOverride ( signalDescriptor
, slioCatalogue ) ) { if ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) {
loggingInterval = rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo ->
rtwLogInfo ) ; } else { loggingInterval = sdiGetLoggingIntervals (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; datasetName = "" ; }
accessor = rtwGetAccessor ( signalDescriptor , loggingInterval ) ;
rtwAddR2Client ( accessor , signalDescriptor , slioCatalogue , datasetName ,
1 ) ; rtDW . hhtkb2ohjl . SlioLTF = accessor ; } } } } rtB . b4jg5qsci2 = rtP
. u00V_Amplitude ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnStart
( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct
* rts = ssGetSFunction ( rtS , 1 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T cqaqemnyqg ; real_T fffdwdzjom ; rtB .
ktalma0oac = rtX . cwkwmzg3kn ; cqaqemnyqg = rtX . coaul5w2sn ; rtB .
b30kdd5lyw = rtB . ktalma0oac * rtX . coaul5w2sn ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnOutputs ( rts , 0 ) ; } rtB . i24zaqcf4y =
rtP . donotdeletethisgain_Gain * rtB . bs0ibbwun2 [ 0 ] ; rtB . axnznxzwpp =
rtP . donotdeletethisgain_Gain_pkhopsoosh * rtB . bs0ibbwun2 [ 1 ] ;
fffdwdzjom = rtB . axnznxzwpp * cqaqemnyqg ; rtB . hqeqn5dkli = rtP .
E_Torque_Gain * fffdwdzjom ; rtB . oz2lj4bjyl = rtB . ktalma0oac * rtB .
hqeqn5dkli ; rtB . lyw0ltjhfd = rtB . axnznxzwpp * rtB . i24zaqcf4y ; rtB .
ernhz1ryas = rtB . oz2lj4bjyl / rtB . lyw0ltjhfd * rtP . Gain1_Gain ; rtB .
jwfyf5irzt = rtP . donotdeletethisgain_Gain_cd1x1ng35r * rtB . au052vs3tz [ 1
] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( ( rtDW . dkgr2cddwe .
AQHandles || rtDW . dkgr2cddwe . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . dkgr2cddwe . AQHandles , rtDW . dkgr2cddwe .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . hqeqn5dkli + 0 )
; } } } rtB . gqonqebseb = rtP . RPM_Gain * rtB . ktalma0oac ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( ( rtDW . hhtkb2ohjl . AQHandles ||
rtDW . hhtkb2ohjl . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . hhtkb2ohjl . AQHandles , rtDW . hhtkb2ohjl .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . gqonqebseb + 0 )
; } } } rtB . hdkxcatxsn = ( ( fffdwdzjom - rtP . torque_in ) - ( rtP .
CoulombTfViscousBmwFrictionTorques_offset * muDoubleScalarSign ( rtB .
ktalma0oac ) + rtP . CoulombTfViscousBmwFrictionTorques_gain * rtB .
ktalma0oac ) ) * rtP . Gain2_Gain ; rtB . faqpvtnhw1 = ( rtP .
Fieldarmaturemutualinductance_Gain * rtB . jwfyf5irzt - cqaqemnyqg ) * rtP .
Gain1_Gain_pgyo0kriob ; rtB . fu5d2eko22 = rtP .
donotdeletethisgain_Gain_apk3shealt * rtB . au052vs3tz [ 0 ] ;
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) { rtB .
b4jg5qsci2 = rtP . u00V_Amplitude ; rtB . fq1a4cq0jk = rtP .
u00V_Amplitude_e2esohy1ez ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnUpdate (
rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnUpdate ( rts , 0 ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } UNUSED_PARAMETER ( tid ) ;
} void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> cwkwmzg3kn = rtB . hdkxcatxsn ; _rtXdot -> coaul5w2sn =
rtB . faqpvtnhw1 ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; real_T *
sfcndX_fx = ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) -> bwn3gsxr5c ;
ssSetdX ( rts , sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if ( ssGetErrorStatus
( rts ) != ( NULL ) ) return ; } { SimStruct * rts = ssGetSFunction ( rtS , 1
) ; real_T * sfcndX_fx = ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) ->
jck5l4tuso ; ssSetdX ( rts , sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlProjection ( void
) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnProjection ( rts ) ;
if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnProjection ( rts ) ; if ( ssGetErrorStatus (
rts ) != ( NULL ) ) return ; } } void MdlTerminate ( void ) { { SimStruct *
rts = ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } { SimStruct *
rts = ssGetSFunction ( rtS , 1 ) ; sfcnTerminate ( rts ) ; } { if ( rtDW .
dkgr2cddwe . AQHandles ) { sdiTerminateStreaming ( & rtDW . dkgr2cddwe .
AQHandles ) ; } if ( rtDW . dkgr2cddwe . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . dkgr2cddwe . SlioLTF ) ; } } { if ( rtDW
. hhtkb2ohjl . AQHandles ) { sdiTerminateStreaming ( & rtDW . hhtkb2ohjl .
AQHandles ) ; } if ( rtDW . hhtkb2ohjl . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . hhtkb2ohjl . SlioLTF ) ; } } if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 69 ) ; ssSetNumBlockIO ( rtS , 17 ) ;
ssSetNumBlockParams ( rtS , 374 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 1.0E-7 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 769218363U ) ;
ssSetChecksumVal ( rtS , 1 , 1447883138U ) ; ssSetChecksumVal ( rtS , 2 ,
927670333U ) ; ssSetChecksumVal ( rtS , 3 , 3409417459U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
machinelab_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "machinelab" ) ;
ssSetPath ( rtS , "machinelab" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 5.0 ) ; ssSetStepSize ( rtS , 1.0E-7 ) ; ssSetFixedStepSize ( rtS ,
1.0E-7 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3 ;
static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 4 ] ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode3" ) ; ssSetVariableStepSolver ( rtS , 0 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
ssSetSolverStateProjection ( rtS , 1 ) ; ( void ) memset ( ( void * ) &
mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ; ssSetModelMethods2 ( rtS , &
mdlMethods2 ) ; ( void ) memset ( ( void * ) & mdlMethods3 , 0 , sizeof (
mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , & mdlMethods3 ) ;
ssSetModelProjection ( rtS , MdlProjection ) ; ssSetSolverMassMatrixType (
rtS , ( ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS ,
INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 769218363U ) ;
ssSetChecksumVal ( rtS , 1 , 1447883138U ) ; ssSetChecksumVal ( rtS , 2 ,
927670333U ) ; ssSetChecksumVal ( rtS , 3 , 3409417459U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } ssSetNumSFunctions ( rtS , 2 ) ; { static SimStruct
childSFunctions [ 2 ] ; static SimStruct * childSFunctionPtrs [ 2 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction (
rtS , 0 , & childSFunctions [ 0 ] ) ; ssSetSFunction ( rtS , 1 , &
childSFunctions [ 1 ] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static
int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof
( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 1 ] ;
_ssSetNumInputPorts ( rts , 1 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static struct _ssInPortUnit inputPortUnits [ 1 ] ;
_ssSetPortInfo2ForInputUnits ( rts , & inputPortUnits [ 0 ] ) ; }
ssSetInputPortUnit ( rts , 0 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 1 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [ 0 ] = &
rtB . fq1a4cq0jk ; sfcnUPtrs [ 1 ] = & rtB . b30kdd5lyw ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 2 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 2 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . bs0ibbwun2 )
) ; } } ssSetContStates ( rts , & rtX . bwn3gsxr5c ) ; ssSetModelName ( rts ,
"State-Space" ) ; ssSetPath ( rts ,
"machinelab/powergui/EquivalentModel1/State-Space" ) ; if ( ssGetRTModel (
rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
StateSpace_P1_Size ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP .
StateSpace_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP .
StateSpace_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP .
StateSpace_P4_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . cth5x4xh3p
[ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . kwzynvnzgb [ 0 ] ) ;
ssSetPWork ( rts , ( void * * ) & rtDW . nwzbaefmky [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 3 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 2 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
cth5x4xh3p [ 0 ] ) ; ssSetDWorkWidth ( rts , 1 , 23 ) ; ssSetDWorkDataType (
rts , 1 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork
( rts , 1 , & rtDW . kwzynvnzgb [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 22 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . nwzbaefmky [ 0 ] ) ; }
sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged (
rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } { SimStruct
* rts = ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ] ; static
time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( (
void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void
* ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 1 ] ;
_ssSetNumInputPorts ( rts , 1 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static struct _ssInPortUnit inputPortUnits [ 1 ] ;
_ssSetPortInfo2ForInputUnits ( rts , & inputPortUnits [ 0 ] ) ; }
ssSetInputPortUnit ( rts , 0 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 1 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = &
rtB . b4jg5qsci2 ; ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidth ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 2 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . au052vs3tz )
) ; } } ssSetContStates ( rts , & rtX . jck5l4tuso ) ; ssSetModelName ( rts ,
"State-Space" ) ; ssSetPath ( rts ,
"machinelab/powergui/EquivalentModel2/State-Space" ) ; if ( ssGetRTModel (
rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
StateSpace_P1_Size_adoog3rqvr ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * )
rtP . StateSpace_P2_Size_paopbwwf1f ) ; ssSetSFcnParam ( rts , 2 , ( mxArray
* ) rtP . StateSpace_P3_Size_go4kcbs35n ) ; ssSetSFcnParam ( rts , 3 , (
mxArray * ) rtP . StateSpace_P4_Size_pxbc5xkidw ) ; } ssSetRWork ( rts , (
real_T * ) & rtDW . gncxnacjsz [ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) &
rtDW . pmruhnakvl [ 0 ] ) ; ssSetPWork ( rts , ( void * * ) & rtDW .
cskemfc4uv [ 0 ] ) ; { static struct _ssDWorkRecord dWorkRecord [ 3 ] ;
static struct _ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts ,
dWorkRecord ) ; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork (
rts , 3 ) ; ssSetDWorkWidth ( rts , 0 , 2 ) ; ssSetDWorkDataType ( rts , 0 ,
SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0
, & rtDW . gncxnacjsz [ 0 ] ) ; ssSetDWorkWidth ( rts , 1 , 23 ) ;
ssSetDWorkDataType ( rts , 1 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . pmruhnakvl [ 0 ] ) ;
ssSetDWorkWidth ( rts , 2 , 22 ) ; ssSetDWorkDataType ( rts , 2 , SS_POINTER
) ; ssSetDWorkComplexSignal ( rts , 2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW .
cskemfc4uv [ 0 ] ) ; } sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts )
; sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged (
rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
