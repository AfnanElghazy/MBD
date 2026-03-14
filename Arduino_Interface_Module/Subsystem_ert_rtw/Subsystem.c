/*
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Feb 10 01:59:36 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Subsystem_step(void)
{
  boolean_T rtb_NOT;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Logic: '<S1>/NOT' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_NOT = !rtDW.UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_NOT;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Output' */
  rtY.Output = rtb_NOT;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
