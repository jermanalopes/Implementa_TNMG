/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_average_beats_tnmg_api.c
 *
 * Code generation for function 'average_beats_tnmg'
 *
 */

/* Include files */
#include "_coder_average_beats_tnmg_api.h"
#include "_coder_average_beats_tnmg_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "average_beats_tnmg",                                 /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R_pos,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *d_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T *u_size);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fs,
                                 const char_T *identifier);

static const mxArray *e_emlrt_marshallOut(const real_T u[4]);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *ecg,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const real_T u);

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel);

static void emxFree_real_T(emxArray_real_T **pEmxArray);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions, boolean_T doPush);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *f_emlrt_marshallOut(const real_T u[3]);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *vcg,
                               const char_T *identifier, emxArray_real_T *y);

static void g_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *filter_type,
                               const char_T *identifier, char_T y[4]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[4]);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b,
                                   const char_T *identifier))[4];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4];

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *y,
                               const char_T *identifier, emxArray_real_T *b_y);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *zi,
                                   const char_T *identifier))[3];

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[4]);

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R_pos,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(R_pos), &thisId, y);
  emlrtDestroyArray(&R_pos);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T *u_size)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, u_size, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fs,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(fs), &thisId);
  emlrtDestroyArray(&fs);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u[4])
{
  static const int32_T i = 0;
  static const int32_T i1 = 4;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *ecg,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(ecg), &thisId, y);
  emlrtDestroyArray(&ecg);
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T i = 0;
  static const int32_T i1 = 3;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *vcg,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(vcg), &thisId, y);
  emlrtDestroyArray(&vcg);
}

static void g_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  emlrtMxSetData((mxArray *)y, &u->data[0]);
  emlrtSetDimensions((mxArray *)y, &u->size[0], 1);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *filter_type,
                               const char_T *identifier, char_T y[4])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(filter_type), &thisId, y);
  emlrtDestroyArray(&filter_type);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[4])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b,
                                   const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(b), &thisId);
  emlrtDestroyArray(&b);
  return y;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *y,
                               const char_T *identifier, emxArray_real_T *b_y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(y), &thisId, b_y);
  emlrtDestroyArray(&y);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *zi,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(zi), &thisId);
  emlrtDestroyArray(&zi);
  return y;
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {12, -1};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {2, -1};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[4])
{
  static const int32_T dims[2] = {1, 4};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 4);
  emlrtDestroyArray(&src);
}

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims = 4;
  real_T(*ret)[4];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  const boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 1U, (void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(ret, i1);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims = 3;
  real_T(*ret)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void average_beats_tnmg_api(const mxArray *const prhs[4], int32_T nlhs,
                            const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *R_pos;
  emxArray_real_T *ecg;
  emxArray_real_T *vcg;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  real_T SNR_overall;
  real_T SNR_overall_type;
  real_T fs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &ecg, 2, true);
  emxInit_real_T(&st, &R_pos, 2, true);
  emxInit_real_T(&st, &vcg, 2, true);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, false, -1);
  /* Marshall function inputs */
  ecg->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "ecg", ecg);
  R_pos->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "R_pos", R_pos);
  fs = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "fs");
  vcg->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "vcg", vcg);
  /* Invoke the target function */
  average_beats_tnmg(ecg, R_pos, fs, vcg, &SNR_overall, &SNR_overall_type);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(SNR_overall);
  emxFree_real_T(&vcg);
  emxFree_real_T(&R_pos);
  emxFree_real_T(&ecg);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(SNR_overall_type);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void average_beats_tnmg_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  average_beats_tnmg_xil_terminate();
  average_beats_tnmg_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void average_beats_tnmg_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void average_beats_tnmg_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void c_ECG_peak_detect_mod_with_deri(const mxArray *const prhs[2], int32_T nlhs,
                                     const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *ecg;
  emxArray_real_T *vcg;
  emxArray_real_T *vcg2;
  emxArray_real_T *vcg_peaks_pos;
  real_T Fs;
  real_T peak_threshold;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &ecg, 2, true);
  emxInit_real_T(&st, &vcg_peaks_pos, 1, true);
  emxInit_real_T(&st, &vcg, 2, true);
  emxInit_real_T(&st, &vcg2, 2, true);
  /* Marshall function inputs */
  ecg->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "ecg", ecg);
  Fs = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Fs");
  /* Invoke the target function */
  ECG_peak_detect_mod_with_derivative(ecg, Fs, vcg_peaks_pos, &peak_threshold,
                                      vcg, vcg2);
  /* Marshall function outputs */
  vcg_peaks_pos->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(vcg_peaks_pos);
  emxFree_real_T(&vcg_peaks_pos);
  emxFree_real_T(&ecg);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(peak_threshold);
  }
  if (nlhs > 2) {
    vcg->canFreeData = false;
    plhs[2] = c_emlrt_marshallOut(vcg);
  }
  emxFree_real_T(&vcg);
  if (nlhs > 3) {
    vcg2->canFreeData = false;
    plhs[3] = c_emlrt_marshallOut(vcg2);
  }
  emxFree_real_T(&vcg2);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void my_butter_coeffs_api(const mxArray *const prhs[3], int32_T nlhs,
                          const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*b_data)[7];
  real_T(*a)[4];
  real_T(*zi)[3];
  real_T fc;
  real_T fs;
  int32_T b_size;
  char_T filter_type[4];
  st.tls = emlrtRootTLSGlobal;
  b_data = (real_T(*)[7])mxMalloc(sizeof(real_T[7]));
  a = (real_T(*)[4])mxMalloc(sizeof(real_T[4]));
  zi = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  /* Marshall function inputs */
  fc = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "fc");
  fs = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "filter_type", filter_type);
  /* Invoke the target function */
  my_butter_coeffs(fc, fs, filter_type, *b_data, *(int32_T(*)[1]) & b_size, *a,
                   *zi);
  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*b_data, &b_size);
  if (nlhs > 1) {
    plhs[1] = e_emlrt_marshallOut(*a);
  }
  if (nlhs > 2) {
    plhs[2] = f_emlrt_marshallOut(*zi);
  }
}

