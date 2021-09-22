/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myfiltfilt.c
 *
 * Code generation for function 'myfiltfilt'
 *
 */

/* Include files */
#include "myfiltfilt.h"
#include "average_beats_tnmg_data.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_initialize.h"
#include "average_beats_tnmg_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static int div_s32_floor(int numerator, int denominator);

/* Function Definitions */
static int div_s32_floor(int numerator, int denominator)
{
  unsigned int absDenominator;
  unsigned int absNumerator;
  int quotient;
  unsigned int tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator < 0) {
      absNumerator = ~(unsigned int)numerator + 1U;
    } else {
      absNumerator = (unsigned int)numerator;
    }
    if (denominator < 0) {
      absDenominator = ~(unsigned int)denominator + 1U;
    } else {
      absDenominator = (unsigned int)denominator;
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

void myfiltfilt(const double b[4], const double a[4], emxArray_real_T *y,
                const double zi[3])
{
  emxArray_real_T *X;
  double d;
  double y_idx_0;
  int b_y;
  int i;
  int i1;
  int loop_ub;
  (void)a;
  if (!isInitialized_average_beats_tnmg) {
    average_beats_tnmg_initialize();
  }
  emxInit_real_T(&X, 1);
  /*  all inputs MUST be column vectors */
  /*  Cria uma versão expandida em 2*nfact */
  /* teste = [2*y(1)-y(nfact+1:-1:2); y; 2*y(end)-y(end-1:-1:end-nfact)]; */
  y_idx_0 = 2.0 * y->data[0];
  d = 2.0 * y->data[y->size[0] - 1];
  b_y = y->size[0];
  i = X->size[0];
  X->size[0] = y->size[0] + 18;
  emxEnsureCapacity_real_T(X, i);
  for (i = 0; i < 9; i++) {
    X->data[i] = y_idx_0 - y->data[9 - i];
  }
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    X->data[i + 9] = y->data[i];
  }
  for (i = 0; i < 9; i++) {
    X->data[(i + y->size[0]) + 9] = d - y->data[(b_y - i) - 2];
  }
  i = y->size[0];
  y->size[0] = X->size[0];
  emxEnsureCapacity_real_T(y, i);
  loop_ub = X->size[0];
  for (i = 0; i < loop_ub; i++) {
    y->data[i] = X->data[i];
  }
  /*  Filtra, espelha os dados e filtra novamente */
  y_idx_0 = zi[0] * y->data[0];
  i = X->size[0];
  X->size[0] = y->size[0];
  emxEnsureCapacity_real_T(X, i);
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    X->data[i] = y->data[i];
  }
  /*  all inputs MUST be column vectors */
  /*  z(n) = 0;      % Creates zeros if input z is omitted */
  b_y = y->size[0];
  i = y->size[0];
  y->size[0] = b_y;
  emxEnsureCapacity_real_T(y, i);
  for (loop_ub = 0; loop_ub < b_y; loop_ub++) {
    y->data[loop_ub] = 0.0;
    y->data[loop_ub] = b[0] * X->data[loop_ub] + y_idx_0;
  }
  b_y = y->size[0] - 1;
  loop_ub = div_s32_floor(-b_y, -1);
  i = X->size[0];
  X->size[0] = loop_ub + 1;
  emxEnsureCapacity_real_T(X, i);
  for (i = 0; i <= loop_ub; i++) {
    X->data[i] = y->data[b_y - i];
  }
  i = y->size[0];
  y->size[0] = X->size[0];
  emxEnsureCapacity_real_T(y, i);
  loop_ub = X->size[0];
  for (i = 0; i < loop_ub; i++) {
    y->data[i] = X->data[i];
  }
  y_idx_0 = zi[0] * y->data[0];
  i = X->size[0];
  X->size[0] = y->size[0];
  emxEnsureCapacity_real_T(X, i);
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    X->data[i] = y->data[i];
  }
  /*  all inputs MUST be column vectors */
  /*  z(n) = 0;      % Creates zeros if input z is omitted */
  b_y = y->size[0];
  i = y->size[0];
  y->size[0] = b_y;
  emxEnsureCapacity_real_T(y, i);
  for (loop_ub = 0; loop_ub < b_y; loop_ub++) {
    y->data[loop_ub] = 0.0;
    y->data[loop_ub] = b[0] * X->data[loop_ub] + y_idx_0;
  }
  /*  Retorna o tamanho original de y - Elimina os nfact adiconados */
  if (10.0 > (double)y->size[0] - 9.0) {
    i = 0;
    b_y = 1;
    i1 = -1;
  } else {
    i = y->size[0] - 10;
    b_y = -1;
    i1 = 9;
  }
  loop_ub = div_s32_floor(i1 - i, b_y);
  i1 = X->size[0];
  X->size[0] = loop_ub + 1;
  emxEnsureCapacity_real_T(X, i1);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    X->data[i1] = y->data[i + b_y * i1];
  }
  i = y->size[0];
  y->size[0] = X->size[0];
  emxEnsureCapacity_real_T(y, i);
  loop_ub = X->size[0];
  for (i = 0; i < loop_ub; i++) {
    y->data[i] = X->data[i];
  }
  emxFree_real_T(&X);
}

/* End of code generation (myfiltfilt.c) */
