/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.h
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri May 10 17:08:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled1_h_
#define RTW_HEADER_untitled1_h_
#ifndef untitled1_COMMON_INCLUDES_
#define untitled1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#endif                                 /* untitled1_COMMON_INCLUDES_ */

#include <stddef.h>
#include "untitled1_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Constant5;                    /* '<Root>/Constant5' */
  real_T Switch;                       /* '<S1>/Switch' */
  int16_T Add;                         /* '<S1>/Add' */
  boolean_T Compare;                   /* '<S2>/Compare' */
} B_untitled1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  int32_T PWM2A_FRAC_LEN;              /* '<Root>/PWM2A' */
  int32_T PWM1A_FRAC_LEN;              /* '<Root>/PWM1A' */
  int32_T LEDAZUL_FRAC_LEN;            /* '<S1>/LED AZUL' */
  int32_T PWM1B_FRAC_LEN;              /* '<Root>/PWM1B' */
} DW_untitled1_T;

/* Parameters (default storage) */
struct P_untitled1_T_ {
  real_T T1;                           /* Variable: T1
                                        * Referenced by:
                                        *   '<Root>/Constant3'
                                        *   '<S3>/Constant'
                                        *   '<S4>/Constant'
                                        *   '<S5>/Constant'
                                        */
  real_T T2;                           /* Variable: T2
                                        * Referenced by:
                                        *   '<Root>/Constant4'
                                        *   '<S4>/Constant'
                                        *   '<S5>/Constant'
                                        */
  real_T T3;                           /* Variable: T3
                                        * Referenced by:
                                        *   '<Root>/Constant5'
                                        *   '<S5>/Constant'
                                        */
  real_T Tini;                         /* Variable: Tini
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S3>/Constant'
                                        *   '<S4>/Constant'
                                        *   '<S5>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 0.000001
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Enable'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T PiernaDerecha_Value;          /* Expression: 1
                                        * Referenced by: '<Root>/Pierna Derecha'
                                        */
  int16_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  int16_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled1_T {
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
extern P_untitled1_T untitled1_P;

/* Block signals (default storage) */
extern B_untitled1_T untitled1_B;

/* Block states (default storage) */
extern DW_untitled1_T untitled1_DW;

/* Model entry point functions */
extern void untitled1_initialize(void);
extern void untitled1_step(void);
extern void untitled1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled1_T *const untitled1_M;
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
 * '<Root>' : 'untitled1'
 * '<S1>'   : 'untitled1/Subsystem'
 * '<S2>'   : 'untitled1/Subsystem/Compare To Constant'
 * '<S3>'   : 'untitled1/Subsystem/Compare To Constant1'
 * '<S4>'   : 'untitled1/Subsystem/Compare To Constant2'
 * '<S5>'   : 'untitled1/Subsystem/Compare To Constant3'
 */
#endif                                 /* RTW_HEADER_untitled1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
