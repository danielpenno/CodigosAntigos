// Estrutura de Dados
// Quest�o 1 - 3� Atividade
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <atividade01.h>

#define INSERIR 1
#define REMOVER 2
#define CONSULTAR 3
#define ELIMINAR 4
#define SAIR 5

#define CONSULTAR_INICIO 1
#define CONSULTAR_FINAL 2

int main()
{
  dados *filmes = NULL;
  filmes = (dados *)malloc(sizeof(dados));
  filmes->start = NULL;
  filmes->end = NULL;
  int opcao, opcao2;
  char titulo[1000];
  char produtora[1000];
  int ano;
  char idioma[1000];
  do
  {
    printf("===============================================================================\n");
    printf("%d - INSERIR", INSERIR);
    printf("\n%d - REMOVER", REMOVER);
    printf("\n%d - CONSULTAR", CONSULTAR);
    printf("\n%d - ELIMINAR", ELIMINAR);
    printf("\n%d - SAIR\n", SAIR);
    printf("===============================================================================\n");
    printf("De acordo com a legenda, digite a opcao: ");
    scanf("%d", &opcao);
    system("cls");
    switch (opcao)
    {
    case INSERIR:
      printf("===============================================================================\n");
      printf("Digite o titulo do filme: ");
      gets(titulo);
      gets(titulo);
      printf("===============================================================================\n");
      printf("Digite a produtora do filme: ");
      scanf("%s", produtora);
      printf("===============================================================================\n");
      printf("Digite o ano do filme: ");
      scanf("%d", &ano);
      printf("===============================================================================\n");
      printf("Digite o idioma do filme: ");
      scanf("%s", idioma);
      i(titulo, produtora, ano, idioma, &filmes);
      break;
    case REMOVER:
      r(&filmes);
      break;
    case CONSULTAR:
      printf("===============================================================================");
      printf("\n%d - CONSULTAR INICIO", CONSULTAR_INICIO);
      printf("\n%d - CONSULTAR FINAL\n", CONSULTAR_FINAL);
      printf("===============================================================================\n");
      printf("De acordo com a legenda, digite a opcao: ");
      scanf("%d", &opcao2);
      system("cls");
      switch (opcao2)
      {
      case CONSULTAR_INICIO:
        printf("===============================================================================\n");
        cinicio(&filmes);
        break;
      case CONSULTAR_FINAL:
        printf("===============================================================================\n");
        cfinal(&filmes);
        break;
      default:
        printf("===============================================================================\n");
        printf("ERRO: Comando invalido!\n");
        break;
      }
      break;
    case ELIMINAR:
      e(&filmes);
      break;
    default:
      printf("===============================================================================\n");
      printf("ERRO: Comando invalido!\n");
      break;
    }
  } while (opcao != SAIR);
  free(filmes);
}
