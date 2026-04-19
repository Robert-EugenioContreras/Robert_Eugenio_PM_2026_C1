#include <stdio.h>
#include <string.h>

/* Funciones de la biblioteca string.h para el manejo de cadenas de caracteres. */

int main(void)
{
    char *cad0 = "Hola México";
    char cad1[20], cad2[20], cad3[20] = ", buenos días";

    strcpy(cad1, cad0);     /* Copia cad0 en cad1. */
    printf("\nPrueba de la función strcpy. cad1 es: %s", cad1);

    strcpy(cad1, "Hola Guatemala");
    printf("\nPrueba de la función strcpy. cad1 es: %s", cad1);

    strcpy(cad2, strcat(cad1, cad3));   /* Concatena cad1 con cad3 y el resultado lo copia en cad2. */
    printf("\nPrueba de la función strcat. cad2 es: %s", cad2);

    return 0;
}