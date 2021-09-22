/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squeeze.h
 *
 * Code generation for function 'squeeze'
 *
 */

#ifndef SQUEEZE_H
#define SQUEEZE_H

/* Include files */
#include "average_beats_tnmg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_squeeze(const emxArray_real_T *a, emxArray_real_T *b);

void c_squeeze(const emxArray_real_T *a, emxArray_real_T *b);

void squeeze(const emxArray_real_T *a, emxArray_real_T *b);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (squeeze.h) */
