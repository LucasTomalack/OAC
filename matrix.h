#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

#define print 0
#define MAX_RAND 100
double** inicializaMatrizes(int m);

void preenche(double** matriz, int m);

void quadrado(double **matriz, int m);

void diferenca(double **m1, double **m2, double **m3, int m);

double soma(double **m3, int m);

// PARALELO
unsigned int num_threads;
void preencheParalelo(double** matriz, int m);

void quadradoParalelo(double **matriz, int m);

void diferencaParalelo(double **m1, double **m2, double **m3, int m);

double somaParalelo(double **m3, int m);

void printMatriz(double **matriz, int m);