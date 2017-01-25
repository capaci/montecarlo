#ifndef _METODOS_X_
#define _METODOS_X_

/*

    Dicas:

    - delta (rand() / RAND_MAX) e' resultado de uma divisao por inteiros,
    mas nao necessariamente e' um inteiro. Faca casting.

    - Na implementação usando SIMD, para setar valores em float64_vec, faça:
        for (int l = 0; l < float64_vec::size; ++l) {
            aux.set_elt(l, 1);
         }

    - Para somar todos os valores e retonar um double, faça:
         double sum_x = sum(var_float64_vec);

*/

#ifndef __USE_SIMD__

double monte_carlo_x(int a, int b, int n, funcao_matematica f) {

    printf("Metodo de Monte Carlo (x).\n");
    double t_inicial = timestamp();
	double x, sum=0.0;
	int i, delta;
	delta = b - a;


    //printf("%sNão implementado para uma variável (x).%s\n", KRED, KNRM);

    LIKWID_MARKER_START("monte_carlo_x");
	
	for (i = 0; i<n; i++) {
		x = a + ((double)rand() / RAND_MAX) * delta;
		sum += f(x, 0, 0);
	}
	
    LIKWID_MARKER_STOP("monte_carlo_x");

    double t_final = timestamp();
    printf("Tempo decorrido: %f seg.\n", t_final - t_inicial);

    return (sum/n) * delta;
}

#else

double monte_carlo_simd_x(int a, int b, int n, funcao_matematica f) {

    printf("Metodo de Monte Carlo [SIMD] (x).\n");
    double resultado = 0;
    double t_inicial = timestamp();

    printf("%sNão implementado para uma variável (x).%s\n", KRED, KNRM);

    LIKWID_MARKER_START("monte_carlo_simd_x");

    /*

        Seu código _aqui_

    */

    LIKWID_MARKER_STOP("monte_carlo_simd_x");

    double t_final = timestamp();
    printf("Tempo decorrido: %f seg.\n", t_final - t_inicial);

    return resultado;
}

#endif

#endif
