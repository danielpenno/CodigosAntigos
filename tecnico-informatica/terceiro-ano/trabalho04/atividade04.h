// Estrutura de Dados
// Quest�o 1 - 3� Atividade
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I_I 1
#define I_F 2
#define I_P 3

#define SAIR_2 4

#define R_I 1
#define R_F 2
#define R_P 3
#define R_E 4

#define SAIR_3 5

typedef struct dados
{
  char titulo[1000];
  char produtora[1000];
  int ano;
  char idioma[1000];
  dados *next;
} dados;

int vazia(dados **filmes)
{
  if ((*filmes) == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void *i_v(char *titulo, char *produtora, int ano, char *idioma, dados **filmes)
{
  (*filmes) = (dados *)malloc(sizeof(dados));
  strcpy((*filmes)->titulo, titulo);
  strcpy((*filmes)->produtora, produtora);
  (*filmes)->ano = ano;
  strcpy((*filmes)->idioma, idioma);
  (*filmes)->next = NULL;
}

dados *i_i(char *titulo, char *produtora, int ano, char *idioma, dados **filmes)
{
  if (vazia(&(*filmes)))
  {
    i_v(titulo, produtora, ano, idioma, &(*filmes));
    return 0;
  }
  dados *aux = *filmes, *novo;
  novo = (dados *)malloc(sizeof(dados));
  strcpy(novo->titulo, titulo);
  strcpy(novo->produtora, produtora);
  novo->ano = ano;
  strcpy(novo->idioma, idioma);
  novo->next = aux;
  (*filmes) = novo;
}

void *i_f(char *titulo, char *produtora, int ano, char *idioma, dados **filmes)
{
  if (vazia(&(*filmes)))
  {
    i_v(titulo, produtora, ano, idioma, &(*filmes));
    return 0;
  }
  dados *aux = *filmes, *novo;
  while (aux->next != NULL)
  {
    aux = aux->next;
  }
  novo = (dados *)malloc(sizeof(dados));
  strcpy(novo->titulo, titulo);
  strcpy(novo->produtora, produtora);
  novo->ano = ano;
  strcpy(novo->idioma, idioma);
  novo->next = NULL;
  aux->next = novo;
}

dados *i_p(char *titulo, char *produtora, int ano, char *idioma, dados **filmes, int posicao)
{
  dados *aux = *filmes, *novo, *ant;
  int cont = 1;
  if (vazia(&(*filmes)))
  {
    i_v(titulo, produtora, ano, idioma, &(*filmes));
    return 0;
  }
  while (aux != NULL)
  {
    if (cont == posicao)
    {
      break;
    }
    ant = aux;
    aux = aux->next;
    cont++;
  }
  if (cont != posicao)
  {
    return 0;
  }
  novo = (dados *)malloc(sizeof(dados));
  strcpy(novo->titulo, titulo);
  strcpy(novo->produtora, produtora);
  novo->ano = ano;
  strcpy(novo->idioma, idioma);
  novo->next = aux;
  if (posicao == 0)
  {
    (*filmes) = novo;
  }
  else
  {
    ant->next = novo;
  }
}

int *r_i(dados **filmes)
{
  dados *aux = *filmes, *ant;
  if (vazia(&(*filmes)))
  {
    return 0;
  }
  ant = aux;
  free(ant);
  aux = aux->next;
  (*filmes) = aux;
}

int *r_f(dados **filmes)
{
  dados *aux = *filmes, *ant;
  if (vazia(&(*filmes)))
  {
    return 0;
  }
  while (aux->next != NULL)
  {
    ant = aux;
    aux = aux->next;
  }
  ant->next = NULL;
  free(aux);
}

int *r_p(dados **filmes, int posicao2)
{
  dados *aux = *filmes, *ant;
  int cont = 1;
  if (vazia(&(*filmes)))
  {
    return 0;
  }
  while (aux != NULL)
  {
    if (cont == posicao2)
    {
      break;
    }
    ant = aux;
    aux = aux->next;
    cont++;
  }
  if (cont != posicao2)
  {
    return 0;
  }
  if (posicao2 == 0)
  {
    (*filmes) = (*filmes)->next;
    free(aux);
  }
  else
  {
    ant->next = aux->next;
    free(aux);
  }
}

void ex(dados **filmes)
{
  dados *aux = *filmes;
  printf("===============================================================================\n");
  while (aux != NULL)
  {
    printf("\tTitulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", aux->titulo, aux->produtora, aux->ano, aux->idioma);
    aux = aux->next;
  }
}

void i(char *titulo, char *produtora, int ano, char *idioma, dados **filmes)
{
  int opcao2, posicao;
  do
  {
    printf("===============================================================================\n");
    printf("%d - INSERIR NO INICIO", I_I);
    printf("\n%d - INSERIR NO FINAL", I_F);
    printf("\n%d - INSERIR EM UMA DETERMINADA POSICAO", I_P);
    printf("\n%d - SAIR\n", SAIR_2);
    printf("===============================================================================\n");
    printf("De acordo com a legenda, digite a opcao: ");
    scanf("%d", &opcao2);
    system("cls");
    switch (opcao2)
    {
    case I_I:
      i_i(titulo, produtora, ano, idioma, &(*filmes));
      opcao2 = SAIR_2;
      break;
    case I_F:
      i_f(titulo, produtora, ano, idioma, &(*filmes));
      opcao2 = SAIR_2;
      break;
    case I_P:
      system("cls");
      printf("===============================================================================\n");
      printf("Digite a posicao desejada: ");
      scanf("%d", &posicao);
      i_p(titulo, produtora, ano, idioma, &(*filmes), posicao);
      opcao2 = SAIR_2;
      break;
    default:
      printf("===============================================================================\n");
      printf("ERRO: Comando invalido!\n");
      break;
    }
  } while (opcao2 != SAIR_2);
}

int r(dados **filmes)
{
  int posicao2, opcao3;
  do
  {
    printf("===============================================================================\n");
    printf("%d - REMOVER DO INICIO", R_I);
    printf("\n%d - REMOVER DO FINAL", R_F);
    printf("\n%d - REMOVER DE UMA DETERMINADA POSICAO", R_P);
    printf("\n%d - REMOVER DE UM DETERMINADO ELEMENTO", R_E);
    printf("\n%d - SAIR\n", SAIR_3);
    printf("===============================================================================\n");
    printf("De acordo com a legenda, digite a opcao: ");
    scanf("%d", &opcao3);
    system("cls");
    switch (opcao3)
    {
    case R_I:
      r_i(&(*filmes));
      opcao3 = SAIR_3;
      break;
    case R_F:
      r_f(&(*filmes));
      opcao3 = SAIR_3;
      break;
    case R_P:
      system("cls");
      printf("===============================================================================\n");
      printf("Digite a posicao desejada: ");
      scanf("%d", &posicao2);
      r_p(&(*filmes), posicao2);
      opcao3 = SAIR_3;
      break;
    case R_E:
      printf("===============================================================================\n");
      printf("ERRO: Opcao indisponivel no momento!\n");
      opcao3 = SAIR_3;
      break;
    default:
      printf("===============================================================================\n");
      printf("ERRO: Comando invalido!\n");
      break;
    }
  } while (opcao3 != SAIR_3);
}
