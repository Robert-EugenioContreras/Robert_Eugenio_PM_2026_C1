#include <stdio.h>

int main(void)
{
    int I = 0;
    float SAL, NOM = 0, PRO;

    printf("Ingrese el salario del profesor: ");
    scanf("%f", &SAL);

    do {
        NOM += SAL;
        I++;
        printf("Ingrese el salario del profesor (0 para terminar): ");
        scanf("%f", &SAL);
    } while (SAL != 0);

    PRO = NOM / I;
    printf("\nNomina total: %.2f", NOM);
    printf("\nPromedio de salarios: %.2f\n", PRO);

    return 0;
}
