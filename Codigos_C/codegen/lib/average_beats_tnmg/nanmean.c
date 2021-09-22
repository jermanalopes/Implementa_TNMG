/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanmean.c
 *
 * Code generation for function 'nanmean'
 *
 */

/* Include files */
#include "nanmean.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
double b_nanmean(const double varargin_1[3])
{
  double y;
  int c;
  y = 0.0;
  c = 0;
  if (!rtIsNaN(varargin_1[0])) {
    y = varargin_1[0];
    c = 1;
  }
  if (!rtIsNaN(varargin_1[1])) {
    y += varargin_1[1];
    c++;
  }
  if (!rtIsNaN(varargin_1[2])) {
    y += varargin_1[2];
    c++;
  }
  if (c == 0) {
    y = rtNaN;
  } else {
    y /= (double)c;
  }
  return y;
}

void c_nanmean(const emxArray_real_T *varargin_1, double y[12])
{
  double s;
  int i;
  int j;
  int k;
  int n;
  int vlen;
  if (varargin_1->size[1] == 0) {
    for (vlen = 0; vlen < 12; vlen++) {
      y[vlen] = rtNaN;
    }
  } else {
    vlen = varargin_1->size[1];
    for (j = 0; j < 12; j++) {
      if (!rtIsNaN(varargin_1->data[j])) {
        s = varargin_1->data[j];
        n = 1;
      } else {
        s = 0.0;
        n = 0;
      }
      for (k = 2; k <= vlen; k++) {
        i = j + (k - 1) * 12;
        if (!rtIsNaN(varargin_1->data[i])) {
          s += varargin_1->data[i];
          n++;
        }
      }
      if (n == 0) {
        s = rtNaN;
      } else {
        s /= (double)n;
      }
      y[j] = s;
    }
  }
}

void nanmean(const emxArray_real_T *varargin_1, double y[3])
{
  double s;
  int i;
  int j;
  int k;
  int n;
  int vlen;
  if (varargin_1->size[1] == 0) {
    y[0] = rtNaN;
    y[1] = rtNaN;
    y[2] = rtNaN;
  } else {
    vlen = varargin_1->size[1];
    for (j = 0; j < 3; j++) {
      if (!rtIsNaN(varargin_1->data[j])) {
        s = varargin_1->data[j];
        n = 1;
      } else {
        s = 0.0;
        n = 0;
      }
      for (k = 2; k <= vlen; k++) {
        i = j + (k - 1) * 3;
        if (!rtIsNaN(varargin_1->data[i])) {
          s += varargin_1->data[i];
          n++;
        }
      }
      if (n == 0) {
        s = rtNaN;
      } else {
        s /= (double)n;
      }
      y[j] = s;
    }
  }
}

/* End of code generation (nanmean.c) */
