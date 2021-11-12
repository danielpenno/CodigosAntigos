// Estrutura de Dados
// Quest�o 1 - 3� Atividade
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados2
{
  char titulo[1000];
  char produtora[1000];
  int ano;
  char idioma[1000];
  dados2 *next;
} dados2;

typedef struct dados
{
  dados2 *start;
  dados2 *end;
} dados;

int es(dados **filmes)
{
  if (((*filmes)->start == NULL) && ((*filmes)->end == NULL))
  {
    return (1);
  }
  if ((*filmes)->start == (*filmes)->end)
  {
    return (2);
  }
  else
  {
    return (0);
  }
}
dados *i(char *titulo, char *produtora, int ano, char *idioma, dados **filmes)
{
  dados2 *aux = NULL;
  aux = (dados2 *)malloc(sizeof(dados2));
  strcpy(aux->titulo, (titulo));
  strcpy(aux->produtora, (produtora));
  aux->ano = ano;
  strcpy(aux->idioma, (idioma));
  if (es(&(*filmes)) == 1)
  {
    (*filmes)->start = aux;
    (*filmes)->end = aux;
  }
  else if (es(&(*filmes)) == 2)
  {
    (*filmes)->end->next = aux;
    (*filmes)->start = (*filmes)->end;
    (*filmes)->end = aux;
  }
  else
  {
    (*filmes)->end->next = aux;
    (*filmes)->end = aux;
  }
  return (*filmes);
}

dados exinicio(dados **filmes)
{
  printf("\tTitulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", (*filmes)->start->titulo, (*filmes)->start->produtora, (*filmes)->start->ano, (*filmes)->start->idioma);
  return (*(*filmes));
}

dados exfinal(dados **filmes)
{
  printf("\tTitulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", (*filmes)->end->titulo, (*filmes)->end->produtora, (*filmes)->end->ano, (*filmes)->end->idioma);
  return (*(*filmes));
}

void cinicio(dados **filmes)
{
  dados2 *aux = (*filmes)->start;
  if ((*filmes)->start != NULL)
  {
    exinicio(&(*filmes));
  }
  (*filmes)->start = aux;
}

void cfinal(dados **filmes)
{
  dados2 *aux = (*filmes)->end;
  if ((*filmes)->end != NULL)
  {
    exfinal(&(*filmes));
  }
  (*filmes)->end = aux;
}

int r(dados **filmes)
{
  dados2 *aux = (*filmes)->start;
  if (es(&(*filmes)) == 1)
  {
    return (0);
  }
  else if ((*filmes)->start == NULL)
  {
    (*filmes)->end = NULL;
    free((*filmes));
  }
  else
  {
    (*filmes)->start = (*filmes)->start->next;
    free(aux);
  }
  return (1);
}

void e(dados **filmes)
{
  while ((*filmes) != NULL)
  {
    r(&(*filmes));
  }
}
