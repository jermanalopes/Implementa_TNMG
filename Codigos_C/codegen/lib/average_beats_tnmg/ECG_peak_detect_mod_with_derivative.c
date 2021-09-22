/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ECG_peak_detect_mod_with_derivative.c
 *
 * Code generation for function 'ECG_peak_detect_mod_with_derivative'
 *
 */

/* Include files */
#include "ECG_peak_detect_mod_with_derivative.h"
#include "average_beats_tnmg_data.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_initialize.h"
#include "average_beats_tnmg_rtwutil.h"
#include "average_beats_tnmg_types.h"
#include "colon.h"
#include "diff.h"
#include "find.h"
#include "minOrMax.h"
#include "nanstd.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void ECG_peak_detect_mod_with_derivative(const emxArray_real_T *ecg, double Fs,
                                         emxArray_real_T *vcg_peaks_pos,
                                         double *peak_threshold,
                                         emxArray_real_T *vcg,
                                         emxArray_real_T *vcg2)
{
  emxArray_boolean_T *mask1;
  emxArray_boolean_T *mask2;
  emxArray_boolean_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *b_dsdx;
  emxArray_real_T *b_vcg;
  emxArray_real_T *dsdx;
  emxArray_real_T *varargin_2;
  emxArray_real_T *vcgd;
  emxArray_real_T *y;
  double b_peak_threshold[3];
  double peak_threshold_data[3];
  double b_vcgd[2];
  double d;
  double rps;
  double rps2;
  double tmp1;
  int peak_threshold_size[2];
  int i;
  int i1;
  int k;
  int nx;
  int nxin;
  int nxout;
  int okp;
  signed char tmp_data[3];
  boolean_T idx[2];
  boolean_T exitg1;
  boolean_T x_idx_0;
  boolean_T x_idx_1_tmp;
  if (!isInitialized_average_beats_tnmg) {
    average_beats_tnmg_initialize();
  }
  /* ,vcg_type) */
  /* the input ECG is a 3xN matrix, where is line is one derivation (I,II,III)
   */
  okp = ecg->size[1];
  nx = ecg->size[1];
  i = vcg->size[0] * vcg->size[1];
  vcg->size[0] = 2;
  vcg->size[1] = ecg->size[1];
  emxEnsureCapacity_real_T(vcg, i);
  for (i = 0; i < okp; i++) {
    vcg->data[2 * i] = ecg->data[12 * i];
  }
  for (i = 0; i < nx; i++) {
    vcg->data[2 * i + 1] = -ecg->data[12 * i + 4];
  }
  emxInit_real_T(&b_vcg, 2);
  okp = vcg->size[1];
  i = b_vcg->size[0] * b_vcg->size[1];
  b_vcg->size[0] = 1;
  b_vcg->size[1] = vcg->size[1];
  emxEnsureCapacity_real_T(b_vcg, i);
  for (i = 0; i < okp; i++) {
    b_vcg->data[i] = vcg->data[2 * i];
  }
  i = vcg2->size[0] * vcg2->size[1];
  vcg2->size[0] = 1;
  vcg2->size[1] = b_vcg->size[1];
  emxEnsureCapacity_real_T(vcg2, i);
  nx = b_vcg->size[1];
  for (k = 0; k < nx; k++) {
    d = vcg->data[2 * k];
    vcg2->data[k] = d * d;
  }
  emxInit_real_T(&dsdx, 2);
  okp = vcg->size[1];
  i = b_vcg->size[0] * b_vcg->size[1];
  b_vcg->size[0] = 1;
  b_vcg->size[1] = vcg->size[1];
  emxEnsureCapacity_real_T(b_vcg, i);
  for (i = 0; i < okp; i++) {
    b_vcg->data[i] = vcg->data[2 * i + 1];
  }
  i = dsdx->size[0] * dsdx->size[1];
  dsdx->size[0] = 1;
  dsdx->size[1] = b_vcg->size[1];
  emxEnsureCapacity_real_T(dsdx, i);
  nx = b_vcg->size[1];
  for (k = 0; k < nx; k++) {
    d = vcg->data[2 * k + 1];
    dsdx->data[k] = d * d;
  }
  i = vcg2->size[0] * vcg2->size[1];
  vcg2->size[0] = 1;
  emxEnsureCapacity_real_T(vcg2, i);
  okp = vcg2->size[1] - 1;
  for (i = 0; i <= okp; i++) {
    vcg2->data[i] += dsdx->data[i];
  }
  emxInit_real_T(&vcgd, 2);
  diff(vcg2, dsdx);
  i = vcgd->size[0] * vcgd->size[1];
  vcgd->size[0] = 1;
  vcgd->size[1] = dsdx->size[1];
  emxEnsureCapacity_real_T(vcgd, i);
  nx = dsdx->size[1];
  for (k = 0; k < nx; k++) {
    d = dsdx->data[k];
    vcgd->data[k] = d * d;
  }
  /*  differentiate and square */
  rps = 0.3 * Fs;
  i = dsdx->size[0] * dsdx->size[1];
  dsdx->size[0] = 1;
  dsdx->size[1] = vcgd->size[1];
  emxEnsureCapacity_real_T(dsdx, i);
  okp = vcgd->size[1];
  for (i = 0; i < okp; i++) {
    dsdx->data[i] = vcgd->data[i];
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
  b_vcgd[0] = 1.0;
  b_vcgd[1] = vcgd->size[1];
  if (minimum(b_vcgd) == 1.0) {
    i = dsdx->size[0] * dsdx->size[1];
    dsdx->size[0] = 1;
    dsdx->size[1] = vcgd->size[1];
    emxEnsureCapacity_real_T(dsdx, i);
    okp = vcgd->size[1];
    for (i = 0; i < okp; i++) {
      dsdx->data[i] = vcgd->data[i];
    }
  }
  b_diff(dsdx, b_vcg);
  nx = b_vcg->size[1];
  for (k = 0; k < nx; k++) {
    rps2 = b_vcg->data[k];
    if (rps2 < 0.0) {
      rps2 = -1.0;
    } else if (rps2 > 0.0) {
      rps2 = 1.0;
    } else if (rps2 == 0.0) {
      rps2 = 0.0;
    }
    b_vcg->data[k] = rps2;
  }
  emxInit_real_T(&varargin_2, 2);
  b_diff(b_vcg, varargin_2);
  if (varargin_2->size[1] != 0) {
    nx = varargin_2->size[1];
  } else {
    nx = 0;
  }
  i = dsdx->size[0] * dsdx->size[1];
  dsdx->size[0] = 1;
  dsdx->size[1] = nx + 1;
  emxEnsureCapacity_real_T(dsdx, i);
  dsdx->data[0] = 0.0;
  for (i = 0; i < nx; i++) {
    dsdx->data[i + 1] = varargin_2->data[i];
  }
  emxInit_boolean_T(&r, 2);
  c_diff(dsdx, varargin_2);
  if (varargin_2->size[1] != 0) {
    nx = varargin_2->size[1];
  } else {
    nx = 0;
  }
  /* peak detection */
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = nx + 1;
  emxEnsureCapacity_boolean_T(r, i);
  r->data[0] = false;
  for (i = 0; i < nx; i++) {
    r->data[i + 1] = !(varargin_2->data[i] == 0.0);
  }
  emxInit_boolean_T(&mask2, 2);
  i = mask2->size[0] * mask2->size[1];
  mask2->size[0] = 1;
  mask2->size[1] = dsdx->size[1];
  emxEnsureCapacity_boolean_T(mask2, i);
  okp = dsdx->size[1];
  for (i = 0; i < okp; i++) {
    mask2->data[i] = ((dsdx->data[i] < 0.0) && r->data[i]);
  }
  emxInit_int32_T(&r1, 1);
  eml_find(mask2, r1);
  i = vcg_peaks_pos->size[0];
  vcg_peaks_pos->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(vcg_peaks_pos, i);
  okp = r1->size[0];
  for (i = 0; i < okp; i++) {
    vcg_peaks_pos->data[i] = r1->data[i];
  }
  emxFree_int32_T(&r1);
  /* remove peaks that do no match the tresholds */
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
  i = dsdx->size[0] * dsdx->size[1];
  dsdx->size[0] = 1;
  dsdx->size[1] = vcgd->size[1];
  emxEnsureCapacity_real_T(dsdx, i);
  okp = vcgd->size[1];
  for (i = 0; i < okp; i++) {
    dsdx->data[i] = vcgd->data[i];
  }
  nx = vcgd->size[1];
  for (nxout = 0; nxout < nx; nxout++) {
    if (vcgd->data[nxout] < 0.0001) {
      dsdx->data[nxout] = rtNaN;
    }
  }
  nx = (int)rt_roundd_snf((double)dsdx->size[1] / 3.0);
  if (1 > nx) {
    okp = 0;
  } else {
    okp = nx;
  }
  i = nx << 1;
  if (nx > i) {
    i1 = 0;
    nxout = 0;
  } else {
    i1 = nx - 1;
    nxout = i;
  }
  if (i > dsdx->size[1]) {
    i = 0;
    nx = 0;
  } else {
    i--;
    nx = dsdx->size[1];
  }
  nxin = b_vcg->size[0] * b_vcg->size[1];
  b_vcg->size[0] = 1;
  b_vcg->size[1] = okp;
  emxEnsureCapacity_real_T(b_vcg, nxin);
  for (nxin = 0; nxin < okp; nxin++) {
    b_vcg->data[nxin] = dsdx->data[nxin];
  }
  nxin = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = 1;
  okp = nxout - i1;
  varargin_2->size[1] = okp;
  emxEnsureCapacity_real_T(varargin_2, nxin);
  for (nxout = 0; nxout < okp; nxout++) {
    varargin_2->data[nxout] = dsdx->data[i1 + nxout];
  }
  emxInit_real_T(&b_dsdx, 2);
  i1 = b_dsdx->size[0] * b_dsdx->size[1];
  b_dsdx->size[0] = 1;
  okp = nx - i;
  b_dsdx->size[1] = okp;
  emxEnsureCapacity_real_T(b_dsdx, i1);
  for (i1 = 0; i1 < okp; i1++) {
    b_dsdx->data[i1] = dsdx->data[i + i1];
  }
  b_peak_threshold[0] = nanstd(b_vcg);
  b_peak_threshold[1] = nanstd(varargin_2);
  b_peak_threshold[2] = nanstd(b_dsdx);
  okp = 0;
  d = b_peak_threshold[0] * 2.0;
  b_peak_threshold[0] = d;
  emxFree_real_T(&b_dsdx);
  emxFree_real_T(&varargin_2);
  if (d > 1000.0) {
    okp = 1;
  }
  d = b_peak_threshold[1] * 2.0;
  b_peak_threshold[1] = d;
  if (d > 1000.0) {
    okp++;
  }
  d = b_peak_threshold[2] * 2.0;
  b_peak_threshold[2] = d;
  if (d > 1000.0) {
    okp++;
  }
  nx = 0;
  if (b_peak_threshold[0] > 1000.0) {
    tmp_data[0] = 1;
    nx = 1;
  }
  if (b_peak_threshold[1] > 1000.0) {
    tmp_data[nx] = 2;
    nx++;
  }
  if (d > 1000.0) {
    tmp_data[nx] = 3;
  }
  peak_threshold_size[0] = 1;
  peak_threshold_size[1] = okp;
  for (i = 0; i < okp; i++) {
    peak_threshold_data[i] = b_peak_threshold[tmp_data[i] - 1];
  }
  *peak_threshold = b_minimum(peak_threshold_data, peak_threshold_size);
  i = mask2->size[0] * mask2->size[1];
  mask2->size[0] = 1;
  mask2->size[1] = vcg_peaks_pos->size[0];
  emxEnsureCapacity_boolean_T(mask2, i);
  okp = vcg_peaks_pos->size[0];
  for (i = 0; i < okp; i++) {
    mask2->data[i] =
        (vcgd->data[(int)vcg_peaks_pos->data[i] - 1] < *peak_threshold);
  }
  b_nullAssignment(vcg_peaks_pos, mask2);
  okp = 1;
  emxInit_boolean_T(&mask1, 1);
  emxInit_real_T(&y, 1);
  while (okp != 0) {
    okp = vcg_peaks_pos->size[0];
    if (vcg_peaks_pos->size[0] == 0) {
      y->size[0] = 0;
    } else {
      nx = vcg_peaks_pos->size[0] - 1;
      if (nx >= 1) {
        nx = 1;
      }
      if (nx < 1) {
        y->size[0] = 0;
      } else {
        i = y->size[0];
        y->size[0] = vcg_peaks_pos->size[0] - 1;
        emxEnsureCapacity_real_T(y, i);
        if (vcg_peaks_pos->size[0] - 1 != 0) {
          rps2 = vcg_peaks_pos->data[0];
          for (nx = 2; nx <= okp; nx++) {
            tmp1 = vcg_peaks_pos->data[nx - 1];
            d = tmp1;
            tmp1 -= rps2;
            rps2 = d;
            y->data[nx - 2] = tmp1;
          }
        }
      }
    }
    i = mask1->size[0];
    mask1->size[0] = y->size[0];
    emxEnsureCapacity_boolean_T(mask1, i);
    okp = y->size[0];
    for (i = 0; i < okp; i++) {
      mask1->data[i] = (y->data[i] < rps);
    }
    i = b_vcg->size[0] * b_vcg->size[1];
    b_vcg->size[0] = 1;
    b_vcg->size[1] = vcg_peaks_pos->size[0];
    emxEnsureCapacity_real_T(b_vcg, i);
    okp = vcg_peaks_pos->size[0];
    for (i = 0; i < okp; i++) {
      b_vcg->data[i] = vcgd->data[(int)vcg_peaks_pos->data[i] - 1];
    }
    diff(b_vcg, dsdx);
    i = mask2->size[0] * mask2->size[1];
    mask2->size[0] = 1;
    mask2->size[1] = dsdx->size[1];
    emxEnsureCapacity_boolean_T(mask2, i);
    okp = dsdx->size[1];
    for (i = 0; i < okp; i++) {
      mask2->data[i] = (dsdx->data[i] > 0.0);
    }
    if (1 > mask1->size[0] - 1) {
      okp = 1;
    } else {
      okp = mask1->size[0];
    }
    if (1 > mask2->size[1] - 1) {
      nx = 1;
    } else {
      nx = mask2->size[1];
    }
    x_idx_0 = (mask1->data[0] && mask2->data[0]);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = nx;
    emxEnsureCapacity_boolean_T(r, i);
    for (i = 0; i <= nx - 2; i++) {
      r->data[i + 1] = !mask2->data[i];
    }
    for (i = 0; i <= okp - 2; i++) {
      idx[i + 1] = mask1->data[i];
    }
    nxin = vcg_peaks_pos->size[0];
    idx[0] = x_idx_0;
    x_idx_1_tmp = (idx[1] && r->data[1]);
    x_idx_1_tmp = (x_idx_0 || x_idx_1_tmp);
    idx[1] = x_idx_1_tmp;
    okp = x_idx_0 + x_idx_1_tmp;
    nxout = (vcg_peaks_pos->size[0] - x_idx_0) - x_idx_1_tmp;
    nx = -1;
    for (k = 0; k < nxin; k++) {
      if ((k + 1 > 2) || (!idx[k])) {
        nx++;
        vcg_peaks_pos->data[nx] = vcg_peaks_pos->data[k];
      }
    }
    i = vcg_peaks_pos->size[0];
    if (1 > nxout) {
      vcg_peaks_pos->size[0] = 0;
    } else {
      vcg_peaks_pos->size[0] = nxout;
    }
    emxEnsureCapacity_real_T(vcg_peaks_pos, i);
  }
  emxFree_boolean_T(&r);
  emxFree_real_T(&y);
  emxFree_boolean_T(&mask2);
  /*  remove vey low peaks and peaks at the very beginning and end of aquisition
   */
  /*  peak_threshold=(nanmedian(vcgd(vcg_peaks_pos))-peak_threshold)/3+peak_threshold;
   */
  /*  mask=vcgd(vcg_peaks_pos)<peak_threshold ... */
  /*      | vcg_peaks_pos < Fs*ref_period/1000 ... */
  /*      | vcg_peaks_pos > (length(vcgd)-Fs*ref_period/1000);  */
  /* peak_threshold=(nanmedian(vcgd(vcg_peaks_pos))-peak_threshold)/3+peak_threshold;
   */
  rps2 = (double)vcgd->size[1] - rps;
  i = mask1->size[0];
  mask1->size[0] = vcg_peaks_pos->size[0];
  emxEnsureCapacity_boolean_T(mask1, i);
  okp = vcg_peaks_pos->size[0];
  for (i = 0; i < okp; i++) {
    mask1->data[i] =
        ((vcg_peaks_pos->data[i] < rps) || (vcg_peaks_pos->data[i] > rps2));
  }
  nxin = vcg_peaks_pos->size[0];
  nx = 0;
  i = mask1->size[0];
  for (k = 0; k < i; k++) {
    nx += mask1->data[k];
  }
  nxout = vcg_peaks_pos->size[0] - nx;
  nx = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > mask1->size[0]) || (!mask1->data[k])) {
      nx++;
      vcg_peaks_pos->data[nx] = vcg_peaks_pos->data[k];
    }
  }
  emxFree_boolean_T(&mask1);
  i = vcg_peaks_pos->size[0];
  if (1 > nxout) {
    vcg_peaks_pos->size[0] = 0;
  } else {
    vcg_peaks_pos->size[0] = nxout;
  }
  emxEnsureCapacity_real_T(vcg_peaks_pos, i);
  /*  check if there is a double peak at the end of the acquisition */
  if (vcg_peaks_pos->size[0] > 1) {
    if (vcg_peaks_pos->data[vcg_peaks_pos->size[0] - 1] -
            vcg_peaks_pos->data[vcg_peaks_pos->size[0] - 2] <
        rps) {
      if (vcgd->data[(int)vcg_peaks_pos->data[vcg_peaks_pos->size[0] - 2] - 1] >
          vcgd->data[(int)vcg_peaks_pos->data[vcg_peaks_pos->size[0] - 1] -
                     1]) {
        okp = vcg_peaks_pos->size[0];
        nxin = vcg_peaks_pos->size[0];
        nxout = vcg_peaks_pos->size[0] - 1;
        for (k = okp; k <= nxout; k++) {
          vcg_peaks_pos->data[k - 1] = vcg_peaks_pos->data[k];
        }
        i = vcg_peaks_pos->size[0];
        vcg_peaks_pos->size[0] = nxin - 1;
        emxEnsureCapacity_real_T(vcg_peaks_pos, i);
      } else {
        okp = vcg_peaks_pos->size[0] - 1;
        nxin = vcg_peaks_pos->size[0];
        nxout = vcg_peaks_pos->size[0] - 1;
        for (k = okp; k <= nxout; k++) {
          vcg_peaks_pos->data[k - 1] = vcg_peaks_pos->data[k];
        }
        i = vcg_peaks_pos->size[0];
        vcg_peaks_pos->size[0] = nxin - 1;
        emxEnsureCapacity_real_T(vcg_peaks_pos, i);
      }
    }
    /*  recenter the peaks as the peaks in VCG (note: peaks were found as peaks
     * in the drivative) */
    rps2 = rt_roundd_snf(rps / 2.0);
    if (rtIsNaN(-rps2 + 1.0) || rtIsNaN(rps2 - 1.0)) {
      i = dsdx->size[0] * dsdx->size[1];
      dsdx->size[0] = 1;
      dsdx->size[1] = 1;
      emxEnsureCapacity_real_T(dsdx, i);
      dsdx->data[0] = rtNaN;
    } else if (rps2 - 1.0 < -rps2 + 1.0) {
      dsdx->size[0] = 1;
      dsdx->size[1] = 0;
    } else if ((rtIsInf(-rps2 + 1.0) || rtIsInf(rps2 - 1.0)) &&
               (-rps2 + 1.0 == rps2 - 1.0)) {
      i = dsdx->size[0] * dsdx->size[1];
      dsdx->size[0] = 1;
      dsdx->size[1] = 1;
      emxEnsureCapacity_real_T(dsdx, i);
      dsdx->data[0] = rtNaN;
    } else if (-rps2 + 1.0 == -rps2 + 1.0) {
      i = dsdx->size[0] * dsdx->size[1];
      dsdx->size[0] = 1;
      okp = (int)((rps2 - 1.0) - (-rps2 + 1.0));
      dsdx->size[1] = okp + 1;
      emxEnsureCapacity_real_T(dsdx, i);
      for (i = 0; i <= okp; i++) {
        dsdx->data[i] = (-rps2 + 1.0) + (double)i;
      }
    } else {
      eml_float_colon(-rps2 + 1.0, rps2 - 1.0, dsdx);
    }
    i = vcg_peaks_pos->size[0];
    for (nxout = 0; nxout < i; nxout++) {
      i1 = b_vcg->size[0] * b_vcg->size[1];
      b_vcg->size[0] = 1;
      b_vcg->size[1] = dsdx->size[1];
      emxEnsureCapacity_real_T(b_vcg, i1);
      okp = dsdx->size[1];
      for (i1 = 0; i1 < okp; i1++) {
        b_vcg->data[i1] =
            vcg2->data[(int)(vcg_peaks_pos->data[nxout] + dsdx->data[i1]) - 1];
      }
      nx = dsdx->size[1];
      if (dsdx->size[1] <= 2) {
        if (dsdx->size[1] == 1) {
          okp = 1;
        } else {
          i1 = (int)(vcg_peaks_pos->data[nxout] + dsdx->data[0]) - 1;
          if ((vcg2->data[i1] <
               vcg2->data[(int)(vcg_peaks_pos->data[nxout] +
                                dsdx->data[dsdx->size[1] - 1]) -
                          1]) ||
              (rtIsNaN(vcg2->data[i1]) &&
               (!rtIsNaN(vcg2->data[(int)(vcg_peaks_pos->data[nxout] +
                                          dsdx->data[dsdx->size[1] - 1]) -
                                    1])))) {
            okp = dsdx->size[1];
          } else {
            okp = 1;
          }
        }
      } else {
        if (!rtIsNaN(
                vcg2->data[(int)(vcg_peaks_pos->data[nxout] + dsdx->data[0]) -
                           1])) {
          okp = 1;
        } else {
          okp = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= nx)) {
            if (!rtIsNaN(b_vcg->data[k - 1])) {
              okp = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (okp == 0) {
          okp = 1;
        } else {
          tmp1 = vcg2->data[(int)(vcg_peaks_pos->data[nxout] +
                                  dsdx->data[okp - 1]) -
                            1];
          i1 = okp + 1;
          for (k = i1; k <= nx; k++) {
            d = b_vcg->data[k - 1];
            if (tmp1 < d) {
              tmp1 = d;
              okp = k;
            }
          }
        }
      }
      vcg_peaks_pos->data[nxout] =
          (vcg_peaks_pos->data[nxout] + (double)okp) - rps2;
    }
  }
  emxFree_real_T(&b_vcg);
  emxFree_real_T(&dsdx);
  emxFree_real_T(&vcgd);
}

/* End of code generation (ECG_peak_detect_mod_with_derivative.c) */
