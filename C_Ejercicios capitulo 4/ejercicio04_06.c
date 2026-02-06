#include <stdio.h>

int factorial(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("El factorial es: %d\n", factorial(num));

    return 0;
}

int factorial(int n)
{
    int i, f = 1;

    for (i = 1; i <= n; i++)
        f *= i;

    return f;
}
