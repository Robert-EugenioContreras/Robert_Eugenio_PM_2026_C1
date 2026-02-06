#include <stdio.h>

float promedio(float a, float b, float c);

int main(void)
{
    float x, y, z;

    printf("Ingrese tres numeros: ");
    scanf("%f %f %f", &x, &y, &z);

    printf("El promedio es: %.2f\n", promedio(x, y, z));

    return 0;
}

float promedio(float a, float b, float c)
{
    return (a + b + c) / 3;
}
