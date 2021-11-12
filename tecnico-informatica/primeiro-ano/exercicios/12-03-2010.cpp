#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *valores = NULL;
  int i, pmaior = 0, pmenor = 0, n;
  float media = 0;
  printf("Digite o numero de valores que deseja ler: ");
  scanf("%d", &n);
  valores = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    printf("Digite o valor %d: ", i + 1);
    scanf("%d", &valores[i]);
    media += valores[i];
    if (valores[i] < valores[pmenor])
    {
      pmenor = i;
    }
    if (valores[i] > valores[pmaior])
    {
      pmaior = i;
    }
  }
  media /= n;
  printf("A media dos valores eh %f\n", media);
  printf("O menor valor eh %d\n", valores[pmenor]);
  printf("O maior valor eh %d\n", valores[pmaior]);
  printf("A posicao do menor valor eh %d\n", pmenor + 1);
  printf("A posicao do maior valor eh %d\n", pmaior + 1);
  free(valores);
  system("pause");
}