#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, total = 0;
  float n;
  printf("Digite o valor de n: ");
  scanf("%f", &n);
  if (n > 0)
  {
    for (i = n - 1; i != 0; i--)
    {
      total += i;
    }
    printf("%d", total);
  }
}
