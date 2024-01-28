#ifndef DFT_H
#define DFT_H

#include "common_defs.h"

void refDftFwd(const T32fc* x, T32fc* y, const int n);

void dft2Fwd(const T32fc *x, T32fc *y);
void dft4Fwd(const T32fc *x, T32fc *y);
void dft6Fwd(const T32fc *x, T32fc *y);
void dft8Fwd(const T32fc *x, T32fc *y);
void dft16Fwd(const T32fc *x, T32fc *y);
void dft32Fwd(const T32fc *x, T32fc *y);

#endif // DFT_H
