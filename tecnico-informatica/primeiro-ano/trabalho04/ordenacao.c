// L�gica de Programa��o
// Quest�o 3 - Trabalho V
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitura(int *x, char alunos[1000][50], float alunos2[1000][4])
{
  int i;
  do
  {
    printf("===============================================================================\n");
    printf("Quantas alunos voce ira listar?<1-1000> ");
    scanf("%d", x);
    system("cls");
  } while ((*x > 1000) || (*x < 1));
  for (i = 0; i < *x; i++)
  {
    system("cls");
    printf("===============================================================================\n");
    printf("Digite o nome do aluno %d: ", i + 1);
    gets(alunos[i]);
    gets(alunos[i]);
    printf("===============================================================================\n");
    printf("Digite a idade do aluno %d: ", i + 1);
    scanf("%f", &alunos2[i][0]);
    printf("===============================================================================\n");
    printf("\n1 - Informatica \n2 - Meio Ambiente \n3 - Agroindustria\n\n");
    printf("De acordo com a legenda, digite o numero do curso do aluno %d: ", i + 1);
    scanf("%f", &alunos2[i][1]);
    printf("===============================================================================\n");
    printf("\n1 - Primeira Serie \n2 - Segunda Serie \n3 - Terceira Serie \n4 - Quarta Serie\n\n");
    printf("De acordo com a legenda, digite a serie do aluno %d: ", i + 1);
    scanf("%f", &alunos2[i][2]);
    printf("===============================================================================\n");
    printf("\n1 - Masculino \n2 - Feminino\n\n");
    printf("De acordo com a legenda, digite o sexo do aluno %d: ", i + 1);
    scanf("%f", &alunos2[i][3]);
    printf("===============================================================================\n");
  }
  system("cls");
}

void imprimir(int x, char alunos[1000][50], float alunos2[1000][4], char alunos3[1][50])
{
  int i, j, opcao;
  int min, aux;
  system("cls");
  printf("===============================================================================\n");
  printf("\n1 - Listar o nome de todos os alunos em ordem alfabetica");
  printf("\n2 - Listar todos os alunos ordenados pela idade");
  printf("\n3 - Listar todos os alunos de informatica");
  printf("\n4 - Listar todos os alunos do sexo masculino");
  printf("\n5 - Listar todos os alunos do sexo feminino\n\n");
  printf("De acordo com a legenda, digite a opcao: ");
  scanf("%d", &opcao);
  system("cls");
  switch (opcao)
  {
  case 1:
    printf("===============================================================================\n");
    printf("Todos os alunos em ordem alfabetica: \n\n");
    for (i = 1; i < x; i++)
    {
      for (j = 0; j < x - 1; j++)
      {
        if (strcmp(alunos[j], alunos[j + 1]) > 0)
        {
          strcpy(alunos3[0], alunos[j]);
          strcpy(alunos[j], alunos[j + 1]);
          strcpy(alunos[j + 1], alunos3[0]);
        }
      }
    }
    for (i = 0; i < x; i++)
    {
      printf("\t%s\n", alunos[i]);
    }
    printf("===============================================================================\n");
    break;
  case 2:
    printf("===============================================================================\n");
    printf("Todos os alunos ordenados pela idade: \n\n");
    for (i = 0; i < x - 1; i++)
    {
      min = i;
      aux = alunos2[i][0];
      for (j = i + 1; j < x; j++)
      {
        if (alunos2[j][0] < aux)
        {
          min = j;
          aux = alunos2[j][0];
        }
      }
      aux = alunos2[i][0];
      alunos2[i][0] = alunos2[min][0];
      alunos2[min][0] = aux;
      strcpy(alunos3[0], alunos[i]);
      strcpy(alunos[i], alunos[min]);
      strcpy(alunos[min], alunos3[0]);
    }
    for (i = 0; i < x; i++)
    {
      printf("\t%s - %.2f\n", alunos[i], alunos2[i][0]);
    }
    printf("===============================================================================\n");
    break;
  case 3:
    printf("===============================================================================\n");
    printf("Alunos de informatica: \n\n");
    for (i = 0; i < x; i++)
    {
      if (alunos2[i][1] == 1)
      {
        printf("\t%s\n", alunos[i]);
      }
    }
    printf("\n===============================================================================\n");
    break;
  case 4:
    printf("===============================================================================\n");
    printf("Alunos do sexo masculino: \n\n");
    for (i = 0; i < x; i++)
    {
      if (alunos2[i][3] == 1)
      {
        printf("\t%s\n", alunos[i]);
      }
    }
    printf("\n===============================================================================\n");
    break;
  case 5:
    printf("===============================================================================\n");
    printf("Alunos do sexo feminino: \n\n");
    for (i = 0; i < x; i++)
    {
      if (alunos2[i][3] == 2)
      {
        printf("\t%s\n", alunos[i]);
      }
    }
    printf("===============================================================================\n");
  }
}

int main()
{
  int x = 0;
  char alunos[1000][50], alunos3[1][50];
  float alunos2[1000][4];
  leitura(&x, alunos, alunos2);
  imprimir(x, alunos, alunos2, alunos3);
  system("pause");
}
