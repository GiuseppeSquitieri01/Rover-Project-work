/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Chart.c
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

#include "Chart.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define IN_ACTUATION                   ((uint8_T)1U)
#define IN_ACTUATION_TASK_B1           ((uint8_T)1U)
#define IN_COMMUNICATION_TASK_B1       ((uint8_T)2U)
#define IN_COMMUNICATION_TASK_B2       ((uint8_T)1U)
#define IN_COMPUTE_FINAL_DECISION      ((uint8_T)1U)
#define IN_CONTROL2                    ((uint8_T)2U)
#define IN_CONTROL_DECISION            ((uint8_T)1U)
#define IN_CONTROL_DECISION_e          ((uint8_T)3U)
#define IN_DECISION                    ((uint8_T)2U)
#define IN_DECISION_i                  ((uint8_T)4U)
#define IN_DEGRADATED_ACTUATION_TASK_B2 ((uint8_T)2U)
#define IN_EMERGENCY_ACTUATION_TASK_B1 ((uint8_T)3U)
#define IN_EMERGENCY_ACTUATION_TASK_B2 ((uint8_T)3U)
#define IN_END_ACT                     ((uint8_T)2U)
#define IN_END_COMM                    ((uint8_T)5U)
#define IN_END_EM                      ((uint8_T)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_READ_OK                     ((uint8_T)1U)
#define IN_READ_TASK_B1                ((uint8_T)4U)
#define IN_READ_TASK_B2                ((uint8_T)4U)
#define IN_RECEIVE_DATA                ((uint8_T)6U)
#define IN_RECEIVE_FINAL_DECISION      ((uint8_T)3U)
#define IN_SEND_DATA                   ((uint8_T)4U)
#define IN_SEND_DATA_c                 ((uint8_T)7U)
#define IN_SEND_FINAL_DECISION         ((uint8_T)8U)
#define IN_SEND_FINAL_DECISION1        ((uint8_T)9U)
#define IN_START                       ((uint8_T)5U)
#define IN_START1                      ((uint8_T)3U)
#define IN_START_b                     ((uint8_T)3U)
#define IN_START_b5                    ((uint8_T)2U)
#define IN_START_b54                   ((uint8_T)10U)
#define IN_TIMEOUT                     ((uint8_T)6U)
#define IN_TIMEOUT_b                   ((uint8_T)11U)
#define IN_WAIT_B2                     ((uint8_T)7U)

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void BOARD2(void);

