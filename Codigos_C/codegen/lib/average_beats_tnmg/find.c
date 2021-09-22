/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i)
{
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x->size[1];
  idx = 0;
  ii = i->size[0];
  i->size[0] = x->size[1];
  emxEnsureCapacity_int32_T(i, ii);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x->data[ii]) {
      idx++;
      i->data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x->size[1] == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    ii = i->size[0];
    if (1 > idx) {
      i->size[0] = 0;
    } else {
      i->size[0] = idx;
    }
    emxEnsureCapacity_int32_T(i, ii);
  }
}

/* End of code generation (find.c) */
