#include <stdio.h>

/* Parámetros por referencia. */

void f1(int *);     /* Prototipo de función. */

int main(void)
{
    int I = 2;
    printf("\nEl valor de I antes de la llamada a la función: %d", I);
    f1(&I);         /* Se envía la dirección de la variable I. */
    printf("\nEl valor de I después de la llamada a la función: %d", I);
    return 0;
}

void f1(int *R)
/* La función f1 recibe un parámetro por referencia a través de un puntero. */
{
    *R = *R * *R;
}