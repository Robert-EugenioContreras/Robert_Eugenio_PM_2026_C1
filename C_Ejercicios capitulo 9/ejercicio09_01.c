#include <stdio.h>

/* Archivos y caracteres.
 * El programa lee caracteres de un archivo. */

void main(void) {
    char p1;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL) { /* Abre para lectura */
        while (!feof(ar)) { /* Mientras no sea el fin del archivo */
            p1 = getc(ar);
            putchar(p1);
        }
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}