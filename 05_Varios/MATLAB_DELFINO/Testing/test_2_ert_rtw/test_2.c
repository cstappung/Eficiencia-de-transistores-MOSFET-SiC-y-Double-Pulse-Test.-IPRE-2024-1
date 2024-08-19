/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_2.c
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

#include "test_2.h"

/* Real-time model */
static RT_MODEL_test_2_T test_2_M_;
RT_MODEL_test_2_T *const test_2_M = &test_2_M_;

/* Model step function */
void test_2_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void test_2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_2_M, (NULL));
}

/* Model terminate function */
void test_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
