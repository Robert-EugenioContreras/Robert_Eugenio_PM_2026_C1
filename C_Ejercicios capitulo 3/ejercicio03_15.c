#include <stdio.h>
#include <math.h>

int main(void)
{
    int I = 1, B = 0, C = 1;
    double RES = 4.0 / I;

    while (fabs(3.1415 - RES) > 0.0005) {
        I += 2;
        if (B) {
            RES += 4.0 / I;
            B = 0;
        } else {
            RES -= 4.0 / I;
            B = 1;
        }
        C++;
    }

    printf("Terminos necesarios: %d\n", C);
    return 0;
}
