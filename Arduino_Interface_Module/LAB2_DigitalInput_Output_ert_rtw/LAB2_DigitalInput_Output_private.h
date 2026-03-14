/*
 * File: LAB2_DigitalInput_Output_private.h
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

#ifndef LAB2_DigitalInput_Output_private_h_
#define LAB2_DigitalInput_Output_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "LAB2_DigitalInput_Output.h"
#include "LAB2_DigitalInput_Output_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void LAB2_DigitalI_IfActionSubsystem(real_T *rty_Out1,
  P_IfActionSubsystem_LAB2_Digi_T *localP);

#endif                                 /* LAB2_DigitalInput_Output_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
