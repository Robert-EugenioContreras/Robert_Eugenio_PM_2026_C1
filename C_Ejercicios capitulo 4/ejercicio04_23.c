#include <stdio.h>

int sumaPares(int n);

int main(void)
{
    int n;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("La suma de los pares es: %d\n", sumaPares(n));

    return 0;
}

int sumaPares(int n)
{
    int i, suma = 0;

    for (i = 2; i <= n; i += 2)
        suma += i;

    return suma;
}
