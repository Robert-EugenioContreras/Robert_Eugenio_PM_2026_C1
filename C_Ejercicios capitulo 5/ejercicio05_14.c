#include <stdio.h>
#include <math.h>

const int MAX = 100;

void Lectura(int [], int);
float Media(int [], int);
float Varianza(int [], int, float);
float Desviacion(float);
void Frecuencia(int [], int);

int main()
{
    int TAM, VEC[MAX];
    float MED, VAR, DES;
    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX ! TAM < 1);
    
    Lectura(VEC, TAM);
    MED = Media(VEC, TAM);
    VAR = Varianza(VEC, TAM, MED);
    DES = Desviacion(VAR);
    printf("\nMedia: %.2f", MED);
    printf("\nVarianza: %.2f", VAR);
    printf("\nDesviación: %.2f", DES);
    Frecuencia(VEC, TAM);
    
    return 0;
}

void Lectura(int A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

float Media(int A[], int T)
{
    int I;
    float SUM = 0.0;
    for (I=0; I<T; I++)
        SUM += A[I];
    return (SUM / T);
}

float Varianza(int A[], int T, float M)
{
    int I;
    float SUM = 0.0;
    for (I=0; I<T; I++)
        SUM += pow((A[I] - M), 2);
    return (SUM / T);
}

float Desviacion(float V)
{
    return (sqrt(V));
}

void Frecuencia(int A[], int T)
{
    int I, J, SUM;
    for (I=0; I<11; I++)
    {
        SUM = 0;
        for (J=0; J<T; J++)
            if (A[J] == I)
                SUM++;
        printf("\nFrecuencia de %d: %d", I, SUM);
    }
}