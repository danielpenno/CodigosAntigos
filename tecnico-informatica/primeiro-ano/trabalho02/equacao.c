// L�gica de Programa��o
// Quest�o 2 - Trabalho II
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

int main()
{
  float a[1000], b[1000], c[1000];
  float delta[1000], x1[1000], x2[1000];
  int x = 0, i;
  do
  {
    printf("===============================================================================\n");
    printf("Quantas equacoes voce ira efetuar?<1-1000> ");
    scanf("%d", &x);
    system("cls");
  } while ((x > 1000) || (x < 1));
  for (i = 0; i < x; i++)
  {
    do
    {
      system("cls");
      printf("===============================================================================\n");
      printf("Aviso: Nao coloque 0 no coeficiente A. Caso coloque o programa retornara ao inicio.\n");
      printf("===============================================================================\n");
      printf("Digite o valor do coeficiente A na equacao %d: ", i + 1);
      scanf("%f", &a[i]);
      printf("Digite o valor do coeficiente B na equacao %d: ", i + 1);
      scanf("%f", &b[i]);
      printf("Digite o valor do coeficiente C na equacao %d: ", i + 1);
      scanf("%f", &c[i]);
    } while (a[i] == 0);
  }
  system("cls");
  printf("===============================================================================\n");
  for (i = 0; i < x; i++)
  {
    delta[i] = (b[i] * b[i]) - 4 * a[i] * c[i];
    if (delta[i] < 0)
    {
      printf("Equacao %d: Nao possui resultado.\n", i + 1);
    }
    if (delta[i] == 0)
    {
      x1[i] = (-b[i] + sqrt(delta[i])) / (2 * a[i]);
      x2[i] = (-b[i] - sqrt(delta[i])) / (2 * a[i]);
      printf("Equacao %d: Resultados iguais - Delta: %.2f - x1: %.2f & x2: %.2f\n", i + 1, delta[i], x1[i], x2[i]);
    }
    if (delta[i] > 0)
    {
      x1[i] = (-b[i] + sqrt(delta[i])) / (2 * a[i]);
      x2[i] = (-b[i] - sqrt(delta[i])) / (2 * a[i]);
      printf("Equacao %d: Resultados diferentes - Delta: %.2f - x1: %.2f & x2: %.2f\n", i + 1, delta[i], x1[i], x2[i]);
    }
  }
  printf("===============================================================================\n");
  system("pause");
}
