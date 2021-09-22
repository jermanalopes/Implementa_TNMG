/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "ECG_peak_detect_mod_with_derivative.h"
#include "average_beats_tnmg.h"
#include "average_beats_tnmg_emxAPI.h"
#include "average_beats_tnmg_terminate.h"
#include "average_beats_tnmg_types.h"
#include "my_butter_coeffs.h"
#include "myfiltfilt.h"
#include "peakdetect.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static emxArray_real_T *argInit_12xUnbounded_real_T(void);

static void argInit_1x4_char_T(char result[4]);

static emxArray_real_T *argInit_1xUnbounded_real_T(void);

static emxArray_real_T *argInit_2xUnbounded_real_T(void);

static void argInit_3x1_real_T(double result[3]);

static void argInit_4x1_real_T(double result[4]);

static emxArray_real_T *argInit_Unboundedx1_real_T(void);

static char argInit_char_T(void);

static double argInit_real_T(void);

static void c_main_ECG_peak_detect_mod_with(void);

static void main_average_beats_tnmg(void);

static void main_my_butter_coeffs(void);

static void main_myfiltfilt(void);

static void main_peakdetect(void);

/* Function Definitions */
static emxArray_real_T *argInit_12xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(12, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 12; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx0 + 12 * idx1] = argInit_real_T();
    }
  }
  return result;
}

static void argInit_1x4_char_T(char result[4])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 4; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(1, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx1] = argInit_real_T();
    }
  }
  return result;
}

static emxArray_real_T *argInit_2xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx0 + 2 * idx1] = argInit_real_T();
    }
  }
  return result;
}

static void argInit_3x1_real_T(double result[3])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static void argInit_4x1_real_T(double result[4])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 4; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  const int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, &i);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }
  return result;
}

static char argInit_char_T(void)
{
  return '?';
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void c_main_ECG_peak_detect_mod_with(void)
{
  emxArray_real_T *ecg;
  emxArray_real_T *vcg;
  emxArray_real_T *vcg2;
  emxArray_real_T *vcg_peaks_pos;
  double peak_threshold;
  emxInitArray_real_T(&vcg_peaks_pos, 1);
  emxInitArray_real_T(&vcg, 2);
  emxInitArray_real_T(&vcg2, 2);
  /* Initialize function 'ECG_peak_detect_mod_with_derivative' input arguments.
   */
  /* Initialize function input argument 'ecg'. */
  ecg = argInit_12xUnbounded_real_T();
  /* Call the entry-point 'ECG_peak_detect_mod_with_derivative'. */
  ECG_peak_detect_mod_with_derivative(ecg, argInit_real_T(), vcg_peaks_pos,
                                      &peak_threshold, vcg, vcg2);
  emxDestroyArray_real_T(vcg2);
  emxDestroyArray_real_T(vcg);
  emxDestroyArray_real_T(vcg_peaks_pos);
  emxDestroyArray_real_T(ecg);
}

static void main_average_beats_tnmg(void)
{
  emxArray_real_T *R_pos;
  emxArray_real_T *ecg;
  emxArray_real_T *vcg;
  double SNR_overall;
  double SNR_overall_type;
  /* Initialize function 'average_beats_tnmg' input arguments. */
  /* Initialize function input argument 'ecg'. */
  ecg = argInit_12xUnbounded_real_T();
  /* Initialize function input argument 'R_pos'. */
  R_pos = argInit_1xUnbounded_real_T();
  /* Initialize function input argument 'vcg'. */
  vcg = argInit_2xUnbounded_real_T();
  /* Call the entry-point 'average_beats_tnmg'. */
  average_beats_tnmg(ecg, R_pos, argInit_real_T(), vcg, &SNR_overall,
                     &SNR_overall_type);
  emxDestroyArray_real_T(vcg);
  emxDestroyArray_real_T(R_pos);
  emxDestroyArray_real_T(ecg);
}

static void main_my_butter_coeffs(void)
{
  double b_data[7];
  double a[4];
  double zi[3];
  double fc_tmp;
  int b_size;
  char cv[4];
  /* Initialize function 'my_butter_coeffs' input arguments. */
  fc_tmp = argInit_real_T();
  /* Initialize function input argument 'filter_type'. */
  /* Call the entry-point 'my_butter_coeffs'. */
  argInit_1x4_char_T(cv);
  my_butter_coeffs(fc_tmp, fc_tmp, cv, b_data, *(int(*)[1]) & b_size, a, zi);
}

static void main_myfiltfilt(void)
{
  emxArray_real_T *y;
  double b_tmp[4];
  double dv[3];
  /* Initialize function 'myfiltfilt' input arguments. */
  /* Initialize function input argument 'b'. */
  argInit_4x1_real_T(b_tmp);
  /* Initialize function input argument 'a'. */
  /* Initialize function input argument 'y'. */
  y = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'zi'. */
  /* Call the entry-point 'myfiltfilt'. */
  argInit_3x1_real_T(dv);
  myfiltfilt(b_tmp, b_tmp, y, dv);
  emxDestroyArray_real_T(y);
}

static void main_peakdetect(void)
{
  emxArray_real_T *b_signal;
  emxArray_real_T *negpeakind;
  emxArray_real_T *pospeakind;
  double c_pospeak_treshold_bigger_than_;
  emxInitArray_real_T(&pospeakind, 1);
  emxInitArray_real_T(&negpeakind, 1);
  /* Initialize function 'peakdetect' input arguments. */
  /* Initialize function input argument 'signal'. */
  b_signal = argInit_1xUnbounded_real_T();
  c_pospeak_treshold_bigger_than_ = argInit_real_T();
  /* Call the entry-point 'peakdetect'. */
  peakdetect(b_signal, c_pospeak_treshold_bigger_than_,
             c_pospeak_treshold_bigger_than_, c_pospeak_treshold_bigger_than_,
             c_pospeak_treshold_bigger_than_, c_pospeak_treshold_bigger_than_,
             pospeakind, negpeakind);
  emxDestroyArray_real_T(negpeakind);
  emxDestroyArray_real_T(pospeakind);
  emxDestroyArray_real_T(b_signal);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_average_beats_tnmg();
  c_main_ECG_peak_detect_mod_with();
  main_my_butter_coeffs();
  main_myfiltfilt();
  main_peakdetect();
  /* Terminate the application.
You do not need to do this more than one time. */
  average_beats_tnmg_terminate();
  return 0;
}

/* End of code generation (main.c) */
