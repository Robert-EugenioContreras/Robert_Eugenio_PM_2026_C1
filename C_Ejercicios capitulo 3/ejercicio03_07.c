#include <stdio.h>

int main(void)
{
    int I, N;
    float LAN, SLA = 0;

    do {
        printf("Ingrese el numero de lanzamientos (1 a 10): ");
        scanf("%d", &N);
    } while (N < 1 || N > 10);

    for (I = 1; I <= N; I++) {
        printf("Ingrese el lanzamiento %d: ", I);
        scanf("%f", &LAN);
        SLA += LAN;
    }

    SLA /= N;
    printf("\nPromedio de lanzamientos: %.2f\n", SLA);

    return 0;
}
