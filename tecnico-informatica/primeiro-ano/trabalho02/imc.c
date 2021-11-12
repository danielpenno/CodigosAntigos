// L�gica de Programa��o
// Quest�o 4 - Trabalho II
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char nome[1000][50];
  float imc[1000], altura[1000], peso[1000];
  float imc_alto[2], imc_baixo[2];
  int x = 0, i, j;
  do
  {
    printf("===============================================================================\n");
    printf("Quantas pessoas voce quer calcular o IMC?<1-1000> ");
    scanf("%d", &x);
    system("cls");
  } while ((x > 1000) || (x < 1));
  for (i = 0; i < x; i++)
  {
    system("cls");
    printf("===============================================================================\n");
    printf("Digite o nome da pessoa %d: ", i + 1);
    gets(nome[i]);
    gets(nome[i]);
    printf("Digite a altura da pessoa %d: ", i + 1);
    scanf("%f", &altura[i]);
    printf("Digite o peso da pessoa %d: ", i + 1);
    scanf("%f", &peso[i]);
  }
  system("cls");
  printf("===============================================================================\n");
  for (i = 0; i < x; i++)
  {
    imc[i] = peso[i] / (altura[i] * altura[i]);
    if (imc[i] < 18.5)
    {
      printf("Nome: %s - IMC: %.2f - Situacao: Abaixo do peso ideal\n", nome[i], imc[i]);
    }
    if ((imc[i] >= 18.5) && (imc[i] <= 24.9))
    {
      printf("Nome: %s - IMC: %.2f - Situacao: Peso normal\n", nome[i], imc[i]);
    }
    if ((imc[i] >= 25) && (imc[i] <= 29.9))
    {
      printf("Nome: %s - IMC: %.2f - Situacao: Acima do peso\n", nome[i], imc[i]);
    }
    if ((imc[i] >= 30) && (imc[i] <= 34.9))
    {
      printf("Nome: %s - IMC: %.2f - Situacao: Obesidade Grau I\n", nome[i], imc[i]);
    }
    if ((imc[i] >= 35) && (imc[i] <= 39.9))
    {
      printf("Nome: %s - IMC: %.2f - Situacao: Obesidade Grau II\n", nome[i], imc[i]);
    }
    if (imc[i] >= 40)
    {
      printf("Nome: %s - IMC: %.2f - Situacao: Obesidade Grau III\n", nome[i], imc[i]);
    }
  }
  for (i = 0; i < x; i++)
  {
    if (imc_alto[1] < imc[i])
    {
      imc_alto[1] = imc[i];
      imc_alto[2] = i;
    }
  }
  imc_baixo[1] = imc[0];
  for (i = 0; i < x; i++)
  {
    if (imc[i] < imc_baixo[1])
    {
      imc_baixo[1] = imc[i];
      imc_baixo[2] = i;
    }
  }
  printf("===============================================================================\n");
  i = imc_alto[2];
  if (imc_alto[1] < 18.5)
  {
    printf("(Maior) Nome: %s - IMC: %.2f - Situacao: Abaixo do peso ideal\n", nome[i], imc_alto[1]);
  }
  if ((imc_alto[1] >= 18.5) && (imc_alto[1] <= 24.9))
  {
    printf("(Maior) Nome: %s - IMC: %.2f - Situacao: Peso normal\n", nome[i], imc_alto[1]);
  }
  if ((imc_alto[1] >= 25) && (imc_alto[1] <= 29.9))
  {
    printf("(Maior) Nome: %s - IMC: %.2f - Situacao: Acima do peso\n", nome[i], imc_alto[1]);
  }
  if ((imc_alto[1] >= 30) && (imc_alto[1] <= 34.9))
  {
    printf("(Maior) Nome: %s - IMC: %.2f - Situacao: Obesidade Grau I\n", nome[i], imc_alto[1]);
  }
  if ((imc_alto[1] >= 35) && (imc_alto[1] <= 39.9))
  {
    printf("(Maior) Nome: %s - IMC: %.2f - Situacao: Obesidade Grau II\n", nome[i], imc_alto[1]);
  }
  if (imc_alto[1] >= 40)
  {
    printf("(Maior) Nome: %s - IMC: %.2f - Situacao: Obesidade Grau III\n", nome[i], imc_alto[1]);
  }
  j = imc_baixo[2];
  if (imc_baixo[1] < 18.5)
  {
    printf("(Menor) Nome: %s - IMC: %.2f - Situacao: Abaixo do peso ideal\n", nome[j], imc_baixo[1]);
  }
  if ((imc_baixo[1] >= 18.5) && (imc_baixo[1] <= 24.9))
  {
    printf("(Menor) Nome: %s - IMC: %.2f - Situacao: Peso normal\n", nome[j], imc_baixo[1]);
  }
  if ((imc_baixo[1] >= 25) && (imc_baixo[1] <= 29.9))
  {
    printf("(Menor) Nome: %s - IMC: %.2f - Situacao: Acima do peso\n", nome[j], imc_baixo[1]);
  }
  if ((imc_baixo[1] >= 30) && (imc_baixo[1] <= 34.9))
  {
    printf("(Menor) Nome: %s - IMC: %.2f - Situacao: Obesidade Grau I\n", nome[j], imc_baixo[1]);
  }
  if ((imc_baixo[1] >= 35) && (imc_baixo[1] <= 39.9))
  {
    printf("(Menor) Nome: %s - IMC: %.2f - Situacao: Obesidade Grau II\n", nome[j], imc_baixo[1]);
  }
  if (imc_baixo[1] >= 40)
  {
    printf("(Menor) Nome: %s - IMC: %.2f - Situacao: Obesidade Grau III\n", nome[j], imc_baixo[1]);
  }
  printf("===============================================================================\n");
  system("pause");
}
