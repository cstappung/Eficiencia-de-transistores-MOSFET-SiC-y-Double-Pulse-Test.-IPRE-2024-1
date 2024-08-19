/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: trest2.c
 *
 * Code generated for Simulink model 'trest2'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May  8 16:00:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "trest2.h"
#include "trest2_private.h"
#include <string.h>

/* Block states (default storage) */
DW_trest2_T trest2_DW;

/* Real-time model */
static RT_MODEL_trest2_T trest2_M_;
RT_MODEL_trest2_T *const trest2_M = &trest2_M_;

/* Model step function */
void trest2_step(void)
{
  /* S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)(trest2_P.Constant_Value != 0);
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)(trest2_P.Constant1_Value != 0);
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)(trest2_P.Constant2_Value != 0);
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output3' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)(trest2_P.Constant3_Value != 0);
  }

  {                                    /* Sample time: [0.05s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  trest2_M->Timing.taskTime0 =
    ((time_T)(++trest2_M->Timing.clockTick0)) * trest2_M->Timing.stepSize0;
}

/* Model initialize function */
void trest2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)trest2_M, 0,
                sizeof(RT_MODEL_trest2_T));
  rtmSetTFinal(trest2_M, -1);
  trest2_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  trest2_M->Sizes.checksums[0] = (745229233U);
  trest2_M->Sizes.checksums[1] = (1899422547U);
  trest2_M->Sizes.checksums[2] = (1857226148U);
  trest2_M->Sizes.checksums[3] = (1148626899U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    trest2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(trest2_M->extModeInfo,
      &trest2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(trest2_M->extModeInfo, trest2_M->Sizes.checksums);
    rteiSetTPtr(trest2_M->extModeInfo, rtmGetTPtr(trest2_M));
  }

  /* states (dwork) */
  (void) memset((void *)&trest2_DW, 0,
                sizeof(DW_trest2_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output2' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output3' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;
}

/* Model terminate function */
void trest2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