/* Function for Chart: '<Root>/Chart' */
static void BOARD2(void)
{
  switch (rtDW.is_BOARD2) {
   case IN_COMMUNICATION_TASK_B2:
    switch (rtDW.is_COMMUNICATION_TASK_B2) {
     case IN_COMPUTE_FINAL_DECISION:
      rtDW.final_decisionB2 = (rtDW.B1_decision == rtDW.B2_decision);
      rtDW.is_COMMUNICATION_TASK_B2 = IN_SEND_FINAL_DECISION;
      break;

     case IN_CONTROL2:
      rtDW.StatusBoardB2 = (rtDW.B2State == 1.0);
      rtDW.is_COMMUNICATION_TASK_B2 = IN_END_COMM;
      break;

     case IN_CONTROL_DECISION_e:
      if (rtDW.final_decisionB2 == 1.0) {
        rtDW.is_COMMUNICATION_TASK_B2 = IN_END_COMM;
      } else {
        rtDW.is_COMMUNICATION_TASK_B2 = IN_CONTROL2;
      }
      break;

     case IN_DECISION_i:
      if ((rtDW.B1State_inB2 == 1.0) && (rtDW.B2State == 0.0)) {
        rtDW.B2_decision = 0.0;
      } else if ((rtDW.B1State_inB2 == 1.0) && (rtDW.B2State == 1.0)) {
        rtDW.B2_decision = 1.0;
      } else if (rtDW.B2State == 1.0) {
        rtDW.B2_decision = 0.0;
        rtDW.StatusBoardB2 = 1.0;
      } else {
        rtDW.B2_decision = 3.0;
        rtDW.StatusBoardB2 = 0.0;
      }

      rtDW.is_COMMUNICATION_TASK_B2 = IN_COMPUTE_FINAL_DECISION;
      break;

     case IN_END_COMM:
      rtDW.is_COMMUNICATION_TASK_B2 = IN_NO_ACTIVE_CHILD;
      rtDW.is_BOARD2 = IN_DEGRADATED_ACTUATION_TASK_B2;
      rtDW.is_DEGRADATED_ACTUATION_TASK_B2 = IN_START1;
      break;

     case IN_RECEIVE_DATA:
      if (rtDW.B1_pin == 1.0) {
        rtDW.B2_pin = 0.0;
        rtDW.is_COMMUNICATION_TASK_B2 = IN_DECISION_i;
      } else if (rtDW.temporalCounter_i2 >= 10U) {
        rtDW.is_COMMUNICATION_TASK_B2 = IN_TIMEOUT_b;
        rtDW.StatusBoardB2 = 0.0;
      }
      break;

     case IN_SEND_DATA_c:
      if (rtDW.B1_pin == 1.0) {
        rtDW.B2_pin = 0.0;
        rtDW.temporalCounter_i2 = 0U;
        rtDW.is_COMMUNICATION_TASK_B2 = IN_RECEIVE_DATA;
      } else if (rtDW.temporalCounter_i2 >= 10U) {
        rtDW.is_COMMUNICATION_TASK_B2 = IN_TIMEOUT_b;
        rtDW.StatusBoardB2 = 0.0;
      }
      break;

     case IN_SEND_FINAL_DECISION:
      rtDW.B2_pin = 1.0;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_COMMUNICATION_TASK_B2 = IN_SEND_FINAL_DECISION1;
      break;

     case IN_SEND_FINAL_DECISION1:
      if (rtDW.B1_pin == 1.0) {
        rtDW.B2_pin = 0.0;
        rtDW.is_COMMUNICATION_TASK_B2 = IN_CONTROL_DECISION_e;
      } else if (rtDW.temporalCounter_i2 >= 10U) {
        rtDW.is_COMMUNICATION_TASK_B2 = IN_TIMEOUT_b;
        rtDW.StatusBoardB2 = 0.0;
      }
      break;

     case IN_START_b54:
      rtDW.B2_pin = 1.0;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_COMMUNICATION_TASK_B2 = IN_SEND_DATA_c;
      break;

     default:
      /* case IN_TIMEOUT: */
      break;
    }
    break;

   case IN_DEGRADATED_ACTUATION_TASK_B2:
    switch (rtDW.is_DEGRADATED_ACTUATION_TASK_B2) {
     case IN_ACTUATION:
      rtDW.is_DEGRADATED_ACTUATION_TASK_B2 = IN_END_ACT;
      break;

     case IN_END_ACT:
      rtDW.is_DEGRADATED_ACTUATION_TASK_B2 = IN_NO_ACTIVE_CHILD;
      rtDW.is_BOARD2 = IN_EMERGENCY_ACTUATION_TASK_B2;
      rtDW.is_EMERGENCY_ACTUATION_TASK_B2 = IN_START_b;
      break;

     default:
      /* case IN_START1: */
      if (rtDW.StatusBoardB2 == 1.0) {
        rtDW.is_DEGRADATED_ACTUATION_TASK_B2 = IN_ACTUATION;
      } else {
        rtDW.is_DEGRADATED_ACTUATION_TASK_B2 = IN_END_ACT;
      }
      break;
    }
    break;

   case IN_EMERGENCY_ACTUATION_TASK_B2:
    switch (rtDW.is_EMERGENCY_ACTUATION_TASK_B2) {
     case IN_ACTUATION:
      rtDW.is_EMERGENCY_ACTUATION_TASK_B2 = IN_END_EM;
      break;

     case IN_END_EM:
      rtDW.is_EMERGENCY_ACTUATION_TASK_B2 = IN_NO_ACTIVE_CHILD;
      rtDW.is_BOARD2 = IN_READ_TASK_B2;
      rtDW.is_READ_TASK_B2 = IN_START_b5;
      rtDW.sonar1 = 0.0;
      rtDW.sonar2 = 0.0;
      rtDW.sonar3 = 0.0;
      rtDW.PSX_LF = 0.0;
      rtDW.PSX_RS = 0.0;
      rtDW.Temp_B2 = 0.0;
      break;

     default:
      /* case IN_START: */
      if (rtDW.StatusBoardB2 == 1.0) {
        rtDW.is_EMERGENCY_ACTUATION_TASK_B2 = IN_ACTUATION;
      } else {
        rtDW.is_EMERGENCY_ACTUATION_TASK_B2 = IN_END_EM;
      }
      break;
    }
    break;

   default:
    /* case IN_READ_TASK_B2: */
    if (rtDW.is_READ_TASK_B2 == IN_READ_OK) {
      rtDW.B2State = ((rtDW.sonar1 >= 0.0) && (rtDW.sonar2 >= 0.0) &&
                      (rtDW.sonar3 >= 0.0) && (rtDW.PSX_LF > 0.0) &&
                      (rtDW.PSX_RS > 0.0) && (rtDW.countTempB2 <= 200.0));
      rtDW.is_READ_TASK_B2 = IN_NO_ACTIVE_CHILD;
      rtDW.is_BOARD2 = IN_COMMUNICATION_TASK_B2;
      rtDW.is_COMMUNICATION_TASK_B2 = IN_START_b54;
      rtDW.StatusBoardB2 = 0.0;
      rtDW.B1State_inB2 = 0.0;
      rtDW.final_decisionB2 = 3.0;
    } else {
      /* case IN_START: */
      rtDW.is_READ_TASK_B2 = IN_READ_OK;
      if ((rtDW.Temp_B2 >= 90.0) || (rtDW.Temp_B2 == 0.0)) {
        rtDW.countTempB2++;
      } else {
        rtDW.countTempB2 = 0.0;
      }
    }
    break;
  }
}

