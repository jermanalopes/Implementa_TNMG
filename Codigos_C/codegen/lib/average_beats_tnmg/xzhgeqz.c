/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzhgeqz.c
 *
 * Code generation for function 'xzhgeqz'
 *
 */

/* Include files */
#include "xzhgeqz.h"
#include "average_beats_tnmg_data.h"
#include "average_beats_tnmg_rtwutil.h"
#include "rt_nonfinite.h"
#include "xzlanhs.h"
#include "xzlartg.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void xzhgeqz(const creal_T A[9], int ilo, int ihi, int *info, creal_T alpha1[3],
             creal_T beta1[3])
{
  creal_T b_A[9];
  creal_T b_ascale;
  creal_T ctemp;
  creal_T shift;
  double absxr;
  double ad22_im;
  double ad22_re;
  double anorm;
  double ascale;
  double ascale_im;
  double ascale_re;
  double b_ascale_re;
  double b_atol;
  double eshift_im;
  double eshift_re;
  double t1_im;
  double t1_im_tmp;
  double t1_re;
  double yi;
  int ad22_re_tmp;
  int ctemp_tmp;
  int exitg1;
  int ifirst;
  int iiter;
  int ilast;
  int ilastm;
  int ilastm1;
  int istart;
  int j;
  int jiter;
  int jp1;
  int shift_re_tmp;
  boolean_T b_guard1 = false;
  boolean_T exitg2;
  boolean_T failed;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  memcpy(&b_A[0], &A[0], 9U * sizeof(creal_T));
  *info = 0;
  alpha1[0].re = 0.0;
  alpha1[0].im = 0.0;
  beta1[0].re = 1.0;
  beta1[0].im = 0.0;
  alpha1[1].re = 0.0;
  alpha1[1].im = 0.0;
  beta1[1].re = 1.0;
  beta1[1].im = 0.0;
  alpha1[2].re = 0.0;
  alpha1[2].im = 0.0;
  beta1[2].re = 1.0;
  beta1[2].im = 0.0;
  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = xzlanhs(A, ilo, ihi);
  yi = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (yi > 2.2250738585072014E-308) {
    b_atol = yi;
  }
  yi = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    yi = anorm;
  }
  ascale = 1.0 / yi;
  failed = true;
  jp1 = ihi + 1;
  for (j = jp1; j < 4; j++) {
    alpha1[j - 1] = A[(j + 3 * (j - 1)) - 1];
  }
  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    ilastm = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
        b_guard1 = false;
        if (ilast + 1 == ilo) {
          goto60 = true;
          b_guard1 = true;
        } else {
          jp1 = ilast + 3 * ilastm1;
          if (fabs(b_A[jp1].re) + fabs(b_A[jp1].im) <= b_atol) {
            b_A[jp1].re = 0.0;
            b_A[jp1].im = 0.0;
            goto60 = true;
            b_guard1 = true;
          } else {
            j = ilastm1;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (j + 1 >= ilo)) {
              if (j + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                jp1 = j + 3 * (j - 1);
                if (fabs(b_A[jp1].re) + fabs(b_A[jp1].im) <= b_atol) {
                  b_A[jp1].re = 0.0;
                  b_A[jp1].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  j--;
                  guard3 = false;
                }
              }
            }
            if (guard3) {
              ifirst = j + 1;
              goto70 = true;
            }
            if (goto70) {
              b_guard1 = true;
            } else {
              alpha1[0].re = rtNaN;
              alpha1[0].im = 0.0;
              beta1[0].re = rtNaN;
              beta1[0].im = 0.0;
              alpha1[1].re = rtNaN;
              alpha1[1].im = 0.0;
              beta1[1].re = rtNaN;
              beta1[1].im = 0.0;
              alpha1[2].re = rtNaN;
              alpha1[2].im = 0.0;
              beta1[2].re = rtNaN;
              beta1[2].im = 0.0;
              *info = 1;
              exitg1 = 1;
            }
          }
        }
        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = b_A[ilast + 3 * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              ilastm = ilast + 1;
              jiter++;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (iiter - iiter / 10 * 10 != 0) {
                jp1 = ilastm1 + 3 * ilastm1;
                anorm = ascale * b_A[jp1].re;
                yi = ascale * b_A[jp1].im;
                if (yi == 0.0) {
                  shift.re = anorm / 0.57735026918962584;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = yi / 0.57735026918962584;
                } else {
                  shift.re = anorm / 0.57735026918962584;
                  shift.im = yi / 0.57735026918962584;
                }
                jp1 = ilast + 3 * ilast;
                anorm = ascale * b_A[jp1].re;
                yi = ascale * b_A[jp1].im;
                if (yi == 0.0) {
                  ad22_re = anorm / 0.57735026918962584;
                  ad22_im = 0.0;
                } else if (anorm == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = yi / 0.57735026918962584;
                } else {
                  ad22_re = anorm / 0.57735026918962584;
                  ad22_im = yi / 0.57735026918962584;
                }
                t1_re = 0.5 * (shift.re + ad22_re);
                t1_im = 0.5 * (shift.im + ad22_im);
                t1_im_tmp = t1_re * t1_im;
                jp1 = ilastm1 + 3 * ilast;
                anorm = ascale * b_A[jp1].re;
                yi = ascale * b_A[jp1].im;
                if (yi == 0.0) {
                  ascale_re = anorm / 0.57735026918962584;
                  ascale_im = 0.0;
                } else if (anorm == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = yi / 0.57735026918962584;
                } else {
                  ascale_re = anorm / 0.57735026918962584;
                  ascale_im = yi / 0.57735026918962584;
                }
                jp1 = ilast + 3 * ilastm1;
                anorm = ascale * b_A[jp1].re;
                yi = ascale * b_A[jp1].im;
                if (yi == 0.0) {
                  b_ascale_re = anorm / 0.57735026918962584;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  b_ascale_re = 0.0;
                  anorm = yi / 0.57735026918962584;
                } else {
                  b_ascale_re = anorm / 0.57735026918962584;
                  anorm = yi / 0.57735026918962584;
                }
                yi = shift.re * ad22_re - shift.im * ad22_im;
                absxr = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) +
                            (ascale_re * b_ascale_re - ascale_im * anorm)) -
                           yi;
                shift.im = ((t1_im_tmp + t1_im_tmp) +
                            (ascale_re * anorm + ascale_im * b_ascale_re)) -
                           absxr;
                if (shift.im == 0.0) {
                  if (shift.re < 0.0) {
                    anorm = 0.0;
                    yi = sqrt(-shift.re);
                  } else {
                    anorm = sqrt(shift.re);
                    yi = 0.0;
                  }
                } else if (shift.re == 0.0) {
                  if (shift.im < 0.0) {
                    anorm = sqrt(-shift.im / 2.0);
                    yi = -anorm;
                  } else {
                    anorm = sqrt(shift.im / 2.0);
                    yi = anorm;
                  }
                } else if (rtIsNaN(shift.re)) {
                  anorm = shift.re;
                  yi = shift.re;
                } else if (rtIsNaN(shift.im)) {
                  anorm = shift.im;
                  yi = shift.im;
                } else if (rtIsInf(shift.im)) {
                  anorm = fabs(shift.im);
                  yi = shift.im;
                } else if (rtIsInf(shift.re)) {
                  if (shift.re < 0.0) {
                    anorm = 0.0;
                    yi = shift.im * -shift.re;
                  } else {
                    anorm = shift.re;
                    yi = 0.0;
                  }
                } else {
                  absxr = fabs(shift.re);
                  anorm = fabs(shift.im);
                  if ((absxr > 4.4942328371557893E+307) ||
                      (anorm > 4.4942328371557893E+307)) {
                    absxr *= 0.5;
                    anorm = rt_hypotd_snf(absxr, anorm * 0.5);
                    if (anorm > absxr) {
                      anorm = sqrt(anorm) * sqrt(absxr / anorm + 1.0);
                    } else {
                      anorm = sqrt(anorm) * 1.4142135623730951;
                    }
                  } else {
                    anorm = sqrt((rt_hypotd_snf(absxr, anorm) + absxr) * 0.5);
                  }
                  if (shift.re > 0.0) {
                    yi = 0.5 * (shift.im / anorm);
                  } else {
                    if (shift.im < 0.0) {
                      yi = -anorm;
                    } else {
                      yi = anorm;
                    }
                    anorm = 0.5 * (shift.im / yi);
                  }
                }
                if ((t1_re - ad22_re) * anorm + (t1_im - ad22_im) * yi <= 0.0) {
                  shift.re = t1_re + anorm;
                  shift.im = t1_im + yi;
                } else {
                  shift.re = t1_re - anorm;
                  shift.im = t1_im - yi;
                }
              } else {
                jp1 = ilast + 3 * ilastm1;
                anorm = ascale * b_A[jp1].re;
                yi = ascale * b_A[jp1].im;
                if (yi == 0.0) {
                  ascale_re = anorm / 0.57735026918962584;
                  ascale_im = 0.0;
                } else if (anorm == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = yi / 0.57735026918962584;
                } else {
                  ascale_re = anorm / 0.57735026918962584;
                  ascale_im = yi / 0.57735026918962584;
                }
                eshift_re += ascale_re;
                eshift_im += ascale_im;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }
              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp_tmp = j + 3 * j;
                ctemp.re =
                    ascale * b_A[ctemp_tmp].re - shift.re * 0.57735026918962584;
                ctemp.im =
                    ascale * b_A[ctemp_tmp].im - shift.im * 0.57735026918962584;
                yi = fabs(ctemp.re) + fabs(ctemp.im);
                jp1 += 3 * j;
                anorm = ascale * (fabs(b_A[jp1].re) + fabs(b_A[jp1].im));
                absxr = yi;
                if (anorm > yi) {
                  absxr = anorm;
                }
                if ((absxr < 1.0) && (absxr != 0.0)) {
                  yi /= absxr;
                  anorm /= absxr;
                }
                jp1 = j + 3 * (j - 1);
                if ((fabs(b_A[jp1].re) + fabs(b_A[jp1].im)) * anorm <=
                    yi * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }
              if (!goto90) {
                istart = ifirst;
                ctemp_tmp = (ifirst + 3 * (ifirst - 1)) - 1;
                ctemp.re =
                    ascale * b_A[ctemp_tmp].re - shift.re * 0.57735026918962584;
                ctemp.im =
                    ascale * b_A[ctemp_tmp].im - shift.im * 0.57735026918962584;
              }
              goto90 = false;
              jp1 = istart + 3 * (istart - 1);
              b_ascale.re = ascale * b_A[jp1].re;
              b_ascale.im = ascale * b_A[jp1].im;
              b_xzlartg(ctemp, b_ascale, &anorm, &shift);
              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  ctemp_tmp = j + 3 * jp1;
                  xzlartg(b_A[3 * jp1 + 1], b_A[ctemp_tmp], &anorm, &shift,
                          &b_A[3 * jp1 + 1]);
                  b_A[ctemp_tmp].re = 0.0;
                  b_A[ctemp_tmp].im = 0.0;
                }
                for (jp1 = j; jp1 <= ilastm; jp1++) {
                  shift_re_tmp = j + 3 * (jp1 - 1);
                  ad22_re = anorm * b_A[shift_re_tmp - 1].re +
                            (shift.re * b_A[shift_re_tmp].re -
                             shift.im * b_A[shift_re_tmp].im);
                  ad22_im = anorm * b_A[shift_re_tmp - 1].im +
                            (shift.re * b_A[shift_re_tmp].im +
                             shift.im * b_A[shift_re_tmp].re);
                  yi = b_A[shift_re_tmp - 1].re;
                  b_A[shift_re_tmp].re = anorm * b_A[shift_re_tmp].re -
                                         (shift.re * b_A[shift_re_tmp - 1].re +
                                          shift.im * b_A[shift_re_tmp - 1].im);
                  b_A[shift_re_tmp].im =
                      anorm * b_A[shift_re_tmp].im -
                      (shift.re * b_A[shift_re_tmp - 1].im - shift.im * yi);
                  b_A[shift_re_tmp - 1].re = ad22_re;
                  b_A[shift_re_tmp - 1].im = ad22_im;
                }
                shift.re = -shift.re;
                shift.im = -shift.im;
                jp1 = j;
                if (ilast + 1 < j + 2) {
                  jp1 = ilast - 1;
                }
                for (ctemp_tmp = ifirst; ctemp_tmp <= jp1 + 2; ctemp_tmp++) {
                  shift_re_tmp = (ctemp_tmp + 3 * (j - 1)) - 1;
                  ad22_re_tmp = (ctemp_tmp + 3 * j) - 1;
                  ad22_re = anorm * b_A[ad22_re_tmp].re +
                            (shift.re * b_A[shift_re_tmp].re -
                             shift.im * b_A[shift_re_tmp].im);
                  ad22_im = anorm * b_A[ad22_re_tmp].im +
                            (shift.re * b_A[shift_re_tmp].im +
                             shift.im * b_A[shift_re_tmp].re);
                  yi = b_A[ad22_re_tmp].re;
                  b_A[shift_re_tmp].re = anorm * b_A[shift_re_tmp].re -
                                         (shift.re * b_A[ad22_re_tmp].re +
                                          shift.im * b_A[ad22_re_tmp].im);
                  b_A[shift_re_tmp].im =
                      anorm * b_A[shift_re_tmp].im -
                      (shift.re * b_A[ad22_re_tmp].im - shift.im * yi);
                  b_A[ad22_re_tmp].re = ad22_re;
                  b_A[ad22_re_tmp].im = ad22_im;
                }
                jp1 = j - 1;
                j++;
              }
            }
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }
  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 <= ilast; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    for (j = 0; j <= ilo - 2; j++) {
      alpha1[j] = b_A[j + 3 * j];
    }
  }
}

/* End of code generation (xzhgeqz.c) */
