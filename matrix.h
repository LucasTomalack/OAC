#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

void inicializaMatrizes(double **Matriz,int m);

void quadrado(double **matriz, int m);

void diferenca(double **m1, double **m2, double **m3, int m);

double soma(double **m3, int m);

// PARALELO
void inicializaMatrizesParalelo(double **Matriz,int m);

void quadradoParalelo(double **matriz, int m);

void diferencaParalelo(double **m1, double **m2, double **m3, int m);

double somaParalelo(double **m3, int m);

void printMatriz(double **matriz, int m);