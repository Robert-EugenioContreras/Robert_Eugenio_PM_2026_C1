#include <stdio.h>

/* Longitud de cadena. 
El programa calcula la longitud de una cadena de caracteres. */

int cuenta(char *);

int main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);

    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d", i);

    return 0;
}

int cuenta(char *cadena)
{
    int c = 0;
    while (cadena[c] != '\0')
    {
        c++;
    }
    return c;
}