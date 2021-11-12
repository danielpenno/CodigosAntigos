#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct no
{
    char nome[128];
    int numConta, prioridade;
    struct no *prox;
} no;

typedef struct fila
{
    no *inicio, *fim;
    int qtd;
} fila;

void criaFila(fila *f)
{
    f->inicio = f->fim = NULL;
    f->qtd = 0;
}

bool filaVazia(fila f)
{
    return (f.inicio == NULL && f.fim == NULL) ? true : false;
}

void inserirCliente(fila *f, int num, int prioridade, char *nome, int caixas[3][2], char nomes[3][128])
{
    int j;
    if (caixas[0][0] == 0 || caixas[1][0] == 0 || caixas[2][0] == 0 && filaVazia(*f))
    {
        for (j = 0; j < 3; j++)
        {
            if (caixas[j][0] == 0)
            {
                printf("===============================================================================\n");
                printf("Nome: %s\n", nome);
                printf("Dirija-se ao caixa: %d", j + 1);
                caixas[j][0] = 2;
                strcpy(nomes[j], nome);
                caixas[j][1] = num;
                break;
            }
        }
        system("pause>NULL");
    }
    else
    {
        no *aux = (no *)malloc(sizeof(no));
        aux->numConta = num;
        aux->prioridade = prioridade;
        strcpy(aux->nome, nome);
        f->qtd++;
        if (f->inicio == NULL)
        {
            aux->prox = NULL;
            f->inicio = aux;
            f->fim = aux;
        }
        else
        {
            if (prioridade > f->inicio->prioridade)
            {
                aux->prox = f->inicio;
                f->inicio = aux;
            }
            else
            {
                no *corre = f->inicio;
                while (corre->prox && corre->prox->prioridade >= prioridade)
                {
                    corre = corre->prox;
                }
                if (corre == f->fim)
                {
                    aux->prox = NULL;
                    f->fim->prox = aux;
                    f->fim = aux;
                }
                else
                {
                    aux->prox = corre->prox;
                    corre->prox = aux;
                }
            }
        }
    }
}

void sairDaFila(fila *f, int numConta)
{
    if (!filaVazia(*f))
    {
        no *buffer = NULL;
        no *aux = f->inicio;
        if (aux->numConta == numConta)
        {
            buffer = aux;
            if (aux->prox == NULL)
            {
                criaFila(f);
            }
            else
            {
                f->inicio = aux->prox;
            }
        }
        else
        {
            bool achou = false;
            while (aux != NULL && !achou)
            {
                if (aux->prox != NULL && aux->prox->numConta == numConta)
                {
                    if (aux->prox->prox == NULL)
                    {
                        buffer = aux->prox;
                        aux->prox = NULL;
                        f->fim = aux;
                        achou = true;
                    }
                    else
                    {
                        buffer = aux->prox;
                        aux->prox = (aux->prox)->prox;
                        achou = true;
                    }
                }
                aux = aux->prox;
            }
        }
        if (buffer != NULL)
        {
            printf("===============================================================================\n");
            printf("Cliente: %s - Conta: %d - Removido com sucesso da fila!", buffer->nome, buffer->numConta);
            free(buffer);
            f->qtd--;
        }
    }
    else
    {
        printf("===============================================================================\n");
        printf("ERRO: Nao existe cliente na fila!");
    }
}

no *desenfileirar(fila *f)
{
    no *aux = NULL;
    if (!filaVazia(*f))
    {
        aux = f->inicio;
        if (f->inicio->prox == NULL)
        {
            criaFila(f);
        }
        else
        {
            f->inicio = (f->inicio)->prox;
            f->qtd--;
        }
    }
}

void chamarCliente(fila *f, int caixas[3][2], char nomes[3][128])
{
    bool done = false;
    int j = 0;
    if (!filaVazia(*f))
    {
        for (j = 0; j < 3; j++)
        {
            if (caixas[j][0] == 0)
            {
                printf("===============================================================================\n");
                printf("Nome: %s\n", f->inicio->nome);
                printf("Dirija-se ao caixa: %d", j + 1);
                caixas[j][0] = 2;
                strcpy(nomes[j], f->inicio->nome);
                caixas[j][1] = f->inicio->numConta;
                desenfileirar(f);
                done = true;
                break;
            }
        }
        if (!done)
        {
            printf("===============================================================================\n");
            printf("ERRO: Todos os caixas ocupados e/ou fechados!");
        }
    }
    else
    {
        printf("===============================================================================\n");
        printf("ERRO: Nao existe cliente na fila!");
    }
}

void liberarCaixa(int caixas[3][2], char nomes[3][128])
{
    int g;
    printf("===============================================================================\n");
    printf("Qual caixa voce deseja liberar? ");
    scanf("%d", &g);
    if (caixas[g - 1][0] == 0)
    {
        printf("===============================================================================\n");
        printf("ERRO: Caixa ja liberado.");
    }
    else if (caixas[g - 1][0] == 2)
    {
        caixas[g - 1][0] = 0;
        strcpy(nomes[g - 1], "");
        caixas[g - 1][1] = "";
        printf("===============================================================================\n");
        printf("Caixa 0%d liberado.", g);
    }
    else
    {
        printf("===============================================================================\n");
        printf("ERRO: Caixa fechado.");
    }
}

