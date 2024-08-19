/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_2_data.c
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

#include "test_2.h"

/* Block parameters (default storage) */
P_test_2_T test_2_P = {
  /* Variable: T1
   * Referenced by:
   *   '<S3>/Constant'
   *   '<S4>/Constant'
   *   '<S5>/Constant'
   */
  2.7654761904761907E-5,

  /* Variable: T2
   * Referenced by:
   *   '<S4>/Constant'
   *   '<S5>/Constant'
   */
  4.9999999999999996E-6,

  /* Variable: T3
   * Referenced by: '<S5>/Constant'
   */
  4.9999999999999996E-6,

  /* Variable: Tini
   * Referenced by:
   *   '<S2>/Constant'
   *   '<S3>/Constant'
   *   '<S4>/Constant'
   *   '<S5>/Constant'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant2'
   */
  0.0,

  /* Expression: 5e-6
   * Referenced by: '<S1>/Constant'
   */
  5.0E-6,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Switch'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Enable'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  2.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pierna Derecha'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S1>/Gain'
   */
  MIN_int16_T,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S1>/Gain1'
   */
  MIN_int16_T,

  /* Computed Parameter: Output1_Y0
   * Referenced by: '<S1>/Output1'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
