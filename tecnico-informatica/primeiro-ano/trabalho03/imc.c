// L�gica de Programa��o
// Quest�o 4 - Trabalho III
// Alunos: Dalton Oliveira, Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

void leitura(float *altura, float *peso)
{
  printf("===============================================================================\n");
  printf("Digite a altura da pessoa: ");
  scanf("%f", altura);
  system("cls");
  printf("===============================================================================\n");
  printf("Digite o peso da pessoa: ");
  scanf("%f", peso);
  system("cls");
}

float calcular_imc(float altura, float peso)
{
  float imc;
  imc = peso / (altura * altura);
  return (imc);
}

void verificar_imc(float imc)
{
  printf("===============================================================================\n");
  if (imc < 18.5)
  {
    printf("IMC: %.2f - Situacao: Abaixo do peso ideal\n", imc);
  }
  if ((imc >= 18.5) && (imc <= 24.9))
  {
    printf("IMC: %.2f - Situacao: Peso normal\n", imc);
  }
  if ((imc >= 25) && (imc <= 29.9))
  {
    printf("IMC: %.2f - Situacao: Acima do peso\n", imc);
  }
  if ((imc >= 30) && (imc <= 34.9))
  {
    printf("IMC: %.2f - Situacao: Obesidade Grau I\n", imc);
  }
  if ((imc >= 35) && (imc <= 39.9))
  {
    printf("IMC: %.2f - Situacao: Obesidade Grau II\n", imc);
  }
  if (imc >= 40)
  {
    printf("IMC: %.2f - Situacao: Obesidade Grau III\n", imc);
  }
  printf("===============================================================================\n");
}

int main()
{
  float imc, altura, peso;
  leitura(&altura, &peso);
  imc = calcular_imc(altura, peso);
  verificar_imc(imc);
  system("pause");
}
