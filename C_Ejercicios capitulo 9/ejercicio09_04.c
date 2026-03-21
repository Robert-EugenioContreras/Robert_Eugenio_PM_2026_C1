#include <stdio.h>

/* Archivos y cadenas de caracteres.
 * El programa lee cadenas de caracteres de un archivo. */

void main(void) {
    char cad[50];
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL) {
        while (!feof(ar)) {
            if (fgets(cad, 50, ar) != NULL) {
                puts(cad);
            }
        }
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}