#include <stdio.h>

int suma(int a, int b);

int main(void)
{
    int x, y;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &x, &y);

    printf("La suma es: %d\n", suma(x, y));

    return 0;
}

int suma(int a, int b)
{
    return a + b;
}
