/*
 * File: TrafficLight.h
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

#ifndef TrafficLight_h_
#define TrafficLight_h_
#ifndef TrafficLight_COMMON_INCLUDES_
#define TrafficLight_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* TrafficLight_COMMON_INCLUDES_ */

#include "TrafficLight_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Clock;                        /* '<S2>/Clock' */
  real_T Mod;                          /* '<S2>/Mod' */
  boolean_T Switch;                    /* '<Root>/Switch' */
  boolean_T Compare;                   /* '<S4>/Compare' */
  boolean_T AND;                       /* '<S2>/AND' */
  boolean_T Compare_k;                 /* '<S7>/Compare' */
} B_TrafficLight_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_d_T obj_l;/* '<S2>/Digital Output2' */
  codertarget_arduinobase_blo_d_T obj_j;/* '<S2>/Digital Output1' */
  codertarget_arduinobase_blo_d_T obj_n;/* '<S2>/Digital Output' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T DelayOneStep_DSTATE;       /* '<Root>/Delay One Step' */
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
  boolean_T DelayOneStep1_DSTATE;      /* '<Root>/Delay One Step1' */
  int8_T Subsystem_SubsysRanBC;        /* '<Root>/Subsystem' */
} DW_TrafficLight_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Green;                     /* '<Root>/Green' */
  boolean_T Yellow;                    /* '<Root>/Yellow' */
  boolean_T Red;                       /* '<Root>/Red' */
  boolean_T Output;                    /* '<Root>/Output' */
} ExtY_TrafficLight_T;

/* Parameters (default storage) */
struct P_TrafficLight_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S4>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S5>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S6>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S7>/Constant'
                                      */
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S1>/Delay Input1'
                                      */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant2_Value;              /* Expression: 31
                                        * Referenced by: '<S2>/Constant2'
                                        */
  boolean_T Green_Y0;                  /* Computed Parameter: Green_Y0
                                        * Referenced by: '<S2>/Green'
                                        */
  boolean_T Yellow_Y0;                 /* Computed Parameter: Yellow_Y0
                                        * Referenced by: '<S2>/Yellow'
                                        */
  boolean_T Red_Y0;                    /* Computed Parameter: Red_Y0
                                        * Referenced by: '<S2>/Red'
                                        */
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  boolean_T DelayOneStep_InitialCondition;
                            /* Computed Parameter: DelayOneStep_InitialCondition
                             * Referenced by: '<Root>/Delay One Step'
                             */
  boolean_T DelayOneStep1_InitialCondition;
                           /* Computed Parameter: DelayOneStep1_InitialCondition
                            * Referenced by: '<Root>/Delay One Step1'
                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_TrafficLight_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_TrafficLight_T TrafficLight_P;

/* Block signals (default storage) */
extern B_TrafficLight_T TrafficLight_B;

/* Block states (default storage) */
extern DW_TrafficLight_T TrafficLight_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TrafficLight_T TrafficLight_Y;

/* Model entry point functions */
extern void TrafficLight_initialize(void);
extern void TrafficLight_step(void);
extern void TrafficLight_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TrafficLight_T *const TrafficLight_M;
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
 * '<Root>' : 'TrafficLight'
 * '<S1>'   : 'TrafficLight/Detect Rise Positive'
 * '<S2>'   : 'TrafficLight/Subsystem'
 * '<S3>'   : 'TrafficLight/Detect Rise Positive/Positive'
 * '<S4>'   : 'TrafficLight/Subsystem/Compare To Constant'
 * '<S5>'   : 'TrafficLight/Subsystem/Compare To Constant1'
 * '<S6>'   : 'TrafficLight/Subsystem/Compare To Constant2'
 * '<S7>'   : 'TrafficLight/Subsystem/Compare To Constant4'
 */
#endif                                 /* TrafficLight_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
