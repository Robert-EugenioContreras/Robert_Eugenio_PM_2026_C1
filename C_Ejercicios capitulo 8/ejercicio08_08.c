#include <stdio.h>
#include <string.h>

/* Hospital.
 * El programa genera información estadística de los pacientes de un hospital. */

typedef struct {
    char zona[20];
    char condicion[20];
} domicilio; /* Estructura para la ubicación del paciente */

typedef struct {
    int matricula;
    char nombre[20];
    int edad;
    float sueldo;
    domicilio direccion; /* Estructura anidada para datos de residencia */
} paciente;

/* Prototipos de funciones */
void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

void main(void) {
    paciente HOSPITAL[100];
    int TAM;

    do {
        printf("Ingrese el número de pacientes (1-100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1); /* Verifica el rango del arreglo */

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nPaciente %d", I + 1);
        printf("\nMatrícula: ");
        scanf("%d", &A[I].matricula);
        fflush(stdin);
        printf("Nombre: ");
        gets(A[I].nombre);
        printf("Edad: ");
        scanf("%d", &A[I].edad);
        printf("Sueldo (Costo): ");
        scanf("%f", &A[I].sueldo);
        fflush(stdin);
        printf("Zona de residencia: ");
        gets(A[I].direccion.zona);
        printf("Condición médica: ");
        gets(A[I].direccion.condicion);
    }
}

void F1(paciente A[], int T) {
    /* Esta función obtiene el porcentaje de pacientes por condición médica. */
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++) {
        /* Se asume que las condiciones se ingresan como números o etiquetas específicas */
        if (strcmp(A[I].direccion.condicion, "1") == 0) C1++;
        else if (strcmp(A[I].direccion.condicion, "2") == 0) C2++;
        else if (strcmp(A[I].direccion.condicion, "3") == 0) C3++;
        else if (strcmp(A[I].direccion.condicion, "4") == 0) C4++;
        else C5++;
    }
    printf("\nPorcentaje de pacientes por condición:");
    printf("\nCondición 1: %.2f%%", (float)C1 / T * 100);
    printf("\nCondición 2: %.2f%%", (float)C2 / T * 100);
    printf("\nCondición 3: %.2f%%", (float)C3 / T * 100);
    printf("\nCondición 4: %.2f%%", (float)C4 / T * 100);
    printf("\nCondición 5: %.2f%%", (float)C5 / T * 100);
}

void F2(paciente A[], int T) {
    /* Muestra los nombres de pacientes en condición "Grave" (Condición 3). */
    int I;
    printf("\n\nPacientes en condición grave:");
    for (I = 0; I < T; I++) {
        if (strcmp(A[I].direccion.condicion, "3") == 0) {
            puts(A[I].nombre);
        }
    }
}

void F3(paciente A[], int T) {
    /* Calcula el costo promedio de los pacientes de la zona "Sur". */
    int I, C = 0;
    float S = 0.0;
    for (I = 0; I < T; I++) {
        if (strcmp(A[I].direccion.zona, "Sur") == 0) {
            S += A[I].sueldo;
            C++;
        }
    }
    if (C > 0)
        printf("\nCosto promedio zona Sur: %.2f", S / C);
    else
        printf("\nNo hay pacientes en la zona Sur");
}