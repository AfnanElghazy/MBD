/*
 * File: TrafficLight.c
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
#include "TrafficLight_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals (default storage) */
B_TrafficLight_T TrafficLight_B;

/* Block states (default storage) */
DW_TrafficLight_T TrafficLight_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TrafficLight_T TrafficLight_Y;

/* Real-time model */
static RT_MODEL_TrafficLight_T TrafficLight_M_;
RT_MODEL_TrafficLight_T *const TrafficLight_M = &TrafficLight_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void TrafficLight_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_Compare;
  boolean_T c_value;

  /* Reset subsysRan breadcrumbs */
  srClearBC(TrafficLight_DW.Subsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/Digital Input' */
  if (TrafficLight_DW.obj.SampleTime != TrafficLight_P.DigitalInput_SampleTime)
  {
    TrafficLight_DW.obj.SampleTime = TrafficLight_P.DigitalInput_SampleTime;
  }

  c_value = readDigitalPin(34);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  MATLABSystem: '<Root>/Digital Input'
   * */
  rtb_Compare = ((int32_T)c_value > (int32_T)TrafficLight_P.Constant_Value);

  /* Switch: '<Root>/Switch' incorporates:
   *  RelationalOperator: '<S1>/FixPt Relational Operator'
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((int32_T)rtb_Compare > (int32_T)TrafficLight_DW.DelayInput1_DSTATE) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Delay: '<Root>/Delay One Step'
     *  Logic: '<Root>/NOT'
     */
    TrafficLight_B.Switch = !TrafficLight_DW.DelayOneStep_DSTATE;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Delay: '<Root>/Delay One Step1'
     */
    TrafficLight_B.Switch = TrafficLight_DW.DelayOneStep1_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (TrafficLight_B.Switch) {
    /* Clock: '<S2>/Clock' */
    TrafficLight_B.Clock = TrafficLight_M->Timing.t[0];

    /* Math: '<S2>/Mod' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    TrafficLight_B.Mod = rt_modd_snf(TrafficLight_B.Clock,
      TrafficLight_P.Constant2_Value);

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     */
    TrafficLight_B.Compare = (TrafficLight_B.Mod <=
      TrafficLight_P.CompareToConstant_const);

    /* MATLABSystem: '<S2>/Digital Output' */
    writeDigitalPin(25, (uint8_T)TrafficLight_B.Compare);

    /* Logic: '<S2>/AND' incorporates:
     *  Constant: '<S5>/Constant'
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     *  RelationalOperator: '<S6>/Compare'
     */
    TrafficLight_B.AND = ((TrafficLight_B.Mod >
      TrafficLight_P.CompareToConstant1_const) && (TrafficLight_B.Mod <=
      TrafficLight_P.CompareToConstant2_const));

    /* MATLABSystem: '<S2>/Digital Output1' */
    writeDigitalPin(32, (uint8_T)TrafficLight_B.AND);

    /* RelationalOperator: '<S7>/Compare' incorporates:
     *  Constant: '<S7>/Constant'
     */
    TrafficLight_B.Compare_k = (TrafficLight_B.Mod >
      TrafficLight_P.CompareToConstant4_const);

    /* MATLABSystem: '<S2>/Digital Output2' */
    writeDigitalPin(33, (uint8_T)TrafficLight_B.Compare_k);
    srUpdateBC(TrafficLight_DW.Subsystem_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Output' */
  TrafficLight_Y.Output = TrafficLight_B.Switch;

  /* Outport: '<Root>/Green' */
  TrafficLight_Y.Green = TrafficLight_B.Compare;

  /* Outport: '<Root>/Yellow' */
  TrafficLight_Y.Yellow = TrafficLight_B.AND;

  /* Outport: '<Root>/Red' */
  TrafficLight_Y.Red = TrafficLight_B.Compare_k;

  /* Update for Delay: '<Root>/Delay One Step' */
  TrafficLight_DW.DelayOneStep_DSTATE = TrafficLight_B.Switch;

  /* Update for UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  TrafficLight_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for Delay: '<Root>/Delay One Step1' */
  TrafficLight_DW.DelayOneStep1_DSTATE = TrafficLight_B.Switch;

  {                                    /* Sample time: [0.2s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((TrafficLight_M->Timing.clockTick1) * 0.2);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  TrafficLight_M->Timing.t[0] =
    ((time_T)(++TrafficLight_M->Timing.clockTick0)) *
    TrafficLight_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    TrafficLight_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void TrafficLight_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TrafficLight_M->solverInfo,
                          &TrafficLight_M->Timing.simTimeStep);
    rtsiSetTPtr(&TrafficLight_M->solverInfo, &rtmGetTPtr(TrafficLight_M));
    rtsiSetStepSizePtr(&TrafficLight_M->solverInfo,
                       &TrafficLight_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&TrafficLight_M->solverInfo, (&rtmGetErrorStatus
      (TrafficLight_M)));
    rtsiSetRTModelPtr(&TrafficLight_M->solverInfo, TrafficLight_M);
  }

  rtsiSetSimTimeStep(&TrafficLight_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&TrafficLight_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&TrafficLight_M->solverInfo, false);
  rtsiSetSolverName(&TrafficLight_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(TrafficLight_M, &TrafficLight_M->Timing.tArray[0]);
  rtmSetTFinal(TrafficLight_M, -1);
  TrafficLight_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  TrafficLight_M->Sizes.checksums[0] = (2927066691U);
  TrafficLight_M->Sizes.checksums[1] = (312597664U);
  TrafficLight_M->Sizes.checksums[2] = (2417768547U);
  TrafficLight_M->Sizes.checksums[3] = (3257665063U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    TrafficLight_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&TrafficLight_DW.Subsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&TrafficLight_DW.Subsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&TrafficLight_DW.Subsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&TrafficLight_DW.Subsystem_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TrafficLight_M->extModeInfo,
      &TrafficLight_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TrafficLight_M->extModeInfo,
                        TrafficLight_M->Sizes.checksums);
    rteiSetTPtr(TrafficLight_M->extModeInfo, rtmGetTPtr(TrafficLight_M));
  }

  /* InitializeConditions for Delay: '<Root>/Delay One Step' */
  TrafficLight_DW.DelayOneStep_DSTATE =
    TrafficLight_P.DelayOneStep_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  TrafficLight_DW.DelayInput1_DSTATE = TrafficLight_P.DetectRisePositive_vinit;

  /* InitializeConditions for Delay: '<Root>/Delay One Step1' */
  TrafficLight_DW.DelayOneStep1_DSTATE =
    TrafficLight_P.DelayOneStep1_InitialCondition;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  TrafficLight_DW.obj_n.matlabCodegenIsDeleted = false;
  TrafficLight_DW.obj_n.isInitialized = 1;
  digitalIOSetup(25, 1);
  TrafficLight_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output1' */
  TrafficLight_DW.obj_j.matlabCodegenIsDeleted = false;
  TrafficLight_DW.obj_j.isInitialized = 1;
  digitalIOSetup(32, 1);
  TrafficLight_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output2' */
  TrafficLight_DW.obj_l.matlabCodegenIsDeleted = false;
  TrafficLight_DW.obj_l.isInitialized = 1;
  digitalIOSetup(33, 1);
  TrafficLight_DW.obj_l.isSetupComplete = true;

  /* SystemInitialize for RelationalOperator: '<S4>/Compare' incorporates:
   *  Outport: '<S2>/Green'
   */
  TrafficLight_B.Compare = TrafficLight_P.Green_Y0;

  /* SystemInitialize for Logic: '<S2>/AND' incorporates:
   *  Outport: '<S2>/Yellow'
   */
  TrafficLight_B.AND = TrafficLight_P.Yellow_Y0;

  /* SystemInitialize for RelationalOperator: '<S7>/Compare' incorporates:
   *  Outport: '<S2>/Red'
   */
  TrafficLight_B.Compare_k = TrafficLight_P.Red_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  TrafficLight_DW.obj.matlabCodegenIsDeleted = false;
  TrafficLight_DW.obj.SampleTime = TrafficLight_P.DigitalInput_SampleTime;
  TrafficLight_DW.obj.isInitialized = 1;
  digitalIOSetup(34, 0);
  TrafficLight_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void TrafficLight_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!TrafficLight_DW.obj.matlabCodegenIsDeleted) {
    TrafficLight_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!TrafficLight_DW.obj_n.matlabCodegenIsDeleted) {
    TrafficLight_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output1' */
  if (!TrafficLight_DW.obj_j.matlabCodegenIsDeleted) {
    TrafficLight_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output2' */
  if (!TrafficLight_DW.obj_l.matlabCodegenIsDeleted) {
    TrafficLight_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
