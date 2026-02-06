#include <stdio.h>

int sumaN(int n);

int main(void)
{
    int n;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("La suma es: %d\n", sumaN(n));

    return 0;
}

int sumaN(int n)
{
    int i, suma = 0;

    for (i = 1; i <= n; i++)
        suma += i;

    return suma;
}
