/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DPT_Model.c
 *
 * Code generated for Simulink model 'DPT_Model'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May  8 17:13:25 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DPT_Model.h"
#include "DPT_Model_private.h"
#include <string.h>

/* Block states (default storage) */
DW_DPT_Model_T DPT_Model_DW;

/* Real-time model */
static RT_MODEL_DPT_Model_T DPT_Model_M_;
RT_MODEL_DPT_Model_T *const DPT_Model_M = &DPT_Model_M_;

/* Model step function */
void DPT_Model_step(void)
{
  /* S-Function (c280xgpio_do): '<Root>/PWM2A' incorporates:
   *  Constant: '<Root>/Enable'
   */
  {
    if (DPT_Model_P.Enable_Value) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }

  {                                    /* Sample time: [1.0E-6s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DPT_Model_M->Timing.clockTick0)) {
    ++DPT_Model_M->Timing.clockTickH0;
  }

  DPT_Model_M->Timing.taskTime0 = DPT_Model_M->Timing.clockTick0 *
    DPT_Model_M->Timing.stepSize0 + DPT_Model_M->Timing.clockTickH0 *
    DPT_Model_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void DPT_Model_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)DPT_Model_M, 0,
                sizeof(RT_MODEL_DPT_Model_T));
  rtmSetTFinal(DPT_Model_M, -1);
  DPT_Model_M->Timing.stepSize0 = 1.0E-6;

  /* External mode info */
  DPT_Model_M->Sizes.checksums[0] = (80261755U);
  DPT_Model_M->Sizes.checksums[1] = (1502322042U);
  DPT_Model_M->Sizes.checksums[2] = (3049732529U);
  DPT_Model_M->Sizes.checksums[3] = (2705420888U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DPT_Model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DPT_Model_M->extModeInfo,
      &DPT_Model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DPT_Model_M->extModeInfo, DPT_Model_M->Sizes.checksums);
    rteiSetTPtr(DPT_Model_M->extModeInfo, rtmGetTPtr(DPT_Model_M));
  }

  /* states (dwork) */
  (void) memset((void *)&DPT_Model_DW, 0,
                sizeof(DW_DPT_Model_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM2A' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;
}

/* Model terminate function */
void DPT_Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
