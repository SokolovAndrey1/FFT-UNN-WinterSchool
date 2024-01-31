#ifndef COMMON_H
#define COMMON_H

#ifdef USE_OPENMP
#include <omp.h>
#endif

#include <math.h>
#include <stdlib.h>

#define YP_2PI 6.28

typedef struct {
    float re;
    float im;
} T32fc;

typedef float T32f;

typedef unsigned int T32u;

#endif // COMMON_H
