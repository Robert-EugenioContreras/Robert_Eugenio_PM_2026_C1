#include <stdio.h>

/* Producto de vectores.
   El programa calcula el producto de dos vectores y almacena el resultado
   en otro arreglo unidimensional. */

const int MAX = 10;

/* Prototipos de funciones */
void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T);
void Producto(int *X, int *Y, int *Z, int T);

int main(void)
{
    int VE1[MAX], VE2[MAX], VE3[MAX];

    /* Se declaran tres arreglos de 10 elementos */

    Lectura(VE1, MAX);
    Lectura(VE2, MAX);

    Producto(VE1, VE2, VE3, MAX);

    printf("\nProducto de los vectores:\n");
    Imprime(VE3, MAX);

    return 0;
}

/* Función para leer un arreglo */
void Lectura(int VEC[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

/* Función para imprimir un arreglo */
void Imprime(int VEC[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("VEC[%d] = %d\n", I, VEC[I]);
    }
}

/* Función para calcular producto de vectores */
void Producto(int *X, int *Y, int *Z, int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        Z[I] = X[I] * Y[I];
    }
}
