#include <stdio.h>

/* Frecuencia de calificaciones.
   El programa obtiene como datos las calificaciones de un grupo de 50 alumnos,
   obtiene la frecuencia de cada una de las calificaciones y además
   escribe cuál es la frecuencia más alta. */

const int TAM = 50;

/* Prototipos de funciones */
void Lectura(int *, int);
void Frecuencia(int *, int, int *, int);
void Impresion(int *, int);
void Mayor(int *, int);

int main(void)
{
    int CAL[TAM], FRE[6] = {0};   /* Declaración de los arreglos */

    Lectura(CAL, TAM);            /* Se llama a la función Lectura */
    Frecuencia(CAL, TAM, FRE, 6); /* Se llama a la función Frecuencia */

    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);

    Mayor(FRE, 6);

    return 0;
}

/* Función para leer el arreglo de calificaciones */
void Lectura(int VEC[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Ingrese la calificacion 0-5 del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

/* Función para imprimir el arreglo de frecuencias */
void Impresion(int VEC[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("\nFREC[%d]: %d", I, VEC[I]);
    }
}

/* Función que calcula la frecuencia de calificaciones */
void Frecuencia(int A[], int P, int B[], int T)
{
    int I;

    for (I = 0; I < P; I++)
    {
        if (A[I] >= 0 && A[I] < T)   /* Se valida que la calificación sea correcta */
            B[A[I]]++;               /* Se incrementa la frecuencia correspondiente */
    }
}

/* Función que obtiene la primera ocurrencia de la frecuencia más alta */
void Mayor(int X[], int T)
{
    int I, MRE = 0, MVAL = X[0];

    for (I = 1; I < T; I++)
    {
        if (X[I] > MVAL)
        {
            MRE = I;
            MVAL = X[I];
        }
    }

    printf("\n\nMayor frecuencia de calificaciones: %d", MRE);
    printf("\nValor: %d\n", MVAL);
}
