#include <stdio.h>

int sumaDigitos(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("Suma de los digitos: %d\n", sumaDigitos(num));

    return 0;
}

int sumaDigitos(int n)
{
    int suma = 0;

    while (n != 0)
    {
        suma += n % 10;
        n /= 10;
    }

    return suma;
}
