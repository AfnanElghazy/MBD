/*
 * File: Subsystem.h
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

#ifndef Subsystem_h_
#define Subsystem_h_
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S1>/Unit Delay' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Output;                    /* '<Root>/Output' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Integrate_With_SoftWare/Subsystem')    - opens subsystem Integrate_With_SoftWare/Subsystem
 * hilite_system('Integrate_With_SoftWare/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Integrate_With_SoftWare'
 * '<S1>'   : 'Integrate_With_SoftWare/Subsystem'
 */
#endif                                 /* Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
