#include <stdio.h>

/* Funciones y parámetros. */

int z, y;

int f1(float, int *);

int main(void)
{
    int w;
    float x;
    z = 5; y = 7; w = 2; x = 3.3;
    printf("\n%d %d %d %5.2f", z, y, w, x);
    w = f1(x, &z);
    printf("\n%d %d %d %5.2f", z, y, w, x);
    return 0;
}

int f1(float x, int *z)
{
    int k;
    static int y = 2;
    y = y + 3;
    k = x + y;
    *z = k * (*z);
    printf("\n%d %d %d %5.2f", *z, y, k, x);
    return (y);
}