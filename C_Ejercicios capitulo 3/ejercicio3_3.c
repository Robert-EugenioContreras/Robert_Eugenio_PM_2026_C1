#include <stdio.h>

int main(void)
{
    int cont = 0;
    float cal, suma = 0;

    printf("Ingrese una calificacion (-1 para terminar): ");
    scanf("%f", &cal);

    while (cal != -1)
    {
        suma += cal;
        cont++;

        printf("Ingrese otra calificacion (-1 para terminar): ");
        scanf("%f", &cal);
    }

    if (cont > 0)
        printf("Promedio: %.2f\n", suma / cont);
    else
        printf("No se ingresaron calificaciones\n");

    return 0;
}
