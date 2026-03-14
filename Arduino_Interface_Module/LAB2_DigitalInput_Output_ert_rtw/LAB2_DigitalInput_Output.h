/*
 * File: LAB2_DigitalInput_Output.h
 *
 * Code generated for Simulink model 'LAB2_DigitalInput_Output'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 14 01:24:49 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LAB2_DigitalInput_Output_h_
#define LAB2_DigitalInput_Output_h_
#ifndef LAB2_DigitalInput_Output_COMMON_INCLUDES_
#define LAB2_DigitalInput_Output_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                           /* LAB2_DigitalInput_Output_COMMON_INCLUDES_ */

#include "LAB2_DigitalInput_Output_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
} DW_IfActionSubsystem_LAB2_Dig_T;

/* Block signals (default storage) */
typedef struct {
  real_T Merge;                        /* '<Root>/Merge' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
} B_LAB2_DigitalInput_Output_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_h_T obj_b;/* '<Root>/Digital Output2' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  DW_IfActionSubsystem_LAB2_Dig_T IfActionSubsystem1;/* '<Root>/If Action Subsystem1' */
  DW_IfActionSubsystem_LAB2_Dig_T IfActionSubsystem;/* '<Root>/If Action Subsystem' */
} DW_LAB2_DigitalInput_Output_T;

/* Parameters for system: '<Root>/If Action Subsystem' */
struct P_IfActionSubsystem_LAB2_Digi_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_LAB2_DigitalInput_Output_T_ {
  real_T DigitalInput_SampleTime;      /* Expression: 1E-3
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 1E-3
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  P_IfActionSubsystem_LAB2_Digi_T IfActionSubsystem1;/* '<Root>/If Action Subsystem1' */
  P_IfActionSubsystem_LAB2_Digi_T IfActionSubsystem;/* '<Root>/If Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_LAB2_DigitalInput_Out_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_LAB2_DigitalInput_Output_T LAB2_DigitalInput_Output_P;

/* Block signals (default storage) */
extern B_LAB2_DigitalInput_Output_T LAB2_DigitalInput_Output_B;

/* Block states (default storage) */
extern DW_LAB2_DigitalInput_Output_T LAB2_DigitalInput_Output_DW;

/* Model entry point functions */
extern void LAB2_DigitalInput_Output_initialize(void);
extern void LAB2_DigitalInput_Output_step(void);
extern void LAB2_DigitalInput_Output_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LAB2_DigitalInput_Ou_T *const LAB2_DigitalInput_Output_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'LAB2_DigitalInput_Output'
 * '<S1>'   : 'LAB2_DigitalInput_Output/If Action Subsystem'
 * '<S2>'   : 'LAB2_DigitalInput_Output/If Action Subsystem1'
 */
#endif                                 /* LAB2_DigitalInput_Output_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
