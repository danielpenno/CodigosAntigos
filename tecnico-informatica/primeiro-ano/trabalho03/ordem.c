// L�gica de Programa��o
// Quest�o 6 - Trabalho III
// Alunos: Dalton Oliveira, Daniel Caio e Gabriel Ai�de

#include <stdio.h>
#include <stdlib.h>

void leitura(float *a, float *b, float *c, int *i)
{
   do
   {
      printf("===============================================================================\n");
      printf("Digite o valor de i: ");
      scanf("%d", i);
      system("cls");
   } while ((*i > 3) || (*i < 1));
   printf("===============================================================================\n");
   printf("Digite o valor de a: ");
   scanf("%f", a);
   system("cls");
   printf("===============================================================================\n");
   printf("Digite o valor de b: ");
   scanf("%f", b);
   system("cls");
   printf("===============================================================================\n");
   printf("Digite o valor de c: ");
   scanf("%f", c);
   system("cls");
}

void verificar_numero(float a, float b, float c, int i)
{
   printf("===============================================================================\n");
   if (i == 1)
   {
      if ((a < b) && (a < c))
      {
         if (b < c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", a, b, c);
            printf("===============================================================================\n");
         }
         if (b > c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", a, c, b);
            printf("===============================================================================\n");
         }
      }
      if ((b < a) && (b < c))
      {
         if (a < c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", b, a, c);
            printf("===============================================================================\n");
         }
         if (a > c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", b, c, a);
            printf("===============================================================================\n");
         }
      }
      if ((c < a) && (c < b))
      {
         if (a < b)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", c, a, b);
            printf("===============================================================================\n");
         }
         if (a > b)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", c, b, a);
            printf("===============================================================================\n");
         }
      }
      if ((a == b) || (a == c) || (c == b))
      {
         printf("ERRO! Digite n�meros diferentes e tente novamente.");
         printf("===============================================================================\n");
      }
   }
   if (i == 2)
   {
      if ((a > b) && (a > c))
      {
         if (b > c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", a, b, c);
            printf("===============================================================================\n");
         }
         if (b < c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", a, c, b);
            printf("===============================================================================\n");
         }
      }
      if ((b > a) && (b > c))
      {
         if (a > c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", b, a, c);
            printf("===============================================================================\n");
         }
         if (a < c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", b, c, a);
            printf("===============================================================================\n");
         }
      }
      if ((c > a) && (c > b))
      {
         if (a > b)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", c, a, b);
            printf("===============================================================================\n");
         }
         if (a < b)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", c, b, a);
            printf("===============================================================================\n");
         }
      }
      if ((a == b) || (a == c) || (c == b))
      {
         printf("ERRO! Digite n�meros diferentes e tente novamente.");
         printf("===============================================================================\n");
      }
   }
   if (i == 3)
   {
      if ((a < b) && (a < c))
      {
         if (b > c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", a, b, c);
            printf("===============================================================================\n");
         }
         if (b < c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", a, c, b);
            printf("===============================================================================\n");
         }
      }
      if ((b < a) && (b < c))
      {
         if (a > c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", b, a, c);
            printf("===============================================================================\n");
         }
         if (a < c)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", b, c, a);
            printf("===============================================================================\n");
         }
      }
      if ((c < a) && (c < b))
      {
         if (a > b)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", c, a, b);
            printf("===============================================================================\n");
         }
         if (a < b)
         {
            printf("A ordem crescente e: %.2f  %.2f  %.2f\n", c, b, a);
            printf("===============================================================================\n");
         }
      }
      if ((a == b) || (a == c) || (c == b))
      {
         printf("ERRO! Digite n�meros diferentes e tente novamente.");
         printf("===============================================================================\n");
      }
   }
}

int main()
{
   float a, b, c;
   int i;
   leitura(&a, &b, &c, &i);
   verificar_numero(a, b, c, i);
   system("pause");
}
