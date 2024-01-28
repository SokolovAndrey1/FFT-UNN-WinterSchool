#include "dft.h"

void dft4Fwd(const T32fc *x, T32fc *y)
{
    T32fc t[4];
    t[0].re = x[0].re + x[2].re;
    t[0].im = x[0].im + x[2].im;
    t[1].re = x[0].re - x[2].re;
    t[1].im = x[0].im - x[2].im;
    t[2].re = x[1].re + x[3].re;
    t[2].im = x[1].im + x[3].im;
    t[3].re = x[1].re - x[3].re;
    t[3].im = x[1].im - x[3].im;
    y[0].re = t[0].re + t[2].re;
    y[0].im = t[0].im + t[2].im;
    y[1].re = t[1].re + t[3].im;
    y[1].im = t[1].im - t[3].re;
    y[2].re = t[0].re + t[2].re;
    y[2].im = t[0].im - t[2].im;
    y[3].re = t[1].re - t[3].im;
    y[3].im = t[1].im + t[3].re;
}
