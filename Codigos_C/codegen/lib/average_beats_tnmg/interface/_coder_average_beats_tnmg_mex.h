/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_average_beats_tnmg_mex.h
 *
 * Code generation for function 'average_beats_tnmg'
 *
 */

#ifndef _CODER_AVERAGE_BEATS_TNMG_MEX_H
#define _CODER_AVERAGE_BEATS_TNMG_MEX_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_ECG_peak_detect_mod_with_derivative_mexFunction(
    int32_T nlhs, mxArray *plhs[4], int32_T nrhs, const mxArray *prhs[2]);

void unsafe_average_beats_tnmg_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                           int32_T nrhs,
                                           const mxArray *prhs[4]);

void unsafe_my_butter_coeffs_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                         int32_T nrhs, const mxArray *prhs[3]);

void unsafe_myfiltfilt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[4]);

void unsafe_peakdetect_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                                   const mxArray *prhs[6]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_average_beats_tnmg_mex.h) */
