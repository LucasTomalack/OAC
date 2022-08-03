#include "matrix.h"

void inicializaMatrizes(double **Matriz, int linhas, int colunas){
    for(int i=0; i<linhas; i++){
        Matriz[i] = (double *) malloc(colunas * sizeof(double));
        for(int j=0; j<colunas; j++){
            Matriz[i][j] = rand()%10;
        }
    }
}       

void quadrado(double **matriz, int n, int m){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
            matriz[i][j] *= matriz[i][j];
    }
  }
}

void diferenca(double **m1, double **m2, double **m3, int n, int m){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
            m3[i][j] = m1[i][j] - m2[i][j];
    }
  }
}

double soma(double **m3, int n, int m){
  double soma = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
            soma += m3[i][j];
    }
  }
  return soma;
}

void printMatriz(double **matriz, int n, int m){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.2f ", matriz[i][j]);
    }
    printf("\n");
  }
}