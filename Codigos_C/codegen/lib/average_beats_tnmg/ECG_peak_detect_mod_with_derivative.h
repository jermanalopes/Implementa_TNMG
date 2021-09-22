/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ECG_peak_detect_mod_with_derivative.h
 *
 * Code generation for function 'ECG_peak_detect_mod_with_derivative'
 *
 */

#ifndef ECG_PEAK_DETECT_MOD_WITH_DERIVATIVE_H
#define ECG_PEAK_DETECT_MOD_WITH_DERIVATIVE_H

/* Include files */
#include "average_beats_tnmg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void ECG_peak_detect_mod_with_derivative(
    const emxArray_real_T *ecg, double Fs, emxArray_real_T *vcg_peaks_pos,
    double *peak_threshold, emxArray_real_T *vcg, emxArray_real_T *vcg2);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (ECG_peak_detect_mod_with_derivative.h) */
