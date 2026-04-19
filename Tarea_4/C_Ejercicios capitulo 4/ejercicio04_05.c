#include <stdio.h>

/* Parámetros por valor. */

int cubo(int);      /* Prototipo de función. */

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
    {
        printf("\nEl cubo de %d es: %d", I, cubo(I));
    }
    return 0;
}

int cubo(int K)     /* K se recibe por valor. */
{
    K = K * K * K;
    return (K);
}