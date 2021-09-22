/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * average_beats_tnmg.c
 *
 * Code generation for function 'average_beats_tnmg'
 *
 */

/* Include files */
#include "average_beats_tnmg.h"
#include "average_beats_tnmg_data.h"
#include "average_beats_tnmg_emxutil.h"
#include "average_beats_tnmg_initialize.h"
#include "average_beats_tnmg_rtwutil.h"
#include "average_beats_tnmg_types.h"
#include "diff.h"
#include "median.h"
#include "nanmean.h"
#include "nanmedian.h"
#include "nanvar.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "squeeze.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void average_beats_tnmg(const emxArray_real_T *ecg, emxArray_real_T *R_pos,
                        double fs, const emxArray_real_T *vcg,
                        double *SNR_overall, double *SNR_overall_type)
{
  emxArray_boolean_T *x;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int8_T *group;
  emxArray_real_T *R_PosAtual;
  emxArray_real_T *a;
  emxArray_real_T *b;
  emxArray_real_T *b_a;
  emxArray_real_T *b_beats;
  emxArray_real_T *b_err;
  emxArray_real_T *b_int;
  emxArray_real_T *b_y;
  emxArray_real_T *beats;
  emxArray_real_T *beats_av;
  emxArray_real_T *c_beats;
  emxArray_real_T *d_beats;
  emxArray_real_T *int0;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  emxArray_real_T *y;
  double b_SNR_median[15];
  double SNR_median[12];
  double beats_av_var[12];
  double c_y[6];
  double dv[3];
  double err;
  double err1;
  double err2;
  double mdc;
  double mediana_R;
  double offset;
  int b_i;
  int b_loop_ub;
  int c_i;
  int i;
  int i1;
  int i2;
  int j;
  int loop_ub;
  int nx;
  int pos;
  int tam_R;
  signed char tmp_data[12];
  boolean_T very_bad_lead[12];
  boolean_T b_x[6];
  boolean_T beat_modified;
  boolean_T guard1 = false;
  (void)vcg;
  if (!isInitialized_average_beats_tnmg) {
    average_beats_tnmg_initialize();
  }
  /*  [in ms] zero if you do not want to correct */
  /*  threshold used to define if a lead signal is noisy or not */
  if (R_pos->size[1] < 2) {
    *SNR_overall = 0.0;
    *SNR_overall_type = 1.0;
    /*      SNR_median = zeros(size(ecg,1),1); */
    /*      SNR_hrv = NaN; */
  } else {
    emxInit_real_T(&beats, 3);
    emxInit_real_T(&R_PosAtual, 2);
    /*  Seta valores iniciais de offset (baseado na mediana dos picos R) */
    /*  SNR_overall = []; */
    /*  SNR_median=zeros(size(ecg,1),1); */
    *SNR_overall_type = 0.0;
    tam_R = R_pos->size[1];
    diff(R_pos, R_PosAtual);
    mediana_R = rt_roundd_snf(median(R_PosAtual) * 1.1);
    offset = rt_roundd_snf(mediana_R / 3.0);
    i = beats->size[0] * beats->size[1] * beats->size[2];
    beats->size[0] = R_pos->size[1];
    beats->size[1] = 12;
    beats->size[2] = (int)mediana_R;
    emxEnsureCapacity_real_T(beats, i);
    loop_ub = R_pos->size[1] * 12 * (int)mediana_R;
    for (i = 0; i < loop_ub; i++) {
      beats->data[i] = rtNaN;
    }
    i = R_PosAtual->size[0] * R_PosAtual->size[1];
    R_PosAtual->size[0] = 1;
    R_PosAtual->size[1] = R_pos->size[1] + 1;
    emxEnsureCapacity_real_T(R_PosAtual, i);
    loop_ub = R_pos->size[1];
    for (i = 0; i < loop_ub; i++) {
      R_PosAtual->data[i] = R_pos->data[i];
    }
    emxInit_int8_T(&group, 2);
    nx = ecg->size[1];
    if (12 > nx) {
      nx = 12;
    }
    if (ecg->size[1] == 0) {
      R_PosAtual->data[R_pos->size[1]] = 0.0;
    } else {
      R_PosAtual->data[R_pos->size[1]] = nx;
    }
    /* Acrescenta o length ao R_Pos */
    i = group->size[0] * group->size[1];
    group->size[0] = 1;
    group->size[1] = R_pos->size[1];
    emxEnsureCapacity_int8_T(group, i);
    loop_ub = R_pos->size[1];
    for (i = 0; i < loop_ub; i++) {
      group->data[i] = 1;
    }
    emxInit_real_T(&int0, 2);
    if (mediana_R - 1.0 < 0.0) {
      int0->size[0] = 1;
      int0->size[1] = 0;
    } else if (rtIsInf(mediana_R - 1.0) && (0.0 == mediana_R - 1.0)) {
      i = int0->size[0] * int0->size[1];
      int0->size[0] = 1;
      int0->size[1] = 1;
      emxEnsureCapacity_real_T(int0, i);
      int0->data[0] = rtNaN;
    } else {
      i = int0->size[0] * int0->size[1];
      int0->size[0] = 1;
      int0->size[1] = (int)(mediana_R - 1.0) + 1;
      emxEnsureCapacity_real_T(int0, i);
      loop_ub = (int)(mediana_R - 1.0);
      for (i = 0; i <= loop_ub; i++) {
        int0->data[i] = i;
      }
    }
    /*  Seleciona em torno das posiÃ§Ãµes de Picos R, int intervalos (valores)
     * para as 12 derivaÃ§Ãµes - ECG e VCG */
    /*  CÃ¡lculo dos picos R para o sinal ECG e VCG de cada uma das 12
     * derivaÃ§Ãµes */
    i = R_pos->size[1];
    emxInit_real_T(&b_int, 2);
    emxInit_real_T(&r, 1);
    emxInit_boolean_T(&x, 2);
    for (b_i = 0; b_i < i; b_i++) {
      i1 = b_int->size[0] * b_int->size[1];
      b_int->size[0] = 1;
      b_int->size[1] = int0->size[1];
      emxEnsureCapacity_real_T(b_int, i1);
      err = R_PosAtual->data[b_i];
      loop_ub = int0->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_int->data[i1] = ((err + int0->data[i1]) - offset) + 1.0;
      }
      /* Pega (int) valores de pos. em torno da pos. do R */
      i1 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = b_int->size[1];
      emxEnsureCapacity_boolean_T(x, i1);
      err = R_PosAtual->data[b_i + 1] - offset / 20.0;
      loop_ub = b_int->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        err1 = b_int->data[i1];
        x->data[i1] = ((err1 > err) || (err1 < 1.0));
      }
      nullAssignment(b_int, x);
      /* coloca nan para valores maiores que o valor definido */
      i1 = r->size[0];
      r->size[0] = b_int->size[1];
      emxEnsureCapacity_real_T(r, i1);
      loop_ub = b_int->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        r->data[i1] = b_int->data[i1];
      }
      if (1 > b_int->size[1]) {
        loop_ub = 0;
      } else {
        loop_ub = b_int->size[1];
      }
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (c_i = 0; c_i < 12; c_i++) {
          beats->data[(b_i + beats->size[0] * c_i) + beats->size[0] * 12 * i1] =
              ecg->data[c_i + 12 * ((int)r->data[i1] - 1)];
        }
      }
      /* Para cada R de cada derivaÃ§Ã£o (pega int valores proximos a R) - ECG
       */
      /* Para cada R (pega int valores proximos para cada derivaÃ§Ã£o) - VCG */
    }
    emxInit_real_T(&beats_av, 2);
    /*  Calcula beats_av - batimentos mÃ©dios em relaÃ§Ã£o a beats  */
    /*  Calcula o batimento mÃ©dio do ECG */
    i = beats_av->size[0] * beats_av->size[1];
    beats_av->size[0] = 12;
    beats_av->size[1] = (int)mediana_R;
    emxEnsureCapacity_real_T(beats_av, i);
    loop_ub = beats->size[0];
    b_loop_ub = beats->size[2];
    emxInit_real_T(&b_beats, 3);
    emxInit_real_T(&r1, 2);
    for (b_i = 0; b_i < 12; b_i++) {
      i = b_beats->size[0] * b_beats->size[1] * b_beats->size[2];
      b_beats->size[0] = loop_ub;
      b_beats->size[1] = 1;
      b_beats->size[2] = b_loop_ub;
      emxEnsureCapacity_real_T(b_beats, i);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_beats->data[i1 + b_beats->size[0] * i] =
              beats
                  ->data[(i1 + beats->size[0] * b_i) + beats->size[0] * 12 * i];
        }
      }
      squeeze(b_beats, r1);
      nanmedian(r1, b_int);
      nx = b_int->size[1];
      for (i = 0; i < nx; i++) {
        beats_av->data[b_i + 12 * i] = b_int->data[i];
      }
      /* Calcula a mediana de cada derivaÃ§Ã£o nos R picos detectados da
       * derivaÃ§Ã£o */
      /* mas em torno dos int valores do pico R  */
    }
    /*  check if there is an offset in beat detections */
    /* %% Analisar a diferenÃ§a entre a potÃªncia do sinal (beats - beats_av) */
    beat_modified = false;
    mdc = rt_roundd_snf(9.0 / fs * 1000.0);
    i = R_pos->size[1];
    emxInit_real_T(&y, 2);
    emxInit_real_T(&a, 2);
    emxInit_real_T(&r2, 2);
    emxInit_real_T(&c_beats, 3);
    for (b_i = 0; b_i < i; b_i++) {
      err = rtInf;
      pos = 0;
      i1 = (int)mdc;
      for (j = 0; j < i1; j++) {
        /* Calcula a diferenÃ§a ao quadrado de beats e beats_av */
        /* err1 = DiferenÃ§a ao Â² entre beats e beats_av das 3 DerivaÃ§Ãµes em
         * um deslocamento de */
        /* janela tamanho mdc - Elimina os NaN iniciais e finais */
        /*              errteste(j)=
         * nanmean(nanmean((squeeze(beats(i,1:3,j:end))-beats_av(1:3,1:(end-j+1))).^2,2));
         */
        if (j + 1U > (unsigned int)beats->size[2]) {
          c_i = 0;
          i2 = 0;
        } else {
          c_i = j;
          i2 = beats->size[2];
        }
        nx = c_beats->size[0] * c_beats->size[1] * c_beats->size[2];
        c_beats->size[0] = 1;
        c_beats->size[1] = 3;
        loop_ub = i2 - c_i;
        c_beats->size[2] = loop_ub;
        emxEnsureCapacity_real_T(c_beats, nx);
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_loop_ub = c_i + i2;
          c_beats->data[3 * i2] =
              beats->data[b_i + beats->size[0] * 12 * b_loop_ub];
          c_beats->data[3 * i2 + 1] =
              beats->data[(b_i + beats->size[0]) +
                          beats->size[0] * 12 * b_loop_ub];
          c_beats->data[3 * i2 + 2] =
              beats->data[(b_i + beats->size[0] * 2) +
                          beats->size[0] * 12 * b_loop_ub];
        }
        b_squeeze(c_beats, r2);
        c_i = a->size[0] * a->size[1];
        a->size[0] = r2->size[0];
        a->size[1] = r2->size[1];
        emxEnsureCapacity_real_T(a, c_i);
        loop_ub = r2->size[1];
        for (c_i = 0; c_i < loop_ub; c_i++) {
          b_loop_ub = r2->size[0];
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            a->data[i2 + 3 * c_i] = r2->data[i2 + r2->size[0] * c_i] -
                                    beats_av->data[i2 + 12 * c_i];
          }
        }
        c_i = y->size[0] * y->size[1];
        y->size[0] = 3;
        y->size[1] = a->size[1];
        emxEnsureCapacity_real_T(y, c_i);
        nx = 3 * a->size[1];
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          y->data[loop_ub] = a->data[loop_ub] * a->data[loop_ub];
        }
        nanmean(y, dv);
        err1 = b_nanmean(dv);
        /* err2 = err1 - inverte o deslocamento da janela mdc */
        c_i = (int)((double)beats->size[2] - ((double)j + 1.0));
        if (1 > c_i + 1) {
          loop_ub = -1;
        } else {
          loop_ub = c_i;
        }
        if (j + 1U > (unsigned int)beats_av->size[1]) {
          c_i = 0;
        } else {
          c_i = j;
        }
        i2 = c_beats->size[0] * c_beats->size[1] * c_beats->size[2];
        c_beats->size[0] = 1;
        c_beats->size[1] = 3;
        c_beats->size[2] = loop_ub + 1;
        emxEnsureCapacity_real_T(c_beats, i2);
        for (i2 = 0; i2 <= loop_ub; i2++) {
          c_beats->data[3 * i2] = beats->data[b_i + beats->size[0] * 12 * i2];
          c_beats->data[3 * i2 + 1] =
              beats->data[(b_i + beats->size[0]) + beats->size[0] * 12 * i2];
          c_beats->data[3 * i2 + 2] =
              beats
                  ->data[(b_i + beats->size[0] * 2) + beats->size[0] * 12 * i2];
        }
        b_squeeze(c_beats, r2);
        i2 = a->size[0] * a->size[1];
        a->size[0] = r2->size[0];
        a->size[1] = r2->size[1];
        emxEnsureCapacity_real_T(a, i2);
        loop_ub = r2->size[1];
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_loop_ub = r2->size[0];
          for (nx = 0; nx < b_loop_ub; nx++) {
            a->data[nx + 3 * i2] = r2->data[nx + r2->size[0] * i2] -
                                   beats_av->data[nx + 12 * (c_i + i2)];
          }
        }
        c_i = y->size[0] * y->size[1];
        y->size[0] = 3;
        y->size[1] = a->size[1];
        emxEnsureCapacity_real_T(y, c_i);
        nx = 3 * a->size[1];
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          y->data[loop_ub] = a->data[loop_ub] * a->data[loop_ub];
        }
        nanmean(y, dv);
        err2 = b_nanmean(dv);
        if (err1 < err) {
          err = err1;
          pos = j;
        }
        /* Guarda a pos da janela mdc para o menor erro */
        if (err2 < err) {
          err = err2;
          pos = -j;
        }
      }
      if (pos != 0) {
        /* atualiza o tamanho do int */
        i1 = b_int->size[0] * b_int->size[1];
        b_int->size[0] = 1;
        b_int->size[1] = int0->size[1];
        emxEnsureCapacity_real_T(b_int, i1);
        err = R_PosAtual->data[b_i] + (double)pos;
        loop_ub = int0->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_int->data[i1] = (err + int0->data[i1]) - offset;
        }
        i1 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = b_int->size[1];
        emxEnsureCapacity_boolean_T(x, i1);
        err = R_PosAtual->data[b_i + 1] - offset / 20.0;
        loop_ub = b_int->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          err1 = b_int->data[i1];
          x->data[i1] = ((err1 > err) || (err1 < 1.0));
        }
        nullAssignment(b_int, x);
        /* coloca nan para valores maiores que o valor definido */
        i1 = r->size[0];
        r->size[0] = b_int->size[1];
        emxEnsureCapacity_real_T(r, i1);
        loop_ub = b_int->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          r->data[i1] = b_int->data[i1];
        }
        if (1 > b_int->size[1]) {
          loop_ub = 0;
        } else {
          loop_ub = b_int->size[1];
        }
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (c_i = 0; c_i < 12; c_i++) {
            beats->data[(b_i + beats->size[0] * c_i) +
                        beats->size[0] * 12 * i1] =
                ecg->data[c_i + 12 * ((int)r->data[i1] - 1)];
          }
        }
        beat_modified = true;
        R_pos->data[b_i] += (double)pos;
      }
    }
    emxFree_real_T(&c_beats);
    emxFree_real_T(&r2);
    emxFree_real_T(&a);
    emxFree_real_T(&y);
    emxFree_real_T(&r);
    emxFree_real_T(&int0);
    emxFree_real_T(&R_PosAtual);
    if (beat_modified) {
      /*  Recalcular o valor da mediana dos batimentos para o novo intervalo */
      i = beats_av->size[0] * beats_av->size[1];
      beats_av->size[0] = 12;
      beats_av->size[1] = (int)mediana_R;
      emxEnsureCapacity_real_T(beats_av, i);
      loop_ub = beats->size[0];
      b_loop_ub = beats->size[2];
      for (b_i = 0; b_i < 12; b_i++) {
        i = b_beats->size[0] * b_beats->size[1] * b_beats->size[2];
        b_beats->size[0] = loop_ub;
        b_beats->size[1] = 1;
        b_beats->size[2] = b_loop_ub;
        emxEnsureCapacity_real_T(b_beats, i);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_beats->data[i1 + b_beats->size[0] * i] =
                beats->data[(i1 + beats->size[0] * b_i) +
                            beats->size[0] * 12 * i];
          }
        }
        squeeze(b_beats, r1);
        nanmedian(r1, b_int);
        nx = b_int->size[1];
        for (i = 0; i < nx; i++) {
          beats_av->data[b_i + 12 * i] = b_int->data[i];
        }
      }
    }
    emxInit_real_T(&b_err, 2);
    /*  redefine average after discarding bad beats and define groups of beats
     */
    /*  DiferenÃ§a entre  */
    nanvar(beats_av, beats_av_var);
    /* Calcula variÃ¢ncia de beats_av por derivaÃ§Ã£o dos int valores */
    i = b_err->size[0] * b_err->size[1];
    b_err->size[0] = 12;
    b_err->size[1] = tam_R;
    emxEnsureCapacity_real_T(b_err, i);
    loop_ub = 12 * tam_R;
    for (i = 0; i < loop_ub; i++) {
      b_err->data[i] = 0.0;
    }
    emxInit_real_T(&b, 2);
    emxInit_real_T(&b_y, 2);
    emxInit_real_T(&b_a, 2);
    emxInit_real_T(&d_beats, 3);
    for (b_i = 0; b_i < tam_R; b_i++) {
      loop_ub = beats->size[2];
      i = d_beats->size[0] * d_beats->size[1] * d_beats->size[2];
      d_beats->size[0] = 1;
      d_beats->size[1] = 12;
      d_beats->size[2] = beats->size[2];
      emxEnsureCapacity_real_T(d_beats, i);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < 12; i1++) {
          d_beats->data[i1 + 12 * i] =
              beats
                  ->data[(b_i + beats->size[0] * i1) + beats->size[0] * 12 * i];
        }
      }
      c_squeeze(d_beats, b);
      /* Por pico R - Pega os int valores das 12 DerivaÃ§Ãµes */
      i = b_a->size[0] * b_a->size[1];
      b_a->size[0] = b->size[0];
      b_a->size[1] = b->size[1];
      emxEnsureCapacity_real_T(b_a, i);
      loop_ub = b->size[0] * b->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_a->data[i] = b->data[i] - beats_av->data[i];
      }
      i = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 12;
      b_y->size[1] = b_a->size[1];
      emxEnsureCapacity_real_T(b_y, i);
      nx = 12 * b_a->size[1];
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        b_y->data[loop_ub] = b_a->data[loop_ub] * b_a->data[loop_ub];
      }
      c_nanmean(b_y, *(double(*)[12]) & b_err->data[12 * b_i]);
      /* in the following lines I am assuming that the ECG is in millivolts */
      /* Analisa os 6 valores iniciais do erro e compara com os valores dos */
      /* beats_av_var. Se tiver mais de 3 valores maiores  */
      for (loop_ub = 0; loop_ub < 6; loop_ub++) {
        c_y[loop_ub] = fabs(b->data[loop_ub + b->size[0]]);
        b_x[loop_ub] =
            (b_err->data[loop_ub + 12 * b_i] < beats_av_var[loop_ub]);
      }
      b_loop_ub = b_x[0];
      for (loop_ub = 0; loop_ub < 5; loop_ub++) {
        b_loop_ub += b_x[loop_ub + 1];
      }
      for (c_i = 0; c_i < 6; c_i++) {
        b_x[c_i] = (0.0 * c_y[c_i] < 10000.0);
      }
      nx = b_x[0];
      for (loop_ub = 0; loop_ub < 5; loop_ub++) {
        nx += b_x[loop_ub + 1];
      }
      group->data[b_i] = (signed char)((b_loop_ub > 3) && (nx > 3));
      /*  testar b(1:6,2) */
    }
    pos = group->size[1] - 1;
    loop_ub = beats->size[2];
    emxInit_int32_T(&r3, 2);
    for (b_i = 0; b_i < 12; b_i++) {
      b_loop_ub = 0;
      for (c_i = 0; c_i <= pos; c_i++) {
        if (group->data[c_i] == 1) {
          b_loop_ub++;
        }
      }
      i = r3->size[0] * r3->size[1];
      r3->size[0] = 1;
      r3->size[1] = b_loop_ub;
      emxEnsureCapacity_int32_T(r3, i);
      nx = 0;
      for (c_i = 0; c_i <= pos; c_i++) {
        if (group->data[c_i] == 1) {
          r3->data[nx] = c_i + 1;
          nx++;
        }
      }
      i = b_beats->size[0] * b_beats->size[1] * b_beats->size[2];
      b_beats->size[0] = r3->size[1];
      b_beats->size[1] = 1;
      b_beats->size[2] = loop_ub;
      emxEnsureCapacity_real_T(b_beats, i);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = r3->size[1];
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_beats->data[i1 + b_beats->size[0] * i] =
              beats->data[((r3->data[i1] + beats->size[0] * b_i) +
                           beats->size[0] * 12 * i) -
                          1];
        }
      }
      squeeze(b_beats, r1);
      nanmedian(r1, b_int);
      b_loop_ub = b_int->size[1];
      for (i = 0; i < b_loop_ub; i++) {
        beats_av->data[b_i + 12 * i] = b_int->data[i];
      }
    }
    emxFree_real_T(&r1);
    emxFree_real_T(&b_beats);
    emxFree_int32_T(&r3);
    emxFree_real_T(&b_int);
    /*  compute SNR  */
    /*  the overall_type field has the following meaninig: */
    /*  0 = good ecg recording */
    /*  1 = bad ecg recording due to overall poor quality */
    /*  2 = bad 0ecg recording due to many leads having very poor quality  */
    /*  3 = bad ecg recording due to large part of tracing being without signal
     */
    /*  max fraction of the tracing that I accept to be a flat line  */
    /* mudanÃ§a */
    /*  maximum number of VERY bad leads (i.e SNR<SNR_threshold/3) that I can
     * accept */
    /*  SNR.overall_type = 2 - Falta de traçado em algumas derivaÃ§Ãµes */
    /*  A diferenÃ§a do ultimo R com o primeiro divido pelo total < 0.35 */
    loop_ub = ecg->size[1];
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = ecg->size[1];
    emxEnsureCapacity_boolean_T(x, i);
    for (i = 0; i < loop_ub; i++) {
      x->data[i] = rtIsNaN(ecg->data[12 * i]);
    }
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(x, i);
    loop_ub = x->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      x->data[i] = !x->data[i];
    }
    nx = x->size[1];
    if (x->size[1] == 0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = x->data[0];
      for (loop_ub = 2; loop_ub <= nx; loop_ub++) {
        b_loop_ub += x->data[loop_ub - 1];
      }
    }
    emxFree_boolean_T(&x);
    if ((R_pos->data[R_pos->size[1] - 1] - R_pos->data[0]) / (double)b_loop_ub <
        0.35) {
      *SNR_overall = 0.0;
      *SNR_overall_type = 3.0;
      /* SNR_overall_type=1;  */
    } else {
      i = b_err->size[0] * b_err->size[1];
      b_err->size[0] = 12;
      b_err->size[1] = tam_R;
      emxEnsureCapacity_real_T(b_err, i);
      /* Zera os erros e recalcula */
      for (b_i = 0; b_i < tam_R; b_i++) {
        /* Calcula a media da dif entre beats e beats_av */
        loop_ub = beats->size[2];
        i = d_beats->size[0] * d_beats->size[1] * d_beats->size[2];
        d_beats->size[0] = 1;
        d_beats->size[1] = 12;
        d_beats->size[2] = beats->size[2];
        emxEnsureCapacity_real_T(d_beats, i);
        for (i = 0; i < loop_ub; i++) {
          for (i1 = 0; i1 < 12; i1++) {
            d_beats->data[i1 + 12 * i] =
                beats->data[(b_i + beats->size[0] * i1) +
                            beats->size[0] * 12 * i];
          }
        }
        c_squeeze(d_beats, b);
        i = b_a->size[0] * b_a->size[1];
        b_a->size[0] = b->size[0];
        b_a->size[1] = b->size[1];
        emxEnsureCapacity_real_T(b_a, i);
        loop_ub = b->size[0] * b->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_a->data[i] = b->data[i] - beats_av->data[i];
        }
        i = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 12;
        b_y->size[1] = b_a->size[1];
        emxEnsureCapacity_real_T(b_y, i);
        nx = 12 * b_a->size[1];
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          b_y->data[loop_ub] = b_a->data[loop_ub] * b_a->data[loop_ub];
        }
        c_nanmean(b_y, *(double(*)[12]) & b_err->data[12 * b_i]);
      }
      /* Calculo SNR */
      pos = group->size[1] - 1;
      b_loop_ub = 0;
      for (b_i = 0; b_i <= pos; b_i++) {
        if (group->data[b_i] == 1) {
          b_loop_ub++;
        }
      }
      emxInit_int32_T(&r4, 2);
      i = r4->size[0] * r4->size[1];
      r4->size[0] = 1;
      r4->size[1] = b_loop_ub;
      emxEnsureCapacity_int32_T(r4, i);
      nx = 0;
      for (b_i = 0; b_i <= pos; b_i++) {
        if (group->data[b_i] == 1) {
          r4->data[nx] = b_i + 1;
          nx++;
        }
      }
      nanvar(beats_av, SNR_median);
      i = beats_av->size[0] * beats_av->size[1];
      beats_av->size[0] = 12;
      beats_av->size[1] = r4->size[1];
      emxEnsureCapacity_real_T(beats_av, i);
      loop_ub = r4->size[1];
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < 12; i1++) {
          beats_av->data[i1 + 12 * i] =
              b_err->data[i1 + 12 * (r4->data[i] - 1)];
        }
      }
      emxFree_int32_T(&r4);
      b_nanmedian(beats_av, beats_av_var);
      b_loop_ub = 0;
      nx = 0;
      for (b_i = 0; b_i < 12; b_i++) {
        err1 = SNR_median[b_i] / beats_av_var[b_i];
        SNR_median[b_i] = err1;
        beat_modified = rtIsNaN(err1);
        if (beat_modified) {
          b_loop_ub++;
          tmp_data[nx] = (signed char)(b_i + 1);
          nx++;
        }
      }
      for (i = 0; i < b_loop_ub; i++) {
        SNR_median[tmp_data[i] - 1] = 0.0;
      }
      /* NaN ? flat line */
      /* Verifica se o exame ta completo */
      /*  compute median giving more weight to DI DII and AVf */
      /*  Calculo SNR.overall type 0, 1 e 3 */
      b_SNR_median[12] = SNR_median[0];
      b_SNR_median[13] = SNR_median[1];
      b_SNR_median[14] = SNR_median[5];
      /*  Coloca como relevante das der (1, 2, 6) */
      /*      if(SNR_overall < SNR_threshold) */
      /*          SNR_overall = 1; */
      /*      else */
      /*           SNR_overall = 0; */
      /*      end */
      /*      SNR_overall_type=double(SNR_overall<SNR_threshold); %0 means good
       * 1 means bad quality. SNR_threshold definido no inicio e = 7 */
      for (b_i = 0; b_i < 12; b_i++) {
        err1 = SNR_median[b_i];
        b_SNR_median[b_i] = err1;
        very_bad_lead[b_i] = (err1 < 1.5);
      }
      *SNR_overall = b_median(b_SNR_median);
      b_loop_ub = very_bad_lead[0];
      for (loop_ub = 0; loop_ub < 11; loop_ub++) {
        b_loop_ub += very_bad_lead[loop_ub + 1];
      }
      guard1 = false;
      if ((b_loop_ub > 3) || very_bad_lead[1] ||
          (very_bad_lead[0] && very_bad_lead[5])) {
        guard1 = true;
      } else {
        for (b_i = 0; b_i < 12; b_i++) {
          very_bad_lead[b_i] = (SNR_median[b_i] <= 0.2);
        }
        b_loop_ub = very_bad_lead[0];
        for (loop_ub = 0; loop_ub < 11; loop_ub++) {
          b_loop_ub += very_bad_lead[loop_ub + 1];
        }
        if (b_loop_ub >= 1) {
          guard1 = true;
        }
      }
      if (guard1) {
        *SNR_overall = 0.0;
        *SNR_overall_type = 2.0;
        /* SNR_overall_type=1;  */
      }
    }
    emxFree_real_T(&d_beats);
    emxFree_real_T(&b_a);
    emxFree_real_T(&b_y);
    emxFree_real_T(&b_err);
    emxFree_real_T(&b);
    emxFree_real_T(&beats_av);
    emxFree_int8_T(&group);
    emxFree_real_T(&beats);
    /* SNR_hrv=std(diff(R_pos)./fs)*1000; */
    /*  compute average vcg */
  }
}

/* End of code generation (average_beats_tnmg.c) */
