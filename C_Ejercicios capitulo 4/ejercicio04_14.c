#include <stdio.h>

/* Rango de calificaciones.
El programa, al recibir como dato las calificaciones de una lista de alumnos,
calcula cuántas de ellas caen en tres rangos de calificación. */

void rango(int, int *, int *, int *);

int main(void)
{
    int i, n, cal, r1 = 0, r2 = 0, r3 = 0;
    printf("Ingresa el número de calificaciones: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Ingresa la calificación %d: ", i);
        scanf("%d", &cal);
        rango(cal, &r1, &r2, &r3);
    }
    printf("\n0..3.99: %d", r1);
    printf("\n4..5.99: %d", r2);
    printf("\n6..10: %d", r3);
    return 0;
}

void rango(int c, int *a, int *b, int *d)
{
    if (c < 4)
        (*a)++;
    else if (c < 6)
        (*b)++;
    else
        (*d)++;
}