#include <stdio.h>

/* Archivos y cadenas de caracteres.
 * El programa escribe cadenas de caracteres en un archivo. */

void main(void) {
    char cad[50];
    FILE *ar;
    if ((ar = fopen("arc.txt", "w")) != NULL) {
        printf("Ingrese una cadena de caracteres: ");
        gets(cad);
        fputs(cad, ar);
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}