/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanmedian.h
 *
 * Code generation for function 'nanmedian'
 *
 */

#ifndef NANMEDIAN_H
#define NANMEDIAN_H

/* Include files */
#include "average_beats_tnmg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_nanmedian(const emxArray_real_T *x, double y[12]);

void nanmedian(const emxArray_real_T *x, emxArray_real_T *y);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (nanmedian.h) */
