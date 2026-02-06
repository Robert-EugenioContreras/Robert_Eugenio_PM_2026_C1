#include <stdio.h>

int main(void)
{
    int I = 2, CAM = 1;
    long SSE = 0;

    while (I <= 2500) {
        printf("%d ", I);
        SSE += I;

        if (CAM) {
            I += 5;
            CAM = 0;
        } else {
            I += 3;
            CAM = 1;
        }
    }

    printf("\nSuma de la serie: %ld\n", SSE);
    return 0;
}
