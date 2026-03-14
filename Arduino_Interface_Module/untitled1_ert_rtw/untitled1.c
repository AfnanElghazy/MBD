/*
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 14 04:54:46 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "rtwtypes.h"
#include "untitled1_private.h"

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

/* Model step function */
void untitled1_step(void)
{
  uint32_T duration;

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (untitled1_DW.obj.TunablePropsChanged) {
    untitled1_DW.obj.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 32, 25, 10);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  untitled1_B.UltrasonicSensor = (real_T)duration * 0.000343 / 2.0;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled1_M->Timing.taskTime0 =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled1_M, -1);
  untitled1_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (3130387668U);
  untitled1_M->Sizes.checksums[1] = (418048483U);
  untitled1_M->Sizes.checksums[2] = (958910513U);
  untitled1_M->Sizes.checksums[3] = (2362617875U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  untitled1_DW.obj.isInitialized = 1;
  MW_UltrasonicSetup(32, 25);
  untitled1_DW.obj.TunablePropsChanged = false;
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
