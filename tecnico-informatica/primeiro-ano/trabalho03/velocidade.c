// L�gica de Programa��o
// Quest�o 7 - Trabalho III
// Alunos: Dalton Oliveira, Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

void leitura(float *velo_max, float *velo_veic)
{
  system("cls");
  printf("===============================================================================\n");
  printf("Digite o valor da velocidade maxima permitida: ");
  scanf("%f", velo_max);
  system("cls");
  printf("===============================================================================\n");
  printf("Digite o valor da velocidade do veiculo: ");
  scanf("%f", velo_veic);
}

void verificar_velo(float velo_max, float velo_veic)
{
  system("cls");
  printf("===============================================================================\n");
  printf("Velocidade maxima permitida: %.2f km/h\n", velo_max);
  printf("===============================================================================\n");
  if (velo_veic <= velo_max)
  {
    printf("Velocidade do veiculo: %.2f km/h - Multa: R$0,00\n", velo_veic);
  }
  if ((velo_veic > velo_max) && (velo_veic <= velo_max + 10))
  {
    printf("Velocidade do veiculo: %.2f km/h - Multa: R$50,00\n", velo_veic);
  }
  if ((velo_veic > velo_max + 10) && (velo_veic <= velo_max + 30))
  {
    printf("Velocidade do veiculo: %.2f km/h - Multa: R$100,00\n", velo_veic);
  }
  if (velo_veic > velo_max + 30)
  {
    printf("Velocidade do veiculo: %.2f km/h - Multa: R$200,00\n", velo_veic);
  }
  printf("===============================================================================\n");
}

int main()
{
  float velo_max, velo_veic;
  leitura(&velo_max, &velo_veic);
  verificar_velo(velo_max, velo_veic);
  system("pause");
}
