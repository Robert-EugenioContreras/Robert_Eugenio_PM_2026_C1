#include <stdio.h>

/* Archivos y estructuras.
 * El programa escribe estructuras de tipo alumno en un archivo. */

typedef struct {
    int matricula;
    char nombre[20];
    int grado;
    float promedio;
} alumno;

void main(void) {
    int i, n;
    alumno alu;
    FILE *ar;
    if ((ar = fopen("ad1.dat", "w")) != NULL) {
        printf("¿Cuántos alumnos desea ingresar?: ");
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            printf("\nMatrícula: "); scanf("%d", &alu.matricula);
            fflush(stdin);
            printf("Nombre: "); gets(alu.nombre);
            printf("Grado: "); scanf("%d", &alu.grado);
            printf("Promedio: "); scanf("%f", &alu.promedio);
            fprintf(ar, "%d %s %d %.2f\n", alu.matricula, alu.nombre, alu.grado, alu.promedio);
        }
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}