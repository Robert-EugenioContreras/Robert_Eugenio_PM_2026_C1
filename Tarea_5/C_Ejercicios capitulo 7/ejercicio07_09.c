#include <stdio.h>

/* Cuenta caracteres. 
El programa, al recibir una cadena de caracteres y un caracter, determina 
cuántas veces se encuentra el caracter en la cadena. */

int cuenta(char *, char);

int main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    printf("Ingrese el caracter: ");
    car = getchar();

    res = cuenta(cad, car);
    printf("\n\nEl caracter %c se encuentra %d veces en la cadena %s", car, res, cad);

    return 0;
}

int cuenta(char *cad, char car)
{
    int i = 0, con = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == car)
            con++;
        i++;
    }
    return con;
}