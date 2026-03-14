/*
 * File: TrafficLight_StateFlow.c
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

#include "TrafficLight_StateFlow.h"
#include "rtwtypes.h"
#include "TrafficLight_StateFlow_private.h"
#include <math.h>

/* Named constants for Chart: '<Root>/Chart' */
#define TrafficLight_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define TrafficLight_St_IN_TrafficLight (2U)
#define TrafficLight_StateF_IN_Crossing (1U)
#define TrafficLight_StateFlo_IN_Yellow (3U)
#define TrafficLight_StateFlow_IN_Green (1U)
#define TrafficLight_StateFlow_IN_Red  (2U)

/* Block signals (default storage) */
B_TrafficLight_StateFlow_T TrafficLight_StateFlow_B;

/* Block states (default storage) */
DW_TrafficLight_StateFlow_T TrafficLight_StateFlow_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TrafficLight_StateFlow_T TrafficLight_StateFlow_Y;

/* Real-time model */
static RT_MODEL_TrafficLight_StateFl_T TrafficLight_StateFlow_M_;
RT_MODEL_TrafficLight_StateFl_T *const TrafficLight_StateFlow_M =
  &TrafficLight_StateFlow_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void TrafficLight_StateFlow_step(void)
{
  real_T tmp;
  uint8_T tmp_0;
  boolean_T rtb_Compare;

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (TrafficLight_StateFlow_DW.obj.SampleTime !=
      TrafficLight_StateFlow_P.DigitalInput1_SampleTime) {
    TrafficLight_StateFlow_DW.obj.SampleTime =
      TrafficLight_StateFlow_P.DigitalInput1_SampleTime;
  }

  rtb_Compare = readDigitalPin(34);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  MATLABSystem: '<Root>/Digital Input1'
   * */
  rtb_Compare = ((int32_T)rtb_Compare > (int32_T)
                 TrafficLight_StateFlow_P.Constant_Value);

  /* Switch: '<Root>/Switch' incorporates:
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((int32_T)rtb_Compare > (int32_T)
      TrafficLight_StateFlow_DW.DelayInput1_DSTATE) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Delay: '<Root>/Delay One Step'
     *  Logic: '<Root>/NOT'
     */
    TrafficLight_StateFlow_B.Switch =
      !(TrafficLight_StateFlow_DW.DelayOneStep_DSTATE != 0.0);
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Delay: '<Root>/Delay One Step1'
     */
    TrafficLight_StateFlow_B.Switch =
      TrafficLight_StateFlow_DW.DelayOneStep1_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Outport: '<Root>/Output3' */
  TrafficLight_StateFlow_Y.Output3 = TrafficLight_StateFlow_B.Switch;

  /* Chart: '<Root>/Chart' */
  if (TrafficLight_StateFlow_DW.isNotInit &&
      (TrafficLight_StateFlow_DW.temporalCounter_i1 < 63U)) {
    TrafficLight_StateFlow_DW.temporalCounter_i1++;
  }

  TrafficLight_StateFlow_DW.isNotInit = true;
  if (TrafficLight_StateFlow_DW.is_c3_TrafficLight_StateFlow ==
      TrafficLight_StateF_IN_Crossing) {
    if (TrafficLight_StateFlow_B.Switch == 1.0) {
      TrafficLight_StateFlow_DW.is_c3_TrafficLight_StateFlow =
        TrafficLight_St_IN_TrafficLight;
      TrafficLight_StateFlow_DW.temporalCounter_i1 = 0U;
      TrafficLight_StateFlow_DW.is_TrafficLight =
        TrafficLight_StateFlow_IN_Green;
    } else {
      TrafficLight_StateFlow_B.G_LED = 0.0;
      TrafficLight_StateFlow_B.Y_LED = 0.0;
      TrafficLight_StateFlow_B.R_LED = 0.0;
    }

    /* case IN_TrafficLight: */
  } else if (TrafficLight_StateFlow_B.Switch == 0.0) {
    TrafficLight_StateFlow_DW.is_TrafficLight = TrafficLight_IN_NO_ACTIVE_CHILD;
    TrafficLight_StateFlow_DW.is_c3_TrafficLight_StateFlow =
      TrafficLight_StateF_IN_Crossing;
  } else {
    switch (TrafficLight_StateFlow_DW.is_TrafficLight) {
     case TrafficLight_StateFlow_IN_Green:
      if (TrafficLight_StateFlow_DW.temporalCounter_i1 >= 50U) {
        TrafficLight_StateFlow_DW.temporalCounter_i1 = 0U;
        TrafficLight_StateFlow_DW.is_TrafficLight =
          TrafficLight_StateFlo_IN_Yellow;
      } else {
        TrafficLight_StateFlow_B.G_LED = 1.0;
        TrafficLight_StateFlow_B.Y_LED = 0.0;
        TrafficLight_StateFlow_B.R_LED = 0.0;
      }
      break;

     case TrafficLight_StateFlow_IN_Red:
      if (TrafficLight_StateFlow_DW.temporalCounter_i1 >= 50U) {
        TrafficLight_StateFlow_DW.temporalCounter_i1 = 0U;
        TrafficLight_StateFlow_DW.is_TrafficLight =
          TrafficLight_StateFlow_IN_Green;
      } else {
        TrafficLight_StateFlow_B.G_LED = 0.0;
        TrafficLight_StateFlow_B.Y_LED = 0.0;
        TrafficLight_StateFlow_B.R_LED = 1.0;
      }
      break;

     default:
      /* case IN_Yellow: */
      if (TrafficLight_StateFlow_DW.temporalCounter_i1 >= 50U) {
        TrafficLight_StateFlow_DW.temporalCounter_i1 = 0U;
        TrafficLight_StateFlow_DW.is_TrafficLight =
          TrafficLight_StateFlow_IN_Red;
      } else {
        TrafficLight_StateFlow_B.G_LED = 0.0;
        TrafficLight_StateFlow_B.Y_LED = 1.0;
        TrafficLight_StateFlow_B.R_LED = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(TrafficLight_StateFlow_B.G_LED);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(25, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  tmp = rt_roundd_snf(TrafficLight_StateFlow_B.Y_LED);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(32, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/Digital Output3' */
  tmp = rt_roundd_snf(TrafficLight_StateFlow_B.R_LED);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(33, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output3' */
  /* Update for Delay: '<Root>/Delay One Step' */
  TrafficLight_StateFlow_DW.DelayOneStep_DSTATE =
    TrafficLight_StateFlow_B.Switch;

  /* Update for UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  TrafficLight_StateFlow_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for Delay: '<Root>/Delay One Step1' */
  TrafficLight_StateFlow_DW.DelayOneStep1_DSTATE =
    TrafficLight_StateFlow_B.Switch;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  TrafficLight_StateFlow_M->Timing.taskTime0 =
    ((time_T)(++TrafficLight_StateFlow_M->Timing.clockTick0)) *
    TrafficLight_StateFlow_M->Timing.stepSize0;
}

/* Model initialize function */
void TrafficLight_StateFlow_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(TrafficLight_StateFlow_M, -1);
  TrafficLight_StateFlow_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  TrafficLight_StateFlow_M->Sizes.checksums[0] = (3687799967U);
  TrafficLight_StateFlow_M->Sizes.checksums[1] = (877088426U);
  TrafficLight_StateFlow_M->Sizes.checksums[2] = (2206038693U);
  TrafficLight_StateFlow_M->Sizes.checksums[3] = (4192271425U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    TrafficLight_StateFlow_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TrafficLight_StateFlow_M->extModeInfo,
      &TrafficLight_StateFlow_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TrafficLight_StateFlow_M->extModeInfo,
                        TrafficLight_StateFlow_M->Sizes.checksums);
    rteiSetTPtr(TrafficLight_StateFlow_M->extModeInfo, rtmGetTPtr
                (TrafficLight_StateFlow_M));
  }

  /* InitializeConditions for Delay: '<Root>/Delay One Step' */
  TrafficLight_StateFlow_DW.DelayOneStep_DSTATE =
    TrafficLight_StateFlow_P.DelayOneStep_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  TrafficLight_StateFlow_DW.DelayInput1_DSTATE =
    TrafficLight_StateFlow_P.DetectRisePositive_vinit;

  /* InitializeConditions for Delay: '<Root>/Delay One Step1' */
  TrafficLight_StateFlow_DW.DelayOneStep1_DSTATE =
    TrafficLight_StateFlow_P.DelayOneStep1_InitialCondition;

  /* Chart: '<Root>/Chart' */
  TrafficLight_StateFlow_DW.is_active_c3_TrafficLight_State = 1U;
  TrafficLight_StateFlow_DW.is_c3_TrafficLight_StateFlow =
    TrafficLight_StateF_IN_Crossing;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  TrafficLight_StateFlow_DW.obj.matlabCodegenIsDeleted = false;
  TrafficLight_StateFlow_DW.obj.SampleTime =
    TrafficLight_StateFlow_P.DigitalInput1_SampleTime;
  TrafficLight_StateFlow_DW.obj.isInitialized = 1;
  digitalIOSetup(34, 0);
  TrafficLight_StateFlow_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  TrafficLight_StateFlow_DW.obj_n.matlabCodegenIsDeleted = false;
  TrafficLight_StateFlow_DW.obj_n.isInitialized = 1;
  digitalIOSetup(25, 1);
  TrafficLight_StateFlow_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  TrafficLight_StateFlow_DW.obj_j.matlabCodegenIsDeleted = false;
  TrafficLight_StateFlow_DW.obj_j.isInitialized = 1;
  digitalIOSetup(32, 1);
  TrafficLight_StateFlow_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  TrafficLight_StateFlow_DW.obj_h.matlabCodegenIsDeleted = false;
  TrafficLight_StateFlow_DW.obj_h.isInitialized = 1;
  digitalIOSetup(33, 1);
  TrafficLight_StateFlow_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void TrafficLight_StateFlow_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!TrafficLight_StateFlow_DW.obj.matlabCodegenIsDeleted) {
    TrafficLight_StateFlow_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!TrafficLight_StateFlow_DW.obj_n.matlabCodegenIsDeleted) {
    TrafficLight_StateFlow_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!TrafficLight_StateFlow_DW.obj_j.matlabCodegenIsDeleted) {
    TrafficLight_StateFlow_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!TrafficLight_StateFlow_DW.obj_h.matlabCodegenIsDeleted) {
    TrafficLight_StateFlow_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
