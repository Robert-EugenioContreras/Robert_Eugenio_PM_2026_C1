#include <stdio.h>

int main(void)
{
    int I, PRI = 0, SEG = 1, SIG;

    printf("%d %d ", PRI, SEG);

    for (I = 3; I <= 50; I++) {
        SIG = PRI + SEG;
        printf("%d ", SIG);
        PRI = SEG;
        SEG = SIG;
    }

    printf("\n");
    return 0;
}
