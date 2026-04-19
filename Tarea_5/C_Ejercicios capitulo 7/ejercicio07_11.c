#include <stdio.h>
#include <ctype.h>

/* Verifica minúsculas. 
El programa, al recibir una cadena de caracteres, verifica si cada uno de 
sus elementos es una letra minúscula. */

int main(void)
{
    char p, cad[50];
    int n, i = 0;

    printf("\nIngrese la posición del caracter que desea verificar: ");
    scanf("%d", &n);
    printf("Ingrese la cadena de caracteres: ");
    fflush(stdin);
    gets(cad);

    if (n > 0 && n <= 50)
    {
        p = cad[n-1];
        if (islower(p))
            printf("\n%c es una letra minúscula", p);
        else
            printf("\n%c no es una letra minúscula", p);
    }
    else
    {
        printf("\nEl valor ingresado de n es incorrecto");
    }

    return 0;
}