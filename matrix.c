#include "matrix.h"

void inicializaMatrizes(double **Matriz, int m){
  int i,j;
  for(i=0; i<m; i++){
      Matriz[i] = (double *) malloc(m * sizeof(double));
      for(j=0; j<m; j++){
          Matriz[i][j] = rand()%10;
      }
  }
  
}       

void quadrado(double **matriz, int m){
  int i,j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
            double value = matriz[i][j];
            matriz[i][j] = value * value;
    }
  }
}

void diferenca(double **m1, double **m2, double **m3, int m){
  int i,j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
            m3[i][j] = m1[i][j] - m2[i][j];
    }
  }
  
}

double soma(double **m3,int m){
  double soma = 0;
  int i,j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
            soma += m3[i][j];
    }
  }
  
  return soma;
}


void printMatriz(double **matriz, int m){
  for (int i = 0; i < m ; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.2f ", matriz[i][j]);
    }
    printf("\n");
  }
}

//PARALELO
void inicializaMatrizesParalelo(double **Matriz, int m){
  int i,j;
  #pragma omp parallel shared(Matriz,i) private(j)
  {
    #pragma omp for 
    for(i=0; i<m; i++){
        Matriz[i] = (double *) malloc(m * sizeof(double));
        for(j=0; j<m; j++){
            Matriz[i][j] = rand()%10;
        }
    }
  }
}       

void quadradoParalelo(double **matriz, int m){
  int i,j;
  #pragma omp parallel shared(matriz, i) private(j)
  {
    #pragma omp for
    for (i = 0; i < m; i++) {
      for (j = 0; j < m; j++) {
              double value = matriz[i][j];
              matriz[i][j] = value * value;
      }
    }
  }
}

void diferencaParalelo(double **m1, double **m2, double **m3, int m){
  int i,j;
  #pragma omp parallel shared(m1,m2,m3,i)
  {
    #pragma omp for
    for (i = 0; i < m; i++) {
      for (j = 0; j < m; j++) {
              m3[i][j] = m1[i][j] - m2[i][j];
      }
  }
  }
}

double somaParalelo(double **m3,int m){
  double soma = 0;
  int i,j;
  #pragma omp parallel shared (m3,i) reduction(+:soma)
  {
    #pragma omp for
    for (i = 0; i < m; i++) {
      for (j = 0; j < m; j++) {
              soma += m3[i][j];
      }
    }
  }
  
  return soma;
}
