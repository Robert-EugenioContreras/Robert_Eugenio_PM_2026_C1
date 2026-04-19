#include <stdio.h>

typedef struct {
    int matricula;
    char nombre[20];
    int grado;
    float promedio;
} alumno;

void lee(FILE *);

void main(void) {
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r")) != NULL) {
        lee(ar);
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}

void lee(FILE *ap) {
    alumno alu;
    while (!feof(ap)) {
        fscanf(ap, "%d", &alu.matricula);
        fflush(stdin);
        fgets(alu.nombre, 20, ap);
        fscanf(ap, "%d %f", &alu.grado, &alu.promedio);
        if (!feof(ap)) {
            printf("\n%d\t%s\t%d\t%.2f", alu.matricula, alu.nombre, alu.grado, alu.promedio);
        }
    }
}