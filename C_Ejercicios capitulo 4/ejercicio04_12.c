#include <stdio.h>

/* Máximo común divisor.
El programa, al recibir como datos dos números enteros, calcula el máximo
común divisor de dichos números. */

int mcd(int, int);

int main(void)
{
    int nu1, nu2, res;
    printf("\nIngresa los dos números: ");
    scanf("%d %d", &nu1, &nu2);
    res = mcd(nu1, nu2);
    printf("\nEl máximo común divisor de %d y %d es: %d", nu1, nu2, res);
    return 0;
}

int mcd(int n1, int n2)
{
    int i;
    if (n1 < n2)
        i = n1 / 2;
    else
        i = n2 / 2;
    while ((n1 % i != 0) || (n2 % i != 0))
        i--;
    return i;
}