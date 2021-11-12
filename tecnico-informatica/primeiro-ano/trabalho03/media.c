// L�gica de Programa��o
// Quest�o 1 - Trabalho III
// Alunos: Dalton Oliveira, Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

void leitura(float *nota1, float *nota2)
{
  do
  {
    printf("===============================================================================\n");
    printf("Digite a primeira nota: ");
    scanf("%f", nota1);
    system("cls");
  } while ((*nota1 > 10) || (*nota1 < 0));
  do
  {
    printf("===============================================================================\n");
    printf("Digite a segunda nota: ");
    scanf("%f", nota2);
    system("cls");
  } while ((*nota2 > 10) || (*nota2 < 0));
}

float calcula_media(float nota1, float nota2)
{
  float media;
  media = (nota1 + nota2) / 2;
  return (media);
}

void verificar_media(float media)
{
  float recuperacao;
  if (media >= 7)
  {
    printf("===============================================================================\n");
    printf("Media: %.2f - Situacao: Aprovado\n", media);
  }
  if ((media < 7) && (media >= 5))
  {
    printf("===============================================================================\n");
    printf("Media: %.2f - Situacao: Em recuperacao\n", media);
    printf("===============================================================================\n");
    printf("Digite a nota de recuperacao: ");
    scanf("%f", &recuperacao);
    system("cls");
    recuperacao = media + recuperacao;
    if (recuperacao >= 10)
    {
      printf("===============================================================================\n");
      printf("Media + Nota de Recuperacao: %.2f - Situacao: Aprovado\n", recuperacao);
    }
    if (recuperacao < 10)
    {
      printf("===============================================================================\n");
      printf("Media + Nota de Recuperacao: %.2f - Situacao: Em construcao\n", recuperacao);
    }
  }
  if (media < 5)
  {
    printf("===============================================================================\n");
    printf("Media: %.2f - Situacao: Em construcao\n", media);
  }
  printf("===============================================================================\n");
}

int main()
{
  float media, nota1, nota2;
  leitura(&nota1, &nota2);
  media = calcula_media(nota1, nota2);
  verificar_media(media);
  system("pause");
}
