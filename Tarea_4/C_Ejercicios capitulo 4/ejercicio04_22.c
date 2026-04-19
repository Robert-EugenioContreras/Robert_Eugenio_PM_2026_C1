#include <stdio.h>

/* Funciones y parámetros. */

int a, b, c, d;

int pal(int, int);

int main(void)
{
    a = 2; c = 3; d = 5;
    a = pal(c, d);
    printf("\n%d %d %d %d", a, b, c, d);
    b = pal(c, a);
    printf("\n%d %d %d %d", a, b, c, d);
    return 0;
}

int pal(int x, int y)
{
    int c;
    b = x * y;
    c = b + y;
    x++;
    y = y * (y + 1);
    printf("\n%d %d %d %d", b, c, x, y);
    return (x);
}