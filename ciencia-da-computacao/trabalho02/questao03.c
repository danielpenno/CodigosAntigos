#include <stdio.h>
#include <stdlib.h>

float max(int matriz[][2], int *maior)
{
  int i, j;
  *maior = matriz[0][0];
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      if (matriz[i][j] > *maior)
      {
        *maior = matriz[i][j];
      }
    }
  }
}
int main()
{
  int matriz[2][2] = {{-1, -2}, {3, -5}};
  int *maior;
  max(matriz, &maior);
  printf("Maior valor da matriz: %d", maior);
  return 0;
}
