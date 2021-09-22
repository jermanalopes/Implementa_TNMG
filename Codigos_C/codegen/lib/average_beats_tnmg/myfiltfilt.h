/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myfiltfilt.h
 *
 * Code generation for function 'myfiltfilt'
 *
 */

#ifndef MYFILTFILT_H
#define MYFILTFILT_H

/* Include files */
#include "average_beats_tnmg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void myfiltfilt(const double b[4], const double a[4], emxArray_real_T *y,
                       const double zi[3]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (myfiltfilt.h) */
