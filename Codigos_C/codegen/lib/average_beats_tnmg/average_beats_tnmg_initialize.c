/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * average_beats_tnmg_initialize.c
 *
 * Code generation for function 'average_beats_tnmg_initialize'
 *
 */

/* Include files */
#include "average_beats_tnmg_initialize.h"
#include "average_beats_tnmg_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void average_beats_tnmg_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_average_beats_tnmg = true;
}

/* End of code generation (average_beats_tnmg_initialize.c) */
