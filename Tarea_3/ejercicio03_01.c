#include <stdio.h>

int main(void)
{
    int i;
    float sal, nom = 0;

    for (i = 1; i <= 15; i++)
    {
        printf("Ingrese el salario del profesor %d: ", i);
        scanf("%f", &sal);
        nom += sal;
    }

    printf("El total de la nómina es: %.2f\n", nom);
    return 0;
}
