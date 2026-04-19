#include <stdio.h>
#include <string.h>

/* Escuela.
 * El programa genera información importante de los alumnos de una escuela. */

typedef struct {
    char mat[20];   /* Nombre de la materia */
    int pro;        /* Promedio de la materia */
} matpro;

typedef struct {
    int matri;      /* Matrícula */
    char nom[20];   /* Nombre del alumno */
    matpro cal[5];  /* Arreglo de estructuras anidada para 5 materias */
} alumno;

// Prototipos de funciones
void Lectura(alumno *, int);
void F1(alumno *, int);
void F2(alumno *, int);
void F3(alumno *, int);

void main(void) {
    alumno ALU[50];
    int TAM;
    
    do {
        printf("Ingrese el tamaño del arreglo (1-50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1); /* Verifica que el tamaño sea correcto */

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);
}

void Lectura(alumno A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nMatrícula: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);
        printf("Nombre: ");
        gets(A[I].nom);
        
        for (J = 0; J < 5; J++) {
            printf("\tMateria %d: ", J + 1);
            fflush(stdin);
            gets(A[I].cal[J].mat);
            printf("\tPromedio %d: ", J + 1);
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T) {
    /* Esta función obtiene la matrícula y el promedio general de cada alumno. */
    int I, J;
    float SUM;
    for (I = 0; I < T; I++) {
        printf("\nMatrícula del alumno: %d", A[I].matri);
        SUM = 0.0;
        for (J = 0; J < 5; J++) {
            SUM = SUM + A[I].cal[J].pro;
        }
        printf("\tPromedio: %.2f", SUM / 5);
    }
}

void F2(alumno A[], int T) {
    /* Obtiene las matrículas de los alumnos cuya calificación en la tercera materia es > 9. */
    int I;
    printf("\nAlumnos con calificación mayor a 9 en la tercera materia");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2].pro > 9) {
            printf("\nMatrícula del alumno: %d", A[I].matri);
        }
    }
}

void F3(alumno A[], int T) {
    /* Obtiene el promedio general de la cuarta materia. */
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++) {
        SUM = SUM + A[I].cal[3].pro;
    }
    printf("\nPromedio de la cuarta materia: %.2f", SUM / T);
}