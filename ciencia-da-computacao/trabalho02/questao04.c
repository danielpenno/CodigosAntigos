#include <stdio.h>
#include <stdlib.h>

typedef struct curso
{
  int matricula;
  char nome[100];
  int coeficiente;
};

int main()
{
  struct curso aluno;
  printf("Digite o nome do aluno: ");
  gets(aluno.nome);
  printf("Digite a matricula do aluno: ");
  scanf("%d", &aluno.matricula);
  printf("Digite o coeficiente do aluno: ");
  scanf("%d", &aluno.coeficiente);
  printf("Nome: %s", aluno.nome);
  printf("\nMatricula: %d", aluno.matricula);
  printf("\nCoeficiente: %d", aluno.coeficiente);
  return 0;
}
