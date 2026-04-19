#include <stdio.h>

/* Múltiplo.
El programa, al recibir como datos dos números enteros, determina si
el segundo es múltiplo del primero. */

int multiplo(int, int);

int main(void)
{
    int nu1, nu2;
    printf("\nIngresa los dos números: ");
    scanf("%d %d", &nu1, &nu2);
    if (multiplo(nu1, nu2))
        printf("\nEl segundo número es múltiplo del primero");
    else
        printf("\nEl segundo número no es múltiplo del primero");
    return 0;
}

int multiplo(int n1, int n2)
{
    int res;
    if ((n2 % n1) == 0)
        res = 1;
    else
        res = 0;
    return (res);
}