// L�gica de Programa��o
// Quest�o 5 - Trabalho III
// Alunos: Dalton Oliveira, Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

void leitura(int *candidato_a, int *candidato_b, int *candidato_c, int *branco, int *nulo)
{
  int opcao;
  do
  {
    system("cls");
    printf("===============================================================================\n");
    printf("1 - Candidato A \n2 - Candidato B \n3 - Candidato C \n4 - Voto em branco \n5 - Voto nulo \n0 - Apuracao\n");
    printf("===============================================================================\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      *candidato_a += 1;
      break;
    case 2:
      *candidato_b += 1;
      break;
    case 3:
      *candidato_c += 1;
      break;
    case 4:
      *branco += 1;
      break;
    case 5:
      *nulo += 1;
      break;
    }
  } while (opcao != 0);
}

void calcular_votos_porcentagem(int candidato_a, int candidato_b, int candidato_c, int branco, int nulo, int total)
{
  total = candidato_a + candidato_b + candidato_c + branco + nulo;
  system("cls");
  printf("===============================================================================\n");
  printf("Candidato A obteve %d votos que corresponde a %d\%% do total.\n", candidato_a, candidato_a * 100 / total);
  printf("===============================================================================\n");
  printf("Candidato B obteve %d votos que corresponde a %d\%% do total.\n", candidato_b, candidato_b * 100 / total);
  printf("===============================================================================\n");
  printf("Candidato C obteve %d votos que corresponde a %d\%% do total.\n", candidato_c, candidato_c * 100 / total);
  printf("===============================================================================\n");
  printf("Tivemos %d votos brancos que corresponde a %d\%% do total.\n", branco, branco * 100 / total);
  printf("===============================================================================\n");
  printf("Tivemos %d votos nulos que corresponde a %d\%% do total.\n", nulo, nulo * 100 / total);
  printf("===============================================================================\n");
}

int main()
{
  int candidato_a = 0, candidato_b = 0, candidato_c = 0;
  int branco = 0, nulo = 0, total = 0;
  leitura(&candidato_a, &candidato_b, &candidato_c, &branco, &nulo);
  calcular_votos_porcentagem(candidato_a, candidato_b, candidato_c, branco, nulo, total);
  system("pause");
}
