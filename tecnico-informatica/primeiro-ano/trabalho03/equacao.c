// L�gica de Programa��o
// Quest�o 2 - Trabalho III
// Alunos: Dalton Oliveira, Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

void leitura(float *a, float *b, float *c)
{
  do
  {
    printf("===============================================================================\n");
    printf("Aviso: Nao coloque 0 no coeficiente A. Caso coloque o programa retornara ao inicio.\n");
    printf("===============================================================================\n");
    printf("Digite o valor do coeficiente A: ");
    scanf("%f", a);
    printf("Digite o valor do coeficiente B: ");
    scanf("%f", b);
    printf("Digite o valor do coeficiente C: ");
    scanf("%f", c);
    system("cls");
  } while (*a == 0);
}

float calcular_delta(float a, float b, float c)
{
  float delta;
  delta = (b * b) - 4 * a * c;
  return (delta);
}

void calcular_x_resultado(float a, float b, float c, float delta)
{
  float x1, x2;
  printf("===============================================================================\n");
  if (delta < 0)
  {
    printf("Resultado: Nao possui resultado.\n");
  }
  if (delta == 0)
  {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    printf("Resultado: Resultados iguais - Delta: %.2f - x1: %.2f & x2: %.2f\n", delta, x1, x2);
  }
  if (delta > 0)
  {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    printf("Resultado: Resultados diferentes - Delta: %.2f - x1: %.2f & x2: %.2f\n", delta, x1, x2);
  }
  printf("===============================================================================\n");
}

int main()
{
  float a, b, c;
  float delta;
  leitura(&a, &b, &c);
  delta = calcular_delta(a, b, c);
  calcular_x_resultado(a, b, c, delta);
  system("pause");
}
