#include "matrix.h"


void paralelo(int m){
    double **A, **B, **D;
    
    double time_start, time_end, time_total;
    double time_total_m = 0;
    A = inicializaMatrizes(m);
    B = inicializaMatrizes(m);
    D = inicializaMatrizes(m);

    time_start = omp_get_wtime();
    preencheParalelo(A, m);
    preencheParalelo(B, m);
    time_end = omp_get_wtime();

    time_total = time_end - time_start;
    time_total_m+=time_total;

    if(print>=1)
        printf("Tempo de inicialização: %f\n", time_total);

    if(print>=2){
        printf("Matriz A:\n");
        printMatriz(A, m);
        printf("\nMatriz B: \n");
        printMatriz(B, m);
    }

    time_start = omp_get_wtime();
    quadradoParalelo(A, m);
    quadradoParalelo(B, m);
    time_end = omp_get_wtime();

    time_total = time_end - time_start;
    time_total_m+=time_total;
    if(print>=1)
        printf("Tempo de quadrado: %f\n", time_total);

    if(print>=2){
        printf("Matriz A quadrada:\n");
        printMatriz(A, m);
        printf("\nMatriz B quadrada: \n");
        printMatriz(B, m);
    }

    time_start = omp_get_wtime();
    diferencaParalelo(A, B,D, m);
    time_end = omp_get_wtime();
    
    time_total = time_end - time_start;
    time_total_m+=time_total;
    if(print>=1)
        printf("Tempo de diferença: %f\n", time_total);

    if(print>=2){
        printf("Matriz D:\n");
        printMatriz(D, m);
    }

    time_start = omp_get_wtime();
    double soma = somaParalelo(D, m);
    time_end = omp_get_wtime();
    time_total = time_end - time_start;
    time_total_m+=time_total;
    if(print>=2){
        printf("Soma: %.2f\n", soma);
    }
    if(print>=1)
        printf("Tempo de soma: %f\n", time_total);

    printf("Tempo total: %.2f\n", time_total_m);
}

void sequencial(int m){
    double **A, **B, **D; 
    double time_start, time_end, time_total;
    double time_total_m = 0;
    A = inicializaMatrizes(m);
    B = inicializaMatrizes(m);
    D = inicializaMatrizes(m);

    time_start = omp_get_wtime();
    preenche(A, m);
    preenche(B, m);
    time_end = omp_get_wtime();
    time_total = time_end - time_start;
    time_total_m+=time_total;
    if(print>=1)
        printf("Tempo de inicialização: %f\n", time_total);

    if(print>=2){
        printf("Matriz A:\n");
        printMatriz(A, m);
        printf("\nMatriz B: \n");
        printMatriz(B, m);
    }

    time_start = omp_get_wtime();
    quadrado(A, m);
    quadrado(B, m);
    time_end = omp_get_wtime();
    time_total = time_end - time_start;
    time_total_m+=time_total;
    if(print>=1)
        printf("Tempo de quadrado: %f\n", time_total);
    
    if(print>=2){
        printf("Matriz A quadrada:\n");
        printMatriz(A, m);
        printf("\nMatriz B quadrada: \n");
        printMatriz(B, m);
    }

    time_start = omp_get_wtime();
    diferenca(A, B,D, m);
    time_end = omp_get_wtime();
    time_total = time_end - time_start;
    time_total_m+=time_total;
    if(print>=1)
        printf("Tempo de diferença: %f\n", time_total);

    if(print>=2){
        printf("Matriz D:\n");
        printMatriz(D, m);
    }

    time_start = omp_get_wtime();
    double somaV = soma(D, m);
    time_end = omp_get_wtime();
    time_total = time_end - time_start;
    time_total_m+=time_total;
    if(print>=2){
        printf("\nSoma: %.2f\n", somaV);
    }
    if(print>=1)
        printf("Tempo de soma: %f\n", time_total);

    printf("Tempo total: %.2f\n", time_total_m);
}

int main(int argc, char const *argv[]){
    if(argc != 3){
        printf("Usage: %s <linhas | colunas> <a | s | p>\n", argv[0]);
        return 1;
    }

    srand(clock());

    int m= atoi(argv[1]);

    if(argv[2][0]=='s'){
        printf("====SEQUENCIAL====\n");
        sequencial(m);
    }
    else if(argv[2][0]=='p'){
        printf("====PARALELO====\n");
        paralelo(m);
    }
    else if(argv[2][0]=='a'){
        printf("====SEQUENCIAL====\n");
        sequencial(m);
        printf("====PARALELO====\n");
        paralelo(m);
    }
    else{
        printf("Usage: %s <linhas | colunas>\n", argv[0]);
        return 1;
    }




return 0;
}
