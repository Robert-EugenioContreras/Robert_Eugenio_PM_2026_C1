#include <stdio.h>
#include <math.h>

int esArmstrong(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (esArmstrong(num))
        printf("El numero es Armstrong\n");
    else
        printf("El numero no es Armstrong\n");

    return 0;
}

int esArmstrong(int n)
{
    int original = n, digitos = 0;
    int suma = 0;

    while (n != 0)
    {
        digitos++;
        n /= 10;
    }

    n = original;

    while (n != 0)
    {
        suma += pow(n % 10, digitos);
        n /= 10;
    }

    return suma == original;
}
