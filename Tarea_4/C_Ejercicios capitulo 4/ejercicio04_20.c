#include <stdio.h>

/* Funciones y parámetros. */

int f1(int, int *);

int a = 3;
int b = 7;
int c = 4;
int d = 2;

int main(void)
{
    a = f1(c, &d);
    printf("\n%d %d %d %d", a, b, c, d);
    c = f1(b, &a);
    printf("\n%d %d %d %d", a, b, c, d);
    return 0;
}

int f1(int x, int *y)
{
    int a;
    a = x - *y;
    c++;
    b = b + c;
    *y = a - b;
    printf("\n%d %d %d %d", a, b, c, *y);
    return (a);
}