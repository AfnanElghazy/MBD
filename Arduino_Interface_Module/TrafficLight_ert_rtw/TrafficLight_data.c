/*
 * File: TrafficLight_data.c
 *
 * Code generated for Simulink model 'TrafficLight'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 14 07:45:10 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrafficLight.h"

/* Block parameters (default storage) */
P_TrafficLight_T TrafficLight_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S4>/Constant'
   */
  10.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S5>/Constant'
   */
  10.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S6>/Constant'
   */
  20.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S7>/Constant'
   */
  20.0,

  /* Mask Parameter: DetectRisePositive_vinit
   * Referenced by: '<S1>/Delay Input1'
   */
  false,

  /* Expression: -1
   * Referenced by: '<Root>/Digital Input'
   */
  -1.0,

  /* Expression: 31
   * Referenced by: '<S2>/Constant2'
   */
  31.0,

  /* Computed Parameter: Green_Y0
   * Referenced by: '<S2>/Green'
   */
  false,

  /* Computed Parameter: Yellow_Y0
   * Referenced by: '<S2>/Yellow'
   */
  false,

  /* Computed Parameter: Red_Y0
   * Referenced by: '<S2>/Red'
   */
  false,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S3>/Constant'
   */
  false,

  /* Computed Parameter: DelayOneStep_InitialCondition
   * Referenced by: '<Root>/Delay One Step'
   */
  false,

  /* Computed Parameter: DelayOneStep1_InitialCondition
   * Referenced by: '<Root>/Delay One Step1'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
