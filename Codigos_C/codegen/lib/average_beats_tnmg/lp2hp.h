/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lp2hp.h
 *
 * Code generation for function 'lp2hp'
 *
 */

#ifndef LP2HP_H
#define LP2HP_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void lp2hp(const double a[9], const double b[3], const double c[3], double wo,
           double at[9], double bt[3], double ct[3], double *dt);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (lp2hp.h) */
