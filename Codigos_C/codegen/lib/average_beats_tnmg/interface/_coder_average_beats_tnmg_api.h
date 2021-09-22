/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_average_beats_tnmg_api.h
 *
 * Code generation for function 'average_beats_tnmg'
 *
 */

#ifndef _CODER_AVERAGE_BEATS_TNMG_API_H
#define _CODER_AVERAGE_BEATS_TNMG_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ECG_peak_detect_mod_with_derivative(emxArray_real_T *ecg, real_T Fs,
                                         emxArray_real_T *vcg_peaks_pos,
                                         real_T *peak_threshold,
                                         emxArray_real_T *vcg,
                                         emxArray_real_T *vcg2);

void average_beats_tnmg(emxArray_real_T *ecg, emxArray_real_T *R_pos, real_T fs,
                        emxArray_real_T *vcg, real_T *SNR_overall,
                        real_T *SNR_overall_type);

void average_beats_tnmg_api(const mxArray *const prhs[4], int32_T nlhs,
                            const mxArray *plhs[2]);

void average_beats_tnmg_atexit(void);

void average_beats_tnmg_initialize(void);

void average_beats_tnmg_terminate(void);

void average_beats_tnmg_xil_shutdown(void);

void average_beats_tnmg_xil_terminate(void);

void c_ECG_peak_detect_mod_with_deri(const mxArray *const prhs[2], int32_T nlhs,
                                     const mxArray *plhs[4]);

void my_butter_coeffs(real_T fc, real_T fs, char_T filter_type[4],
                      real_T b_data[], int32_T b_size[1], real_T a[4],
                      real_T zi[3]);

void my_butter_coeffs_api(const mxArray *const prhs[3], int32_T nlhs,
                          const mxArray *plhs[3]);

void myfiltfilt(real_T b[4], real_T a[4], emxArray_real_T *y, real_T zi[3]);

void myfiltfilt_api(const mxArray *const prhs[4], const mxArray **plhs);

void peakdetect(emxArray_real_T *b_signal, real_T pospeak_treshold_bigger_than,
                real_T pospeak_treshold_smaller_than,
                real_T negpeak_treshold_bigger_than,
                real_T negpeak_treshold_smaller_than, real_T plot_results,
                emxArray_real_T *pospeakind, emxArray_real_T *negpeakind);

void peakdetect_api(const mxArray *const prhs[6], int32_T nlhs,
                    const mxArray *plhs[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_average_beats_tnmg_api.h) */
