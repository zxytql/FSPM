/*
 * File: _coder_parameterfun_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Sep-2022 02:46:41
 */

#ifndef _CODER_PARAMETERFUN_API_H
#define _CODER_PARAMETERFUN_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real_T parameterfun(real_T d, real_T tx_p, real_T c, real_T f);

void parameterfun_api(const mxArray *const prhs[4], const mxArray **plhs);

void parameterfun_atexit(void);

void parameterfun_initialize(void);

void parameterfun_terminate(void);

void parameterfun_xil_shutdown(void);

void parameterfun_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_parameterfun_api.h
 *
 * [EOF]
 */
