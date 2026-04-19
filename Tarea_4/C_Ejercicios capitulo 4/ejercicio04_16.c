#include <stdio.h>
#include <math.h>

/* Temperaturas.
El programa, al recibir como datos 24 temperaturas de un día, calcula el
promedio y determina las temperaturas máxima y mínima. */

void acutem(float);
void maxima(float, int);
void minima(float, int);

float sum = 0.0;
float max = -100.0;
float min = 100.0;
int hmax, hmin;

int main(void)
{
    float tem;
    int i;
    for (i = 1; i <= 24; i++)
    {
        printf("Ingresa la temperatura de la hora %d: ", i);
        scanf("%f", &tem);
        acutem(tem);
        maxima(tem, i);
        minima(tem, i);
    }
    printf("\nPromedio del día: %5.2f", sum / 24);
    printf("\nMáxima del día: %5.2f \tHora: %d", max, hmax);
    printf("\nMínima del día: %5.2f \tHora: %d", min, hmin);
    return 0;
}

void acutem(float t)
{
    sum += t;
}

void maxima(float t, int h)
{
    if (max < t)
    {
        max = t;
        hmax = h;
    }
}

void minima(float t, int h)
{
    if (min > t)
    {
        min = t;
        hmin = h;
    }
}