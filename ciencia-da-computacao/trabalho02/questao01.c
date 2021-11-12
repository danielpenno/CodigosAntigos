#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float delta(float a, float b, float c)
{
    float d;
    d = b * b - 4 * a * c;
    return (d);
}

int main()
{
    float a, b, c;
    printf("Digite o valor do termo a: ");
    scanf("%f", &a);
    printf("Digite o valor do termo b: ");
    scanf("%f", &b);
    printf("Digite o valor do termo c: ");
    scanf("%f", &c);
    printf("Delta: %f", delta(a, b, c));
    return 0;
}
