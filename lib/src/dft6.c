#include "dft.h"

static const T32f Cos_1_3 = -0.5f;
static const T32f Sin_1_3 = -0.8660254f;

void dft6Fwd(const T32fc *x, T32fc *y)
{
    T32fc t[4], u[6];
    // 2x Dft3
    // 1st Dft3
    t[0].re = x[2].re + x[4].re;
    t[0].im = x[2].im + x[4].im;
    t[1].re = x[2].re - x[4].re;
    t[1].im = x[2].im - x[4].im;
    t[2].re = t[0].re * Cos_1_3 + x[0].re;
    t[2].im = t[0].im * Cos_1_3 + x[0].im;
    t[3].re = t[1].im * Sin_1_3;
    t[3].im = t[1].re * Sin_1_3;
    u[0].re = t[0].re + x[0].re;
    u[0].im = t[0].im + x[0].im;
    u[1].re = t[2].re - t[3].re;
    u[1].im = t[2].im + t[3].im;
    u[2].re = t[2].re + t[3].re;
    u[2].im = t[2].im - t[3].im;
    // 2nd Dft3
    t[0].re = x[5].re + x[1].re;
    t[0].im = x[5].im + x[1].im;
    t[1].re = x[5].re - x[1].re;
    t[1].im = x[5].im - x[1].im;
    t[2].re = t[0].re * Cos_1_3 + x[3].re;
    t[2].im = t[0].im * Cos_1_3 + x[3].im;
    t[3].re = t[1].im * Sin_1_3;
    t[3].im = t[1].re * Sin_1_3;
    u[3].re = t[0].re + x[3].re;
    u[3].im = t[0].im + x[3].im;
    u[4].re = t[2].re - t[3].re;
    u[4].im = t[2].im + t[3].im;
    u[5].re = t[2].re + t[3].re;
    u[5].im = t[2].im - t[3].im;
    // 3x Dft2
    // 1st Dft2
    y[0].re = u[0].re + u[3].re;
    y[0].im = u[0].im + u[3].im;
    y[3].re = u[0].re - u[3].re;
    y[3].im = u[0].im - u[3].im;
    // 2nd Dft2
    y[2].re = u[2].re + u[5].re;
    y[2].im = u[2].im + u[5].im;
    y[5].re = u[2].re - u[5].re;
    y[5].im = u[2].im - u[5].im;
    // 3rd Df2
    y[4].re = u[1].re + u[4].re;
    y[4].im = u[1].im + u[4].im;
    y[1].re = u[1].re - u[4].re;
    y[1].im = u[1].im - u[4].im;
}
