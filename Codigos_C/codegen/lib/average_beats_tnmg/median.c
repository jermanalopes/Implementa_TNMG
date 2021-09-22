/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * median.c
 *
 * Code generation for function 'median'
 *
 */

/* Include files */
#include "median.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_types.h"
#include "quickselect.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
double b_median(const double x[15])
{
  double a__4[15];
  double vk_tmp;
  double vref;
  double y;
  int c;
  int exitg1;
  int ia;
  int ib;
  int ilast;
  int ipiv;
  int k;
  int ngroupsof5;
  int nlast;
  int oldnv;
  boolean_T checkspeed;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T isslow;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 15) {
      if (rtIsNaN(x[k])) {
        y = rtNaN;
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      memcpy(&a__4[0], &x[0], 15U * sizeof(double));
      ipiv = 7;
      ia = 0;
      ib = 14;
      ilast = 14;
      oldnv = 15;
      checkspeed = false;
      isslow = false;
      exitg2 = false;
      while ((!exitg2) && (ia + 1 < ib + 1)) {
        vref = a__4[ipiv];
        a__4[ipiv] = a__4[ib];
        a__4[ib] = vref;
        ilast = ia;
        ipiv = -1;
        for (k = ia + 1; k <= ib; k++) {
          vk_tmp = a__4[k - 1];
          if (vk_tmp == vref) {
            a__4[k - 1] = a__4[ilast];
            a__4[ilast] = vk_tmp;
            ipiv++;
            ilast++;
          } else if (vk_tmp < vref) {
            a__4[k - 1] = a__4[ilast];
            a__4[ilast] = vk_tmp;
            ilast++;
          }
        }
        a__4[ib] = a__4[ilast];
        a__4[ilast] = vref;
        guard1 = false;
        if (8 <= ilast + 1) {
          if (8 >= ilast - ipiv) {
            exitg2 = true;
          } else {
            ib = ilast - 1;
            guard1 = true;
          }
        } else {
          ia = ilast + 1;
          guard1 = true;
        }
        if (guard1) {
          c = (ib - ia) + 1;
          if (checkspeed) {
            isslow = (c > oldnv / 2);
            oldnv = c;
          }
          checkspeed = !checkspeed;
          if (isslow) {
            while (c > 1) {
              ngroupsof5 = c / 5;
              nlast = c - ngroupsof5 * 5;
              c = ngroupsof5;
              for (k = 0; k < ngroupsof5; k++) {
                ipiv = (ia + k * 5) + 1;
                ipiv = b_thirdOfFive(a__4, ipiv, ipiv + 4) - 1;
                ilast = ia + k;
                vref = a__4[ilast];
                a__4[ilast] = a__4[ipiv];
                a__4[ipiv] = vref;
              }
              if (nlast > 0) {
                ipiv = (ia + ngroupsof5 * 5) + 1;
                ipiv = b_thirdOfFive(a__4, ipiv, (ipiv + nlast) - 1) - 1;
                ilast = ia + ngroupsof5;
                vref = a__4[ilast];
                a__4[ilast] = a__4[ipiv];
                a__4[ipiv] = vref;
                c = ngroupsof5 + 1;
              }
            }
          } else if (c >= 3) {
            ipiv = ia + (c - 1) / 2;
            if (a__4[ia] < a__4[ipiv]) {
              if (!(a__4[ipiv] < a__4[ib])) {
                if (a__4[ia] < a__4[ib]) {
                  ipiv = ib;
                } else {
                  ipiv = ia;
                }
              }
            } else if (a__4[ia] < a__4[ib]) {
              ipiv = ia;
            } else if (a__4[ipiv] < a__4[ib]) {
              ipiv = ib;
            }
            if (ipiv + 1 > ia + 1) {
              vref = a__4[ia];
              a__4[ia] = a__4[ipiv];
              a__4[ipiv] = vref;
            }
          }
          ipiv = ia;
          ilast = ib;
        }
      }
      y = a__4[ilast];
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return y;
}

double median(const emxArray_real_T *x)
{
  emxArray_real_T *a__4;
  double b;
  double y;
  int a__6;
  int exitg1;
  int k;
  int midm1;
  int vlen;
  vlen = x->size[1];
  if (x->size[1] == 0) {
    y = rtNaN;
  } else {
    k = 0;
    emxInit_real_T(&a__4, 2);
    do {
      exitg1 = 0;
      if (k <= vlen - 1) {
        if (rtIsNaN(x->data[k])) {
          y = rtNaN;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        if (vlen <= 4) {
          if (vlen == 0) {
            y = rtNaN;
          } else if (vlen == 1) {
            y = x->data[0];
          } else if (vlen == 2) {
            if (((x->data[0] < 0.0) != (x->data[1] < 0.0)) ||
                rtIsInf(x->data[0])) {
              y = (x->data[0] + x->data[1]) / 2.0;
            } else {
              y = x->data[0] + (x->data[1] - x->data[0]) / 2.0;
            }
          } else if (vlen == 3) {
            if (x->data[0] < x->data[1]) {
              if (x->data[1] < x->data[2]) {
                a__6 = 1;
              } else if (x->data[0] < x->data[2]) {
                a__6 = 2;
              } else {
                a__6 = 0;
              }
            } else if (x->data[0] < x->data[2]) {
              a__6 = 0;
            } else if (x->data[1] < x->data[2]) {
              a__6 = 2;
            } else {
              a__6 = 1;
            }
            y = x->data[a__6];
          } else {
            if (x->data[0] < x->data[1]) {
              if (x->data[1] < x->data[2]) {
                k = 0;
                a__6 = 1;
                vlen = 2;
              } else if (x->data[0] < x->data[2]) {
                k = 0;
                a__6 = 2;
                vlen = 1;
              } else {
                k = 2;
                a__6 = 0;
                vlen = 1;
              }
            } else if (x->data[0] < x->data[2]) {
              k = 1;
              a__6 = 0;
              vlen = 2;
            } else if (x->data[1] < x->data[2]) {
              k = 1;
              a__6 = 2;
              vlen = 0;
            } else {
              k = 2;
              a__6 = 1;
              vlen = 0;
            }
            if (x->data[k] < x->data[3]) {
              if (x->data[3] < x->data[vlen]) {
                if (((x->data[a__6] < 0.0) != (x->data[3] < 0.0)) ||
                    rtIsInf(x->data[a__6])) {
                  y = (x->data[a__6] + x->data[3]) / 2.0;
                } else {
                  y = x->data[a__6] + (x->data[3] - x->data[a__6]) / 2.0;
                }
              } else if (((x->data[a__6] < 0.0) != (x->data[vlen] < 0.0)) ||
                         rtIsInf(x->data[a__6])) {
                y = (x->data[a__6] + x->data[vlen]) / 2.0;
              } else {
                y = x->data[a__6] + (x->data[vlen] - x->data[a__6]) / 2.0;
              }
            } else if (((x->data[k] < 0.0) != (x->data[a__6] < 0.0)) ||
                       rtIsInf(x->data[k])) {
              y = (x->data[k] + x->data[a__6]) / 2.0;
            } else {
              y = x->data[k] + (x->data[a__6] - x->data[k]) / 2.0;
            }
          }
        } else {
          midm1 = vlen >> 1;
          if ((vlen & 1) == 0) {
            a__6 = a__4->size[0] * a__4->size[1];
            a__4->size[0] = 1;
            a__4->size[1] = x->size[1];
            emxEnsureCapacity_real_T(a__4, a__6);
            k = x->size[1];
            for (a__6 = 0; a__6 < k; a__6++) {
              a__4->data[a__6] = x->data[a__6];
            }
            quickselect(a__4, midm1 + 1, vlen, &y, &k, &a__6);
            if (midm1 < k) {
              quickselect(a__4, midm1, a__6 - 1, &b, &k, &vlen);
              if (((y < 0.0) != (b < 0.0)) || rtIsInf(y)) {
                y = (y + b) / 2.0;
              } else {
                y += (b - y) / 2.0;
              }
            }
          } else {
            a__6 = a__4->size[0] * a__4->size[1];
            a__4->size[0] = 1;
            a__4->size[1] = x->size[1];
            emxEnsureCapacity_real_T(a__4, a__6);
            k = x->size[1];
            for (a__6 = 0; a__6 < k; a__6++) {
              a__4->data[a__6] = x->data[a__6];
            }
            quickselect(a__4, midm1 + 1, vlen, &y, &k, &a__6);
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    emxFree_real_T(&a__4);
  }
  return y;
}

/* End of code generation (median.c) */
