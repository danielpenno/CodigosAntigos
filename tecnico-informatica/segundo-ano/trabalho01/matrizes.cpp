// L�gica de Programa��o
// Quest�o 2 -  2� Atividade
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int col, lin;
  int i, j;
  float **m = NULL, **n = NULL, **o = NULL;
  printf("===============================================================================\n");
  printf("Digite o numero de linhas das matrizes: ");
  scanf("%d", &lin);
  printf("Digite o numero de colunas das matrizes: ");
  scanf("%d", &col);
  printf("===============================================================================\n");
  system("cls");
  m = (float **)malloc(sizeof(int *) * lin);
  for (i = 0; i < lin; i++)
  {
    m[i] = (float *)malloc(sizeof(int) * col);
  }
  n = (float **)malloc(sizeof(int *) * lin);
  for (i = 0; i < lin; i++)
  {
    n[i] = (float *)malloc(sizeof(int) * col);
  }
  o = (float **)malloc(sizeof(int *) * lin);
  for (i = 0; i < lin; i++)
  {
    o[i] = (float *)malloc(sizeof(int) * col);
  }
  printf("===============================================================================\n");
  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("Digite o valor da %d coluna da %d linha da primeira matriz: ", j + 1, i + 1);
      scanf("%f", &m[i][j]);
    }
  }
  system("cls");
  printf("===============================================================================\n");
  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("Digite o valor da %d coluna da %d linha da segunda matriz: ", j + 1, i + 1);
      scanf("%f", &n[i][j]);
    }
  }
  system("cls");
  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      o[i][j] = m[i][j] + n[i][j];
    }
  }
  printf("===============================================================================\n");
  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("Valor da %d coluna da %d linha da primeira matriz: %.2f\n", j + 1, i + 1, m[i][j]);
      printf("Valor da %d coluna da %d linha da segunda matriz: %.2f\n", j + 1, i + 1, n[i][j]);
      printf("Valor da soma das duas matrizes: %.2f\n", o[i][j]);
      printf("===============================================================================\n");
    }
  }
  for (i = 0; i < lin; i++)
  {
    free(m[i]);
  }
  free(m);
  for (i = 0; i < lin; i++)
  {
    free(n[i]);
  }
  free(n);
  for (i = 0; i < lin; i++)
  {
    free(o[i]);
  }
  free(o);
  system("pause");
}
