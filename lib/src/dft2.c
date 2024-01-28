#include "dft.h"

void dft2Fwd(const T32fc *x, T32fc *y)
{
    y[1].re = x[0].re - x[1].re;
    y[1].im = x[0].im - x[1].im;
    y[0].re = x[0].re + x[1].re;
    y[0].im = x[0].im + x[1].im;
}
