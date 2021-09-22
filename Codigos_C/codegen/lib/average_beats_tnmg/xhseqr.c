/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.c
 *
 * Code generation for function 'xhseqr'
 *
 */

/* Include files */
#include "xhseqr.h"
#include "average_beats_tnmg_rtwutil.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
int xhseqr(double h[9])
{
  double v[3];
  double aa;
  double ab;
  double ba;
  double bb;
  double d;
  double h22;
  double rt1r;
  double s;
  double tst;
  int b_k;
  int hoffset;
  int i;
  int info;
  int its;
  int j;
  int k;
  int knt;
  int m;
  int nr;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T goto150;
  info = 0;
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 0.0;
  h[2] = 0.0;
  i = 2;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    k = -1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      k = i - 1;
      exitg3 = false;
      while ((!exitg3) && (k + 2 > 1)) {
        nr = k + 3 * k;
        ba = fabs(h[nr + 1]);
        if (ba <= 3.0062525400134592E-292) {
          exitg3 = true;
        } else {
          hoffset = 3 * (k + 1);
          knt = k + hoffset;
          bb = fabs(h[knt + 1]);
          tst = fabs(h[nr]) + bb;
          if (tst == 0.0) {
            if (k >= 1) {
              tst = fabs(h[k + 3 * (k - 1)]);
            }
            if (k + 3 <= 3) {
              tst += fabs(h[hoffset + 2]);
            }
          }
          if (ba <= 2.2204460492503131E-16 * tst) {
            tst = fabs(h[knt]);
            if (ba > tst) {
              ab = ba;
              ba = tst;
            } else {
              ab = tst;
            }
            tst = fabs(h[nr] - h[knt + 1]);
            if (bb > tst) {
              aa = bb;
              bb = tst;
            } else {
              aa = tst;
            }
            s = aa + ab;
            tst = 2.2204460492503131E-16 * (bb * (aa / s));
            if ((3.0062525400134592E-292 > tst) || rtIsNaN(tst)) {
              tst = 3.0062525400134592E-292;
            }
            if (ba * (ab / s) <= tst) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }
      if (k + 2 > 1) {
        h[(k + 3 * k) + 1] = 0.0;
      }
      if (k + 2 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        if (its == 10) {
          s = fabs(h[1]) + fabs(h[5]);
          tst = 0.75 * s + h[0];
          aa = -0.4375 * s;
          ab = s;
          h22 = tst;
        } else if (its == 20) {
          s = fabs(h[i + 3 * (i - 1)]) + fabs(h[i - 1]);
          tst = 0.75 * s + h[i + 3 * i];
          aa = -0.4375 * s;
          ab = s;
          h22 = tst;
        } else {
          hoffset = i + 3 * (i - 1);
          tst = h[hoffset - 1];
          ab = h[hoffset];
          aa = h[(i + 3 * i) - 1];
          h22 = h[i + 3 * i];
        }
        s = ((fabs(tst) + fabs(aa)) + fabs(ab)) + fabs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          tst = 0.0;
          ba = 0.0;
          aa = 0.0;
        } else {
          tst /= s;
          ab /= s;
          aa /= s;
          h22 /= s;
          bb = (tst + h22) / 2.0;
          tst = (tst - bb) * (h22 - bb) - aa * ab;
          aa = sqrt(fabs(tst));
          if (tst >= 0.0) {
            rt1r = bb * s;
            ba = rt1r;
            tst = aa * s;
            aa = -tst;
          } else {
            rt1r = bb + aa;
            ba = bb - aa;
            if (fabs(rt1r - h22) <= fabs(ba - h22)) {
              rt1r *= s;
              ba = rt1r;
            } else {
              ba *= s;
              rt1r = ba;
            }
            tst = 0.0;
            aa = 0.0;
          }
        }
        m = i - 1;
        if (i - 1 >= 1) {
          ab = h[0] - ba;
          s = (fabs(ab) + fabs(aa)) + fabs(h[1]);
          bb = h[1] / s;
          v[0] = (bb * h[3] + (h[0] - rt1r) * (ab / s)) - tst * (aa / s);
          v[1] = bb * (((h[0] + h[4]) - rt1r) - ba);
          v[2] = bb * h[5];
          s = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
          v[0] /= s;
          v[1] /= s;
          v[2] /= s;
        }
        for (b_k = m; b_k <= i; b_k++) {
          nr = (i - b_k) + 2;
          if (3 < nr) {
            nr = 3;
          }
          if (b_k > i - 1) {
            hoffset = (b_k + 3 * (b_k - 2)) - 1;
            for (j = 0; j < nr; j++) {
              v[j] = h[j + hoffset];
            }
          }
          aa = v[0];
          bb = 0.0;
          if (nr > 0) {
            tst = xnrm2(nr - 1, v);
            if (tst != 0.0) {
              ab = rt_hypotd_snf(v[0], tst);
              if (v[0] >= 0.0) {
                ab = -ab;
              }
              if (fabs(ab) < 1.0020841800044864E-292) {
                knt = -1;
                do {
                  knt++;
                  for (hoffset = 2; hoffset <= nr; hoffset++) {
                    v[hoffset - 1] *= 9.9792015476736E+291;
                  }
                  ab *= 9.9792015476736E+291;
                  aa *= 9.9792015476736E+291;
                } while (!(fabs(ab) >= 1.0020841800044864E-292));
                ab = rt_hypotd_snf(aa, xnrm2(nr - 1, v));
                if (aa >= 0.0) {
                  ab = -ab;
                }
                bb = (ab - aa) / ab;
                tst = 1.0 / (aa - ab);
                for (hoffset = 2; hoffset <= nr; hoffset++) {
                  v[hoffset - 1] *= tst;
                }
                for (hoffset = 0; hoffset <= knt; hoffset++) {
                  ab *= 1.0020841800044864E-292;
                }
                aa = ab;
              } else {
                bb = (ab - v[0]) / ab;
                tst = 1.0 / (v[0] - ab);
                for (hoffset = 2; hoffset <= nr; hoffset++) {
                  v[hoffset - 1] *= tst;
                }
                aa = ab;
              }
            }
          }
          v[0] = aa;
          if (b_k > i - 1) {
            h[b_k - 1] = aa;
            h[b_k] = 0.0;
            if (b_k < i) {
              h[2] = 0.0;
            }
          }
          d = v[1];
          aa = bb * v[1];
          if (nr == 3) {
            s = v[2];
            tst = bb * v[2];
            for (j = b_k; j < 4; j++) {
              nr = 3 * (j - 1);
              knt = b_k + nr;
              ab = (h[knt - 1] + d * h[knt]) + s * h[nr + 2];
              h[knt - 1] -= ab * bb;
              h[knt] -= ab * aa;
              h[nr + 2] -= ab * tst;
            }
            if (b_k + 3 < i + 1) {
              nr = b_k + 2;
            } else {
              nr = i;
            }
            for (j = 0; j <= nr; j++) {
              knt = j + 3 * (b_k - 1);
              hoffset = j + 3 * b_k;
              ab = (h[knt] + d * h[hoffset]) + s * h[j + 6];
              h[knt] -= ab * bb;
              h[hoffset] -= ab * aa;
              h[j + 6] -= ab * tst;
            }
          } else if (nr == 2) {
            for (j = b_k; j < 4; j++) {
              knt = b_k + 3 * (j - 1);
              tst = h[knt - 1];
              ab = tst + d * h[knt];
              h[knt - 1] = tst - ab * bb;
              h[knt] -= ab * aa;
            }
            for (j = 0; j <= i; j++) {
              knt = j + 3 * (b_k - 1);
              hoffset = j + 3 * b_k;
              ab = h[knt] + d * h[hoffset];
              h[knt] -= ab * bb;
              h[hoffset] -= ab * aa;
            }
          }
        }
        its++;
      }
    }
    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((k + 2 != i + 1) && (k + 2 == i)) {
        nr = i + 3 * i;
        d = h[nr - 1];
        j = 3 * (i - 1);
        hoffset = i + j;
        s = h[hoffset];
        tst = h[nr];
        xdlanv2(&h[(i + 3 * (i - 1)) - 1], &d, &s, &tst, &aa, &ab, &bb, &ba,
                &h22, &rt1r);
        h[nr - 1] = d;
        h[hoffset] = s;
        h[nr] = tst;
        if (3 > i + 1) {
          hoffset = 1 - i;
          knt = i + (i + 1) * 3;
          for (b_k = 0; b_k <= hoffset; b_k++) {
            nr = knt + b_k * 3;
            tst = h22 * h[nr - 1] + rt1r * h[nr];
            h[nr] = h22 * h[nr] - rt1r * h[nr - 1];
            h[nr - 1] = tst;
          }
        }
        if (i - 1 >= 1) {
          hoffset = i * 3;
          tst = h22 * h[j] + rt1r * h[hoffset];
          h[hoffset] = h22 * h[hoffset] - rt1r * h[j];
          h[j] = tst;
        }
      }
      i = k;
    }
  }
  return info;
}

/* End of code generation (xhseqr.c) */
