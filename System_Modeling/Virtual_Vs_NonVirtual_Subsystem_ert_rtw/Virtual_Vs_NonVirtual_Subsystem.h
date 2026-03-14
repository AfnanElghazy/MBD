/*
 * File: Virtual_Vs_NonVirtual_Subsystem.h
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

#ifndef Virtual_Vs_NonVirtual_Subsystem_h_
#define Virtual_Vs_NonVirtual_Subsystem_h_
#ifndef Virtual_Vs_NonVirtual_Subsystem_COMMON_INCLUDES_
#define Virtual_Vs_NonVirtual_Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                    /* Virtual_Vs_NonVirtual_Subsystem_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S2>/Delay1' */
  real_T Delay1_DSTATE_b;              /* '<S1>/Delay1' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output;                       /* '<Root>/Output' */
  real_T Output1;                      /* '<Root>/Output1' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Virtual_Vs_NonVirtual_Subsystem_initialize(void);
extern void Virtual_Vs_NonVirtual_Subsystem_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Virtual_Vs_NonVirtual_Subsystem'
 * '<S1>'   : 'Virtual_Vs_NonVirtual_Subsystem/NonVirtual_Subsystem'
 * '<S2>'   : 'Virtual_Vs_NonVirtual_Subsystem/Virtual_Subsystem'
 */
#endif                                 /* Virtual_Vs_NonVirtual_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
