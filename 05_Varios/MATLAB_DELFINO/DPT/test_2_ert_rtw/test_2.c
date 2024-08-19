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
 * C/C++ source code generated on : Mon May 13 12:06:56 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_2.h"
#include "rtwtypes.h"
#include "test_2_private.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
B_test_2_T test_2_B;

/* Block states (default storage) */
DW_test_2_T test_2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_test_2_T test_2_PrevZCX;

/* Real-time model */
static RT_MODEL_test_2_T test_2_M_;
RT_MODEL_test_2_T *const test_2_M = &test_2_M_;

/* Model step function */
void test_2_step(void)
{
  real_T Add_tmp;
  real_T rtb_PulseGenerator;
  ZCEventType zcEvent;

  /* S-Function (c280xgpio_do): '<Root>/PWM2A' incorporates:
   *  Constant: '<Root>/Enable'
   */
  {
    if (test_2_P.Enable_Value) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (test_2_DW.clockTickCounter <
                        test_2_P.PulseGenerator_Duty) &&
    (test_2_DW.clockTickCounter >= 0L) ? test_2_P.PulseGenerator_Amp : 0.0;
  if (test_2_DW.clockTickCounter >= test_2_P.PulseGenerator_Period - 1.0) {
    test_2_DW.clockTickCounter = 0L;
  } else {
    test_2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&test_2_PrevZCX.Subsystem_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     *  Delay: '<S1>/Delay'
     *  Sum: '<S1>/Sum'
     */
    if (test_2_P.Constant1_Value > test_2_P.Switch_Threshold) {
      test_2_DW.Delay_DSTATE = test_2_P.Constant2_Value;
    } else {
      test_2_DW.Delay_DSTATE += test_2_P.Constant_Value;
    }

    /* End of Switch: '<S1>/Switch' */

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     *  Delay: '<S1>/Delay'
     */
    test_2_B.Compare = (test_2_DW.Delay_DSTATE >= test_2_P.Tini);

    /* S-Function (c280xgpio_do): '<S1>/LED AZUL' */
    {
      if (test_2_B.Compare) {
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
    rtb_PulseGenerator = test_2_P.Tini + test_2_P.T1;

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    Add_tmp = rtb_PulseGenerator + test_2_P.T2;

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
    test_2_B.Add = ((((test_2_DW.Delay_DSTATE >= rtb_PulseGenerator ?
                       test_2_P.Gain_Gain : 0) >> 8U) + ((int16_T)
      test_2_B.Compare << 7U)) + ((test_2_DW.Delay_DSTATE >= Add_tmp) << 7U)) +
      ((test_2_DW.Delay_DSTATE >= Add_tmp + test_2_P.T3 ? test_2_P.Gain1_Gain :
        0) >> 8U);
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* S-Function (c280xgpio_do): '<Root>/PWM1A' */
  {
    if (test_2_B.Add) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/PWM1B' incorporates:
   *  Constant: '<Root>/Pierna Derecha'
   */
  {
    if (test_2_P.PiernaDerecha_Value) {
      GpioDataRegs.GPASET.bit.GPIO3 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
    }
  }
}

/* Model initialize function */
void test_2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_2_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &test_2_B), 0,
                sizeof(B_test_2_T));

  /* states (dwork) */
  (void) memset((void *)&test_2_DW, 0,
                sizeof(DW_test_2_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM2A' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test_2_DW.clockTickCounter = 0L;

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
  test_2_PrevZCX.Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Subsystem' */
  /* Start for S-Function (c280xgpio_do): '<S1>/LED AZUL' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  test_2_DW.Delay_DSTATE = test_2_P.Delay_InitialCondition;

  /* SystemInitialize for Sum: '<S1>/Add' incorporates:
   *  Outport: '<S1>/Output1'
   */
  test_2_B.Add = test_2_P.Output1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
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
