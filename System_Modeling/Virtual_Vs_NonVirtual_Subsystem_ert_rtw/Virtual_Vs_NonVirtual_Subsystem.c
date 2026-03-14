/*
 * File: Virtual_Vs_NonVirtual_Subsystem.c
 *
 * Code generated for Simulink model 'Virtual_Vs_NonVirtual_Subsystem'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Feb 26 15:50:07 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Virtual_Vs_NonVirtual_Subsystem.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
static void Afnona(void);

/* Output and update for atomic system: '<Root>/NonVirtual_Subsystem' */
static void Afnona(void)
{
  /* Outport: '<Root>/Output1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<S1>/Delay1'
   *  Sum: '<S1>/Add'
   */
  rtY.Output1 = rtDW.Delay1_DSTATE_b + 1.0;

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  Outport: '<Root>/Output1'
   */
  rtDW.Delay1_DSTATE_b = rtY.Output1;
}

/* Model step function */
void Virtual_Vs_NonVirtual_Subsystem_step(void)
{
  real_T rtb_Add;

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<S2>/Delay1'
   */
  rtb_Add = rtDW.Delay1_DSTATE + 1.0;

  /* Outport: '<Root>/Output' */
  rtY.Output = rtb_Add;

  /* Outputs for Atomic SubSystem: '<Root>/NonVirtual_Subsystem' */
  Afnona();

  /* End of Outputs for SubSystem: '<Root>/NonVirtual_Subsystem' */

  /* Update for Delay: '<S2>/Delay1' */
  rtDW.Delay1_DSTATE = rtb_Add;
}

/* Model initialize function */
void Virtual_Vs_NonVirtual_Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
