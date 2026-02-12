#include <stdio.h>

/* Funciones y parámetros. */

int a, b, c, d;

void funcion1(int, int *, int *);
int funcion2(int *, int);

int main(void)
{
    int a;
    a = 1; b = 2; c = 3; d = 4;
    printf("\n%d %d %d %d", a, b, c, d);
    funcion1(a, &b, &c);
    printf("\n%d %d %d %d", a, b, c, d);
    a = funcion2(&c, d);
    printf("\n%d %d %d %d", a, b, c, d);
    return 0;
}

void funcion1(int r, int *b, int *c)
{
    int d;
    a = *c;
    d = a + 3 + *b;
    (*b)++;
    (*c) += 2;
    printf("\n%d %d %d %d", a, *b, *c, d);
}

int funcion2(int *c, int d)
{
    int b;
    a++;
    b = 7;
    d += 3;
    (*c) += 2;
    printf("\n%d %d %d %d", a, b, *c, d);
    return (d);
}