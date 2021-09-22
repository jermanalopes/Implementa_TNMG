/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanstd.c
 *
 * Code generation for function 'nanstd'
 *
 */

/* Include files */
#include "nanstd.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
double nanstd(const emxArray_real_T *varargin_1)
{
  double r;
  double xbar;
  double y;
  int k;
  int n;
  int nn;
  n = varargin_1->size[1] - 1;
  if (varargin_1->size[1] == 0) {
    y = rtNaN;
  } else {
    xbar = 0.0;
    nn = 0;
    for (k = 0; k <= n; k++) {
      r = varargin_1->data[k];
      if (!rtIsNaN(r)) {
        xbar += r;
        nn++;
      }
    }
    if (nn == 0) {
      y = rtNaN;
    } else {
      xbar /= (double)nn;
      y = 0.0;
      for (k = 0; k <= n; k++) {
        r = varargin_1->data[k];
        if (!rtIsNaN(r)) {
          r -= xbar;
          y += r * r;
        }
      }
      if (nn > 1) {
        nn--;
      }
      y /= (double)nn;
    }
  }
  return sqrt(y);
}

/* End of code generation (nanstd.c) */
