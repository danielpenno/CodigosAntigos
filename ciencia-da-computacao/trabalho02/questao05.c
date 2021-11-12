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
  int qtd, i;
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &qtd);
  struct curso *aluno;
  aluno = (struct curso *)malloc(sizeof(struct curso) * qtd);
  for (i = 0; i < qtd; i++)
  {
    printf("Digite o nome do aluno %d: ", i + 1);
    gets(aluno[i].nome);
    gets(aluno[i].nome);
    printf("Digite a matricula do aluno %d: ", i + 1);
    scanf("%d", &aluno[i].matricula);
    printf("Digite o coeficiente do aluno %d: ", i + 1);
    scanf("%d", &aluno[i].coeficiente);
  }
  for (i = 0; i < qtd; i++)
  {
    printf("\nNome do aluno %d: %s", i + 1, aluno[i].nome);
    printf("\nMatricula do aluno %d: %d", i + 1, aluno[i].matricula);
    printf("\nCoeficiente do aluno %d: %d", i + 1, aluno[i].coeficiente);
  }
  return 0;
}
