#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas. 
El programa, al recibir n cadenas de caracteres, determina el número de 
letras minúsculas y mayúsculas que contiene cada una. */

void minumay(char *cad);    /* Prototipo de función. */

int main(void)
{
    int i, n;
    char FRA[30];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        fflush(stdin);
        gets(FRA);
        minumay(FRA);
    }

    return 0;
}

void minumay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;
    while (cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;
        i++;
    }
    printf("\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d\n", ma);
}