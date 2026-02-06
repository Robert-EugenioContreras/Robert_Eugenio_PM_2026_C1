#include <stdio.h>

int mcd(int a, int b);

int main(void)
{
    int x, y;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &x, &y);

    printf("El MCD es: %d\n", mcd(x, y));

    return 0;
}

int mcd(int a, int b)
{
    int r;

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}
