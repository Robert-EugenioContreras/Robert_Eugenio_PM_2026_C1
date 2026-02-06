#include <stdio.h>

int potencia(int base, int exp);

int main(void)
{
    int b, e;

    printf("Ingrese base y exponente: ");
    scanf("%d %d", &b, &e);

    printf("Resultado: %d\n", potencia(b, e));

    return 0;
}

int potencia(int base, int exp)
{
    int i, resultado = 1;

    for (i = 1; i <= exp; i++)
        resultado *= base;

    return resultado;
}
