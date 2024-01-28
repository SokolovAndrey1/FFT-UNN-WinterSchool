#include "dft.h"

void refDftFwd(const T32fc* x, T32fc* y, const int n)
{
    for (int k = 0; k < n; k++)
    {
        T32f yRe = 0.f;
        T32f yIm = 0.f;
        for (int j = 0; j < n; j++)
        {
            yRe += x[j].re * cos((YP_2PI * j * k) / n) + x[j].im * sin((YP_2PI * j * k) / n);
            yIm += -x[j].re * sin((YP_2PI * j * k) / n) + x[j].im * cos((YP_2PI * j * k) / n);
        }
        y[k].re = yRe;
        y[k].im = yIm;
    }
}
