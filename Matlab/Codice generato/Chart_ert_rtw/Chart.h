/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Chart.h
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Feb 13 18:57:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef Chart_h_
#define Chart_h_
#ifndef Chart_COMMON_INCLUDES_
#define Chart_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Chart_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T B1State;                      /* '<Root>/Chart' */
  real_T B2State;                      /* '<Root>/Chart' */
  real_T Enc1;                         /* '<Root>/Chart' */
  real_T Enc2;                         /* '<Root>/Chart' */
  real_T Enc3;                         /* '<Root>/Chart' */
  real_T Enc4;                         /* '<Root>/Chart' */
  real_T PSX_LF;                       /* '<Root>/Chart' */
  real_T PSX_RS;                       /* '<Root>/Chart' */
  real_T Temp_B1;                      /* '<Root>/Chart' */
  real_T Temp_B2;                      /* '<Root>/Chart' */
  real_T countTempB1;                  /* '<Root>/Chart' */
  real_T countTempB2;                  /* '<Root>/Chart' */
  real_T sonar1;                       /* '<Root>/Chart' */
  real_T sonar2;                       /* '<Root>/Chart' */
  real_T sonar3;                       /* '<Root>/Chart' */
  real_T B1State_inB2;                 /* '<Root>/Chart' */
  real_T B2State_inB1;                 /* '<Root>/Chart' */
  real_T StatusBoardB2;                /* '<Root>/Chart' */
  real_T B1_decision;                  /* '<Root>/Chart' */
  real_T B1_pin;                       /* '<Root>/Chart' */
  real_T B2_decision;                  /* '<Root>/Chart' */
  real_T B2_pin;                       /* '<Root>/Chart' */
  real_T Board_state;                  /* '<Root>/Chart' */
  real_T final_decisionB1;             /* '<Root>/Chart' */
  real_T final_decisionB2;             /* '<Root>/Chart' */
  uint8_T is_active_c3_Chart;          /* '<Root>/Chart' */
  uint8_T is_BOARD1;                   /* '<Root>/Chart' */
  uint8_T is_ACTUATION_TASK_B1;        /* '<Root>/Chart' */
  uint8_T is_COMMUNICATION_TASK_B1;    /* '<Root>/Chart' */
  uint8_T is_EMERGENCY_ACTUATION_TASK_B1;/* '<Root>/Chart' */
  uint8_T is_READ_TASK_B1;             /* '<Root>/Chart' */
  uint8_T is_BOARD2;                   /* '<Root>/Chart' */
  uint8_T is_COMMUNICATION_TASK_B2;    /* '<Root>/Chart' */
  uint8_T is_DEGRADATED_ACTUATION_TASK_B2;/* '<Root>/Chart' */
  uint8_T is_EMERGENCY_ACTUATION_TASK_B2;/* '<Root>/Chart' */
  uint8_T is_READ_TASK_B2;             /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  uint8_T temporalCounter_i2;          /* '<Root>/Chart' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void Chart_initialize(void);
extern void Chart_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Stateflow_rover/Chart')    - opens subsystem Stateflow_rover/Chart
 * hilite_system('Stateflow_rover/Chart/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Stateflow_rover'
 * '<S1>'   : 'Stateflow_rover/Chart'
 */
#endif                                 /* Chart_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
