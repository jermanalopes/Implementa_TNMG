/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squeeze.c
 *
 * Code generation for function 'squeeze'
 *
 */

/* Include files */
#include "squeeze.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_squeeze(const emxArray_real_T *a, emxArray_real_T *b)
{
  int i;
  int sqsz_idx_0;
  int sqsz_idx_1;
  sqsz_idx_0 = 1;
  sqsz_idx_1 = 1;
  if (a->size[2] == 1) {
    sqsz_idx_1 = 3;
  } else {
    sqsz_idx_0 = 3;
    if (a->size[2] != 1) {
      sqsz_idx_1 = a->size[2];
    }
  }
  i = b->size[0] * b->size[1];
  b->size[0] = sqsz_idx_0;
  b->size[1] = sqsz_idx_1;
  emxEnsureCapacity_real_T(b, i);
  sqsz_idx_0 *= sqsz_idx_1;
  for (i = 0; i < sqsz_idx_0; i++) {
    b->data[i] = a->data[i];
  }
}

void c_squeeze(const emxArray_real_T *a, emxArray_real_T *b)
{
  int i;
  int sqsz_idx_0;
  int sqsz_idx_1;
  sqsz_idx_0 = 1;
  sqsz_idx_1 = 1;
  if (a->size[2] == 1) {
    sqsz_idx_1 = 12;
  } else {
    sqsz_idx_0 = 12;
    if (a->size[2] != 1) {
      sqsz_idx_1 = a->size[2];
    }
  }
  i = b->size[0] * b->size[1];
  b->size[0] = sqsz_idx_0;
  b->size[1] = sqsz_idx_1;
  emxEnsureCapacity_real_T(b, i);
  sqsz_idx_0 *= sqsz_idx_1;
  for (i = 0; i < sqsz_idx_0; i++) {
    b->data[i] = a->data[i];
  }
}

void squeeze(const emxArray_real_T *a, emxArray_real_T *b)
{
  int sqsz[2];
  int i;
  int j;
  sqsz[0] = 1;
  sqsz[1] = 1;
  if ((a->size[2] == 1) && (a->size[0] == 1)) {
    sqsz[1] = 1;
  } else {
    j = 0;
    if (a->size[0] != 1) {
      j = 1;
      sqsz[0] = a->size[0];
    }
    if (a->size[2] != 1) {
      sqsz[j] = a->size[2];
    }
  }
  i = b->size[0] * b->size[1];
  b->size[0] = sqsz[0];
  b->size[1] = sqsz[1];
  emxEnsureCapacity_real_T(b, i);
  j = sqsz[0] * sqsz[1];
  for (i = 0; i < j; i++) {
    b->data[i] = a->data[i];
  }
}

/* End of code generation (squeeze.c) */
