/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * prctile.c
 *
 * Code generation for function 'prctile'
 *
 */

/* Include files */
#include "prctile.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_rtwutil.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
double percentile_vector(const emxArray_real_T *x)
{
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  double pct;
  double r;
  int b_i;
  int i;
  int j;
  int k;
  int kEnd;
  int n;
  int nj;
  int p;
  int pEnd;
  int q;
  int qEnd;
  if (x->size[0] == 0) {
    pct = rtNaN;
  } else {
    emxInit_int32_T(&idx, 1);
    n = x->size[0] + 1;
    i = idx->size[0];
    idx->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(idx, i);
    nj = x->size[0];
    for (i = 0; i < nj; i++) {
      idx->data[i] = 0;
    }
    emxInit_int32_T(&iwork, 1);
    i = iwork->size[0];
    iwork->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(iwork, i);
    i = x->size[0] - 1;
    for (k = 1; k <= i; k += 2) {
      if ((x->data[k - 1] <= x->data[k]) || rtIsNaN(x->data[k])) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }
    if ((x->size[0] & 1) != 0) {
      idx->data[x->size[0] - 1] = x->size[0];
    }
    b_i = 2;
    while (b_i < n - 1) {
      nj = b_i << 1;
      j = 1;
      for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        p = j;
        q = pEnd - 1;
        qEnd = j + nj;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          r = x->data[idx->data[q] - 1];
          i = idx->data[p - 1];
          if ((x->data[i - 1] <= r) || rtIsNaN(r)) {
            iwork->data[k] = i;
            p++;
            if (p == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork->data[k] = idx->data[q];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q];
            q++;
            if (q + 1 == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }
        j = qEnd;
      }
      b_i = nj;
    }
    emxFree_int32_T(&iwork);
    nj = x->size[0];
    while ((nj > 0) && rtIsNaN(x->data[idx->data[nj - 1] - 1])) {
      nj--;
    }
    if (nj < 1) {
      pct = rtNaN;
    } else if (nj == 1) {
      pct = x->data[idx->data[0] - 1];
    } else {
      r = 0.5 * (double)nj;
      b_i = (int)rt_roundd_snf(r);
      if (b_i >= nj) {
        pct = x->data[idx->data[nj - 1] - 1];
      } else {
        r -= (double)b_i;
        pct = (0.5 - r) * x->data[idx->data[b_i - 1] - 1] +
              (r + 0.5) * x->data[idx->data[b_i] - 1];
      }
    }
    emxFree_int32_T(&idx);
  }
  return pct;
}

/* End of code generation (prctile.c) */
