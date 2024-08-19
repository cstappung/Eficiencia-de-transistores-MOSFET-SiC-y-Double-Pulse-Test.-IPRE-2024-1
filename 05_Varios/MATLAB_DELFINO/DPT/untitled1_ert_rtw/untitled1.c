/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
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

#include "untitled1.h"
#include "rtwtypes.h"
#include "untitled1_private.h"
#include <string.h>

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

/* Model step function */
void untitled1_step(void)
{
  real_T Add_tmp;
  real_T Add_tmp_0;

  /* Constant: '<Root>/Constant3' */
  untitled1_B.Constant3 = untitled1_P.T1;

  /* Constant: '<Root>/Constant4' */
  untitled1_B.Constant4 = untitled1_P.T2;

  /* Constant: '<Root>/Constant5' */
  untitled1_B.Constant5 = untitled1_P.T3;

  /* S-Function (c280xgpio_do): '<Root>/PWM2A' incorporates:
   *  Constant: '<Root>/Enable'
   */
  {
    if (untitled1_P.Enable_Value) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  if (untitled1_P.Constant1_Value > untitled1_P.Switch_Threshold) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    untitled1_B.Switch = untitled1_P.Constant2_Value;
  } else {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Delay: '<S1>/Delay'
     *  Sum: '<S1>/Sum'
     */
    untitled1_B.Switch = untitled1_P.Constant_Value + untitled1_DW.Delay_DSTATE;
  }

  /* End of Switch: '<S1>/Switch' */

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  untitled1_B.Compare = (untitled1_B.Switch >= untitled1_P.Tini);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  Add_tmp = untitled1_P.Tini + untitled1_P.T1;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  Add_tmp_0 = Add_tmp + untitled1_P.T2;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   */
  untitled1_B.Add = ((((untitled1_B.Switch >= Add_tmp ? untitled1_P.Gain_Gain :
                        0) >> 8U) + ((int16_T)untitled1_B.Compare << 7U)) +
                     ((untitled1_B.Switch >= Add_tmp_0) << 7U)) +
    ((untitled1_B.Switch >= Add_tmp_0 + untitled1_P.T3 ? untitled1_P.Gain1_Gain :
      0) >> 8U);

  /* S-Function (c280xgpio_do): '<Root>/PWM1A' */
  {
    if (untitled1_B.Add) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<S1>/LED AZUL' */
  {
    if (untitled1_B.Compare) {
      GpioDataRegs.GPASET.bit.GPIO31 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO31 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/PWM1B' incorporates:
   *  Constant: '<Root>/Pierna Derecha'
   */
  {
    if (untitled1_P.PiernaDerecha_Value) {
      GpioDataRegs.GPASET.bit.GPIO3 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
    }
  }

  /* Update for Delay: '<S1>/Delay' */
  untitled1_DW.Delay_DSTATE = untitled1_B.Switch;

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
  if (!(++untitled1_M->Timing.clockTick0)) {
    ++untitled1_M->Timing.clockTickH0;
  }

  untitled1_M->Timing.taskTime0 = untitled1_M->Timing.clockTick0 *
    untitled1_M->Timing.stepSize0 + untitled1_M->Timing.clockTickH0 *
    untitled1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled1_M, 0,
                sizeof(RT_MODEL_untitled1_T));
  rtmSetTFinal(untitled1_M, -1);
  untitled1_M->Timing.stepSize0 = 1.0E-6;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (1765501636U);
  untitled1_M->Sizes.checksums[1] = (2466067779U);
  untitled1_M->Sizes.checksums[2] = (358513038U);
  untitled1_M->Sizes.checksums[3] = (857492821U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled1_B), 0,
                sizeof(B_untitled1_T));

  /* states (dwork) */
  (void) memset((void *)&untitled1_DW, 0,
                sizeof(DW_untitled1_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM2A' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM1A' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPADIR.all |= 0x4U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<S1>/LED AZUL' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM1B' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFF3FU;
  GpioCtrlRegs.GPADIR.all |= 0x8U;
  EDIS;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  untitled1_DW.Delay_DSTATE = untitled1_P.Delay_InitialCondition;
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
