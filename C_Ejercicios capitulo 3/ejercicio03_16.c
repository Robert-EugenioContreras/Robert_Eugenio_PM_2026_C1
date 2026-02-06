#include <stdio.h>

int main(void)
{
    int I, MAT, MAMAT=0, MEMAT=0;
    float CAL, SUM, PRO, MAPRO=0, MEPRO=11;

    printf("Ingrese matricula (0 para terminar): ");
    scanf("%d", &MAT);

    while (MAT != 0) {
        SUM = 0;
        for (I = 1; I <= 5; I++) {
            scanf("%f", &CAL);
            SUM += CAL;
        }

        PRO = SUM / 5;
        if (PRO > MAPRO) { MAPRO = PRO; MAMAT = MAT; }
        if (PRO < MEPRO) { MEPRO = PRO; MEMAT = MAT; }

        scanf("%d", &MAT);
    }

    printf("Mejor alumno: %d %.2f\n", MAMAT, MAPRO);
    printf("Peor alumno: %d %.2f\n", MEMAT, MEPRO);

    return 0;
}