void fecharCaixa(int caixas[3][2], char nomes[3][128])
{
    int g;
    printf("===============================================================================\n");
    printf("Qual caixa voce deseja fechar? ");
    scanf("%d", &g);
    if (caixas[g - 1][0] == 1)
    {
        printf("===============================================================================\n");
        printf("ERRO: Caixa ja fechado.");
    }
    else if (caixas[g - 1][0] == 2)
    {
        printf("===============================================================================\n");
        printf("ERRO: Caixa ocupado, libere ele antes de fechar.");
    }
    else
    {
        caixas[g - 1][0] = 1;
        strcpy(nomes[g - 1], "");
        caixas[g - 1][1] = "";
        printf("===============================================================================\n");
        printf("Caixa 0%d fechado.", g);
    }
}

void abrirCaixa(int caixas[3][2], char nomes[3][128])
{
    int g;
    printf("===============================================================================\n");
    printf("Qual caixa voce deseja abrir? ");
    scanf("%d", &g);
    if (caixas[g - 1][0] == 0)
    {
        printf("===============================================================================\n");
        printf("ERRO: Caixa ja esta aberto.");
    }
    else if (caixas[g - 1][0] == 2)
    {
        printf("===============================================================================\n");
        printf("ERRO: Caixa ocupado.");
    }
    else
    {
        caixas[g - 1][0] = 0;
        strcpy(nomes[g - 1], "");
        caixas[g - 1][1] = "";
        printf("===============================================================================\n");
        printf("Caixa 0%d aberto.", g);
    }
}

void imprimeFila(fila *f)
{
    no *aux = f->inicio;
    int posicao = 1;
    if (!filaVazia(*f))
    {
        printf("===============================================================================\n");
        while (aux != NULL)
        {
            printf("\nNome: %s - Conta: %d - Posicao na fila: %d", aux->nome, aux->numConta, posicao);
            aux = aux->prox;
            posicao++;
        }
        printf("\n\n===============================================================================\n");
    }
    else
    {
        printf("===============================================================================\n");
        printf("ERRO: Fila de clientes vazia!");
    }
}

int main()
{
    fila novo;
    int caixas[3][2];
    char nomes[3][128];
    int opcao, numConta, prioridade, i;
    char nome[128];
    criaFila(&novo);
    for (i = 0; i < 3; i++)
    {
        caixas[i][0] = 0;
    }
    do
    {
        system("cls");
        printf("===============================================================================\n");
        for (i = 0; i < 3; i++)
        {
            printf("CAIXA 0%d\n", i + 1);
            printf("===============================================================================\n");
            if (caixas[i][0] == 0)
            {
                printf("Status: LIVRE\n");
            }
            else if (caixas[i][0] == 1)
            {
                printf("Status: FECHADO\n");
            }
            else
            {
                printf("Status: OCUPADO\n");
                printf("Nome: %s - Conta: %d\n", &nomes[i], caixas[i][1]);
            }
            printf("===============================================================================\n");
        }
        printf("1 - INSERIR CLIENTE NA FILA");
        printf("\n2 - REMOVER CLIENTE DA FILA");
        printf("\n3 - EXIBIR FILA DE CLIENTES");
        printf("\n4 - CHAMAR CLIENTE");
        printf("\n5 - LIBERAR CAIXA");
        printf("\n6 - ABRIR CAIXA");
        printf("\n7 - FECHAR CAIXA");
        printf("\n0 - SAIR\n");
        printf("===============================================================================\n");
        printf("De acordo com a legenda, digite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            while (novo.qtd > 0)
                free(desenfileirar(&novo));
            opcao = 0;
            break;
        case 1:
            printf("===============================================================================\n");
            printf("Digite o nome do cliente: ");
            gets(nome);
            gets(nome);
            printf("Digite o numero da conta do cliente: ");
            scanf("%d", &numConta);
            printf("O cliente tem prioridade? (1 - SIM/0 - NAO) ");
            scanf("%d", &prioridade);
            inserirCliente(&novo, numConta, prioridade, nome, caixas, nomes);
            break;
        case 2:
            printf("===============================================================================\n");
            printf("Digite o numero da conta do cliente: ");
            scanf("%d", &numConta);
            sairDaFila(&novo, numConta);
            system("pause>NULL");
            break;
        case 3:
            imprimeFila(&novo);
            system("pause>NULL");
            break;
        case 4:
            chamarCliente(&novo, caixas, &nomes);
            system("pause>NULL");
            break;
        case 5:
            liberarCaixa(caixas, nomes);
            system("pause>NULL");
            break;
        case 6:
            abrirCaixa(caixas, nomes);
            system("pause>NULL");
            break;
        case 7:
            fecharCaixa(caixas, nomes);
            system("pause>NULL");
            break;
        default:
            printf("===============================================================================\n");
            printf("ERRO: Digite uma opcao valida!");
            system("pause>NULL");
        }
    } while (opcao != 0);
}
