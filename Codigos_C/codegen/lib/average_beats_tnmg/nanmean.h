/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanmean.h
 *
 * Code generation for function 'nanmean'
 *
 */

#ifndef NANMEAN_H
#define NANMEAN_H

/* Include files */
#include "average_beats_tnmg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_nanmean(const double varargin_1[3]);

void c_nanmean(const emxArray_real_T *varargin_1, double y[12]);

void nanmean(const emxArray_real_T *varargin_1, double y[3]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (nanmean.h) */
