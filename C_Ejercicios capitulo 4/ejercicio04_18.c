#include <stdio.h>

int mcd(int a, int b);
int mcm(int a, int b);

int main(void)
{
    int x, y;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &x, &y);

    printf("El MCM es: %d\n", mcm(x, y));

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

int mcm(int a, int b)
{
    return (a * b) / mcd(a, b);
}
