#include <stdio.h>

int main(void)
{
    int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    float CAL;

    printf("Ingrese la calificacion (-1 para terminar): ");
    scanf("%f", &CAL);

    while (CAL != -1) {
        if (CAL < 4) R1++;
        else if (CAL < 6) R2++;
        else if (CAL < 8) R3++;
        else if (CAL < 9) R4++;
        else R5++;

        printf("Ingrese la calificacion (-1 para terminar): ");
        scanf("%f", &CAL);
    }

    printf("0..3.99: %d\n4..5.99: %d\n6..7.99: %d\n8..8.99: %d\n9..10: %d\n",
           R1, R2, R3, R4, R5);

    return 0;
}
