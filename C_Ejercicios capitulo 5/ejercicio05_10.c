#include <stdio.h>

/* Búsqueda secuencial en arreglos ordenados en forma creciente */

const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int *, int);
int Busca(int *, int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);   /* Se verifica que el tamaño sea correcto */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);   /* Se llama a la función que busca en el arreglo */

    if (RES)
        printf("\nEl elemento se encuentra en la posicion %d\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo\n");

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

/* Función de búsqueda secuencial para arreglo ordenado */
int Busca(int A[], int T, int E)
{
    int I = 0, BAN = 0, RES;

    while ((I < T) && (E >= A[I]) && !BAN)
    {
        if (A[I] == E)
            BAN = 1;
        else
            I++;
    }

    if (BAN)
        RES = I + 1;   /* Se suma 1 porque las posiciones comienzan desde 0 */
    else
        RES = 0;

    return RES;
}
