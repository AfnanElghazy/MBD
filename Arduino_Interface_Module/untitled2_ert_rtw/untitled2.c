/*
 * File: untitled2.c
 *
 * Code generated for Simulink model 'untitled2'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 14 07:29:22 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled2.h"
#include "untitled2_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals (default storage) */
B_untitled2_T untitled2_B;

/* Block states (default storage) */
DW_untitled2_T untitled2_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled2_T untitled2_Y;

/* Real-time model */
static RT_MODEL_untitled2_T untitled2_M_;
RT_MODEL_untitled2_T *const untitled2_M = &untitled2_M_;
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
void untitled2_step(void)
{
  /* Clock: '<Root>/Clock' */
  untitled2_B.Clock = untitled2_M->Timing.t[0];

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  untitled2_B.Mod = rt_modd_snf(untitled2_B.Clock, untitled2_P.Constant2_Value);

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  untitled2_B.Compare = (untitled2_B.Mod <= untitled2_P.CompareToConstant_const);

  /* Outport: '<Root>/Green' */
  untitled2_Y.Green = untitled2_B.Compare;

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(25, (uint8_T)untitled2_B.Compare);

  /* Logic: '<Root>/AND' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   */
  untitled2_B.AND = ((untitled2_B.Mod > untitled2_P.CompareToConstant1_const) &&
                     (untitled2_B.Mod <= untitled2_P.CompareToConstant2_const));

  /* Outport: '<Root>/Yellow' */
  untitled2_Y.Yellow = untitled2_B.AND;

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(32, (uint8_T)untitled2_B.AND);

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  untitled2_B.Compare_k = (untitled2_B.Mod >
    untitled2_P.CompareToConstant4_const);

  /* Outport: '<Root>/Red' */
  untitled2_Y.Red = untitled2_B.Compare_k;

  /* MATLABSystem: '<Root>/Digital Output2' */
  writeDigitalPin(33, (uint8_T)untitled2_B.Compare_k);

  {                                    /* Sample time: [0.2s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((untitled2_M->Timing.clockTick1) * 0.2);

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
  untitled2_M->Timing.t[0] =
    ((time_T)(++untitled2_M->Timing.clockTick0)) * untitled2_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled2_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled2_M->solverInfo,
                          &untitled2_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled2_M->solverInfo, &rtmGetTPtr(untitled2_M));
    rtsiSetStepSizePtr(&untitled2_M->solverInfo, &untitled2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled2_M->solverInfo, (&rtmGetErrorStatus
      (untitled2_M)));
    rtsiSetRTModelPtr(&untitled2_M->solverInfo, untitled2_M);
  }

  rtsiSetSimTimeStep(&untitled2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled2_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&untitled2_M->solverInfo, false);
  rtsiSetSolverName(&untitled2_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled2_M, &untitled2_M->Timing.tArray[0]);
  rtmSetTFinal(untitled2_M, -1);
  untitled2_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  untitled2_M->Sizes.checksums[0] = (4282338437U);
  untitled2_M->Sizes.checksums[1] = (3784819082U);
  untitled2_M->Sizes.checksums[2] = (3568766994U);
  untitled2_M->Sizes.checksums[3] = (2623433718U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled2_M->extModeInfo,
      &untitled2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled2_M->extModeInfo, untitled2_M->Sizes.checksums);
    rteiSetTPtr(untitled2_M->extModeInfo, rtmGetTPtr(untitled2_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  untitled2_DW.obj_n.matlabCodegenIsDeleted = false;
  untitled2_DW.obj_n.isInitialized = 1;
  digitalIOSetup(25, 1);
  untitled2_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  untitled2_DW.obj_j.matlabCodegenIsDeleted = false;
  untitled2_DW.obj_j.isInitialized = 1;
  digitalIOSetup(32, 1);
  untitled2_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  untitled2_DW.obj.matlabCodegenIsDeleted = false;
  untitled2_DW.obj.isInitialized = 1;
  digitalIOSetup(33, 1);
  untitled2_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled2_DW.obj_n.matlabCodegenIsDeleted) {
    untitled2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!untitled2_DW.obj_j.matlabCodegenIsDeleted) {
    untitled2_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!untitled2_DW.obj.matlabCodegenIsDeleted) {
    untitled2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
