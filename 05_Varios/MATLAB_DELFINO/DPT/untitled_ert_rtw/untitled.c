/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri May 10 18:56:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "untitled_private.h"
#include <string.h>

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  real_T Add_tmp;
  real_T Add_tmp_0;

  /* S-Function (c280xgpio_do): '<Root>/PWM2A' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    if (untitled_P.Constant_Value_i) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Delay: '<S1>/Delay'
   *  Sum: '<S1>/Sum'
   */
  if (untitled_P.Constant1_Value > untitled_P.Switch_Threshold) {
    untitled_DW.Delay_DSTATE = untitled_P.Constant2_Value;
  } else {
    untitled_DW.Delay_DSTATE += untitled_P.Constant_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Delay: '<S1>/Delay'
   */
  untitled_B.Compare = (untitled_DW.Delay_DSTATE >= untitled_P.Tini);

  /* S-Function (c280xgpio_do): '<Root>/LED AZUL' */
  {
    if (untitled_B.Compare) {
      GpioDataRegs.GPASET.bit.GPIO31 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO31 = 1U;
    }
  }

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  Add_tmp = untitled_P.Tini + untitled_P.T1;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  Add_tmp_0 = Add_tmp + untitled_P.T2;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   */
  untitled_B.Add = ((((untitled_DW.Delay_DSTATE >= Add_tmp ?
                       untitled_P.Gain_Gain : 0) >> 8U) + ((int16_T)
    untitled_B.Compare << 7U)) + ((untitled_DW.Delay_DSTATE >= Add_tmp_0) << 7U))
    + ((untitled_DW.Delay_DSTATE >= Add_tmp_0 + untitled_P.T3 ?
        untitled_P.Gain1_Gain : 0) >> 8U);

  /* S-Function (c280xgpio_do): '<Root>/PWM1A' */
  {
    if (untitled_B.Add) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/PWM1B' incorporates:
   *  Constant: '<Root>/Pierna Derecha'
   */
  {
    if (untitled_P.PiernaDerecha_Value) {
      GpioDataRegs.GPASET.bit.GPIO3 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
    }
  }

  {                                    /* Sample time: [3.0E-6s, 0.0s] */
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
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.taskTime0 = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 3.0E-6;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2317843744U);
  untitled_M->Sizes.checksums[1] = (3368609300U);
  untitled_M->Sizes.checksums[2] = (2574171424U);
  untitled_M->Sizes.checksums[3] = (1463272570U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM2A' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/LED AZUL' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM1A' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPADIR.all |= 0x4U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM1B' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFF3FU;
  GpioCtrlRegs.GPADIR.all |= 0x8U;
  EDIS;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  untitled_DW.Delay_DSTATE = untitled_P.Delay_InitialCondition;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
