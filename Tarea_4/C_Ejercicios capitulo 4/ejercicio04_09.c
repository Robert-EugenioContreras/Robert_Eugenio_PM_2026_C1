#include <stdio.h>

/* Paso de una función como parámetro por referencia. */

int suma(int, int);
int resta(int, int);
int control(int (*)(int, int), int, int);

int main(void)
{
    int v1 = 5, v2 = 3;
    printf("\nSuma: %d", control(suma, v1, v2));
    printf("\nResta: %d", control(resta, v1, v2));
    return 0;
}

int suma(int x, int y)
{
    return (x + y);
}

int resta(int x, int y)
{
    return (x - y);
}

int control(int (*f)(int, int), int x, int y)
{
    return ((*f)(x, y));
}