#include <stdio.h>
#include <string.h>

/* Otras funciones de la biblioteca string.h para el manejo de cadenas. */

int main(void)
{
    int i;
    char cad0[20] = "Hola México";
    char cad1[20] = "Hola Guatemala";
    char cad2[20] = "Hola El Salvador";
    char cad3[20] = "Hola Honduras";

    i = strcmp(cad0, cad1);
    /* La función strcmp compara dos cadenas y regresa un valor entero. */
    printf("\nResultado de la comparación de cad0 y cad1 (i): %d", i);

    i = strcmp(cad0, cad2);
    printf("\nResultado de la comparación de cad0 y cad2 (i): %d", i);

    i = strcmp(cad0, cad3);
    printf("\nResultado de la comparación de cad0 y cad3 (i): %d", i);

    i = strlen(cad0);
    /* La función strlen regresa la longitud (número de caracteres) de la cadena. */
    printf("\nLongitud de la cadena cad0: %d", i);

    char *ptr = strchr(cad1, 'G');
    /* Regresa un puntero a la primera ocurrencia del caracter 'G' en cad1. */
    if (ptr != NULL)
        printf("\nLa primera ocurrencia de G en cad1 es: %s", ptr);

    ptr = strchr(cad1, 'm');
    if (ptr != NULL)
        printf("\nLa primera ocurrencia de m en cad1 es: %s", ptr);

    return 0;
}