#include <stdio.h>

/* Pares e impares.
El programa, al recibir como datos N números enteros, calcula cuántos
de ellos son pares y cuántos impares, con la ayuda de una función. */

void parimp(int, int *, int *);

int main(void)
{
    int i, n, num, par = 0, imp = 0;
    printf("Ingresa el número de datos: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Ingresa el dato %d: ", i);
        scanf("%d", &num);
        parimp(num, &par, &imp);
    }
    printf("\nNúmero de pares: %d", par);
    printf("\nNúmero de impares: %d", imp);
    return 0;
}

void parimp(int n, int *p, int *i)
{
    if (n % 2 == 0)
        (*p)++;
    else
        (*i)++;
}