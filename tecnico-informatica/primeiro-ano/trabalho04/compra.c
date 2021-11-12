// L�gica de Programa��o
// Quest�o 1 - Trabalho V
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitura(int *x, int codigo[1000], float qtd[1000], float preco[1000])
{
  int i;
  do
  {
    printf("===============================================================================\n");
    printf("Quantas produtos voce ira contabilizar?<1-1000> ");
    scanf("%d", x);
    system("cls");
  } while ((*x > 1000) || (*x < 1));
  for (i = 0; i < *x; i++)
  {
    system("cls");
    printf("===============================================================================\n");
    printf("Digite o codigo do produto %d: ", i + 1);
    scanf("%d", &codigo[i]);
    printf("Digite a quantidade do produto %d: ", i + 1);
    scanf("%f", &qtd[i]);
    printf("Digite o preco do produto %d: ", i + 1);
    scanf("%f", &preco[i]);
  }
  system("cls");
}

void calcular_subtotal_e_total(int x, float qtd[1000], float preco[1000], float subtotal[1000], float *total)
{
  int i;
  for (i = 0; i < x; i++)
  {
    subtotal[i] = qtd[i] * preco[i];
    *total = *total + subtotal[i];
  }
}

void caro_barato(int x, float subtotal[1000], float caro[2], float barato[2])
{
  int i;
  for (i = 0; i < x; i++)
  {
    if (caro[0] < subtotal[i])
    {
      caro[0] = subtotal[i];
      caro[1] = i;
    }
  }
  barato[0] = subtotal[0];
  for (i = 0; i < x; i++)
  {
    if (subtotal[i] < barato[0])
    {
      barato[0] = subtotal[i];
      barato[1] = i;
    }
  }
}

void imprimir(int x, int codigo[1000], float qtd[1000], float preco[1000], float subtotal[1000], float total, float caro[2], float barato[2])
{
  int i, j, m;
  system("cls");
  printf("===============================================================================\n");
  for (i = 0; i < x; i++)
  {
    printf("%d - Codigo: %d - Quantidade: %.2f - Preco: %.2f - Subtotal: %.2f\n", i + 1, codigo[i], qtd[i], preco[i], subtotal[i]);
  }
  j = caro[1];
  m = barato[1];
  printf("===============================================================================\n");
  printf("Total: %.2f\n", total);
  printf("Mais caro: %d\n", codigo[j]);
  printf("Mais barato: %d\n", codigo[m]);
  printf("Mais proximo da media: N/A\n");
  printf("===============================================================================\n");
}

int main()
{
  int x = 0, codigo[1000];
  float total = 0, qtd[1000], preco[1000], subtotal[1000];
  float caro[2], barato[2];
  leitura(&x, codigo, qtd, preco);
  calcular_subtotal_e_total(x, qtd, preco, subtotal, &total);
  caro_barato(x, subtotal, caro, barato);
  imprimir(x, codigo, qtd, preco, subtotal, total, caro, barato);
  system("pause");
}
