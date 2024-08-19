/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_2.h
 *
 * Code generated for Simulink model 'test_2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon May 13 12:06:56 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_2_h_
#define RTW_HEADER_test_2_h_
#ifndef test_2_COMMON_INCLUDES_
#define test_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#endif                                 /* test_2_COMMON_INCLUDES_ */

#include <stddef.h>
#include "test_2_types.h"
#include "rt_zcfcn.h"
#include <string.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  int16_T Add;                         /* '<S1>/Add' */
  boolean_T Compare;                   /* '<S2>/Compare' */
} B_test_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  int32_T PWM2A_FRAC_LEN;              /* '<Root>/PWM2A' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T PWM1A_FRAC_LEN;              /* '<Root>/PWM1A' */
  int32_T PWM1B_FRAC_LEN;              /* '<Root>/PWM1B' */
  int32_T LEDAZUL_FRAC_LEN;            /* '<S1>/LED AZUL' */
} DW_test_2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<Root>/Subsystem' */
} PrevZCX_test_2_T;

/* Parameters (default storage) */
struct P_test_2_T_ {
  real_T T1;                           /* Variable: T1
                                        * Referenced by:
                                        *   '<S3>/Constant'
                                        *   '<S4>/Constant'
                                        *   '<S5>/Constant'
                                        */
  real_T T2;                           /* Variable: T2
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S5>/Constant'
                                        */
  real_T T3;                           /* Variable: T3
                                        * Referenced by: '<S5>/Constant'
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
  real_T Constant_Value;               /* Expression: 5e-6
                                        * Referenced by: '<S1>/Constant'
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
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Enable'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
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
  int16_T Output1_Y0;                  /* Computed Parameter: Output1_Y0
                                        * Referenced by: '<S1>/Output1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_2_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_test_2_T test_2_P;

/* Block signals (default storage) */
extern B_test_2_T test_2_B;

/* Block states (default storage) */
extern DW_test_2_T test_2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_test_2_T test_2_PrevZCX;

/* Model entry point functions */
extern void test_2_initialize(void);
extern void test_2_step(void);
extern void test_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_2_T *const test_2_M;
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
 * '<Root>' : 'test_2'
 * '<S1>'   : 'test_2/Subsystem'
 * '<S2>'   : 'test_2/Subsystem/Compare To Constant'
 * '<S3>'   : 'test_2/Subsystem/Compare To Constant1'
 * '<S4>'   : 'test_2/Subsystem/Compare To Constant2'
 * '<S5>'   : 'test_2/Subsystem/Compare To Constant3'
 */
#endif                                 /* RTW_HEADER_test_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
