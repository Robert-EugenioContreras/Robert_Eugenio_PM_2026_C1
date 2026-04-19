#include <stdio.h>

int main(void)
{
    int I, J, NUM, SUM, C = 0;

    printf("Ingrese numero limite: ");
    scanf("%d", &NUM);

    for (I = 1; I <= NUM; I++) {
        SUM = 0;
        for (J = 1; J <= I / 2; J++) {
            if (I % J == 0)
                SUM += J;
        }
        if (SUM == I) {
            printf("%d es perfecto\n", I);
            C++;
        }
    }

    printf("Cantidad de numeros perfectos: %d\n", C);
    return 0;
}
