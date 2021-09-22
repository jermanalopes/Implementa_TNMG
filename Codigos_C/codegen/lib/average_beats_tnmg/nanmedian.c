/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanmedian.c
 *
 * Code generation for function 'nanmedian'
 *
 */

/* Include files */
#include "nanmedian.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_types.h"
#include "prctile.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_nanmedian(const emxArray_real_T *x, double y[12])
{
  emxArray_real_T *wk;
  int i;
  int k;
  int vlen;
  if (x->size[1] == 0) {
    for (i = 0; i < 12; i++) {
      y[i] = rtNaN;
    }
  } else {
    emxInit_real_T(&wk, 1);
    vlen = x->size[1];
    i = wk->size[0];
    wk->size[0] = x->size[1];
    emxEnsureCapacity_real_T(wk, i);
    for (i = 0; i < 12; i++) {
      wk->data[0] = x->data[i];
      for (k = 2; k <= vlen; k++) {
        wk->data[k - 1] = x->data[i + (k - 1) * 12];
      }
      y[i] = percentile_vector(wk);
    }
    emxFree_real_T(&wk);
  }
}

void nanmedian(const emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_real_T *wk;
  int ix;
  int iy;
  int iystart;
  int k;
  int npages;
  int vlen;
  int xi;
  ix = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(y, ix);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    npages = x->size[1];
    ix = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, ix);
    for (ix = 0; ix < npages; ix++) {
      y->data[ix] = rtNaN;
    }
  } else {
    emxInit_real_T(&wk, 1);
    vlen = x->size[0];
    ix = wk->size[0];
    wk->size[0] = x->size[0];
    emxEnsureCapacity_real_T(wk, ix);
    npages = x->size[1];
    ix = -1;
    iy = 0;
    for (xi = 0; xi < npages; xi++) {
      iystart = iy;
      wk->data[0] = x->data[ix + 1];
      for (k = 2; k <= vlen; k++) {
        wk->data[k - 1] = x->data[ix + k];
      }
      ix += vlen;
      iy++;
      y->data[iystart] = percentile_vector(wk);
    }
    emxFree_real_T(&wk);
  }
}

/* End of code generation (nanmedian.c) */
