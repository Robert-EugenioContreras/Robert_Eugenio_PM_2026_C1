#include <stdio.h>
#include <stdlib.h>

/* Funciones para el manejo de caracteres.
El programa utiliza funciones de la biblioteca stdlib.h para convertir
cadenas de caracteres a números. */

int main(void)
{
    union {
        int i;
        double d;
    } num;

    char cad1[20], cad2[20];

    printf("\nIngrese una cadena de caracteres (numeros enteros): ");
    gets(cad1);
    num.i = atoi(cad1);   /* Convierte cadena a entero. */
    printf("\nValor entero: %d", num.i);

    printf("\nIngrese una cadena de caracteres (numeros reales): ");
    gets(cad2);
    num.d = atof(cad2);   /* Convierte cadena a real (double). */
    printf("\nValor real: %.2f\n", num.d);

    return 0;
}