#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;
    printf("1 - DEPOSITAR\n");
    printf("2 - SACAR\n");
    printf("3 - ENCERRAR CONTA\n");
    printf("Digite a opcao que voce deseja utilizar: ");
    scanf("%d", &opcao);
    while (opcao != 3)
    {
        printf("%d", opcao);

        return (0);
    }
}
