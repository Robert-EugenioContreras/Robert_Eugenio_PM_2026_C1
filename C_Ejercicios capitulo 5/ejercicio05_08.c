#include <stdio.h>

/* Primos.
   El programa almacena en un arreglo unidimensional
   los primeros 100 números primos. */

const int TAM = 100;

void Imprime(int, int *);
void Primo(int, int *);

int main(void)
{
    int P[TAM] = {2};
    int I, J = 1, PRI = 3;
    int FLA;

    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);

        if (FLA == 1)
        {
            P[J] = PRI;
            J++;
        }

        PRI += 2;
    }

    Imprime(TAM, P);

    return 0;
}

void Primo(int A, int *B)
{
    int DI = 3;

    while (*B && (DI <= (A / 2)))
    {
        if (A % DI == 0)
            *B = 0;

        DI++;
    }
}

void Imprime(int T, int Primos[])
{
    int I;

    for (I = 0; I < T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}
