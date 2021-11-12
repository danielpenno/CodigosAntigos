// L�gica de Programa��o
// Quest�o 2 - Trabalho V
// Alunos: C�ssio Avelino e Daniel Caio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitura(int *x, int codigo[1000], float salario[1000])
{
  int i;
  do
  {
    printf("===============================================================================\n");
    printf("Quantas funcionarios voce ira utilizar?<1-1000> ");
    scanf("%d", x);
    system("cls");
  } while ((*x > 1000) || (*x < 1));
  for (i = 0; i < *x; i++)
  {
    system("cls");
    printf("===============================================================================\n");
    printf("Digite o codigo do funcionario %d: ", i + 1);
    scanf("%d", &codigo[i]);
    printf("Digite o salario do funcionario %d: ", i + 1);
    scanf("%f", &salario[i]);
  }
  system("cls");
}

void calcular_salario_e_total_novo(int x, float salario[1000], float novo_salario[1000], float *total_novo)
{
  int i;
  float total_velho = 0, total_novo2 = 0, salario2 = 0;
  for (i = 0; i < x; i++)
  {
    salario2 = 0;
    if (salario[i] < 1000)
    {
      salario2 = ((salario[i] / 100) * 40);
      novo_salario[i] = salario[i] + salario2;
    }
    if ((salario[i] >= 1000) && (salario[i] <= 2000))
    {
      salario2 = ((salario[i] / 100) * 30);
      novo_salario[i] = salario[i] + salario2;
    }
    if (salario[i] > 2000)
    {
      salario2 = ((salario[i] / 100) * 10);
      novo_salario[i] = salario[i] + salario2;
    }
    total_velho = total_velho + salario[i];
    total_novo2 = total_novo2 + novo_salario[i];
  }
  *total_novo = total_novo2 - total_velho;
}

void imprimir(int x, int codigo[1000], float salario[1000], float novo_salario[1000], float total_novo)
{
  int i;
  system("cls");
  printf("===============================================================================\n");
  for (i = 0; i < x; i++)
  {
    printf("%d - Codigo: %d - Salario: %.2f - Novo Salario: %.2f\n", i + 1, codigo[i], salario[i], novo_salario[i]);
  }
  printf("===============================================================================\n");
  printf("Custo adicional: %.2f\n", total_novo);
  printf("===============================================================================\n");
}

int main()
{
  int x = 0, codigo[1000];
  float total_novo = 0, salario[1000], novo_salario[1000];
  leitura(&x, codigo, salario);
  calcular_salario_e_total_novo(x, salario, novo_salario, &total_novo);
  imprimir(x, codigo, salario, novo_salario, total_novo);
  system("pause");
}
