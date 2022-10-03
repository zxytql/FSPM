/*
 * File: parameterfun.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Sep-2022 02:46:41
 */

/* Include Files */
#include "parameterfun.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double d
 *                double tx_p
 *                double c
 *                double f
 * Return Type  : double
 */
double parameterfun(double d, double tx_p, double c, double f)
{
  return (20.0 * log10(d) + c * d) - ((tx_p - 32.45) - 20.0 * log10(f));
}

/*
 * File trailer for parameterfun.c
 *
 * [EOF]
 */
