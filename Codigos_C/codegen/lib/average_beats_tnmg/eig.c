/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "eig.h"
#include "average_beats_tnmg_data.h"
#include "average_beats_tnmg_rtwutil.h"
#include "eigHermitianStandard.h"
#include "rt_nonfinite.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void eig(const double A[9], creal_T V[3])
{
  creal_T At[9];
  creal_T beta1[3];
  creal_T atmp;
  double dv[3];
  double a;
  double absxk;
  double anrm;
  double anrmto;
  double cfrom1;
  double cto1;
  double ctoc;
  int At_tmp;
  int exitg1;
  int exitg3;
  int i;
  int ihi;
  int ii;
  int ilo;
  int j;
  int jj;
  int nzcount;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T ilascl;
  boolean_T notdone;
  notdone = true;
  for (ii = 0; ii < 9; ii++) {
    if ((!notdone) || (rtIsInf(A[ii]) || rtIsNaN(A[ii]))) {
      notdone = false;
    }
  }
  if (!notdone) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
    V[2].re = rtNaN;
    V[2].im = 0.0;
  } else {
    notdone = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 3)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= j) {
          if (!(A[i + 3 * j] == A[j + 3 * i])) {
            notdone = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    if (notdone) {
      eigHermitianStandard(A, dv);
      V[0].re = dv[0];
      V[0].im = 0.0;
      V[1].re = dv[1];
      V[1].im = 0.0;
      V[2].re = dv[2];
      V[2].im = 0.0;
    } else {
      for (ii = 0; ii < 9; ii++) {
        At[ii].re = A[ii];
        At[ii].im = 0.0;
      }
      anrm = 0.0;
      ii = 0;
      exitg2 = false;
      while ((!exitg2) && (ii < 9)) {
        absxk = rt_hypotd_snf(At[ii].re, 0.0);
        if (rtIsNaN(absxk)) {
          anrm = rtNaN;
          exitg2 = true;
        } else {
          if (absxk > anrm) {
            anrm = absxk;
          }
          ii++;
        }
      }
      if (rtIsInf(anrm) || rtIsNaN(anrm)) {
        V[0].re = rtNaN;
        V[0].im = 0.0;
        beta1[0].re = rtNaN;
        beta1[0].im = 0.0;
        V[1].re = rtNaN;
        V[1].im = 0.0;
        beta1[1].re = rtNaN;
        beta1[1].im = 0.0;
        V[2].re = rtNaN;
        V[2].im = 0.0;
        beta1[2].re = rtNaN;
        beta1[2].im = 0.0;
      } else {
        ilascl = false;
        anrmto = anrm;
        guard1 = false;
        if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
          anrmto = 6.7178761075670888E-139;
          ilascl = true;
          guard1 = true;
        } else if (anrm > 1.4885657073574029E+138) {
          anrmto = 1.4885657073574029E+138;
          ilascl = true;
          guard1 = true;
        }
        if (guard1) {
          absxk = anrm;
          ctoc = anrmto;
          notdone = true;
          while (notdone) {
            cfrom1 = absxk * 2.0041683600089728E-292;
            cto1 = ctoc / 4.9896007738368E+291;
            if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
              a = 2.0041683600089728E-292;
              absxk = cfrom1;
            } else if (cto1 > absxk) {
              a = 4.9896007738368E+291;
              ctoc = cto1;
            } else {
              a = ctoc / absxk;
              notdone = false;
            }
            for (ii = 0; ii < 9; ii++) {
              At[ii].re *= a;
              At[ii].im *= a;
            }
          }
        }
        ilo = 1;
        ihi = 3;
        do {
          exitg3 = 0;
          i = 0;
          j = 0;
          notdone = false;
          ii = ihi;
          exitg2 = false;
          while ((!exitg2) && (ii > 0)) {
            nzcount = 0;
            i = ii;
            j = ihi;
            jj = 0;
            exitg4 = false;
            while ((!exitg4) && (jj <= ihi - 1)) {
              At_tmp = (ii + 3 * jj) - 1;
              if ((At[At_tmp].re != 0.0) || (At[At_tmp].im != 0.0) ||
                  (ii == jj + 1)) {
                if (nzcount == 0) {
                  j = jj + 1;
                  nzcount = 1;
                  jj++;
                } else {
                  nzcount = 2;
                  exitg4 = true;
                }
              } else {
                jj++;
              }
            }
            if (nzcount < 2) {
              notdone = true;
              exitg2 = true;
            } else {
              ii--;
            }
          }
          if (!notdone) {
            exitg3 = 2;
          } else {
            if (i != ihi) {
              atmp = At[i - 1];
              At[i - 1] = At[ihi - 1];
              At[ihi - 1] = atmp;
              atmp = At[i + 2];
              At[i + 2] = At[ihi + 2];
              At[ihi + 2] = atmp;
              atmp = At[i + 5];
              At[i + 5] = At[ihi + 5];
              At[ihi + 5] = atmp;
            }
            if (j != ihi) {
              for (ii = 0; ii < ihi; ii++) {
                nzcount = ii + 3 * (j - 1);
                atmp = At[nzcount];
                At_tmp = ii + 3 * (ihi - 1);
                At[nzcount] = At[At_tmp];
                At[At_tmp] = atmp;
              }
            }
            ihi--;
            if (ihi == 1) {
              exitg3 = 1;
            }
          }
        } while (exitg3 == 0);
        if (exitg3 != 1) {
          do {
            exitg1 = 0;
            i = 0;
            j = 0;
            notdone = false;
            jj = ilo;
            exitg2 = false;
            while ((!exitg2) && (jj <= ihi)) {
              nzcount = 0;
              i = ihi;
              j = jj;
              ii = ilo;
              exitg4 = false;
              while ((!exitg4) && (ii <= ihi)) {
                At_tmp = (ii + 3 * (jj - 1)) - 1;
                if ((At[At_tmp].re != 0.0) || (At[At_tmp].im != 0.0) ||
                    (ii == jj)) {
                  if (nzcount == 0) {
                    i = ii;
                    nzcount = 1;
                    ii++;
                  } else {
                    nzcount = 2;
                    exitg4 = true;
                  }
                } else {
                  ii++;
                }
              }
              if (nzcount < 2) {
                notdone = true;
                exitg2 = true;
              } else {
                jj++;
              }
            }
            if (!notdone) {
              exitg1 = 1;
            } else {
              if (i != ilo) {
                for (ii = ilo; ii < 4; ii++) {
                  nzcount = 3 * (ii - 1);
                  jj = (i + nzcount) - 1;
                  atmp = At[jj];
                  At_tmp = (ilo + nzcount) - 1;
                  At[jj] = At[At_tmp];
                  At[At_tmp] = atmp;
                }
              }
              if (j != ilo) {
                for (ii = 0; ii < ihi; ii++) {
                  nzcount = ii + 3 * (j - 1);
                  atmp = At[nzcount];
                  At_tmp = ii + 3 * (ilo - 1);
                  At[nzcount] = At[At_tmp];
                  At[At_tmp] = atmp;
                }
              }
              ilo++;
              if (ilo == ihi) {
                exitg1 = 1;
              }
            }
          } while (exitg1 == 0);
        }
        if (ihi >= ilo + 2) {
          ii = ilo;
          while (ii < 2) {
            xzlartg(At[1], At[2], &absxk, &atmp, &At[1]);
            At[2].re = 0.0;
            At[2].im = 0.0;
            ctoc = atmp.re * At[5].re - atmp.im * At[5].im;
            cfrom1 = atmp.re * At[5].im + atmp.im * At[5].re;
            At[5].re =
                absxk * At[5].re - (atmp.re * At[4].re + atmp.im * At[4].im);
            At[5].im =
                absxk * At[5].im - (atmp.re * At[4].im - atmp.im * At[4].re);
            At[4].re = absxk * At[4].re + ctoc;
            At[4].im = absxk * At[4].im + cfrom1;
            ctoc = atmp.re * At[8].re - atmp.im * At[8].im;
            cfrom1 = atmp.re * At[8].im + atmp.im * At[8].re;
            At[8].re =
                absxk * At[8].re - (atmp.re * At[7].re + atmp.im * At[7].im);
            At[8].im =
                absxk * At[8].im - (atmp.re * At[7].im - atmp.im * At[7].re);
            At[7].re = absxk * At[7].re + ctoc;
            At[7].im = absxk * At[7].im + cfrom1;
            atmp.re = -atmp.re;
            atmp.im = -atmp.im;
            ctoc = atmp.re * At[3].re - atmp.im * At[3].im;
            cfrom1 = atmp.re * At[3].im + atmp.im * At[3].re;
            At[3].re =
                absxk * At[3].re - (atmp.re * At[6].re + atmp.im * At[6].im);
            At[3].im =
                absxk * At[3].im - (atmp.re * At[6].im - atmp.im * At[6].re);
            At[6].re = absxk * At[6].re + ctoc;
            At[6].im = absxk * At[6].im + cfrom1;
            ctoc = atmp.re * At[4].re - atmp.im * At[4].im;
            cfrom1 = atmp.re * At[4].im + atmp.im * At[4].re;
            At[4].re =
                absxk * At[4].re - (atmp.re * At[7].re + atmp.im * At[7].im);
            At[4].im =
                absxk * At[4].im - (atmp.re * At[7].im - atmp.im * At[7].re);
            At[7].re = absxk * At[7].re + ctoc;
            At[7].im = absxk * At[7].im + cfrom1;
            ctoc = atmp.re * At[5].re - atmp.im * At[5].im;
            cfrom1 = atmp.re * At[5].im + atmp.im * At[5].re;
            At[5].re =
                absxk * At[5].re - (atmp.re * At[8].re + atmp.im * At[8].im);
            At[5].im =
                absxk * At[5].im - (atmp.re * At[8].im - atmp.im * At[8].re);
            At[8].re = absxk * At[8].re + ctoc;
            At[8].im = absxk * At[8].im + cfrom1;
            ii = 2;
          }
        }
        xzhgeqz(At, ilo, ihi, &ii, V, beta1);
        if ((ii == 0) && ilascl) {
          notdone = true;
          while (notdone) {
            cfrom1 = anrmto * 2.0041683600089728E-292;
            cto1 = anrm / 4.9896007738368E+291;
            if ((cfrom1 > anrm) && (anrm != 0.0)) {
              a = 2.0041683600089728E-292;
              anrmto = cfrom1;
            } else if (cto1 > anrmto) {
              a = 4.9896007738368E+291;
              anrm = cto1;
            } else {
              a = anrm / anrmto;
              notdone = false;
            }
            V[0].re *= a;
            V[0].im *= a;
            V[1].re *= a;
            V[1].im *= a;
            V[2].re *= a;
            V[2].im *= a;
          }
        }
      }
      if (beta1[0].im == 0.0) {
        if (V[0].im == 0.0) {
          cto1 = V[0].re / beta1[0].re;
          absxk = 0.0;
        } else if (V[0].re == 0.0) {
          cto1 = 0.0;
          absxk = V[0].im / beta1[0].re;
        } else {
          cto1 = V[0].re / beta1[0].re;
          absxk = V[0].im / beta1[0].re;
        }
      } else if (beta1[0].re == 0.0) {
        if (V[0].re == 0.0) {
          cto1 = V[0].im / beta1[0].im;
          absxk = 0.0;
        } else if (V[0].im == 0.0) {
          cto1 = 0.0;
          absxk = -(V[0].re / beta1[0].im);
        } else {
          cto1 = V[0].im / beta1[0].im;
          absxk = -(V[0].re / beta1[0].im);
        }
      } else {
        cfrom1 = fabs(beta1[0].re);
        absxk = fabs(beta1[0].im);
        if (cfrom1 > absxk) {
          absxk = beta1[0].im / beta1[0].re;
          ctoc = beta1[0].re + absxk * beta1[0].im;
          cto1 = (V[0].re + absxk * V[0].im) / ctoc;
          absxk = (V[0].im - absxk * V[0].re) / ctoc;
        } else if (absxk == cfrom1) {
          if (beta1[0].re > 0.0) {
            absxk = 0.5;
          } else {
            absxk = -0.5;
          }
          if (beta1[0].im > 0.0) {
            ctoc = 0.5;
          } else {
            ctoc = -0.5;
          }
          cto1 = (V[0].re * absxk + V[0].im * ctoc) / cfrom1;
          absxk = (V[0].im * absxk - V[0].re * ctoc) / cfrom1;
        } else {
          absxk = beta1[0].re / beta1[0].im;
          ctoc = beta1[0].im + absxk * beta1[0].re;
          cto1 = (absxk * V[0].re + V[0].im) / ctoc;
          absxk = (absxk * V[0].im - V[0].re) / ctoc;
        }
      }
      V[0].re = cto1;
      V[0].im = absxk;
      if (beta1[1].im == 0.0) {
        if (V[1].im == 0.0) {
          cto1 = V[1].re / beta1[1].re;
          absxk = 0.0;
        } else if (V[1].re == 0.0) {
          cto1 = 0.0;
          absxk = V[1].im / beta1[1].re;
        } else {
          cto1 = V[1].re / beta1[1].re;
          absxk = V[1].im / beta1[1].re;
        }
      } else if (beta1[1].re == 0.0) {
        if (V[1].re == 0.0) {
          cto1 = V[1].im / beta1[1].im;
          absxk = 0.0;
        } else if (V[1].im == 0.0) {
          cto1 = 0.0;
          absxk = -(V[1].re / beta1[1].im);
        } else {
          cto1 = V[1].im / beta1[1].im;
          absxk = -(V[1].re / beta1[1].im);
        }
      } else {
        cfrom1 = fabs(beta1[1].re);
        absxk = fabs(beta1[1].im);
        if (cfrom1 > absxk) {
          absxk = beta1[1].im / beta1[1].re;
          ctoc = beta1[1].re + absxk * beta1[1].im;
          cto1 = (V[1].re + absxk * V[1].im) / ctoc;
          absxk = (V[1].im - absxk * V[1].re) / ctoc;
        } else if (absxk == cfrom1) {
          if (beta1[1].re > 0.0) {
            absxk = 0.5;
          } else {
            absxk = -0.5;
          }
          if (beta1[1].im > 0.0) {
            ctoc = 0.5;
          } else {
            ctoc = -0.5;
          }
          cto1 = (V[1].re * absxk + V[1].im * ctoc) / cfrom1;
          absxk = (V[1].im * absxk - V[1].re * ctoc) / cfrom1;
        } else {
          absxk = beta1[1].re / beta1[1].im;
          ctoc = beta1[1].im + absxk * beta1[1].re;
          cto1 = (absxk * V[1].re + V[1].im) / ctoc;
          absxk = (absxk * V[1].im - V[1].re) / ctoc;
        }
      }
      V[1].re = cto1;
      V[1].im = absxk;
      if (beta1[2].im == 0.0) {
        if (V[2].im == 0.0) {
          cto1 = V[2].re / beta1[2].re;
          absxk = 0.0;
        } else if (V[2].re == 0.0) {
          cto1 = 0.0;
          absxk = V[2].im / beta1[2].re;
        } else {
          cto1 = V[2].re / beta1[2].re;
          absxk = V[2].im / beta1[2].re;
        }
      } else if (beta1[2].re == 0.0) {
        if (V[2].re == 0.0) {
          cto1 = V[2].im / beta1[2].im;
          absxk = 0.0;
        } else if (V[2].im == 0.0) {
          cto1 = 0.0;
          absxk = -(V[2].re / beta1[2].im);
        } else {
          cto1 = V[2].im / beta1[2].im;
          absxk = -(V[2].re / beta1[2].im);
        }
      } else {
        cfrom1 = fabs(beta1[2].re);
        absxk = fabs(beta1[2].im);
        if (cfrom1 > absxk) {
          absxk = beta1[2].im / beta1[2].re;
          ctoc = beta1[2].re + absxk * beta1[2].im;
          cto1 = (V[2].re + absxk * V[2].im) / ctoc;
          absxk = (V[2].im - absxk * V[2].re) / ctoc;
        } else if (absxk == cfrom1) {
          if (beta1[2].re > 0.0) {
            absxk = 0.5;
          } else {
            absxk = -0.5;
          }
          if (beta1[2].im > 0.0) {
            ctoc = 0.5;
          } else {
            ctoc = -0.5;
          }
          cto1 = (V[2].re * absxk + V[2].im * ctoc) / cfrom1;
          absxk = (V[2].im * absxk - V[2].re * ctoc) / cfrom1;
        } else {
          absxk = beta1[2].re / beta1[2].im;
          ctoc = beta1[2].im + absxk * beta1[2].re;
          cto1 = (absxk * V[2].re + V[2].im) / ctoc;
          absxk = (absxk * V[2].im - V[2].re) / ctoc;
        }
      }
      V[2].re = cto1;
      V[2].im = absxk;
    }
  }
}

/* End of code generation (eig.c) */
