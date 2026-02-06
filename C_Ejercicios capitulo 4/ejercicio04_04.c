#include <stdio.h>

int esPar(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (esPar(num))
        printf("El numero es par\n");
    else
        printf("El numero es impar\n");

    return 0;
}

int esPar(int n)
{
    return n % 2 == 0;
}
