// L�gica de Programa��o
// Quest�o 1 -  2� Atividade
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  typedef struct dados
  {
    char cliente[1000][50];
    char carro[1000][50];
  } dados;
  dados a;
  int i, n;
  float media = 0, media2 = 0;
  int col = 7;
  float **m = NULL;
  printf("===============================================================================\n");
  printf("Quantas operacoes voce deseja fazer?");
  scanf("%d", &n);
  system("cls");
  m = (float **)malloc(sizeof(int *) * n);
  for (i = 0; i < n; i++)
  {
    m[i] = (float *)malloc(sizeof(int) * col);
  }
  for (i = 0; i < n; i++)
  {
    system("cls");
    printf("===============================================================================\n");
    printf("Digite o nome do cliente %d: ", i + 1);
    gets(a.cliente[i]);
    gets(a.cliente[i]);
    printf("===============================================================================\n");
    printf("Digite o modelo do carro %d: ", i + 1);
    gets(a.carro[i]);
    printf("===============================================================================\n");
    printf("Digite a quilometragem de saida do carro %d: ", i + 1);
    scanf("%f", &m[i][0]);
    printf("===============================================================================\n");
    printf("Digite a quilometragem de chegada do carro %d: ", i + 1);
    scanf("%f", &m[i][1]);
    printf("===============================================================================\n");
    printf("Digie o valor cobrado por quilometro rodado do carro %d: ", i + 1);
    scanf("%f", &m[i][2]);
    printf("===============================================================================\n");
  }
  system("cls");
  for (i = 0; i < n; i++)
  {
    m[i][3] = (m[i][1] - m[i][0]);
    m[i][4] = (m[i][3] * m[i][2]);
    media = media + m[i][3];
    media2 = media2 + m[i][4];
  }
  media = media / n;
  media2 = media2 / n;
  printf("===============================================================================\n");
  for (i = 0; i < n; i++)
  {
    printf("\tCliente: %s", a.cliente[i]);
    printf("\n\tCarro: %s", a.carro[i]);
    printf("\n\tQuilometragem de saida: %.2f", m[i][0]);
    printf("\n\tQuilometragem de chegada: %.2f", m[i][1]);
    printf("\n\tValor cobrado por quilometro rodado: R$%.2f", m[i][2]);
    printf("\n\tQuilometragem rodada: %.2f", m[i][3]);
    printf("\n\tValor a ser cobrado: R$%.2f", m[i][4]);
    printf("\n===============================================================================\n");
  }
  printf("Media de quilometragem por locacao: %.2f\n", media);
  printf("Media do valor de cada locacao: %.2f", media2);
  printf("\n===============================================================================\n");
  for (i = 0; i < n; i++)
  {
    free(m[i]);
  }
  free(m);
  system("pause");
}
