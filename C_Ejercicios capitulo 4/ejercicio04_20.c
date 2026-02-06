#include <stdio.h>

int esPerfecto(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (esPerfecto(num))
        printf("El numero es perfecto\n");
    else
        printf("El numero no es perfecto\n");

    return 0;
}

int esPerfecto(int n)
{
    int i, suma = 0;

    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
            suma += i;
    }

    return suma == n;
}
