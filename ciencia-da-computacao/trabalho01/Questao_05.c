#include <stdio.h>
#include <stdlib.h>

int main()
{
   float matrizA[3][3] = {{4, 5, 2}, {2, 1, 0}, {9, 9, 1}};
   float matrizB[4][4] = {{4, 5, 2, 0}, {2, 1, 0, 0}, {9, 9, 1, 0}, {}};
   int l, c;
   for (l = 0; l < 3; l++)
   {
      for (c = 0; c < 3; c++)
      {
         matrizB[l][3] += matrizA[l][c];
         matrizB[3][l] += matrizA[c][l];
      }
      printf("\nSomatorio da %d linha: %f\n", l + 1, matrizB[l][3]);
      printf("\nSomatorio da %d coluna: %f\n", l + 1, matrizB[3][l]);
   }
}
