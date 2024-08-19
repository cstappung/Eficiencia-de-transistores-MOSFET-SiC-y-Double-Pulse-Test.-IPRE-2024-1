#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "pwm_testing.h"
#include "pwm_testing_private.h"

void init_CAP1(void)
{
  EALLOW;
  CpuSysRegs.PCLKCR3.bit.ECAP1 = 1U;
  ECap1Regs.ECEINT.all = 0x0000U;      /* Disable all capture interrupts*/
  ECap1Regs.ECCLR.all = 0xFFFFU;       /* Clear all CAP interrupt flags*/
  ECap1Regs.ECCTL1.bit.CAPLDEN = 0U;   /* Disable CAP1-CAP4 register loads*/
  ECap1Regs.ECCTL2.bit.TSCTRSTOP = 0U; /* Make sure the counter is stopped*/
  ECap1Regs.CTRPHS = 0U;               /* Counter Phase Control*/
  ECap1Regs.ECCTL2.bit.SYNCO_SEL = 2U; /* Disable sync out signal*/
  ECap1Regs.ECCTL2.bit.CAP_APWM = 0U;  /* Capture mode*/
  ECap1Regs.ECCTL2.bit.CONT_ONESHT = 0U;/* One-shot*/
  ECap1Regs.ECCTL1.bit.PRESCALE = 0U;  /*Event prescaler*/
  ECap1Regs.ECCTL2.bit.STOP_WRAP = 0U; /* Stop at 4 events*/
  ECap1Regs.ECCTL1.bit.CAP1POL = 0U;   /* Select rising or falling edge*/
  ECap1Regs.ECCTL1.bit.CTRRST1 = 0U;   /* Difference operation        */
  ECap1Regs.ECCLR.all = 0x0FFU;        /* Clear pending interrupts*/
  ECap1Regs.ECCTL2.bit.REARM = 1U;     /* arm one-shot*/
  ECap1Regs.ECCTL2.bit.TSCTRSTOP = 1U; /* Start Counter*/
  ECap1Regs.ECCTL1.bit.CAPLDEN = 1U;   /* Enable CAP1-CAP4 register loads*/
  EDIS;
}
