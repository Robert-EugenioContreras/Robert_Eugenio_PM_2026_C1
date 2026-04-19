#include <stdio.h>

/* Funciones para el manejo de caracteres. 
El programa, al recibir caracteres de la entrada estándar, utiliza diferentes 
funciones de la biblioteca stdio.h para manejarlos. */

int main(void)
{
    char p1, p2, p3 = '$';
    /* p3 se inicializa con el caracter '$'. */

    printf("\nIngrese un caracter: ");
    p1 = getchar();     /* Se utiliza la función getchar para leer un caracter. */
    putchar(p1);        /* Se utiliza la función putchar para escribir un caracter. */
    printf("\n");

    fflush(stdin);

    printf("\nIngrese otro caracter: ");
    fflush(stdin);
    scanf("%c", &p2);   /* Se utiliza scanf con el formato %c para leer un caracter. */
    printf("%c", p2);   /* Se utiliza printf con el formato %c para escribir un caracter. */
    printf("\n");

    putchar(p3);        /* Finalmente se escribe el caracter almacenado en p3. */
    printf("\n");

    return 0;
}