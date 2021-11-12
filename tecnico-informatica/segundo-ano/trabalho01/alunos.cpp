// L�gica de Programa��o
// Quest�o 4 -  2� Atividade
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  typedef struct dados
  {
    char nomes[1000][50];
    char nomes2[1][50];
  } dados;
  dados a;
  int min, aux;
  int col = 4, lin;
  int i, j, n, opcao;
  int **m = NULL;
  printf("===============================================================================\n");
  printf("Quantos alunos voce quer cadastrar? ");
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
    printf("Digite o nome do aluno %d: ", i + 1);
    gets(a.nomes[i]);
    gets(a.nomes[i]);
    printf("===============================================================================\n");
    printf("Digite a idade do aluno %d: ", i + 1);
    scanf("%d", &m[i][0]);
    printf("===============================================================================\n");
    printf("\n1 - Informatica \n2 - Meio Ambiente \n3 - Agroindustria\n\n");
    printf("De acordo com a legenda, digite o numero do curso do aluno %d: ", i + 1);
    scanf("%d", &m[i][1]);
    printf("===============================================================================\n");
    printf("\n1 - Primeira Serie \n2 - Segunda Serie \n3 - Terceira Serie \n4 - Quarta Serie\n\n");
    printf("De acordo com a legenda, digite a serie do aluno %d: ", i + 1);
    scanf("%d", &m[i][2]);
    printf("===============================================================================\n");
    printf("\n1 - Masculino \n2 - Feminino\n\n");
    printf("De acordo com a legenda, digite o sexo do aluno %d: ", i + 1);
    scanf("%d", &m[i][3]);
    printf("===============================================================================\n");
  }
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
    for (i = 1; i < n; i++)
    {
      for (j = 0; j < n - 1; j++)
      {
        if (strcmp(a.nomes[j], a.nomes[j + 1]) > 0)
        {
          strcpy(a.nomes2[0], a.nomes[j]);
          strcpy(a.nomes[j], a.nomes[j + 1]);
          strcpy(a.nomes[j + 1], a.nomes2[0]);
        }
      }
    }
    for (i = 0; i < n; i++)
    {
      printf("\t%s\n", a.nomes[i]);
    }
    printf("===============================================================================\n");
    break;
  case 2:
    printf("===============================================================================\n");
    printf("Todos os alunos ordenados pela idade: \n\n");
    for (i = 0; i < n - 1; i++)
    {
      min = i;
      aux = m[i][0];
      for (j = i + 1; j < n; j++)
      {
        if (m[j][0] < aux)
        {
          min = j;
          aux = m[j][0];
        }
      }
      aux = m[i][0];
      m[i][0] = m[min][0];
      m[min][0] = aux;
      strcpy(a.nomes2[0], a.nomes[i]);
      strcpy(a.nomes[i], a.nomes[min]);
      strcpy(a.nomes[min], a.nomes2[0]);
    }
    for (i = 0; i < n; i++)
    {
      printf("\t%s - %d\n", a.nomes[i], m[i][0]);
    }
    printf("===============================================================================\n");
    break;
  case 3:
    printf("===============================================================================\n");
    printf("Alunos de informatica: \n\n");
    for (i = 0; i < n; i++)
    {
      if (m[i][1] == 1)
      {
        printf("\t%s\n", a.nomes[i]);
      }
    }
    printf("\n===============================================================================\n");
    break;
  case 4:
    printf("===============================================================================\n");
    printf("Alunos do sexo masculino: \n\n");
    for (i = 0; i < n; i++)
    {
      if (m[i][3] == 1)
      {
        printf("\t%s\n", a.nomes[i]);
      }
    }
    printf("\n===============================================================================\n");
    break;
  case 5:
    printf("===============================================================================\n");
    printf("Alunos do sexo feminino: \n\n");
    for (i = 0; i < n; i++)
    {
      if (m[i][3] == 2)
      {
        printf("\t%s\n", a.nomes[i]);
      }
    }
    printf("===============================================================================\n");
  }
  for (i = 0; i < lin; i++)
  {
    free(m[i]);
  }
  free(m);
  system("pause");
}
