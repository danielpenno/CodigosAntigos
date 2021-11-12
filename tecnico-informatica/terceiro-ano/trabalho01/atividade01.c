// Estrutura de Dados
// Quest�o 1 - 1� Atividade
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CADASTRAR 1
#define LISTAR 2
#define PESQUISAR 3
#define ORDERNAR 4
#define SAIR 5

#define QUANTIDADE 1000

typedef struct dados
{
  char titulo[1000];
  char produtora[1000];
  int ano;
  char idioma[1000];
} dados;

int main()
{
  char titulo2[1][100];
  char produtora2[1][100];
  char idioma2[1][100];
  char ano2;
  char buscar[100];
  int opcao;
  int i, j, qtd_filme = 0;
  struct dados *filmes;
  filmes = (struct dados *)malloc(sizeof(struct dados) * QUANTIDADE);
  do
  {
    printf("===============================================================================\n");
    printf("%d - CADASTRAR FILME", CADASTRAR);
    printf("\n%d - LISTAR FILME CADASTRADOS", LISTAR);
    printf("\n%d - PESQUISAR FILME CADASTRADO", PESQUISAR);
    printf("\n%d - LISTAR FILME CADASTRADOS ORDENADOS PELO TITULO", ORDERNAR);
    printf("\n%d - SAIR\n", SAIR);
    printf("===============================================================================\n");
    printf("De acordo com a legenda, digite a opcao: ");
    scanf("%d", &opcao);
    system("cls");
    switch (opcao)
    {
    case CADASTRAR:
      if (qtd_filme >= QUANTIDADE)
      {
        printf("===============================================================================\n");
        printf("ERRO: O registro de filmes esta cheio!\n");
      }
      else
      {
        printf("===============================================================================\n");
        printf("Digite o titulo do filme: ");
        gets(filmes[qtd_filme].titulo);
        gets(filmes[qtd_filme].titulo);
        printf("===============================================================================\n");
        printf("Digite a produtora do filme: ");
        scanf("%s", filmes[qtd_filme].produtora);
        printf("===============================================================================\n");
        printf("Digite o ano do filme: ");
        scanf("%d", &(filmes[qtd_filme].ano));
        printf("===============================================================================\n");
        printf("Digite o idioma do filme: ");
        scanf("%s", filmes[qtd_filme].idioma);
        qtd_filme++;
      }
      break;
    case LISTAR:
      printf("===============================================================================\n");
      printf("FILMES CADASTRADOS: \n\n");
      for (i = 0; i < qtd_filme; i++)
      {
        printf("\tTitulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", filmes[i].titulo, filmes[i].produtora, filmes[i].ano, filmes[i].idioma);
      }
      break;
    case PESQUISAR:
      printf("===============================================================================\n");
      printf("Digite o titulo do filme a ser pesquisado: ");
      scanf("%s", buscar);
      system("cls");
      printf("===============================================================================\n");
      printf("FILMES ENCONTRADOS: \n\n");
      for (i = 0; i < qtd_filme; i++)
      {
        if (!strcmp(filmes[i].titulo, buscar))
        {
          printf("\tTitulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", filmes[i].titulo, filmes[i].produtora, filmes[i].ano, filmes[i].idioma);
        }
      }
      break;
    case ORDERNAR:
      for (i = 1; i < qtd_filme; i++)
      {
        for (j = 0; j < qtd_filme - 1; j++)
        {
          if (strcmp(filmes[j].titulo, filmes[j + 1].titulo) > 0)
          {
            strcpy(titulo2[0], filmes[j].titulo);
            strcpy(filmes[j].titulo, filmes[j + 1].titulo);
            strcpy(filmes[j + 1].titulo, titulo2[0]);
            strcpy(produtora2[0], filmes[j].produtora);
            strcpy(filmes[j].produtora, filmes[j + 1].produtora);
            strcpy(filmes[j + 1].produtora, produtora2[0]);
            ano2 = filmes[j].ano;
            filmes[j].ano = filmes[j + 1].ano;
            filmes[j + 1].ano = ano2;
            strcpy(idioma2[0], filmes[j].idioma);
            strcpy(filmes[j].idioma, filmes[j + 1].idioma);
            strcpy(filmes[j + 1].idioma, idioma2[0]);
          }
        }
      }
      printf("===============================================================================\n");
      printf("FILMES CADASTRADOS ORDENADOS PELO TITULO: \n\n");
      for (i = 0; i < qtd_filme; i++)
      {
        printf("\tTitulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", filmes[i].titulo, filmes[i].produtora, filmes[i].ano, filmes[i].idioma);
      }
      break;
    default:
      printf("===============================================================================\n");
      printf("ERRO: Comando invalido!\n");
      break;
    }
  } while (opcao != SAIR);
  free(filmes);
}