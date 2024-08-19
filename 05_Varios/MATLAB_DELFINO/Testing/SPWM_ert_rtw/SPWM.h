/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SPWM.h
 *
 * Code generated for Simulink model 'SPWM'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May 23 15:36:01 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SPWM_h_
#define RTW_HEADER_SPWM_h_
#ifndef SPWM_COMMON_INCLUDES_
#define SPWM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* SPWM_COMMON_INCLUDES_ */

#include <stddef.h>
#include "SPWM_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  real_T Gain3;                        /* '<S1>/Gain3' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S1>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
} B_SPWM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  int32_T PWM2A_FRAC_LEN;              /* '<Root>/PWM2A' */
} DW_SPWM_T;

/* Parameters (default storage) */
struct P_SPWM_T_ {
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 1e-5
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: 2*pi*50
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Gain3_Gain;                   /* Expression: 50
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 50
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Enable_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Enable'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SPWM_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_SPWM_T SPWM_P;

/* Block signals (default storage) */
extern B_SPWM_T SPWM_B;

/* Block states (default storage) */
extern DW_SPWM_T SPWM_DW;

/* Model entry point functions */
extern void SPWM_initialize(void);
extern void SPWM_step(void);
extern void SPWM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SPWM_T *const SPWM_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SPWM'
 * '<S1>'   : 'SPWM/Subsystem'
 */
#endif                                 /* RTW_HEADER_SPWM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
