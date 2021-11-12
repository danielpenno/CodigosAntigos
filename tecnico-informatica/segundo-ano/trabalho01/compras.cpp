// L�gica de Programa��o
// Quest�o 3 -  2� Atividade
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void valor(int **m, int n, int caro[2], int barato[2])
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (caro[0] < m[i][3])
    {
      caro[0] = m[i][3];
      caro[1] = m[i][0];
    }
  }
  barato[0] = m[0][3];
  barato[1] = m[0][0];
  for (i = 0; i < n; i++)
  {
    if (m[i][3] < barato[0])
    {
      barato[0] = m[i][3];
      barato[1] = m[i][0];
    }
  }
}

void imprimir(int **m, int n, float total, int caro[2], int barato[2])
{
  int i;
  system("cls");
  printf("===============================================================================\n");
  for (i = 0; i < n; i++)
  {
    printf("%d - Codigo: %d - Quantidade: %d - Preco: %d - Subtotal: %d\n", i + 1, m[i][0], m[i][1], m[i][2], m[i][3]);
  }
  printf("===============================================================================\n");
  printf("Total: %.2f\n", total);
  printf("Mais caro: %d\n", caro[1]);
  printf("Mais barato: %d\n", barato[1]);
  printf("===============================================================================\n");
}

int main()
{
  float total = 0;
  int caro[2], barato[2];
  int n, i;
  int **m = NULL;
  int col = 4;
  printf("===============================================================================\n");
  printf("Quantas produtos voce ira contabilizar? ");
  scanf("%d", &n);
  system("cls");
  m = (int **)malloc(sizeof(int *) * n);
  for (i = 0; i < n; i++)
  {
    m[i] = (int *)malloc(sizeof(int) * col);
  }
  for (i = 0; i < n; i++)
  {
    system("cls");
    printf("===============================================================================\n");
    printf("Digite o codigo do produto %d: ", i + 1);
    scanf("%d", &m[i][0]);
    printf("Digite a quantidade do produto %d: ", i + 1);
    scanf("%d", &m[i][1]);
    printf("Digite o preco do produto %d: ", i + 1);
    scanf("%d", &m[i][2]);
  }
  system("cls");
  for (i = 0; i < n; i++)
  {
    m[i][3] = m[i][1] * m[i][2];
    total += m[i][3];
  }
  valor(m, n, caro, barato);
  imprimir(m, n, total, caro, barato);
  for (i = 0; i < n; i++)
  {
    free(m[i]);
  }
  free(m);
  system("pause");
}
