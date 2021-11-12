// L�gica de Programa��o
// Quest�o 3 - Trabalho III
// Alunos: Dalton Oliveira, Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

void leitura_leite(float *leite_preco1, float *leite_preco2, float *leite_preco3)
{
    printf("===============================================================================\n");
    printf("Digite o preco do leite longa vida no supermercado O Barateiro(RS): ");
    scanf("%f", leite_preco1);
    printf("Digite o preco do leite longa vida no supermercado Boas Compras(RS): ");
    scanf("%f", leite_preco2);
    printf("Digite o preco do leite longa vida no supermercado Leva Mais(RS): ");
    scanf("%f", leite_preco3);
    printf("===============================================================================\n");
    system("cls");
}

void leitura_achoc(float *achoc_preco1, float *achoc_preco2, float *achoc_preco3)
{
    printf("===============================================================================\n");
    printf("Digite o preco do achocolatado em po no supermercado O Barateiro(RS): ");
    scanf("%f", achoc_preco1);
    printf("Digite o preco do achocolatado em po no supermercado Boas Compras(RS): ");
    scanf("%f", achoc_preco2);
    printf("Digite o preco do achocolatado em po no supermercado Leva Mais(RS): ");
    scanf("%f", achoc_preco3);
    printf("===============================================================================\n");
    system("cls");
}

void leitura_bisc(float *bisc_preco1, float *bisc_preco2, float *bisc_preco3)
{
    printf("===============================================================================\n");
    printf("Digite o preco do biscoito no supermercado O Barateiro(RS): ");
    scanf("%f", bisc_preco1);
    printf("Digite o preco do biscoito no supermercado Boas Compras(RS): ");
    scanf("%f", bisc_preco2);
    printf("Digite o preco do biscoito no supermercado Leva Mais(RS): ");
    scanf("%f", bisc_preco3);
    printf("===============================================================================\n");
    system("cls");
}

void verificar_leite(float leite_preco1, float leite_preco2, float leite_preco3, float *leite_preco, int *leite_merc)
{
    printf("===============================================================================\n");
    if ((leite_preco1 < leite_preco2) && (leite_preco1 < leite_preco3))
    {
        printf("O preco do leite longa vida mais barato esta no supermercado O Barateiro.\n");
        *leite_merc = 1;
        *leite_preco = leite_preco1;
    }
    if ((leite_preco2 < leite_preco1) && (leite_preco2 < leite_preco3))
    {
        printf("O preco do leite longa vida mais barato esta no supermercado Boas Compras.\n");
        *leite_merc = 2;
        *leite_preco = leite_preco2;
    }
    if ((leite_preco3 < leite_preco1) && (leite_preco3 < leite_preco2))
    {
        printf("O preco do leite longa vida mais barato esta no supermercado Leva Mais.\n");
        *leite_merc = 3;
        *leite_preco = leite_preco3;
    }
    if ((leite_preco1 == leite_preco2) && (leite_preco1 < leite_preco3))
    {
        printf("O preco do leite longa vida mais barato esta no supermercado O Barateiro.\n");
        *leite_merc = 1;
        *leite_preco = leite_preco1;
    }
    if ((leite_preco1 == leite_preco3) && (leite_preco1 < leite_preco2))
    {
        printf("O preco do leite longa vida mais barato esta no supermercado O Barateiro.\n");
        *leite_merc = 1;
        *leite_preco = leite_preco1;
    }
    if ((leite_preco2 == leite_preco3) && (leite_preco2 < leite_preco1))
    {
        printf("O preco do leite longa vida mais barato esta no supermercado Boas Compras.\n");
        *leite_merc = 2;
        *leite_preco = leite_preco2;
    }
    if ((leite_preco1 == leite_preco2) && (leite_preco1 == leite_preco3))
    {
        printf("O preco do leite longa vida mais barato esta no supermercado O Barateiro.\n");
        *leite_merc = 1;
        *leite_preco = leite_preco1;
    }
}

void verificar_achoc(float achoc_preco1, float achoc_preco2, float achoc_preco3, float *achoc_preco, int *achoc_merc)
{
    printf("===============================================================================\n");
    if ((achoc_preco1 < achoc_preco2) && (achoc_preco1 < achoc_preco3))
    {
        printf("O preco do achocolatado em po mais barato esta no supermercado O Barateiro.\n");
        *achoc_merc = 1;
        *achoc_preco = achoc_preco1;
    }
    if ((achoc_preco2 < achoc_preco1) && (achoc_preco2 < achoc_preco3))
    {
        printf("O preco do achocolatado em po mais barato esta no supermercado Boas Compras.\n");
        *achoc_merc = 2;
        *achoc_preco = achoc_preco2;
    }
    if ((achoc_preco3 < achoc_preco1) && (achoc_preco3 < achoc_preco2))
    {
        printf("O preco do achocolatado em po mais barato esta no supermercado Leva Mais.\n");
        *achoc_merc = 3;
        *achoc_preco = achoc_preco3;
    }
    if ((achoc_preco1 == achoc_preco2) && (achoc_preco1 < achoc_preco3))
    {
        printf("O preco do achocolatado em po mais barato esta no supermercado O Barateiro.\n");
        *achoc_merc = 1;
        *achoc_preco = achoc_preco1;
    }
    if ((achoc_preco1 == achoc_preco3) && (achoc_preco1 < achoc_preco2))
    {
        printf("O preco do achocolatado em po mais barato esta no supermercado O Barateiro.\n");
        *achoc_merc = 1;
        *achoc_preco = achoc_preco1;
    }
    if ((achoc_preco2 == achoc_preco3) && (achoc_preco2 < achoc_preco1))
    {
        printf("O preco do achocolatado em po mais barato esta no supermercado Boas Compras.\n");
        *achoc_merc = 2;
        *achoc_preco = achoc_preco2;
    }
    if ((achoc_preco1 == achoc_preco2) && (achoc_preco1 == achoc_preco3))
    {
        printf("O preco do achocolatado em po mais barato esta no supermercado O Barateiro.\n");
        *achoc_merc = 1;
        *achoc_preco = achoc_preco1;
    }
}

