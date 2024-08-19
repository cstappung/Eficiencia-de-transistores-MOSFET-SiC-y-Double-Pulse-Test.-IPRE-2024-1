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
 * C/C++ source code generated on : Wed May 22 11:28:45 2024
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
#endif                                 /* test_2_COMMON_INCLUDES_ */

#include <stddef.h>
#include "test_2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_test_2_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void test_2_initialize(void);
extern void test_2_step(void);
extern void test_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_2_T *const test_2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Enable' : Unused code path elimination
 */

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
 */
#endif                                 /* RTW_HEADER_test_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
