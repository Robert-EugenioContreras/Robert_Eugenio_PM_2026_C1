#include <stdio.h>

int mayor(int a, int b);

int main(void)
{
    int x, y;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &x, &y);

    printf("El mayor es: %d\n", mayor(x, y));

    return 0;
}

int mayor(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
