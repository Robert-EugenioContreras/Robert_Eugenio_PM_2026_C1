#include <stdio.h>

/* Incrementa grados.
 * El programa lee estructuras de tipo alumno de un archivo, incrementa el grado
 * y escribe las estructuras en otro archivo. */

typedef struct {
    int matricula;
    char nombre[20];
    int grado;
    float promedio;
} alumno;

void main(void) {
    alumno alu;
    FILE *ar1, *ar2;
    if (((ar1 = fopen("ad1.dat", "r")) != NULL) && ((ar2 = fopen("ad2.dat", "w")) != NULL)) {
        while (!feof(ar1)) {
            fscanf(ar1, "%d", &alu.matricula);
            fflush(stdin);
            fgets(alu.nombre, 20, ar1);
            fscanf(ar1, "%d %f", &alu.grado, &alu.promedio);
            if (!feof(ar1)) {
                alu.grado++;
                fprintf(ar2, "%d %s %d %.2f\n", alu.matricula, alu.nombre, alu.grado, alu.promedio);
            }
        }
        fclose(ar1);
        fclose(ar2);
    } else {
        printf("No se pudieron abrir los archivos");
    }
}