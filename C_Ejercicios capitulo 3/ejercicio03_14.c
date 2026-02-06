#include <stdio.h>

int main(void)
{
    int VOT, C1=0, C2=0, C3=0, C4=0, C5=0, NU=0, SVO;
    float PO1, PO2, PO3, PO4, PO5, PON;

    printf("Ingrese voto (0 para terminar): ");
    scanf("%d", &VOT);

    while (VOT != 0) {
        switch (VOT) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
            default: NU++;
        }
        scanf("%d", &VOT);
    }

    SVO = C1 + C2 + C3 + C4 + C5 + NU;

    PO1 = (float)C1 / SVO * 100;
    PO2 = (float)C2 / SVO * 100;
    PO3 = (float)C3 / SVO * 100;
    PO4 = (float)C4 / SVO * 100;
    PO5 = (float)C5 / SVO * 100;
    PON = (float)NU / SVO * 100;

    printf("Total votos: %d\n", SVO);
    printf("C1: %.2f%% C2: %.2f%% C3: %.2f%% C4: %.2f%% C5: %.2f%% Nulos: %.2f%%\n",
           PO1, PO2, PO3, PO4, PO5, PON);

    return 0;
}
