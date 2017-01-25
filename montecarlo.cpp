#include <likwid.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/time.h>
#include <random>
#ifdef __USE_SIMD__
    #include "vecmathlib/vec_base.h"
    #include "vecmathlib/vecmathlib.h"
#endif
#include "funcoes_mat.h"
#include "tipos.h"
#include "metodos_x.h"
#include "metodos_xy.h"
#include "metodos_xyz.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define SEMENTE 1234

double timestamp(void);

void executa_metodo(funcao_metodo f, funcao_matematica f_mat,
                    int a, int b, int n) {

    printf("Resultado = %lf\n\n", (*f)(a, b, n, f_mat));

}

int inicia_programa(double a, double b, int n, int num_var) {

    // declara uma variavel do tipo metodo e outra do tipo funcao matematica
    funcao_metodo f_metodo;  // monte_carlo ou monte_carlo_simd
    funcao_matematica f_mat; // ex: x_ao_quadrado, x_mais_um, ...

    printf("\n");
    printf("===================================="\
           "====================================\n\n");

    /* Executa o metodo, calculando a integral da funcao matematica */
    if (num_var == 1) {
        // Ajusta metodo e funcao matematica serao utilizados
        #ifdef __USE_SIMD__
        f_mat = &um_sobre_x_1v_simd;
        f_metodo = &monte_carlo_simd_x;
        #else
        f_mat = &um_sobre_x_1v;
        f_metodo = &monte_carlo_x;
        #endif
        executa_metodo(f_metodo, f_mat, a, b, n);

        printf("===================================="\
               "====================================\n\n");
    }

    if (num_var == 2) {
        // Ajusta metodo e funcao matematica serao utilizados
        #ifdef __USE_SIMD__
        f_mat = &um_sobre_x_2v_simd;
        f_metodo = &monte_carlo_simd_xy;
        #else
        f_mat = &um_sobre_x_2v;
        f_metodo = &monte_carlo_xy;
        #endif
        executa_metodo(f_metodo, f_mat, a, b, n);

        printf("===================================="\
               "====================================\n\n");

    }

    if (num_var == 3) {
        // Ajusta metodo e funcao matematica serao utilizados
        #ifdef __USE_SIMD__
        f_mat = &um_sobre_x_3v_simd;
        f_metodo = &monte_carlo_simd_xyz;
        #else
        f_mat = &um_sobre_x_3v;
        f_metodo = &monte_carlo_xyz;
        #endif
        executa_metodo(f_metodo, f_mat, a, b, n);

        printf("===================================="\
               "====================================\n\n");

    }

    return 0;
}

int main(int argc, char *argv[]) {

    LIKWID_MARKER_INIT;

    // Checagem de argumentos: ./a.out a b amostras #num_var
	if (argc < 5){
        LIKWID_MARKER_CLOSE;
		printf("Monte Carlo exemplo.\n");
        printf("Parametros: <inicio> <fim> <#amostras> <#nvars>\n");
        printf("Onde: \n");
		printf("\tinicio\t\tPonto de inicio do intervalo da integral.\n");
		printf("\tfim\t\tPonto de fim do intervalo da integral.\n");
		printf("\t#amostras\t\tNumero de amostras.\n");
		printf("\t#nvars\t\tNumero de variaveis/dimensoes (x, y, z, ...).\n");
        return 1;
    }

    int num_var = (argc > 4) ? MIN(atoi(argv[4]), 3) : 1;
    int ret; // retorno
	srand(SEMENTE);
    #ifdef __USE_SIMD__
        printf("Usando SIMD...\n");
        exemplo_funcao_simd();
        ret = inicia_programa(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), num_var);
    #else
        ret = inicia_programa(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), num_var);
    #endif

    LIKWID_MARKER_CLOSE;

	return ret;
}
