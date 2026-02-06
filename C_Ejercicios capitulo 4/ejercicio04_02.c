#include <stdio.h>

int cuadrado(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("El cuadrado es: %d\n", cuadrado(num));

    return 0;
}

int cuadrado(int n)
{
    return n * n;
}
