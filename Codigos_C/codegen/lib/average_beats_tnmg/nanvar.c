/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanvar.c
 *
 * Code generation for function 'nanvar'
 *
 */

/* Include files */
#include "nanvar.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void nanvar(const emxArray_real_T *x, double y[12])
{
  double b_y;
  double r;
  double xbar;
  int i;
  int ix;
  int j;
  int k;
  int n;
  int nn;
  n = x->size[1] - 1;
  ix = -1;
  for (j = 0; j < 12; j++) {
    ix++;
    if (x->size[1] == 0) {
      y[j] = rtNaN;
    } else {
      xbar = 0.0;
      nn = 0;
      for (k = 0; k <= n; k++) {
        i = ix + k * 12;
        if (!rtIsNaN(x->data[i])) {
          xbar += x->data[i];
          nn++;
        }
      }
      if (nn == 0) {
        y[j] = rtNaN;
      } else {
        xbar /= (double)nn;
        b_y = 0.0;
        for (k = 0; k <= n; k++) {
          i = ix + k * 12;
          if (!rtIsNaN(x->data[i])) {
            r = x->data[i] - xbar;
            b_y += r * r;
          }
        }
        if (nn > 1) {
          nn--;
        }
        y[j] = b_y / (double)nn;
      }
    }
  }
}

/* End of code generation (nanvar.c) */
