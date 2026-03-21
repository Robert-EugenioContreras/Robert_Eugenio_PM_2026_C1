#include <stdio.h>

typedef struct {
    int matricula;
    char nombre[20];
    int grado;
    float promedio;
} alumno;

void escribe(FILE *); /* Prototipo */

void main(void) {
    FILE *ar;
    if ((ar = fopen("ad1.dat", "w")) != NULL) {
        escribe(ar);
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}

void escribe(FILE *ap) {
    alumno alu;
    int i = 0, n;
    printf("¿Cuántos alumnos desea ingresar?: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nMatrícula: "); scanf("%d", &alu.matricula);
        fflush(stdin);
        printf("Nombre: "); gets(alu.nombre);
        printf("Grado: "); scanf("%d", &alu.grado);
        printf("Promedio: "); scanf("%f", &alu.promedio);
        fprintf(ap, "%d %s %d %.2f\n", alu.matricula, alu.nombre, alu.grado, alu.promedio);
    }
}