void myfiltfilt_api(const mxArray *const prhs[4], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *y;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  real_T(*a)[4];
  real_T(*b)[4];
  real_T(*zi)[3];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &y, 1, true);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = emlrtProtectR2012b(prhs[2], 2, true, -1);
  /* Marshall function inputs */
  b = k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "b");
  a = k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "a");
  y->canFreeData = false;
  m_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "y", y);
  zi = o_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "zi");
  /* Invoke the target function */
  myfiltfilt(*b, *a, y, *zi);
  /* Marshall function outputs */
  y->canFreeData = false;
  g_emlrt_marshallOut(y, prhs_copy_idx_2);
  *plhs = prhs_copy_idx_2;
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void peakdetect_api(const mxArray *const prhs[6], int32_T nlhs,
                    const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *b_signal;
  emxArray_real_T *negpeakind;
  emxArray_real_T *pospeakind;
  const mxArray *prhs_copy_idx_0;
  real_T negpeak_treshold_bigger_than;
  real_T negpeak_treshold_smaller_than;
  real_T plot_results;
  real_T pospeak_treshold_bigger_than;
  real_T pospeak_treshold_smaller_than;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &b_signal, 2, true);
  emxInit_real_T(&st, &pospeakind, 1, true);
  emxInit_real_T(&st, &negpeakind, 1, true);
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, false, -1);
  /* Marshall function inputs */
  b_signal->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "signal", b_signal);
  pospeak_treshold_bigger_than = e_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[1]), "pospeak_treshold_bigger_than");
  pospeak_treshold_smaller_than = e_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[2]), "pospeak_treshold_smaller_than");
  negpeak_treshold_bigger_than = e_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[3]), "negpeak_treshold_bigger_than");
  negpeak_treshold_smaller_than = e_emlrt_marshallIn(
      &st, emlrtAliasP(prhs[4]), "negpeak_treshold_smaller_than");
  plot_results = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "plot_results");
  /* Invoke the target function */
  peakdetect(b_signal, pospeak_treshold_bigger_than,
             pospeak_treshold_smaller_than, negpeak_treshold_bigger_than,
             negpeak_treshold_smaller_than, plot_results, pospeakind,
             negpeakind);
  /* Marshall function outputs */
  pospeakind->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(pospeakind);
  emxFree_real_T(&pospeakind);
  emxFree_real_T(&b_signal);
  if (nlhs > 1) {
    negpeakind->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(negpeakind);
  }
  emxFree_real_T(&negpeakind);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_average_beats_tnmg_api.c) */
