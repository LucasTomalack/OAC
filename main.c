#include "matrix.h"

#define NUM_THREADS 4
int main(int argc, char const *argv[]){
    if(argc != 2){
        printf("Usage: %s <linhas | colunas>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    double **Ap, **Bp, **Dp;
    double **As, **Bs, **Ds;
    int m= atoi(argv[1]);
    
    Ap = (double **) malloc(m * sizeof(double *));
    Bp = (double **) malloc(m * sizeof(double *));
    Dp = (double **) malloc(m * sizeof(double *));

    As = (double **) malloc(m * sizeof(double *));
    Bs = (double **) malloc(m * sizeof(double *));
    Ds = (double **) malloc(m * sizeof(double *));

    sequencial(As, Bs, Ds, m);
    paralelo(Ap, Bp, Dp, m);




return 0;
}

void paralelo(double **A, double **B, double **D, int m){
    double time_start, time_end, time_total;

    omp_set_num_threads(NUM_THREADS);

    time_start = omp_get_wtime();
    inicializaMatrizesParalelo(A, m);
    inicializaMatrizesParalelo(B, m);
    inicializaMatrizesParalelo(D, m);
    time_end = omp_get_wtime();

    time_total = time_end - time_start;
    printf("Tempo de inicialização: %f\n", time_total);

    printf("Matriz A:\n");
    printMatriz(A, m);
    printf("\nMatriz B: \n");
    printMatriz(B, m);

    time_start = omp_get_wtime();
    quadradoParalelo(A, m);
    quadradoParalelo(B, m);
    time_end = omp_get_wtime();

    time_total = time_end - time_start;
    printf("Tempo de quadrado: %f\n", time_total);

    printf("\nMatriz A quadrada: \n");
    printMatriz(A, m);
    printf("\nMatriz B quadrada: \n");
    printMatriz(B, m);

    time_start = omp_get_wtime();
    diferencaParalelo(A, B,D, m);
    time_end = omp_get_wtime();
    
    time_total = time_end - time_start;
    printf("Tempo de diferença: %f\n", time_total);

    printf("\nMatriz D: \n");
    printMatriz(D, m);

    time_start = omp_get_wtime();
    double soma = somaParalelo(D, m);
    time_end = omp_get_wtime();
    time_total = time_end - time_start;
    printf("Tempo de soma: %.2f\n", time_total);
}

void sequencial(double **A, double **B, double **D, int m){
    double time_start, time_end, time_total;

    inicializaMatrizes(A, m);
    inicializaMatrizes(B, m);
    inicializaMatrizes(D, m);

    printf("Matriz A:\n");
    printMatriz(A, m);
    printf("\nMatriz B: \n");
    printMatriz(B, m);

    quadrado(A, m);
    quadrado(B, m);
    

    printf("\nMatriz A quadrada: \n");
    printMatriz(A, m);
    printf("\nMatriz B quadrada: \n");
    printMatriz(B, m);

    diferenca(A, B,D, m);


    printf("\nMatriz D: \n");
    printMatriz(D, m);

    double somaV = soma(D, m);
    printf("\nSoma: %.2f\n", somaV);    
}