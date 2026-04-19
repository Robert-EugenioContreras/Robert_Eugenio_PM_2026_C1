#include <stdio.h>

/* Parámetros y funciones. */

int f1(void);
int f2(void);

int a = 1, b = 2, c = 3, d = 4;

int main(void)
{
    int a;
    a = f1();
    printf("\n%d %d %d %d", a, b, c, d);
    a = f2();
    printf("\n%d %d %d %d", a, b, c, d);
    return 0;
}

int f1(void)
{
    int b, c;
    b = a + 1;
    c = b + 1;
    d = c + 1;
    return (a);
}

int f2(void)
{
    static int c = 10;
    c++;
    b = 20;
    return (a);
}