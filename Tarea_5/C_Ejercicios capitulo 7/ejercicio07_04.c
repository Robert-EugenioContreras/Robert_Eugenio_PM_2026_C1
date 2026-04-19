#include <stdio.h>

/* Declaración de cadenas de caracteres y asignación de valores. */

int main(void)
{
    char *cad0;
    cad0 = "Argentina";     /* Correcto. */
    puts(cad0);

    cad0 = "Brasil";        /* Correcto. */
    puts(cad0);

    /* char *cad1;
    gets(cad1); */          /* Error. No se ha reservado memoria para cad1. */

    char cad2[20] = "Mexico"; /* Correcto. */
    puts(cad2);

    /* cad2 = "Guatemala"; */  /* Error. No se puede asignar una cadena a un arreglo de esta forma. */

    return 0;
}