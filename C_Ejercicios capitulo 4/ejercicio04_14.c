#include <stdio.h>

int contarDigitos(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("Cantidad de digitos: %d\n", contarDigitos(num));

    return 0;
}

int contarDigitos(int n)
{
    int contador = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        n /= 10;
        contador++;
    }

    return contador;
}
