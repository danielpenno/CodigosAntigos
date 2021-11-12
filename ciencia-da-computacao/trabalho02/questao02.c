#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float delta(float a, float b, float c)
{
    float d;
    d = b * b - 4 * a * c;
    return (d);
}

void xs(float *x1, float *x2, float a, float b, float delta2)
{
    *x1 = (-b + sqrt(delta2)) / (2 * a);
    *x2 = (-b - sqrt(delta2)) / (2 * a);
}

int main()
{
    float a, b, c, delta2, x1, x2;
    printf("Digite o valor do termo a: ");
    scanf("%f", &a);
    printf("Digite o valor do termo b: ");
    scanf("%f", &b);
    printf("Digite o valor do termo c: ");
    scanf("%f", &c);
    delta2 = delta(a, b, c);
    xs(&x1, &x2, a, b, delta2);
    printf("x1: %.2f", x1);
    printf("\nx2: %.2f", x2);
    return 0;
}
