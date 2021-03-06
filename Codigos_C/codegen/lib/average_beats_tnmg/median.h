/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * median.h
 *
 * Code generation for function 'median'
 *
 */

#ifndef MEDIAN_H
#define MEDIAN_H

/* Include files */
#include "average_beats_tnmg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_median(const double x[15]);

double median(const emxArray_real_T *x);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (median.h) */
