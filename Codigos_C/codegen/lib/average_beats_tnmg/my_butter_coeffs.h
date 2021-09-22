/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * my_butter_coeffs.h
 *
 * Code generation for function 'my_butter_coeffs'
 *
 */

#ifndef MY_BUTTER_COEFFS_H
#define MY_BUTTER_COEFFS_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void my_butter_coeffs(double fc, double fs, const char filter_type[4],
                             double b_data[], int b_size[1], double a[4],
                             double zi[3]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (my_butter_coeffs.h) */
