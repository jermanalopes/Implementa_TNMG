/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  double tmp2;
  double work;
  int dimSize;
  int m;
  dimSize = x->size[1];
  if (x->size[1] <= 1) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    m = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1] - 1;
    emxEnsureCapacity_real_T(y, m);
    work = x->data[0];
    for (m = 2; m <= dimSize; m++) {
      tmp2 = work;
      work = x->data[m - 1];
      y->data[m - 2] = work - tmp2;
    }
  }
}

void c_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  double tmp2;
  double work;
  int dimSize;
  int m;
  dimSize = x->size[1];
  if (x->size[1] <= 1) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    m = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1] - 1;
    emxEnsureCapacity_real_T(y, m);
    work = x->data[0];
    for (m = 2; m <= dimSize; m++) {
      tmp2 = work;
      work = x->data[m - 1];
      y->data[m - 2] = work - tmp2;
    }
  }
}

void diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  double d;
  double tmp1;
  double work_data;
  int dimSize;
  int u0;
  dimSize = x->size[1];
  if (x->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    u0 = x->size[1] - 1;
    if (u0 >= 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      u0 = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = x->size[1] - 1;
      emxEnsureCapacity_real_T(y, u0);
      if (x->size[1] - 1 != 0) {
        work_data = x->data[0];
        for (u0 = 2; u0 <= dimSize; u0++) {
          tmp1 = x->data[u0 - 1];
          d = tmp1;
          tmp1 -= work_data;
          work_data = d;
          y->data[u0 - 2] = tmp1;
        }
      }
    }
  }
}

/* End of code generation (diff.c) */
