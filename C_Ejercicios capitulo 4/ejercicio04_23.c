#include <stdio.h>

/* Parámetros por referencia y funciones. */

void trueque(int *x, int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

int suma(int x)
{
    return (x + x);
}

int main(void)
{
    int x = 1, y = 2;
    printf("\nValores iniciales: x=%d y=%d", x, y);
    trueque(&x, &y);
    printf("\nValores después del trueque: x=%d y=%d", x, y);
    printf("\nSuma de x: %d", suma(x));
    return 0;
}