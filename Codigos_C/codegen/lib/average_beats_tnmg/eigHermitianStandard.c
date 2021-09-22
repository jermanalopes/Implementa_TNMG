/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eigHermitianStandard.c
 *
 * Code generation for function 'eigHermitianStandard'
 *
 */

/* Include files */
#include "eigHermitianStandard.h"
#include "average_beats_tnmg_rtwutil.h"
#include "rt_nonfinite.h"
#include "xhseqr.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static int div_nde_s32_floor(int numerator, int denominator);

/* Function Definitions */
static int div_nde_s32_floor(int numerator, int denominator)
{
  int b_numerator;
  if (((numerator < 0) != (denominator < 0)) &&
      (numerator % denominator != 0)) {
    b_numerator = -1;
  } else {
    b_numerator = 0;
  }
  return numerator / denominator + b_numerator;
}

void eigHermitianStandard(const double A[9], double V[3])
{
  double T[9];
  double work[3];
  double tau[2];
  double b_alpha1_tmp;
  double beta1;
  double xnorm;
  int alpha1_tmp;
  int b_i;
  int c_i;
  int coltop;
  int exitg1;
  int i;
  int ia;
  int in;
  int iv0_tmp;
  int jA;
  int knt;
  int lastc;
  int lastv;
  int rowleft;
  boolean_T exitg2;
  boolean_T p;
  p = true;
  for (i = 0; i < 9; i++) {
    xnorm = A[i];
    T[i] = xnorm;
    if ((!p) || (rtIsInf(xnorm) || rtIsNaN(xnorm))) {
      p = false;
    }
  }
  if (!p) {
    for (b_i = 0; b_i < 9; b_i++) {
      T[b_i] = rtNaN;
    }
    i = 2;
    for (coltop = 0; coltop < 2; coltop++) {
      if (i <= 3) {
        memset(&T[(coltop * 3 + i) + -1], 0, (4 - i) * sizeof(double));
      }
      i++;
    }
  } else {
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    for (c_i = 0; c_i < 2; c_i++) {
      coltop = c_i * 3 + 2;
      in = (c_i + 1) * 3;
      alpha1_tmp = (c_i + 3 * c_i) + 1;
      b_alpha1_tmp = T[alpha1_tmp];
      rowleft = coltop + 1;
      tau[c_i] = 0.0;
      xnorm = 0.0;
      if (1 - c_i >= 1) {
        xnorm = fabs(T[coltop]);
      }
      if (xnorm != 0.0) {
        beta1 = rt_hypotd_snf(b_alpha1_tmp, xnorm);
        if (b_alpha1_tmp >= 0.0) {
          beta1 = -beta1;
        }
        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = -1;
          b_i = (coltop - c_i) + 1;
          do {
            knt++;
            for (i = rowleft; i <= b_i; i++) {
              T[i - 1] *= 9.9792015476736E+291;
            }
            beta1 *= 9.9792015476736E+291;
            b_alpha1_tmp *= 9.9792015476736E+291;
          } while (!(fabs(beta1) >= 1.0020841800044864E-292));
          xnorm = 0.0;
          if (1 - c_i >= 1) {
            xnorm = fabs(T[coltop]);
          }
          beta1 = rt_hypotd_snf(b_alpha1_tmp, xnorm);
          if (b_alpha1_tmp >= 0.0) {
            beta1 = -beta1;
          }
          tau[c_i] = (beta1 - b_alpha1_tmp) / beta1;
          xnorm = 1.0 / (b_alpha1_tmp - beta1);
          for (i = rowleft; i <= b_i; i++) {
            T[i - 1] *= xnorm;
          }
          for (i = 0; i <= knt; i++) {
            beta1 *= 1.0020841800044864E-292;
          }
          b_alpha1_tmp = beta1;
        } else {
          tau[c_i] = (beta1 - b_alpha1_tmp) / beta1;
          xnorm = 1.0 / (b_alpha1_tmp - beta1);
          b_i = (coltop - c_i) + 1;
          for (i = rowleft; i <= b_i; i++) {
            T[i - 1] *= xnorm;
          }
          b_alpha1_tmp = beta1;
        }
      }
      T[alpha1_tmp] = 1.0;
      iv0_tmp = (c_i + coltop) - 1;
      jA = in + 1;
      if (tau[c_i] != 0.0) {
        lastv = 1 - c_i;
        i = (iv0_tmp - c_i) + 1;
        while ((lastv + 1 > 0) && (T[i] == 0.0)) {
          lastv--;
          i--;
        }
        lastc = 3;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          rowleft = in + lastc;
          ia = rowleft;
          do {
            exitg1 = 0;
            if (ia <= rowleft + lastv * 3) {
              if (T[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia += 3;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = -1;
        lastc = 0;
      }
      if (lastv + 1 > 0) {
        if (lastc != 0) {
          if (0 <= lastc - 1) {
            memset(&work[0], 0, lastc * sizeof(double));
          }
          knt = iv0_tmp;
          b_i = (in + 3 * lastv) + 1;
          for (i = jA; i <= b_i; i += 3) {
            rowleft = (i + lastc) - 1;
            for (ia = i; ia <= rowleft; ia++) {
              coltop = ia - i;
              work[coltop] += T[ia - 1] * T[knt];
            }
            knt++;
          }
        }
        if (!(-tau[c_i] == 0.0)) {
          jA = in;
          for (coltop = 0; coltop <= lastv; coltop++) {
            xnorm = T[iv0_tmp + coltop];
            if (xnorm != 0.0) {
              xnorm *= -tau[c_i];
              b_i = jA + 1;
              rowleft = lastc + jA;
              for (knt = b_i; knt <= rowleft; knt++) {
                T[knt - 1] += work[(knt - jA) - 1] * xnorm;
              }
            }
            jA += 3;
          }
        }
      }
      jA = (c_i + in) + 2;
      if (tau[c_i] != 0.0) {
        lastv = 2 - c_i;
        i = (iv0_tmp - c_i) + 1;
        while ((lastv > 0) && (T[i] == 0.0)) {
          lastv--;
          i--;
        }
        lastc = 1 - c_i;
        exitg2 = false;
        while ((!exitg2) && (lastc + 1 > 0)) {
          coltop = jA + lastc * 3;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + lastv) - 1) {
              if (T[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = -1;
      }
      if (lastv > 0) {
        if (lastc + 1 != 0) {
          if (0 <= lastc) {
            memset(&work[0], 0, (lastc + 1) * sizeof(double));
          }
          b_i = jA + 3 * lastc;
          for (i = jA; i <= b_i; i += 3) {
            xnorm = 0.0;
            rowleft = (i + lastv) - 1;
            for (ia = i; ia <= rowleft; ia++) {
              xnorm += T[ia - 1] * T[(iv0_tmp + ia) - i];
            }
            coltop = div_nde_s32_floor(i - jA, 3);
            work[coltop] += xnorm;
          }
        }
        if (!(-tau[c_i] == 0.0)) {
          for (coltop = 0; coltop <= lastc; coltop++) {
            xnorm = work[coltop];
            if (xnorm != 0.0) {
              xnorm *= -tau[c_i];
              b_i = lastv + jA;
              for (knt = jA; knt < b_i; knt++) {
                T[knt - 1] += T[(iv0_tmp + knt) - jA] * xnorm;
              }
            }
            jA += 3;
          }
        }
      }
      T[alpha1_tmp] = b_alpha1_tmp;
    }
    xhseqr(T);
  }
  V[0] = T[0];
  V[1] = T[4];
  V[2] = T[8];
}

/* End of code generation (eigHermitianStandard.c) */
