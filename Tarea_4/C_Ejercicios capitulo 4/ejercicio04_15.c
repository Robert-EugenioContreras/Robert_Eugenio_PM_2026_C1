#include <stdio.h>

/* Productoria.
El programa calcula la productoria de los N primeros números naturales. */

int productoria(int);

int main(void)
{
    int n;
    printf("Ingresa el número de datos: ");
    scanf("%d", &n);
    if (n > 0)
        printf("\nLa productoria de %d es: %d", n, productoria(n));
    else
        printf("\nEl dato ingresado es incorrecto");
    return 0;
}

int productoria(int n)
{
    int i, pro = 1;
    for (i = 1; i <= n; i++)
        pro *= i;
    return pro;
}