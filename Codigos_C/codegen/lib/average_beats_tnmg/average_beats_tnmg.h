/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * average_beats_tnmg.h
 *
 * Code generation for function 'average_beats_tnmg'
 *
 */

#ifndef AVERAGE_BEATS_TNMG_H
#define AVERAGE_BEATS_TNMG_H

/* Include files */
#include "average_beats_tnmg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void average_beats_tnmg(const emxArray_real_T *ecg,
                               emxArray_real_T *R_pos, double fs,
                               const emxArray_real_T *vcg, double *SNR_overall,
                               double *SNR_overall_type);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (average_beats_tnmg.h) */