void verificar_bisc(float bisc_preco1, float bisc_preco2, float bisc_preco3, float *bisc_preco, int *bisc_merc)
{
    printf("===============================================================================\n");
    if ((bisc_preco1 < bisc_preco2) && (bisc_preco1 < bisc_preco3))
    {
        printf("O preco do biscoito mais barato esta no supermercado O Barateiro.\n");
        *bisc_merc = 1;
        *bisc_preco = bisc_preco1;
    }
    if ((bisc_preco2 < bisc_preco1) && (bisc_preco2 < bisc_preco3))
    {
        printf("O preco do biscoito mais barato esta no supermercado Boas Compras.\n");
        *bisc_merc = 2;
        *bisc_preco = bisc_preco2;
    }
    if ((bisc_preco3 < bisc_preco1) && (bisc_preco3 < bisc_preco2))
    {
        printf("O preco do biscoito mais barato esta no supermercado Leva Mais.\n");
        *bisc_merc = 3;
        *bisc_preco = bisc_preco3;
    }
    if ((bisc_preco1 == bisc_preco2) && (bisc_preco1 < bisc_preco3))
    {
        printf("O preco do biscoito mais barato esta no supermercado O Barateiro.\n");
        *bisc_merc = 1;
        *bisc_preco = bisc_preco1;
    }
    if ((bisc_preco1 == bisc_preco3) && (bisc_preco1 < bisc_preco2))
    {
        printf("O preco do biscoito mais barato esta no supermercado O Barateiro.\n");
        *bisc_merc = 1;
        *bisc_preco = bisc_preco1;
    }
    if ((bisc_preco2 == bisc_preco3) && (bisc_preco2 < bisc_preco1))
    {
        printf("O preco do biscoito mais barato esta no supermercado Boas Compras.\n");
        *bisc_merc = 2;
        *bisc_preco = bisc_preco2;
    }
    if ((bisc_preco1 == bisc_preco2) && (bisc_preco1 == bisc_preco3))
    {
        printf("O preco do biscoito mais barato esta no supermercado O Barateiro.\n");
        *bisc_merc = 1;
        *bisc_preco = bisc_preco1;
    }
}

void gerar_total(int leite_merc, int achoc_merc, int bisc_merc, float leite_preco, float achoc_preco, float bisc_preco)
{
    float total, total2, desconto;
    printf("===============================================================================\n");
    total = (12 * leite_preco) + (achoc_preco) + (20 * bisc_preco);
    printf("Total das compras: RS%.2f\n", total);
    if ((leite_merc == 1) && (achoc_merc == 1) && (bisc_merc == 1))
    {
        printf("===============================================================================\n");
        desconto = (total / 100) * 10;
        total2 = total - desconto;
        printf("Voce comprou todos os prod. no mesmo sup., entao voce possui 10\%% de desconto.\n");
        printf("Total com 10\%% de desconto: RS%.2f\n", total2);
    }
    if ((leite_merc == 2) && (achoc_merc == 2) && (bisc_merc == 2))
    {
        printf("===============================================================================\n");
        desconto = (total / 100) * 10;
        total2 = total - desconto;
        printf("Voce comprou todos os prod. no mesmo sup., entao voce possui 10\%% de desconto.\n");
        printf("Total com 10\%% de desconto: RS%.2f\n", total2);
    }
    if ((leite_merc == 3) && (achoc_merc == 3) && (bisc_merc == 3))
    {
        printf("===============================================================================\n");
        desconto = (total / 100) * 10;
        total2 = total - desconto;
        printf("Voce comprou todos os prod. no mesmo sup., entao voce possui 10\%% de desconto.\n");
        printf("Total com 10\%% de desconto: RS%.2f\n", total2);
    }
    printf("===============================================================================\n");
}

int main()
{
    float leite_preco1, leite_preco2, leite_preco3;
    float achoc_preco1, achoc_preco2, achoc_preco3;
    float bisc_preco1, bisc_preco2, bisc_preco3;
    float leite_preco, achoc_preco, bisc_preco;
    int leite_merc, achoc_merc, bisc_merc;
    leitura_leite(&leite_preco1, &leite_preco2, &leite_preco3);
    leitura_achoc(&achoc_preco1, &achoc_preco2, &achoc_preco3);
    leitura_bisc(&bisc_preco1, &bisc_preco2, &bisc_preco3);
    verificar_leite(leite_preco1, leite_preco2, leite_preco3, &leite_preco, &leite_merc);
    verificar_achoc(achoc_preco1, achoc_preco2, achoc_preco3, &achoc_preco, &achoc_merc);
    verificar_bisc(bisc_preco1, bisc_preco2, bisc_preco3, &bisc_preco, &bisc_merc);
    gerar_total(leite_merc, achoc_merc, bisc_merc, leite_preco, achoc_preco, bisc_preco);
    system("pause");
}
