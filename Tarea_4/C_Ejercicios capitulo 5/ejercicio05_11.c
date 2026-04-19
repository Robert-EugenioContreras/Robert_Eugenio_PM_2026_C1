#include <stdio.h>

/* Búsqueda binaria */

const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int *, int);
int Binaria(int *, int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);   /* Se verifica que el tamaño del arreglo sea correcto */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);   /* Se llama a la función que busca en el arreglo */

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

/* Función de búsqueda binaria */
int Binaria(int A[], int T, int E)
{
    int IZQ = 0, DER = T - 1, CEN, BAN = 0;

    while ((IZQ <= DER) && !BAN)
    {
        CEN = (IZQ + DER) / 2;

        if (E == A[CEN])
            BAN = CEN + 1;   /* Se suma 1 porque las posiciones comienzan en 0 */
        else
            if (E > A[CEN])
                IZQ = CEN + 1;
            else
                DER = CEN - 1;
    }

    return BAN;   /* Regresa 0 si no lo encuentra */
}
