#include <stdio.h>
#include <string.h>

/* Escuela.
 * El programa genera información estadística de los alumnos de una escuela. */

typedef struct {
    int matricula;
    char nombre[30];
    float cal[5]; // Arreglo dentro de la estructura
} alumno;

void Lectura(alumno A[], int T);
void F1(alumno A[], int T);
void F2(alumno A[], int T);
void F3(alumno alumno A[], int T);

void main(void) {
    alumno ARRE[50];
    int TAM;
    do {
        printf("Ingrese el tamaño del arreglo (1-50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(ARRE, TAM);
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);
}

void Lectura(alumno A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nMatricula: ");
        scanf("%d", &A[I].matricula);
        fflush(stdin);
        printf("Nombre: ");
        gets(A[I].nombre);
        for (J = 0; J < 5; J++) {
            printf("\tCalificacion %d: ", J + 1);
            scanf("%f", &A[I].cal[J]);
        }
    }
}

void F1(alumno A[], int T) {
    int I, J;
    float SUM, PRO;
    for (I = 0; I < T; I++) {
        printf("\nMatricula: %d", A[I].matricula);
        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM = SUM + A[I].cal[J];
        PRO = SUM / 5;
        printf("\tPromedio: %.2f", PRO);
    }
}

void F2(alumno A[], int T) {
    int I;
    printf("\nAlumnos con calificacion en la tercera materia > 9");
    for (I = 0; I < T; I++)
        if (A[I].cal[2] > 9)
            printf("\nMatricula: %d", A[I].matricula);
}

void F3(alumno A[], int T) {
    int I;
    float SUM = 0.0, PRO;
    for (I = 0; I < T; I++)
        SUM = SUM + A[I].cal[3];
    PRO = SUM / T;
    printf("\nPromedio de la materia 4: %.2f", PRO);
}