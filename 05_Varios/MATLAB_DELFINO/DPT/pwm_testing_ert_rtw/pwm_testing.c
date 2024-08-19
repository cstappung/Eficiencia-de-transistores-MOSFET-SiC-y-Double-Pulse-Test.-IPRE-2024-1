/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pwm_testing.c
 *
 * Code generated for Simulink model 'pwm_testing'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon May 13 13:48:20 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pwm_testing.h"
#include "rtwtypes.h"
#include "pwm_testing_private.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
B_pwm_testing_T pwm_testing_B;

/* Block states (default storage) */
DW_pwm_testing_T pwm_testing_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_pwm_testing_T pwm_testing_PrevZCX;

/* Real-time model */
static RT_MODEL_pwm_testing_T pwm_testing_M_;
RT_MODEL_pwm_testing_T *const pwm_testing_M = &pwm_testing_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void pwm_testing_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(pwm_testing_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (pwm_testing_M->Timing.TaskCounters.TID[1])++;
  if ((pwm_testing_M->Timing.TaskCounters.TID[1]) > 2499) {/* Sample time: [0.0025s, 0.0s] */
    pwm_testing_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void pwm_testing_step0(void)           /* Sample time: [1.0E-6s, 0.0s] */
{
  {                                    /* Sample time: [1.0E-6s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (c280xgpio_do): '<Root>/PWM2A' incorporates:
   *  Constant: '<Root>/Enable'
   */
  {
    if (pwm_testing_P.Enable_Value) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/PWM1B' incorporates:
   *  Constant: '<Root>/Pierna Derecha'
   */
  {
    if (pwm_testing_P.PiernaDerecha_Value) {
      GpioDataRegs.GPASET.bit.GPIO3 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
    }
  }

  /* S-Function (c280xcap): '<Root>/eCAP' */
  pwm_testing_B.eCAP = ECap1Regs.CAP1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++pwm_testing_M->Timing.clockTick0)) {
    ++pwm_testing_M->Timing.clockTickH0;
  }

  pwm_testing_M->Timing.taskTime0 = pwm_testing_M->Timing.clockTick0 *
    pwm_testing_M->Timing.stepSize0 + pwm_testing_M->Timing.clockTickH0 *
    pwm_testing_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void pwm_testing_step1(void)           /* Sample time: [0.0025s, 0.0s] */
{
  real_T Add_tmp;
  real_T rtb_PulseGenerator;
  ZCEventType zcEvent;

  /* Reset subsysRan breadcrumbs */
  srClearBC(pwm_testing_DW.Subsystem_SubsysRanBC);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (pwm_testing_DW.clockTickCounter <
                        pwm_testing_P.PulseGenerator_Duty) &&
    (pwm_testing_DW.clockTickCounter >= 0L) ? pwm_testing_P.PulseGenerator_Amp :
    0.0;
  if (pwm_testing_DW.clockTickCounter >= pwm_testing_P.PulseGenerator_Period -
      1.0) {
    pwm_testing_DW.clockTickCounter = 0L;
  } else {
    pwm_testing_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &pwm_testing_PrevZCX.Subsystem_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     *  Delay: '<S1>/Delay'
     *  Sum: '<S1>/Sum'
     */
    if (pwm_testing_P.Constant1_Value > pwm_testing_P.Switch_Threshold) {
      pwm_testing_DW.Delay_DSTATE = pwm_testing_P.Constant2_Value;
    } else {
      pwm_testing_DW.Delay_DSTATE += pwm_testing_P.Constant_Value;
    }

    /* End of Switch: '<S1>/Switch' */

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     *  Delay: '<S1>/Delay'
     */
    pwm_testing_B.Compare = (pwm_testing_DW.Delay_DSTATE >= pwm_testing_P.Tini);

    /* S-Function (c280xgpio_do): '<S1>/LED AZUL' */
    {
      if (pwm_testing_B.Compare) {
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
    rtb_PulseGenerator = pwm_testing_P.Tini + pwm_testing_P.T1;

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    Add_tmp = rtb_PulseGenerator + pwm_testing_P.T2;

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
    pwm_testing_B.Add = ((((pwm_testing_DW.Delay_DSTATE >= rtb_PulseGenerator ?
      pwm_testing_P.Gain_Gain : 0) >> 8U) + ((int16_T)pwm_testing_B.Compare <<
      7U)) + ((pwm_testing_DW.Delay_DSTATE >= Add_tmp) << 7U)) +
      ((pwm_testing_DW.Delay_DSTATE >= Add_tmp + pwm_testing_P.T3 ?
        pwm_testing_P.Gain1_Gain : 0) >> 8U);
    pwm_testing_DW.Subsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* S-Function (c280xgpio_do): '<Root>/PWM1A' */
  {
    if (pwm_testing_B.Add) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0025, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  pwm_testing_M->Timing.clockTick1++;
}

/* Model initialize function */
void pwm_testing_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)pwm_testing_M, 0,
                sizeof(RT_MODEL_pwm_testing_T));
  rtmSetTFinal(pwm_testing_M, -1);
  pwm_testing_M->Timing.stepSize0 = 1.0E-6;

  /* External mode info */
  pwm_testing_M->Sizes.checksums[0] = (2881875433U);
  pwm_testing_M->Sizes.checksums[1] = (3638997004U);
  pwm_testing_M->Sizes.checksums[2] = (1453498807U);
  pwm_testing_M->Sizes.checksums[3] = (757307399U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    pwm_testing_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&pwm_testing_DW.Subsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&pwm_testing_DW.Subsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&pwm_testing_DW.Subsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(pwm_testing_M->extModeInfo,
      &pwm_testing_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pwm_testing_M->extModeInfo,
                        pwm_testing_M->Sizes.checksums);
    rteiSetTPtr(pwm_testing_M->extModeInfo, rtmGetTPtr(pwm_testing_M));
  }

  /* block I/O */
  (void) memset(((void *) &pwm_testing_B), 0,
                sizeof(B_pwm_testing_T));

  /* states (dwork) */
  (void) memset((void *)&pwm_testing_DW, 0,
                sizeof(DW_pwm_testing_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/PWM2A' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  pwm_testing_DW.clockTickCounter = 0L;

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

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM' */

  /*** Initialize ePWM3 modules ***/
  {
    /*  // Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 0U;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select
       EPwm3Regs.TBCTL2.bit.SYNCOSELX           = 0U;          // Sync Output Select - additional options

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x30U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 99U;             // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 50U;     // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 50U;     // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 422U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  pwm_testing_PrevZCX.Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Subsystem' */
  /* Start for S-Function (c280xgpio_do): '<S1>/LED AZUL' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  pwm_testing_DW.Delay_DSTATE = pwm_testing_P.Delay_InitialCondition;

  /* SystemInitialize for Sum: '<S1>/Add' incorporates:
   *  Outport: '<S1>/Output1'
   */
  pwm_testing_B.Add = pwm_testing_P.Output1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
}

/* Model terminate function */
void pwm_testing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
