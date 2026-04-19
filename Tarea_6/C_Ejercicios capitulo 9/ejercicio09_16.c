#include <stdio.h>

/* Suma reales.
   El programa, al recibir como dato un archivo de texto que contiene 
   números reales, calcula la suma de los mismos. */

void sumareal(FILE *);          /* Prototipo de función. */

int main(void)
{
    FILE *ar;
    if ((ar = fopen("arc2.txt", "r")) != NULL)
    {
        sumareal(ar);
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void sumareal(FILE *ap1)
/* Esta función lee números reales de un archivo y calcula su suma. */
{
    float sum = 0.0, r;
    while (!feof(ap1))
    {
        fscanf(ap1, "%f", &r);
        if (!feof(ap1))
            sum = sum + r;
    }
    printf("\nLa suma es: %.2f", sum);
}