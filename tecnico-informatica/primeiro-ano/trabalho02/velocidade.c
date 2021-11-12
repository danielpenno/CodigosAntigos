// L�gica de Programa��o
// Quest�o 7 - Trabalho II
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

int main()
{
  float velo_max, velo_veic[1000];
  int x = 0, i;
  do
  {
    printf("===============================================================================\n");
    printf("Quantos veiculos voce ira utilizar?<1-1000> ");
    scanf("%d", &x);
    system("cls");
  } while ((x > 1000) || (x < 1));
  system("cls");
  printf("===============================================================================\n");
  printf("Digite o valor da velocidade maxima permitida: ");
  scanf("%f", &velo_max);
  for (i = 0; i < x; i++)
  {
    system("cls");
    printf("===============================================================================\n");
    printf("Digite o valor da velocidade do veiculo %d: ", i + 1);
    scanf("%f", &velo_veic[i]);
  }
  system("cls");
  printf("===============================================================================\n");
  printf("Velocidade maxima permitida: %.2f km/h\n", velo_max);
  printf("===============================================================================\n");
  for (i = 0; i < x; i++)
  {
    if (velo_veic[i] <= velo_max)
    {
      printf("Velocidade do veiculo %d: %.2f km/h - Multa: R$0,00\n", i + 1, velo_veic[i]);
    }
    if ((velo_veic[i] > velo_max) && (velo_veic[i] <= velo_max + 10))
    {
      printf("Velocidade do veiculo %d: %.2f km/h - Multa: R$50,00\n", i + 1, velo_veic[i]);
    }
    if ((velo_veic[i] > velo_max + 10) && (velo_veic[i] <= velo_max + 30))
    {
      printf("Velocidade do veiculo %d: %.2f km/h - Multa: R$100,00\n", i + 1, velo_veic[i]);
    }
    if (velo_veic[i] > velo_max + 30)
    {
      printf("Velocidade do veiculo %d: %.2f km/h - Multa: R$200,00\n", i + 1, velo_veic[i]);
    }
  }
  printf("===============================================================================\n");
  system("pause");
}
