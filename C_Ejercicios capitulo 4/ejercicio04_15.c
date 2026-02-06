#include <stdio.h>

int invertir(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("Numero invertido: %d\n", invertir(num));

    return 0;
}

int invertir(int n)
{
    int invertido = 0;

    while (n != 0)
    {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }

    return invertido;
}