/* Model step function */
void Chart_step(void)
{
  /* Chart: '<Root>/Chart' */
  if (rtDW.temporalCounter_i1 < 127U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < 15U) {
    rtDW.temporalCounter_i2++;
  }

  if (rtDW.is_active_c3_Chart == 0U) {
    rtDW.is_active_c3_Chart = 1U;
    rtDW.is_BOARD1 = IN_READ_TASK_B1;
    rtDW.is_READ_TASK_B1 = IN_START_b5;
    rtDW.Enc1 = 0.0;
    rtDW.Enc2 = 0.0;
    rtDW.Enc3 = 0.0;
    rtDW.Enc4 = 0.0;
    rtDW.Temp_B1 = 0.0;
    rtDW.is_BOARD2 = IN_READ_TASK_B2;
    rtDW.is_READ_TASK_B2 = IN_START_b5;
    rtDW.sonar1 = 0.0;
    rtDW.sonar2 = 0.0;
    rtDW.sonar3 = 0.0;
    rtDW.PSX_LF = 0.0;
    rtDW.PSX_RS = 0.0;
    rtDW.Temp_B2 = 0.0;
  } else {
    switch (rtDW.is_BOARD1) {
     case IN_ACTUATION_TASK_B1:
      switch (rtDW.is_ACTUATION_TASK_B1) {
       case IN_ACTUATION:
        rtDW.is_ACTUATION_TASK_B1 = IN_END_ACT;
        break;

       case IN_END_ACT:
        rtDW.is_ACTUATION_TASK_B1 = IN_NO_ACTIVE_CHILD;
        rtDW.is_BOARD1 = IN_EMERGENCY_ACTUATION_TASK_B1;
        rtDW.is_EMERGENCY_ACTUATION_TASK_B1 = IN_START_b;
        break;

       default:
        /* case IN_START1: */
        if (rtDW.Board_state == 1.0) {
          rtDW.is_ACTUATION_TASK_B1 = IN_ACTUATION;
        } else {
          rtDW.is_ACTUATION_TASK_B1 = IN_END_ACT;
        }
        break;
      }
      break;

     case IN_COMMUNICATION_TASK_B1:
      switch (rtDW.is_COMMUNICATION_TASK_B1) {
       case IN_CONTROL_DECISION:
        if (rtDW.final_decisionB1 != 1.0) {
          rtDW.Board_state = 3.0;
        }

        rtDW.is_COMMUNICATION_TASK_B1 = IN_NO_ACTIVE_CHILD;
        rtDW.is_BOARD1 = IN_ACTUATION_TASK_B1;
        rtDW.is_ACTUATION_TASK_B1 = IN_START1;
        break;

       case IN_DECISION:
        if ((rtDW.B1State == 1.0) && (rtDW.B2State_inB1 == 0.0)) {
          rtDW.Board_state = 0.0;
          rtDW.B1_decision = 0.0;
        } else if ((rtDW.B1State == 1.0) && (rtDW.B2State_inB1 == 1.0)) {
          rtDW.Board_state = 1.0;
          rtDW.B1_decision = 1.0;
        } else if (rtDW.B2State_inB1 == 1.0) {
          rtDW.B1_decision = 2.0;
        } else {
          rtDW.B1_decision = 3.0;
        }

        rtDW.is_COMMUNICATION_TASK_B1 = IN_SEND_DATA;
        break;

       case IN_RECEIVE_FINAL_DECISION:
        if (rtDW.B2_pin == 1.0) {
          rtDW.B1_pin = 0.0;
          rtDW.is_COMMUNICATION_TASK_B1 = IN_CONTROL_DECISION;
        } else if (rtDW.temporalCounter_i1 >= 10U) {
          rtDW.is_COMMUNICATION_TASK_B1 = IN_TIMEOUT;
          rtDW.Board_state = 1.0;
        }
        break;

       case IN_SEND_DATA:
        rtDW.B1_pin = 1.0;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.is_COMMUNICATION_TASK_B1 = IN_WAIT_B2;
        break;

       case IN_START:
        if (rtDW.B2_pin == 1.0) {
          rtDW.B1_pin = 0.0;
          rtDW.is_COMMUNICATION_TASK_B1 = IN_DECISION;
        } else if (rtDW.temporalCounter_i1 >= 78U) {
          rtDW.is_COMMUNICATION_TASK_B1 = IN_TIMEOUT;
          rtDW.Board_state = 1.0;
        }
        break;

       case IN_TIMEOUT:
        rtDW.temporalCounter_i1 = 0U;
        rtDW.is_COMMUNICATION_TASK_B1 = IN_START;
        rtDW.B2State_inB1 = 0.0;
        rtDW.final_decisionB1 = 3.0;
        rtDW.B1_decision = 4.0;
        rtDW.Board_state = 3.0;
        break;

       default:
        /* case IN_WAIT_B2: */
        if (rtDW.B2_pin == 1.0) {
          rtDW.B1_pin = 0.0;
          rtDW.temporalCounter_i1 = 0U;
          rtDW.is_COMMUNICATION_TASK_B1 = IN_RECEIVE_FINAL_DECISION;
        } else if (rtDW.temporalCounter_i1 >= 10U) {
          rtDW.is_COMMUNICATION_TASK_B1 = IN_TIMEOUT;
          rtDW.Board_state = 1.0;
        }
        break;
      }
      break;

     case IN_EMERGENCY_ACTUATION_TASK_B1:
      switch (rtDW.is_EMERGENCY_ACTUATION_TASK_B1) {
       case IN_ACTUATION:
        rtDW.is_EMERGENCY_ACTUATION_TASK_B1 = IN_END_EM;
        break;

       case IN_END_EM:
        rtDW.is_EMERGENCY_ACTUATION_TASK_B1 = IN_NO_ACTIVE_CHILD;
        rtDW.is_BOARD1 = IN_READ_TASK_B1;
        rtDW.is_READ_TASK_B1 = IN_START_b5;
        rtDW.Enc1 = 0.0;
        rtDW.Enc2 = 0.0;
        rtDW.Enc3 = 0.0;
        rtDW.Enc4 = 0.0;
        rtDW.Temp_B1 = 0.0;
        break;

       default:
        /* case IN_START: */
        if (rtDW.Board_state == 0.0) {
          rtDW.is_EMERGENCY_ACTUATION_TASK_B1 = IN_ACTUATION;
        } else {
          rtDW.is_EMERGENCY_ACTUATION_TASK_B1 = IN_END_EM;
        }
        break;
      }
      break;

     default:
      /* case IN_READ_TASK_B1: */
      if (rtDW.is_READ_TASK_B1 == IN_READ_OK) {
        rtDW.B1State = ((rtDW.Enc1 >= 0.0) && (rtDW.Enc2 >= 0.0) && (rtDW.Enc3 >=
          0.0) && (rtDW.Enc4 >= 0.0) && (rtDW.countTempB1 <= 200.0));
        rtDW.is_READ_TASK_B1 = IN_NO_ACTIVE_CHILD;
        rtDW.is_BOARD1 = IN_COMMUNICATION_TASK_B1;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.is_COMMUNICATION_TASK_B1 = IN_START;
        rtDW.B2State_inB1 = 0.0;
        rtDW.final_decisionB1 = 3.0;
        rtDW.B1_decision = 4.0;
        rtDW.Board_state = 3.0;
      } else {
        /* case IN_START: */
        rtDW.is_READ_TASK_B1 = IN_READ_OK;
        if ((rtDW.Temp_B1 >= 90.0) || (rtDW.Temp_B1 == 0.0)) {
          rtDW.countTempB1++;
        } else {
          rtDW.countTempB1 = 0.0;
        }
      }
      break;
    }

    BOARD2();
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Chart_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
