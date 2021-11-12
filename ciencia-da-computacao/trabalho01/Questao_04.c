#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int i, j;
  char c[100] = {}, d[100] = {};
  char p[3][100];
  for (i = 0; i < 3; i++)
  {
    printf("\nDigite a %d palavra: ", i + 1);
    scanf("%s", p[i]);
  }
  for (i = 1; i < 3; i++)
  {
    for (j = 0; j < 3 - 1; j++)
    {
      if (strcmp(p[j], p[j + 1]) > 0)
      {
        strcpy(c, p[j]);
        strcpy(p[j], p[j + 1]);
        strcpy(p[j + 1], c);
      }
    }
  }
  for (i = 0; i < 3; i++)
  {
    strcat(d, p[i]);
    strcat(d, " ");
  }
  printf("\n%s\n", &d);
}
