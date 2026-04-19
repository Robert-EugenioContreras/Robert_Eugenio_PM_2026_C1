#include <stdio.h>
#include <stdlib.h>

/* Suma y promedio. 
El programa, al recibir una cadena de caracteres que contiene números reales, 
obtiene la suma y el promedio de los mismos. */

int main(void)
{
    char cad[50];
    float sum = 0, pro;
    int i = 0, con = 0;

    printf("\nIngrese la cadena de caracteres (números): ");
    gets(cad);

    while (cad[i] != '\0')
    {
        sum += atof(&cad[i]);
        con++;
        while (cad[i] != ' ' && cad[i] != '\0')
            i++;
        while (cad[i] == ' ' && cad[i] != '\0')
            i++;
    }

    pro = sum / con;
    printf("\nSuma: %.2f", sum);
    printf("\nPromedio: %.2f", pro);

    return 0;
}