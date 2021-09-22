/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * my_butter_coeffs.c
 *
 * Code generation for function 'my_butter_coeffs'
 *
 */

/* Include files */
#include "my_butter_coeffs.h"
#include "average_beats_tnmg_data.h"
#include "average_beats_tnmg_initialize.h"
#include "eig.h"
#include "lp2hp.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }
  return y;
}

void my_butter_coeffs(double fc, double fs, const char filter_type[4],
                      double b_data[], int b_size[1], double a[4], double zi[3])
{
  static const char cv[128] = {
      '\x00',  '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
      '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
      '\x12',  '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b',  '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',     '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',     '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',     '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',     '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',     'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',     'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',     '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',     'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',     'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',     'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',     '\x7f'};
  static const signed char iv[6] = {1, 1, 1, -1, -1, -1};
  static const signed char iv1[6] = {1, -1, 1, -1, 1, -1};
  static const signed char iv2[6] = {1, 0, 0, 0, 1, 0};
  static const char b[4] = {'h', 'i', 'g', 'h'};
  static const char b_b[4] = {'s', 't', 'o', 'p'};
  creal_T c_data[7];
  creal_T b_x_data[6];
  creal_T z_data[6];
  creal_T b_c[4];
  creal_T p[3];
  creal_T x[3];
  double ad[9];
  double t1[9];
  double t2[9];
  double num_data[7];
  double x_data[6];
  double t[4];
  double c[3];
  double c_b[3];
  double cd[3];
  double den[3];
  double a21;
  double b_re;
  double d;
  double d1;
  double im;
  double maxval;
  double re;
  double u;
  double x_re;
  double zWn_im;
  double zWn_re;
  int btype;
  int r2;
  int r3;
  int ret;
  int rtemp;
  int z_size;
  char filter[4];
  signed char b1[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T y;
  if (!isInitialized_average_beats_tnmg) {
    average_beats_tnmg_initialize();
  }
  /*  since the function to generate the coefficients for a butterworth filter
   */
  /*  is quite complex and computetionally expensive, I replaced it with a */
  /*  switch/case condition that selecte the right coefficients depending on */
  /*  the sampling frequency of the signal (fs). The coeffients represent a 3rd
   */
  /*  order high-pass Butterworth filter with a cutoff requency of 0.4Hz (2.5 */
  /*  sec). */
  /*  switch fs */
  /*      case 300 */
  /*          b=[0.991657389432111;  -2.974972168296334;   2.974972168296334;
   * -0.991657389432111]; */
  /*          a=[ 1.000000000000000;  -2.983244888175193;   2.966629849266392;
   * -0.983384378015305]; */
  /*          zi=[ -0.991657388816874;   1.983314777644058;
   * -0.991657388827097]; */
  /*      case 500 */
  /*          b = [  0.994986058442272 ; -2.984958175326816
   * ;  2.984958175326816;  -0.994986058442272]; */
  /*          a =[   1.000000000000000 ; -2.989946914091736 ;  2.979944296951953
   * ; -0.989997256494488]; */
  /*          zi = [ -0.994986057554526;   1.989972115117976;
   * -0.994986057563406]; */
  /*      case 1000 */
  /*          b =[   0.997489880846521;  -2.992469642539564;   2.992469642539564
   * ; -0.997489880846521]; */
  /*          a =[   1.000000000000000;  -2.994973453077183
   * ;  2.989959531303781;  -0.994986062391207]; */
  /*          zi= [ -0.997489885639811;   1.994979771255529;
   * -0.997489885615778]; */
  /*      otherwise */
  /*          error(['filter coefficients not available for sampling frequency
   * of ' num2str(fs) ' Hz']) */
  /*  end */
  /* this is the code for a matlab implementation that works with all fs */
  filter[0] = cv[(unsigned char)filter_type[0] & 127];
  filter[1] = cv[(unsigned char)filter_type[1] & 127];
  filter[2] = cv[(unsigned char)filter_type[2] & 127];
  filter[3] = cv[(unsigned char)filter_type[3] & 127];
  ret = memcmp(&filter[0], &b[0], 4);
  guard1 = false;
  if (ret == 0) {
    guard1 = true;
  } else {
    ret = memcmp(&filter[0], &b_b[0], 4);
    if (ret == 0) {
      guard1 = true;
    } else {
      btype = 0;
    }
  }
  if (guard1) {
    ret = memcmp(&filter[0], &b[0], 4);
    if (ret == 0) {
      btype = 3;
    } else {
      btype = 4;
    }
  }
  u = 4.0 * tan(3.1415926535897931 * (fc / fs * 2.0) / 2.0);
  memset(&t1[0], 0, 9U * sizeof(double));
  c_b[1] = 0.0;
  c[1] = 0.0;
  c_b[2] = 0.0;
  c[2] = 0.0;
  t1[0] = -1.0;
  c_b[0] = 1.0;
  p[0].re = 1.0;
  p[0].im = 0.0;
  for (ret = 0; ret < 2; ret++) {
    maxval = 1.7320508075688774 * (double)ret + -0.86602540378443871;
    d = p[ret].im;
    d1 = p[ret].re;
    p[ret + 1].re = 0.49999999999999978 * d1 - -maxval * d;
    p[ret + 1].im = 0.49999999999999978 * d + -maxval * d1;
    for (r3 = ret + 1; r3 >= 2; r3--) {
      p[1].re -= -0.49999999999999978 * p[0].re - maxval * p[0].im;
      p[1].im -= -0.49999999999999978 * p[0].im + maxval * p[0].re;
    }
  }
  t[1] = 0.0;
  t[2] = 0.0;
  t[0] = 1.0;
  t[3] = 1.0000000000000002;
  d = (1.0 - -p[1].re * 0.0) / 1.0000000000000002;
  a[1] = d;
  a[0] = -p[1].re - d * 0.0;
  d = (0.0 - -p[2].re * 0.0) / 1.0000000000000002;
  a[3] = d;
  a[2] = -p[2].re - d * 0.0;
  b1[1] = 0;
  b1[0] = 1;
  for (ret = 0; ret < 2; ret++) {
    t1[ret + 1] = b1[ret];
    d = a[ret + 2];
    d1 = a[ret];
    t1[ret + 4] = d1 + d * 0.0;
    t1[ret + 7] = d1 * 0.0 + d * 1.0000000000000002;
    c[ret + 1] = t[(ret << 1) + 1];
    b1[ret] = 0;
    c_b[ret + 1] = 0.0;
  }
  c[0] = 0.0;
  c[1] *= 0.99999999999999989;
  c[2] *= 0.99999999999999989;
  if (btype == 1) {
    for (r3 = 0; r3 < 9; r3++) {
      ad[r3] = u * t1[r3];
    }
  } else {
    lp2hp(t1, c_b, c, u, ad, den, cd, &maxval);
  }
  memset(&t2[0], 0, 9U * sizeof(double));
  t2[0] = 1.0;
  t2[4] = 1.0;
  t2[8] = 1.0;
  for (r3 = 0; r3 < 9; r3++) {
    d = ad[r3] * 0.5 / 2.0;
    ad[r3] = d;
    d1 = t2[r3];
    t1[r3] = d1 + d;
    d1 -= d;
    t2[r3] = d1;
  }
  ret = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(t2[0]);
  a21 = fabs(t2[1]);
  if (a21 > maxval) {
    maxval = a21;
    ret = 1;
    r2 = 0;
  }
  if (fabs(t2[2]) > maxval) {
    ret = 2;
    r2 = 1;
    r3 = 0;
  }
  t2[r2] /= t2[ret];
  t2[r3] /= t2[ret];
  t2[r2 + 3] -= t2[r2] * t2[ret + 3];
  t2[r3 + 3] -= t2[r3] * t2[ret + 3];
  t2[r2 + 6] -= t2[r2] * t2[ret + 6];
  t2[r3 + 6] -= t2[r3] * t2[ret + 6];
  if (fabs(t2[r3 + 3]) > fabs(t2[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  t2[r3 + 3] /= t2[r2 + 3];
  t2[r3 + 6] -= t2[r3 + 3] * t2[r2 + 6];
  d = t1[ret];
  d1 = t1[r2] - d * t2[r2];
  maxval = t2[r3 + 3];
  a21 = t2[r3 + 6];
  zWn_im = ((t1[r3] - d * t2[r3]) - d1 * maxval) / a21;
  ad[2] = zWn_im;
  re = t2[ret + 6];
  d -= zWn_im * re;
  im = t2[r2 + 6];
  d1 -= zWn_im * im;
  zWn_re = t2[r2 + 3];
  d1 /= zWn_re;
  ad[1] = d1;
  b_re = t2[ret + 3];
  d -= d1 * b_re;
  d /= t2[ret];
  ad[0] = d;
  d = t1[ret + 3];
  d1 = t1[r2 + 3] - d * t2[r2];
  zWn_im = ((t1[r3 + 3] - d * t2[r3]) - d1 * maxval) / a21;
  ad[5] = zWn_im;
  d -= zWn_im * re;
  d1 -= zWn_im * im;
  d1 /= zWn_re;
  ad[4] = d1;
  d -= d1 * b_re;
  d /= t2[ret];
  ad[3] = d;
  d = t1[ret + 6];
  d1 = t1[r2 + 6] - d * t2[r2];
  zWn_im = ((t1[r3 + 6] - d * t2[r3]) - d1 * maxval) / a21;
  ad[8] = zWn_im;
  d -= zWn_im * re;
  d1 -= zWn_im * im;
  d1 /= zWn_re;
  ad[7] = d1;
  d -= d1 * b_re;
  d /= t2[ret];
  ad[6] = d;
  eig(ad, p);
  zWn_im = 2.0 * rt_atan2d_snf(u, 4.0);
  switch (btype) {
  case 1:
    z_size = 3;
    z_data[0].re = -1.0;
    z_data[0].im = -0.0;
    z_data[1].re = -1.0;
    z_data[1].im = -0.0;
    z_data[2].re = -1.0;
    z_data[2].im = -0.0;
    x_re = (((1.0 - p[0].re) * (1.0 - p[1].re) -
             (0.0 - p[0].im) * (0.0 - p[1].im)) *
                (1.0 - p[2].re) -
            ((1.0 - p[0].re) * (0.0 - p[1].im) +
             (0.0 - p[0].im) * (1.0 - p[1].re)) *
                (0.0 - p[2].im)) /
           8.0;
    break;
  case 2:
    z_size = 6;
    for (r3 = 0; r3 < 6; r3++) {
      z_data[r3].re = iv[r3];
      z_data[r3].im = 0.0;
    }
    zWn_re = zWn_im * 0.0;
    if (zWn_im == 0.0) {
      zWn_re = exp(zWn_re);
      zWn_im = 0.0;
    } else {
      maxval = exp(zWn_re / 2.0);
      zWn_re = maxval * (maxval * cos(zWn_im));
      zWn_im = maxval * (maxval * sin(zWn_im));
    }
    x[0].re = zWn_re - p[0].re;
    x[0].im = zWn_im - p[0].im;
    x[1].re = zWn_re - p[1].re;
    x[1].im = zWn_im - p[1].im;
    x[2].re = zWn_re - p[2].re;
    x[2].im = zWn_im - p[2].im;
    x_re = x[0].re * x[1].re - x[0].im * x[1].im;
    maxval = x[0].re * x[1].im + x[0].im * x[1].re;
    b_re = x_re * x[2].re - maxval * x[2].im;
    im = x_re * x[2].im + maxval * x[2].re;
    for (r3 = 0; r3 < 6; r3++) {
      b_x_data[r3].re = zWn_re - z_data[r3].re;
      b_x_data[r3].im = zWn_im - z_data[r3].im;
    }
    zWn_re = b_x_data[0].re;
    zWn_im = b_x_data[0].im;
    for (r3 = 0; r3 < 5; r3++) {
      d = b_x_data[r3 + 1].re;
      d1 = b_x_data[r3 + 1].im;
      re = zWn_re * d - zWn_im * d1;
      zWn_im = zWn_re * d1 + zWn_im * d;
      zWn_re = re;
    }
    if (zWn_im == 0.0) {
      if (im == 0.0) {
        x_re = b_re / zWn_re;
      } else if (b_re == 0.0) {
        x_re = 0.0;
      } else {
        x_re = b_re / zWn_re;
      }
    } else if (zWn_re == 0.0) {
      if (b_re == 0.0) {
        x_re = im / zWn_im;
      } else if (im == 0.0) {
        x_re = 0.0;
      } else {
        x_re = im / zWn_im;
      }
    } else {
      maxval = fabs(zWn_re);
      a21 = fabs(zWn_im);
      if (maxval > a21) {
        maxval = zWn_im / zWn_re;
        x_re = (b_re + maxval * im) / (zWn_re + maxval * zWn_im);
      } else if (a21 == maxval) {
        if (zWn_re > 0.0) {
          zWn_re = 0.5;
        } else {
          zWn_re = -0.5;
        }
        if (zWn_im > 0.0) {
          zWn_im = 0.5;
        } else {
          zWn_im = -0.5;
        }
        x_re = (b_re * zWn_re + im * zWn_im) / maxval;
      } else {
        maxval = zWn_re / zWn_im;
        x_re = (maxval * b_re + im) / (zWn_im + maxval * zWn_re);
      }
    }
    break;
  case 3:
    z_size = 3;
    z_data[0].re = 1.0;
    z_data[0].im = 0.0;
    z_data[1].re = 1.0;
    z_data[1].im = 0.0;
    z_data[2].re = 1.0;
    z_data[2].im = 0.0;
    x_re = (((p[0].re + 1.0) * (p[1].re + 1.0) - p[0].im * p[1].im) *
                (p[2].re + 1.0) -
            ((p[0].re + 1.0) * p[1].im + p[0].im * (p[1].re + 1.0)) * p[2].im) /
           8.0;
    break;
  case 4:
    zWn_re = zWn_im * 0.0;
    z_size = 6;
    x_re =
        (1.0 - p[0].re) * (1.0 - p[1].re) - (0.0 - p[0].im) * (0.0 - p[1].im);
    maxval =
        (1.0 - p[0].re) * (0.0 - p[1].im) + (0.0 - p[0].im) * (1.0 - p[1].re);
    b_re = x_re * (1.0 - p[2].re) - maxval * (0.0 - p[2].im);
    im = x_re * (0.0 - p[2].im) + maxval * (1.0 - p[2].re);
    for (r3 = 0; r3 < 6; r3++) {
      ret = iv1[r3];
      re = (double)ret * zWn_re;
      a21 = (double)ret * zWn_im;
      if (a21 == 0.0) {
        re = exp(re);
        a21 = 0.0;
        d = 0.0;
      } else {
        maxval = exp(re / 2.0);
        re = maxval * (maxval * cos(a21));
        a21 = maxval * (maxval * sin(a21));
        d = a21;
      }
      z_data[r3].re = re;
      z_data[r3].im = a21;
      b_x_data[r3].re = 1.0 - re;
      b_x_data[r3].im = 0.0 - d;
    }
    zWn_re = b_x_data[0].re;
    zWn_im = b_x_data[0].im;
    for (r3 = 0; r3 < 5; r3++) {
      d = b_x_data[r3 + 1].re;
      d1 = b_x_data[r3 + 1].im;
      re = zWn_re * d - zWn_im * d1;
      zWn_im = zWn_re * d1 + zWn_im * d;
      zWn_re = re;
    }
    if (zWn_im == 0.0) {
      if (im == 0.0) {
        x_re = b_re / zWn_re;
      } else if (b_re == 0.0) {
        x_re = 0.0;
      } else {
        x_re = b_re / zWn_re;
      }
    } else if (zWn_re == 0.0) {
      if (b_re == 0.0) {
        x_re = im / zWn_im;
      } else if (im == 0.0) {
        x_re = 0.0;
      } else {
        x_re = im / zWn_im;
      }
    } else {
      maxval = fabs(zWn_re);
      a21 = fabs(zWn_im);
      if (maxval > a21) {
        maxval = zWn_im / zWn_re;
        x_re = (b_re + maxval * im) / (zWn_re + maxval * zWn_im);
      } else if (a21 == maxval) {
        if (zWn_re > 0.0) {
          zWn_re = 0.5;
        } else {
          zWn_re = -0.5;
        }
        if (zWn_im > 0.0) {
          zWn_im = 0.5;
        } else {
          zWn_im = -0.5;
        }
        x_re = (b_re * zWn_re + im * zWn_im) / maxval;
      } else {
        maxval = zWn_re / zWn_im;
        x_re = (maxval * b_re + im) / (zWn_im + maxval * zWn_re);
      }
    }
    break;
  }
  for (r3 = 0; r3 < z_size; r3++) {
    x_data[r3] = z_data[r3].im;
  }
  y = false;
  ret = 0;
  exitg1 = false;
  while ((!exitg1) && (ret + 1 <= z_size)) {
    if ((x_data[ret] == 0.0) || rtIsNaN(x_data[ret])) {
      ret++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (!y) {
    for (r3 = 0; r3 < z_size; r3++) {
      z_data[r3].im = 0.0;
    }
  }
  b_c[0].re = 1.0;
  b_c[0].im = 0.0;
  for (ret = 0; ret < 3; ret++) {
    maxval = -p[ret].re;
    a21 = -p[ret].im;
    d = b_c[ret].im;
    d1 = b_c[ret].re;
    b_c[ret + 1].re = maxval * d1 - a21 * d;
    b_c[ret + 1].im = maxval * d + a21 * d1;
    for (r3 = ret + 1; r3 >= 2; r3--) {
      d = p[ret].re;
      d1 = p[ret].im;
      a21 = d * b_c[r3 - 2].im + d1 * b_c[r3 - 2].re;
      b_c[r3 - 1].re -= d * b_c[r3 - 2].re - d1 * b_c[r3 - 2].im;
      b_c[r3 - 1].im -= a21;
    }
  }
  r2 = z_size + 1;
  c_data[0].re = 1.0;
  c_data[0].im = 0.0;
  for (ret = 0; ret < z_size; ret++) {
    maxval = -z_data[ret].re;
    a21 = -z_data[ret].im;
    d = c_data[ret].im;
    d1 = c_data[ret].re;
    c_data[ret + 1].re = maxval * d1 - a21 * d;
    c_data[ret + 1].im = maxval * d + a21 * d1;
    for (r3 = ret + 1; r3 >= 2; r3--) {
      d = z_data[ret].re;
      d1 = z_data[ret].im;
      a21 = d * c_data[r3 - 2].im + d1 * c_data[r3 - 2].re;
      c_data[r3 - 1].re -= d * c_data[r3 - 2].re - d1 * c_data[r3 - 2].im;
      c_data[r3 - 1].im -= a21;
    }
  }
  for (r3 = 0; r3 < r2; r3++) {
    num_data[r3] = x_re * c_data[r3].re;
  }
  b_size[0] = z_size + 1;
  if (0 <= r2 - 1) {
    memcpy(&b_data[0], &num_data[0], r2 * sizeof(double));
  }
  a[0] = b_c[0].re;
  a[1] = b_c[1].re;
  a[2] = b_c[2].re;
  a[3] = b_c[3].re;
  memset(&t1[0], 0, 9U * sizeof(double));
  t1[0] = 1.0;
  t1[4] = 1.0;
  t1[8] = 1.0;
  ad[0] = 1.0 - (-b_c[1].re);
  ad[1] = 0.0 - (-b_c[2].re);
  ad[2] = 0.0 - (-b_c[3].re);
  for (r3 = 0; r3 < 2; r3++) {
    ret = 3 * (r3 + 1);
    ad[ret] = t1[ret] - (double)iv2[3 * r3];
    ad[ret + 1] = t1[ret + 1] - (double)iv2[3 * r3 + 1];
    ad[ret + 2] = t1[ret + 2] - (double)iv2[3 * r3 + 2];
  }
  c_b[0] = num_data[1] - num_data[0] * b_c[1].re;
  c_b[1] = num_data[2] - num_data[0] * b_c[2].re;
  c_b[2] = num_data[3] - num_data[0] * b_c[3].re;
  mldivide(ad, c_b, zi);
  /*  NOTE eye is a function that creates an identity matrix; */
}

/* End of code generation (my_butter_coeffs.c) */
