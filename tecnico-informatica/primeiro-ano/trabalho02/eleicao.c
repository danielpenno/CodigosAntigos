// L�gica de Programa��o
// Quest�o 5 - Trabalho II
// Alunos: Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int opcao;
  int candidato_a = 0, candidato_b = 0, candidato_c = 0;
  int branco = 0, nulo = 0, total = 0;
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
      candidato_a++;
      break;
    case 2:
      candidato_b++;
      break;
    case 3:
      candidato_c++;
      break;
    case 4:
      branco++;
      break;
    case 5:
      nulo++;
      break;
    }
  } while (opcao != 0);
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
  system("pause");
}
