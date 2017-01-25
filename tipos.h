#ifndef _TIPOS_
#define _TIPOS_
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>

#define DIFF 0.001
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define DEBUG 1

#ifdef __USE_SIMD__
typedef float64_vec (*funcao_matematica)(float64_vec, double, double);
#else
typedef double (*funcao_matematica)(double, double, double);
#endif
typedef double (*funcao_metodo)(int, int, int, funcao_matematica);

double timestamp(void) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return ((double) (tp.tv_sec + tp.tv_usec / 1000000.0));
}

#endif
