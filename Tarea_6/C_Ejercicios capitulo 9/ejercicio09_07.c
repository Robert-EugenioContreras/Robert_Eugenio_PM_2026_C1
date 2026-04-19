#include <stdio.h>

/* Archivos y estructuras.
 * El programa lee estructuras de tipo alumno de un archivo. */

typedef struct {
    int matricula;
    char nombre[20];
    int grado;
    float promedio;
} alumno;

void main(void) {
    alumno alu;
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r")) != NULL) {
        while (!feof(ar)) {
            fscanf(ar, "%d", &alu.matricula);
            fflush(stdin);
            fgets(alu.nombre, 20, ar); // Usamos fgets para el nombre
            fscanf(ar, "%d %f", &alu.grado, &alu.promedio);
            if (!feof(ar)) {
                printf("\n%d\t%s\t%d\t%.2f", alu.matricula, alu.nombre, alu.grado, alu.promedio);
            }
        }
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}