#include <stdio.h>

/* Cubo-2.
El programa calcula el cubo de los 10 primeros números naturales con la
ayuda de una función. */

int cubo(int);      /* Prototipo de función. */

int main(void)
{
    int I, CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo(I);      /* Llamada a la función cubo. */
        printf("\nEl cubo de %d es: %d", I, CUB);
    }
    return 0;
}

int cubo(int N)     /* Declaración de la función. */
/* La función calcula el cubo del parámetro N. */
{
    return (N * N * N);
}