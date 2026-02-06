#include <stdio.h>

int esPrimo(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (esPrimo(num))
        printf("El numero es primo\n");
    else
        printf("El numero no es primo\n");

    return 0;
}

int esPrimo(int n)
{
    int i;

    if (n <= 1)
        return 0;

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}
