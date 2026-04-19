#include <stdio.h>

/* Archivos con formato. 
 * El programa lee números reales de teclado y los escribe en un archivo.
 * Luego lee los números del archivo y los imprime en pantalla. */

void main(void) {
    int i, n;
    float res;
    FILE *ar;
    if ((ar = fopen("arc.txt", "w")) != NULL) {
        printf("¿Cuántos números reales desea ingresar?: ");
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            printf("Ingrese el número %d: ", i + 1);
            scanf("%f", &res);
            fprintf(ar, "%.2f ", res);
        }
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }

    if ((ar = fopen("arc.txt", "r")) != NULL) {
        printf("\nNúmeros leídos del archivo:\n");
        while (!feof(ar)) {
            fscanf(ar, "%f", &res);
            if (!feof(ar)) printf("%.2f ", res);
        }
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}