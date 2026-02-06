#include <stdio.h>
#include <math.h>

int main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &N);

    if (N > 0) {
        for (I = 1; I <= N; I++) {
            printf("Ingrese el numero %d: ", I);
            scanf("%d", &NUM);

            if (NUM % 2 == 0) {
                SPA += NUM;
            } else {
                SIM += NUM;
                CIM++;
            }
        }

        printf("Suma de pares: %d\n", SPA);
        if (CIM > 0)
            printf("Promedio de impares: %.2f\n", (float)SIM / CIM);
    } else {
        printf("Valor de N incorrecto\n");
    }

    return 0;
}
