#include "matrix.h"
int main(){
    double **A, **B, **D;
    int n, m;

    A = (double **) malloc(n * sizeof(double *));
    B = (double **) malloc(n * sizeof(double *));
    D = (double **) malloc(n * sizeof(double *));

    inicializaMatrizes(A, n, m);
    inicializaMatrizes(B, n, m);
    inicializaMatrizes(D, n, m);
    
return 0;
}