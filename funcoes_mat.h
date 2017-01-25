#ifndef _FUNCOES_MAT_
#define _FUNCOES_MAT_
#include <math.h>
#ifdef __USE_SIMD__
using namespace vecmathlib;
#endif

#ifdef __USE_SIMD__

/******************************************************************************
    Exemplo de uso de tipos vetoriais, usando a biblioteca vecmathlib.
 ******************************************************************************/
float64_vec um_sobre_x_1v_SIMD(float64_vec entrada) {
    float64_vec ret;

    // ret = {0, 0, 0, 0};
    ret = float64_vec(0.0);

    std::cout << "===============================================" << std::endl;
    std::cout << "Exemplo de utilização do tipo float64_vec" << std::endl;
    std::cout << "Retorno (valor atual) = " << ret << std::endl;

    // soma retorno + entrada
    ret = ret + entrada;

    std::cout << "Retorno (valor atual) = " << ret << std::endl;
    std::cout << "Retorno (dobro) = " << ret * 2 << std::endl;
    std::cout << "Retorno (soma) = " << sum(ret) << std::endl;
    std::cout << "===============================================" << std::endl;

    return ret;
}

float64_vec exemplo_funcao_simd() {
    float64_vec ent;

    // ent = {1, 2, 3, 4};
    for (int i = 0; i < float64_vec::size; ++i) {
        ent.set_elt(i, float(i + 1));
    }

    return um_sobre_x_1v_SIMD(ent);
}

/******************************************************************************
    Fim do exemplo.
 ******************************************************************************/

/******************************************************************************
    Funções senoides SIMD (a serem implementadas).
 ******************************************************************************/

float64_vec um_sobre_x_1v_simd(float64_vec x, double y, double z) {
    return sin(x) + 1;
}

float64_vec um_sobre_x_2v_simd(float64_vec x, double y, double z) {
    return sin(x) + sin(y) + 1;
}

float64_vec um_sobre_x_3v_simd(float64_vec x, double y, double z) {
    return sin(x) + sin(y) + sin(z) + 1;
}

#else

/******************************************************************************
    Funções senoides normais (já implementadas).
 ******************************************************************************/

double um_sobre_x_1v(double x, double y, double z) {
    return sin(x) + 1;
}

double um_sobre_x_2v(double x, double y, double z) {
    return sin(x) + sin(y) + 1;
}

double um_sobre_x_3v(double x, double y, double z) {
    return sin(x) + sin(y) + sin(z) + 1;
}

#endif

#endif
