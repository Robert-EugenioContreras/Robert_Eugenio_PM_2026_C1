#include <stdio.h>

/* Ordenación por inserción directa */

const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

int main(void)
{
    int TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);   /* Verifica tamaño correcto */

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);
    Imprime(VEC, TAM);

    return 0;
}

/* Función para leer el arreglo */
void Lectura(int A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

/* Función de ordenación por inserción directa */
void Ordena(int A[], int T)
{
    int I, L, AUX;

    for (I = 1; I < T; I++)
    {
        AUX = A[I];
        L = I - 1;

        while ((L >= 0) && (AUX < A[L]))
        {
            A[L + 1] = A[L];
            L--;
        }

        A[L + 1] = AUX;
    }
}

/* Función para imprimir el arreglo ordenado */
void Imprime(int A[], int T)
{
    int I;

    printf("\nArreglo ordenado:\n");

    for (I = 0; I < T; I++)
        printf("A[%d] = %d\n", I, A[I]);
}
