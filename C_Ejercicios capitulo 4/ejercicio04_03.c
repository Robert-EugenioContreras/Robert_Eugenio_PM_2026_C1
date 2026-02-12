#include <stdio.h>

/* Conflicto de variables con el mismo nombre. */

void f1(void);      /* Prototipo de función. */
int K = 5;          /* Variable global. */

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();
    return 0;
}

void f1(void)
/* La función utiliza dos variables con el mismo nombre, solo que una es global
y la otra local a la función f1. */
{
    int K = 2;      /* Variable local. */
    K += 2;
    printf("\n\nEl valor de la variable local es: %d", K);
    ::K += 2;       /* Uso del operador de resolución de ámbito para acceder a la global. */
    printf("\nEl valor de la variable global es: %d", ::K);
}