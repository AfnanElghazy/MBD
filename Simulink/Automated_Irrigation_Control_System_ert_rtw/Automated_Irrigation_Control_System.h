/*
 * File: Automated_Irrigation_Control_System.h
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

#ifndef Automated_Irrigation_Control_System_h_
#define Automated_Irrigation_Control_System_h_
#ifndef Automated_Irrigation_Control_System_COMMON_INCLUDES_
#define Automated_Irrigation_Control_System_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                /* Automated_Irrigation_Control_System_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T SoilMoistureSensing;          /* '<Root>/Soil Moisture Sensing' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T waterpump;                    /* '<Root>/water pump' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Automated_Irrigation_Control_System_initialize(void);
extern void Automated_Irrigation_Control_System_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'Automated_Irrigation_Control_System'
 * '<S1>'   : 'Automated_Irrigation_Control_System/Irrigation_Subsystem'
 * '<S2>'   : 'Automated_Irrigation_Control_System/Irrigation_Subsystem/If Action Subsystem1'
 * '<S3>'   : 'Automated_Irrigation_Control_System/Irrigation_Subsystem/If Action Subsystem2'
 */
#endif                              /* Automated_Irrigation_Control_System_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
