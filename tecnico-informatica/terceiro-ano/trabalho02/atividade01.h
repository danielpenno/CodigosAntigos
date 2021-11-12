// Estrutura de Dados
// Quest�o 1 - 2� Atividade
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados
{
  char titulo[1000];
  char produtora[1000];
  int ano;
  char idioma[1000];
  dados *next;
} dados;

dados *i(char *titulo, char *produtora, int ano, char *idioma, dados **filmes)
{
  dados *aux = NULL;
  aux = (dados *)malloc(sizeof(dados));
  strcpy(aux->titulo, (titulo));
  strcpy(aux->produtora, (produtora));
  aux->ano = ano;
  strcpy(aux->idioma, (idioma));
  aux->next = *filmes;
  *filmes = aux;
  return (*filmes);
}
void c(dados **filmes)
{
  dados *aux = *filmes;
  printf("\tTitulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", (*filmes)->titulo, (*filmes)->produtora, (*filmes)->ano, (*filmes)->idioma);
}

dados *r(dados **filmes)
{
  dados *aux = *filmes;
  *filmes = (*filmes)->next;
  free(aux);
  return (*filmes);
}

void e(dados **filmes)
{
  while (*filmes != NULL)
  {
    r(&(*filmes));
  }
}
