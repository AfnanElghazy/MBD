/*
 * File: Automated_Irrigation_Control_System.c
 *
 * Code generated for Simulink model 'Automated_Irrigation_Control_System'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Mar 13 00:29:57 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Automated_Irrigation_Control_System.h"
#include "rtwtypes.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Automated_Irrigation_Control_System_step(void)
{
  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/Soil Moisture Sensing'
   *  Outport: '<Root>/water pump'
   */
  rtY.waterpump = !(rtU.SoilMoistureSensing > 90.0);
}

/* Model initialize function */
void Automated_Irrigation_Control_System_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
