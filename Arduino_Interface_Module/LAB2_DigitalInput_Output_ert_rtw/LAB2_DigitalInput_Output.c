/*
 * File: LAB2_DigitalInput_Output.c
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

#include "LAB2_DigitalInput_Output.h"
#include "rtwtypes.h"
#include "LAB2_DigitalInput_Output_private.h"
#include <math.h>

/* Block signals (default storage) */
B_LAB2_DigitalInput_Output_T LAB2_DigitalInput_Output_B;

/* Block states (default storage) */
DW_LAB2_DigitalInput_Output_T LAB2_DigitalInput_Output_DW;

/* Real-time model */
static RT_MODEL_LAB2_DigitalInput_Ou_T LAB2_DigitalInput_Output_M_;
RT_MODEL_LAB2_DigitalInput_Ou_T *const LAB2_DigitalInput_Output_M =
  &LAB2_DigitalInput_Output_M_;

/*
 * Output and update for action system:
 *    '<Root>/If Action Subsystem'
 *    '<Root>/If Action Subsystem1'
 */
void LAB2_DigitalI_IfActionSubsystem(real_T *rty_Out1,
  P_IfActionSubsystem_LAB2_Digi_T *localP)
{
  /* SignalConversion generated from: '<S1>/Out1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

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
void LAB2_DigitalInput_Output_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (LAB2_DigitalInput_Output_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/Digital Input' */
  if (LAB2_DigitalInput_Output_DW.obj_d.SampleTime !=
      LAB2_DigitalInput_Output_P.DigitalInput_SampleTime) {
    LAB2_DigitalInput_Output_DW.obj_d.SampleTime =
      LAB2_DigitalInput_Output_P.DigitalInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  LAB2_DigitalInput_Output_B.DigitalInput = readDigitalPin(25);

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (LAB2_DigitalInput_Output_DW.obj.SampleTime !=
      LAB2_DigitalInput_Output_P.DigitalInput1_SampleTime) {
    LAB2_DigitalInput_Output_DW.obj.SampleTime =
      LAB2_DigitalInput_Output_P.DigitalInput1_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input1' */
  LAB2_DigitalInput_Output_B.DigitalInput1 = readDigitalPin(34);

  /* If: '<Root>/If' incorporates:
   *  Sum: '<Root>/Sum'
   */
  if ((int32_T)((uint32_T)LAB2_DigitalInput_Output_B.DigitalInput +
                LAB2_DigitalInput_Output_B.DigitalInput1) == 2) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    LAB2_DigitalI_IfActionSubsystem(&LAB2_DigitalInput_Output_B.Merge,
      &LAB2_DigitalInput_Output_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    LAB2_DigitalI_IfActionSubsystem(&LAB2_DigitalInput_Output_B.Merge,
      &LAB2_DigitalInput_Output_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
  }

  /* End of If: '<Root>/If' */
  /* MATLABSystem: '<Root>/Digital Output2' */
  tmp = rt_roundd_snf(LAB2_DigitalInput_Output_B.Merge);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(23, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LAB2_DigitalInput_Output_M->Timing.taskTime0 =
    ((time_T)(++LAB2_DigitalInput_Output_M->Timing.clockTick0)) *
    LAB2_DigitalInput_Output_M->Timing.stepSize0;
}

/* Model initialize function */
void LAB2_DigitalInput_Output_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(LAB2_DigitalInput_Output_M, -1);
  LAB2_DigitalInput_Output_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  LAB2_DigitalInput_Output_M->Sizes.checksums[0] = (4107477957U);
  LAB2_DigitalInput_Output_M->Sizes.checksums[1] = (4107767641U);
  LAB2_DigitalInput_Output_M->Sizes.checksums[2] = (2808945867U);
  LAB2_DigitalInput_Output_M->Sizes.checksums[3] = (2409784838U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    LAB2_DigitalInput_Output_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &LAB2_DigitalInput_Output_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &LAB2_DigitalInput_Output_DW.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(LAB2_DigitalInput_Output_M->extModeInfo,
      &LAB2_DigitalInput_Output_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB2_DigitalInput_Output_M->extModeInfo,
                        LAB2_DigitalInput_Output_M->Sizes.checksums);
    rteiSetTPtr(LAB2_DigitalInput_Output_M->extModeInfo, rtmGetTPtr
                (LAB2_DigitalInput_Output_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  LAB2_DigitalInput_Output_DW.obj_d.matlabCodegenIsDeleted = false;
  LAB2_DigitalInput_Output_DW.obj_d.SampleTime =
    LAB2_DigitalInput_Output_P.DigitalInput_SampleTime;
  LAB2_DigitalInput_Output_DW.obj_d.isInitialized = 1;
  digitalIOSetup(25, 0);
  LAB2_DigitalInput_Output_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  LAB2_DigitalInput_Output_DW.obj.matlabCodegenIsDeleted = false;
  LAB2_DigitalInput_Output_DW.obj.SampleTime =
    LAB2_DigitalInput_Output_P.DigitalInput1_SampleTime;
  LAB2_DigitalInput_Output_DW.obj.isInitialized = 1;
  digitalIOSetup(34, 0);
  LAB2_DigitalInput_Output_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  LAB2_DigitalInput_Output_DW.obj_b.matlabCodegenIsDeleted = false;
  LAB2_DigitalInput_Output_DW.obj_b.isInitialized = 1;
  digitalIOSetup(23, 1);
  LAB2_DigitalInput_Output_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void LAB2_DigitalInput_Output_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!LAB2_DigitalInput_Output_DW.obj_d.matlabCodegenIsDeleted) {
    LAB2_DigitalInput_Output_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!LAB2_DigitalInput_Output_DW.obj.matlabCodegenIsDeleted) {
    LAB2_DigitalInput_Output_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!LAB2_DigitalInput_Output_DW.obj_b.matlabCodegenIsDeleted) {
    LAB2_DigitalInput_Output_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
