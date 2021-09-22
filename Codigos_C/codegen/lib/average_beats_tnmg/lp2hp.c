/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lp2hp.c
 *
 * Code generation for function 'lp2hp'
 *
 */

/* Include files */
#include "lp2hp.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void lp2hp(const double a[9], const double b[3], const double c[3], double wo,
           double at[9], double bt[3], double ct[3], double *dt)
{
  double x[9];
  double absx21_tmp;
  double absx31_tmp;
  double maxval;
  double t1;
  double t2;
  int itmp;
  int p1;
  int p2;
  int p3;
  memcpy(&x[0], &a[0], 9U * sizeof(double));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  maxval = fabs(a[0]);
  absx21_tmp = fabs(a[1]);
  absx31_tmp = fabs(a[2]);
  if ((absx21_tmp > maxval) && (absx21_tmp > absx31_tmp)) {
    p1 = 3;
    p2 = 0;
    x[0] = a[1];
    x[1] = a[0];
    x[3] = a[4];
    x[4] = a[3];
    x[6] = a[7];
    x[7] = a[6];
  } else if (absx31_tmp > maxval) {
    p1 = 6;
    p3 = 0;
    x[0] = a[2];
    x[2] = a[0];
    x[3] = a[5];
    x[5] = a[3];
    x[6] = a[8];
    x[8] = a[6];
  }
  x[1] /= x[0];
  x[2] /= x[0];
  x[4] -= x[1] * x[3];
  x[5] -= x[2] * x[3];
  x[7] -= x[1] * x[6];
  x[8] -= x[2] * x[6];
  if (fabs(x[5]) > fabs(x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    t1 = x[1];
    x[1] = x[2];
    x[2] = t1;
    t1 = x[4];
    x[4] = x[5];
    x[5] = t1;
    t1 = x[7];
    x[7] = x[8];
    x[8] = t1;
  }
  x[5] /= x[4];
  x[8] -= x[5] * x[7];
  t1 = (x[1] * x[5] - x[2]) / x[8];
  t2 = -(x[1] + x[7] * t1) / x[4];
  at[p1] = ((1.0 - x[3] * t2) - x[6] * t1) / x[0];
  at[p1 + 1] = t2;
  at[p1 + 2] = t1;
  t1 = -x[5] / x[8];
  t2 = (1.0 - x[7] * t1) / x[4];
  at[p2] = -(x[3] * t2 + x[6] * t1) / x[0];
  at[p2 + 1] = t2;
  at[p2 + 2] = t1;
  t1 = 1.0 / x[8];
  t2 = -x[7] * t1 / x[4];
  at[p3] = -(x[3] * t2 + x[6] * t1) / x[0];
  at[p3 + 1] = t2;
  at[p3 + 2] = t1;
  mldivide(a, b, bt);
  bt[0] *= -wo;
  bt[1] *= -wo;
  bt[2] *= -wo;
  for (p1 = 0; p1 < 9; p1++) {
    at[p1] *= wo;
    x[p1] = a[p1];
  }
  p1 = 0;
  p2 = 1;
  p3 = 2;
  if (absx21_tmp > maxval) {
    maxval = absx21_tmp;
    p1 = 1;
    p2 = 0;
  }
  if (absx31_tmp > maxval) {
    p1 = 2;
    p2 = 1;
    p3 = 0;
  }
  x[p2] = a[p2] / a[p1];
  x[p3] /= x[p1];
  x[p2 + 3] -= x[p2] * x[p1 + 3];
  x[p3 + 3] -= x[p3] * x[p1 + 3];
  x[p2 + 6] -= x[p2] * x[p1 + 6];
  x[p3 + 6] -= x[p3] * x[p1 + 6];
  if (fabs(x[p3 + 3]) > fabs(x[p2 + 3])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
  }
  x[p3 + 3] /= x[p2 + 3];
  x[p3 + 6] -= x[p3 + 3] * x[p2 + 6];
  ct[p1] = c[0] / x[p1];
  ct[p2] = c[1] - ct[p1] * x[p1 + 3];
  ct[p3] = c[2] - ct[p1] * x[p1 + 6];
  ct[p2] /= x[p2 + 3];
  ct[p3] -= ct[p2] * x[p2 + 6];
  ct[p3] /= x[p3 + 6];
  ct[p2] -= ct[p3] * x[p3 + 3];
  ct[p1] -= ct[p3] * x[p3];
  ct[p1] -= ct[p2] * x[p2];
  *dt = 0.0 - ((ct[0] * b[0] + ct[1] * b[1]) + ct[2] * b[2]);
}

/* End of code generation (lp2hp.c) */
