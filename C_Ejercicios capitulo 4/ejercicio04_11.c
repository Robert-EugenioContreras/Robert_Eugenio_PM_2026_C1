#include <stdio.h>

/* Mayor divisor.
El programa, al recibir como dato un número entero positivo, calcula
su mayor divisor. */

int mad(int);

int main(void)
{
    int num, res;
    printf("\nIngresa el número: ");
    scanf("%d", &num);
    res = mad(num);
    printf("\nEl mayor divisor de %d es: %d", num, res);
    return 0;
}

int mad(int n1)
{
    int i = (n1 / 2);
    while (n1 % i != 0)
        i--;
    return i;
}