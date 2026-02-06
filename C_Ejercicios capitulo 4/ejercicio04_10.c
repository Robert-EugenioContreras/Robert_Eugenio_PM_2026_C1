#include <stdio.h>

float areaCirculo(float r);

int main(void)
{
    float radio;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    printf("El area del circulo es: %.2f\n", areaCirculo(radio));

    return 0;
}

float areaCirculo(float r)
{
    return 3.1416 * r * r;
}

