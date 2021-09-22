/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * peakdetect.c
 *
 * Code generation for function 'peakdetect'
 *
 */

/* Include files */
#include "peakdetect.h"
#include "average_beats_tnmg_data.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_initialize.h"
#include "average_beats_tnmg_types.h"
#include "diff.h"
#include "find.h"
#include "minOrMax.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void peakdetect(emxArray_real_T *b_signal, double pospeak_treshold_bigger_than,
                double pospeak_treshold_smaller_than,
                double negpeak_treshold_bigger_than,
                double negpeak_treshold_smaller_than, double plot_results,
                emxArray_real_T *pospeakind, emxArray_real_T *negpeakind)
{
  emxArray_boolean_T *b_dsdx;
  emxArray_int32_T *r;
  emxArray_real_T *ddsdx;
  emxArray_real_T *dsdx;
  emxArray_real_T *varargin_2;
  double c_signal[2];
  double x;
  int k;
  int nx;
  (void)plot_results;
  if (!isInitialized_average_beats_tnmg) {
    average_beats_tnmg_initialize();
  }
  /*  find negative and positive peaks in a singal, and return their location */
  /*  the input can be a matrix of mutliple signal with each row corresponding
   */
  /*  to a singal. In this case the output is a cell vector with the output */
  /*  pospeak{i} and negpeak{i} being the location of positive and negative */
  /*  peaks in the signal corresponding to the i-th row of the input matrix */
  /*  TRESHOLD: a treshold can be set for the peaks: [bigger_than smaller_than].
   */
  /*  If only one value is inputed, this is taken as a "bigger_than for positive
   * peaks */
  /*  and a "smaller_than" for negative peaks. If this paramter is */
  /*  missinng or set as empty, no treshold is applied */
  /* NOTE - handling the case of a series of samples with the same value: */
  /* an arbitrary choice is made to mark only the first sample of such series as
   * a peak */
  c_signal[0] = 1.0;
  c_signal[1] = b_signal->size[1];
  emxInit_real_T(&dsdx, 2);
  if (minimum(c_signal) == 1.0) {
    k = dsdx->size[0] * dsdx->size[1];
    dsdx->size[0] = 1;
    dsdx->size[1] = b_signal->size[1];
    emxEnsureCapacity_real_T(dsdx, k);
    nx = b_signal->size[1];
    for (k = 0; k < nx; k++) {
      dsdx->data[k] = b_signal->data[k];
    }
    k = b_signal->size[0] * b_signal->size[1];
    b_signal->size[0] = 1;
    b_signal->size[1] = dsdx->size[1];
    emxEnsureCapacity_real_T(b_signal, k);
    nx = dsdx->size[1];
    for (k = 0; k < nx; k++) {
      b_signal->data[k] = dsdx->data[k];
    }
  }
  b_diff(b_signal, dsdx);
  nx = dsdx->size[1];
  for (k = 0; k < nx; k++) {
    x = dsdx->data[k];
    if (x < 0.0) {
      x = -1.0;
    } else if (x > 0.0) {
      x = 1.0;
    } else if (x == 0.0) {
      x = 0.0;
    }
    dsdx->data[k] = x;
  }
  emxInit_real_T(&varargin_2, 2);
  b_diff(dsdx, varargin_2);
  if (varargin_2->size[1] != 0) {
    nx = varargin_2->size[1];
  } else {
    nx = 0;
  }
  k = dsdx->size[0] * dsdx->size[1];
  dsdx->size[0] = 1;
  dsdx->size[1] = nx + 1;
  emxEnsureCapacity_real_T(dsdx, k);
  dsdx->data[0] = 0.0;
  for (k = 0; k < nx; k++) {
    dsdx->data[k + 1] = varargin_2->data[k];
  }
  emxInit_real_T(&ddsdx, 2);
  c_diff(dsdx, varargin_2);
  if (varargin_2->size[1] != 0) {
    nx = varargin_2->size[1];
  } else {
    nx = 0;
  }
  k = ddsdx->size[0] * ddsdx->size[1];
  ddsdx->size[0] = 1;
  ddsdx->size[1] = nx + 1;
  emxEnsureCapacity_real_T(ddsdx, k);
  ddsdx->data[0] = 0.0;
  for (k = 0; k < nx; k++) {
    ddsdx->data[k + 1] = varargin_2->data[k];
  }
  emxFree_real_T(&varargin_2);
  emxInit_boolean_T(&b_dsdx, 2);
  /* peak detection */
  k = b_dsdx->size[0] * b_dsdx->size[1];
  b_dsdx->size[0] = 1;
  b_dsdx->size[1] = dsdx->size[1];
  emxEnsureCapacity_boolean_T(b_dsdx, k);
  nx = dsdx->size[1];
  for (k = 0; k < nx; k++) {
    b_dsdx->data[k] = ((dsdx->data[k] < 0.0) && (!(ddsdx->data[k] == 0.0)));
  }
  emxInit_int32_T(&r, 1);
  eml_find(b_dsdx, r);
  k = pospeakind->size[0];
  pospeakind->size[0] = r->size[0];
  emxEnsureCapacity_real_T(pospeakind, k);
  nx = r->size[0];
  for (k = 0; k < nx; k++) {
    pospeakind->data[k] = r->data[k];
  }
  k = b_dsdx->size[0] * b_dsdx->size[1];
  b_dsdx->size[0] = 1;
  b_dsdx->size[1] = dsdx->size[1];
  emxEnsureCapacity_boolean_T(b_dsdx, k);
  nx = dsdx->size[1];
  for (k = 0; k < nx; k++) {
    b_dsdx->data[k] = ((dsdx->data[k] > 0.0) && (!(ddsdx->data[k] == 0.0)));
  }
  emxFree_real_T(&ddsdx);
  emxFree_real_T(&dsdx);
  eml_find(b_dsdx, r);
  k = negpeakind->size[0];
  negpeakind->size[0] = r->size[0];
  emxEnsureCapacity_real_T(negpeakind, k);
  nx = r->size[0];
  for (k = 0; k < nx; k++) {
    negpeakind->data[k] = r->data[k];
  }
  emxFree_int32_T(&r);
  /* remove peaks that do no match the tresholds */
  k = b_dsdx->size[0] * b_dsdx->size[1];
  b_dsdx->size[0] = 1;
  b_dsdx->size[1] = pospeakind->size[0];
  emxEnsureCapacity_boolean_T(b_dsdx, k);
  nx = pospeakind->size[0];
  for (k = 0; k < nx; k++) {
    b_dsdx->data[k] = (b_signal->data[(int)pospeakind->data[k] - 1] >
                       pospeak_treshold_smaller_than);
  }
  b_nullAssignment(pospeakind, b_dsdx);
  k = b_dsdx->size[0] * b_dsdx->size[1];
  b_dsdx->size[0] = 1;
  b_dsdx->size[1] = pospeakind->size[0];
  emxEnsureCapacity_boolean_T(b_dsdx, k);
  nx = pospeakind->size[0];
  for (k = 0; k < nx; k++) {
    b_dsdx->data[k] = (b_signal->data[(int)pospeakind->data[k] - 1] <
                       pospeak_treshold_bigger_than);
  }
  b_nullAssignment(pospeakind, b_dsdx);
  k = b_dsdx->size[0] * b_dsdx->size[1];
  b_dsdx->size[0] = 1;
  b_dsdx->size[1] = negpeakind->size[0];
  emxEnsureCapacity_boolean_T(b_dsdx, k);
  nx = negpeakind->size[0];
  for (k = 0; k < nx; k++) {
    b_dsdx->data[k] = (b_signal->data[(int)negpeakind->data[k] - 1] >
                       negpeak_treshold_smaller_than);
  }
  b_nullAssignment(negpeakind, b_dsdx);
  k = b_dsdx->size[0] * b_dsdx->size[1];
  b_dsdx->size[0] = 1;
  b_dsdx->size[1] = negpeakind->size[0];
  emxEnsureCapacity_boolean_T(b_dsdx, k);
  nx = negpeakind->size[0];
  for (k = 0; k < nx; k++) {
    b_dsdx->data[k] = (b_signal->data[(int)negpeakind->data[k] - 1] <
                       negpeak_treshold_bigger_than);
  }
  b_nullAssignment(negpeakind, b_dsdx);
  /* create a cell array for the case of multiple signals */
  /*  if nr_channels>1 */
  /*      nr_samples=size(signal,2); */
  /*      [pp_row,pp_col] = ind2sub(size(signal),pospeakind); */
  /*      [np_row,np_col] = ind2sub(size(signal),negpeakind); */
  /*      for n=1:nr_channels; */
  /*          pp{n}=pp_col(pp_row==n); */
  /*          np{n}=np_col(np_row==n); */
  /*      end */
  /*      pospeakind=pp; */
  /*      negpeakind=np; */
  /*  end */
  /*  if plot_results */
  /*      tt=1:length(signal); */
  /*      figure */
  /*      plot(tt,signal) */
  /*      hold on */
  /*      plot(tt,signal,'.') */
  /*      if nr_chanels==1 */
  /*          plot(tt(pospeakind),signal(pospeakind),'r.') */
  /*          plot(tt(negpeakind),signal(negpeakind),'k.') */
  /*      else */
  /*          for n=1:nr_channels */
  /*              plot(tt(pospeakind{n}),signal(n,pospeakind{n}),'r.') */
  /*              plot(tt(negpeakind{n}),signal(n,negpeakind{n}),'k.') */
  /*          end */
  /*      end */
  emxFree_boolean_T(&b_dsdx);
}

/* End of code generation (peakdetect.c) */
