#include <stdio.h>

/* Lluvias.
El programa, al recibir como datos las lluvias diarias del mes de agosto,
calcula el promedio del mes y determina los días con mayor y menor lluvia. */

void mayor(float, int);
void menor(float, int);

float gmay = -1.0;
float gmen = 1000.0;
int dmay, dmen;

int main(void)
{
    float llu, sum = 0.0;
    int i;
    for (i = 1; i <= 31; i++)
    {
        printf("Ingresa la lluvia del día %d: ", i);
        scanf("%f", &llu);
        sum += llu;
        mayor(llu, i);
        menor(llu, i);
    }
    printf("\nPromedio de lluvias en agosto: %5.2f", sum / 31);
    printf("\nMayor lluvia: %5.2f \tDía: %d", gmay, dmay);
    printf("\nMenor lluvia: %5.2f \tDía: %d", gmen, dmen);
    return 0;
}

void mayor(float m1, int d)
{
    if (gmay < m1)
    {
        gmay = m1;
        dmay = d;
    }
}

void menor(float m1, int d)
{
    if (gmen > m1)
    {
        gmen = m1;
        dmen = d;
    }
}