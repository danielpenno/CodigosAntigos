#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <atividade01.h> // biblioteca

#define N_FILMES 1000 // variavel global

int main()
{
    char pesquisar[100], troca[1][100], troca2[1][100], troca3[1][100], troca4; // variaveis de pesquisa e troca
    int opc, i, j, qtfilme = 0;
    struct filmes *filme;                                              // alocacao dinamica
    filme = (struct filmes *)malloc(sizeof(struct filmes) * N_FILMES); // alocacao dinamica
    do
    {
        printf("1 - Cadastrar filme");                // MENU
        printf("\n2 - Listar filmes cadastrados");    // MENU
        printf("\n3 - Pesquisar filmes cadastrados"); // MENU
        printf("\n4 - Ordenar filmes pelo titulo");   // MENU
        printf("\n5 - Sair\n");                       // MENU
        printf("\nDigite a opcao: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            if (qtfilme >= N_FILMES)
            { // verificar se o registro ja esta cheio
                printf("Erro ao registrar! Registro cheio!\n");
            }
            else
            {
                printf("Digite o titulo do filme: ");
                gets(filme[qtfilme].tto);
                gets(filme[qtfilme].tto);
                printf("Digite a produtora do filme: ");
                scanf("%s", filme[qtfilme].produt);
                printf("Digite o ano do filme: ");
                scanf("%d", &(filme[qtfilme].ano));
                printf("Digite o idioma do filme: ");
                scanf("%s", filme[qtfilme].idi);
                qtfilme++;
            }
            break;
        case 2:
            printf("Filmes cadastrados: \n"); // listar filmes cadastrados
            for (i = 0; i < qtfilme; i++)
            {
                printf("Titulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", filme[i].tto, filme[i].produt, filme[i].ano, filme[i].idi);
            }
            break;
        case 3:
            printf("Digite o titulo do filme para pesquisa: ");
            scanf("%s", pesquisar);
            printf("Filmes achados: \n");
            for (i = 0; i < qtfilme; i++)
            { // comparar se eh igual com variavel de titulo
                if (!strcmp(filme[i].tto, pesquisar))
                {
                    printf("Titulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", filme[i].tto, filme[i].produt, filme[i].ano, filme[i].idi);
                }
            }
            break;
        case 4:
            for (i = 1; i < qtfilme; i++)
            {
                for (j = 0; j < qtfilme - 1; j++)
                {
                    if (strcmp(filme[j].tto, filme[j + 1].tto) > 0)
                    {                                   // comparar strings para definir a ordem
                        strcpy(troca[0], filme[j].tto); // troca de valores
                        strcpy(filme[j].tto, filme[j + 1].tto);
                        strcpy(filme[j + 1].tto, troca[0]);
                        troca4 = filme[j].ano;
                        filme[j].ano = filme[j + 1].ano;
                        filme[j + 1].ano = troca4;
                        strcpy(troca2[0], filme[j].produt);
                        strcpy(filme[j].produt, filme[j + 1].produt);
                        strcpy(filme[j + 1].produt, troca2[0]);
                        strcpy(troca3[0], filme[j].idi);
                        strcpy(filme[j].idi, filme[j + 1].idi);
                        strcpy(filme[j + 1].idi, troca3[0]);
                    }
                }
            }
            printf("Filmes cadastrados ordenados por titulo: \n"); // listar filmes ordenados
            for (i = 0; i < qtfilme; i++)
            {
                printf("Titulo: %s - Produtora: %s - Ano: %d - Idioma: %s\n", filme[i].tto, filme[i].produt, filme[i].ano, filme[i].idi);
            }
            break;
        default:
            printf("Digite um comando valido!\n"); // erro
            break;
        }
    } while (opc != 5);
    free(filme); // desalocacao dinamica
}