#include <stdio.h>

/* Conteo de caracteres.
 * El programa cuenta el número de caracteres que tiene un archivo. */

void main(void) {
    char p1;
    int con = 0;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL) {
        while (!feof(ar)) {
            p1 = getc(ar);
            if (!feof(ar)) con++;
        }
        fclose(ar);
        printf("\nNúmero de caracteres en el archivo: %d", con);
    } else {
        printf("No se pudo abrir el archivo");
    }
}