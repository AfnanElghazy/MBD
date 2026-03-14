/*
 * File: TrafficLight_StateFlow.h
 *
 * Code generated for Simulink model 'TrafficLight_StateFlow'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 14 08:22:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef TrafficLight_StateFlow_h_
#define TrafficLight_StateFlow_h_
#ifndef TrafficLight_StateFlow_COMMON_INCLUDES_
#define TrafficLight_StateFlow_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                             /* TrafficLight_StateFlow_COMMON_INCLUDES_ */

#include "TrafficLight_StateFlow_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T Switch;                       /* '<Root>/Switch' */
  real_T G_LED;                        /* '<Root>/Chart' */
  real_T R_LED;                        /* '<Root>/Chart' */
  real_T Y_LED;                        /* '<Root>/Chart' */
} B_TrafficLight_StateFlow_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Input1' */
  codertarget_arduinobase_blo_m_T obj_h;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_blo_m_T obj_j;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_m_T obj_n;/* '<Root>/Digital Output' */
  real_T DelayOneStep_DSTATE;          /* '<Root>/Delay One Step' */
  real_T DelayOneStep1_DSTATE;         /* '<Root>/Delay One Step1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  uint32_T is_c3_TrafficLight_StateFlow;/* '<Root>/Chart' */
  uint32_T is_TrafficLight;            /* '<Root>/Chart' */
  boolean_T DelayInput1_DSTATE;        /* '<S2>/Delay Input1' */
  uint8_T is_active_c3_TrafficLight_State;/* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  boolean_T isNotInit;                 /* '<Root>/Chart' */
} DW_TrafficLight_StateFlow_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output3;                      /* '<Root>/Output3' */
} ExtY_TrafficLight_StateFlow_T;

/* Parameters (default storage) */
struct P_TrafficLight_StateFlow_T_ {
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S2>/Delay Input1'
                                      */
  real_T DigitalInput1_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T DelayOneStep_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<Root>/Delay One Step'
                                        */
  real_T DelayOneStep1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<Root>/Delay One Step1'
                                         */
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TrafficLight_StateFlo_T {
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
extern P_TrafficLight_StateFlow_T TrafficLight_StateFlow_P;

/* Block signals (default storage) */
extern B_TrafficLight_StateFlow_T TrafficLight_StateFlow_B;

/* Block states (default storage) */
extern DW_TrafficLight_StateFlow_T TrafficLight_StateFlow_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TrafficLight_StateFlow_T TrafficLight_StateFlow_Y;

/* Model entry point functions */
extern void TrafficLight_StateFlow_initialize(void);
extern void TrafficLight_StateFlow_step(void);
extern void TrafficLight_StateFlow_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TrafficLight_StateFl_T *const TrafficLight_StateFlow_M;
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
 * '<Root>' : 'TrafficLight_StateFlow'
 * '<S1>'   : 'TrafficLight_StateFlow/Chart'
 * '<S2>'   : 'TrafficLight_StateFlow/Detect Rise Positive'
 * '<S3>'   : 'TrafficLight_StateFlow/Detect Rise Positive/Positive'
 */
#endif                                 /* TrafficLight_StateFlow_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
