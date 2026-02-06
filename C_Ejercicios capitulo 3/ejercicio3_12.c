#include <stdio.h>

int main(void)
{
    int NUM;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);

    if (NUM > 0) {
        while (NUM != 1) {
            printf("%d ", NUM);
            if (NUM % 2 == 0)
                NUM /= 2;
            else
                NUM = NUM * 3 + 1;
        }
        printf("1\n");
    } else {
        printf("Numero invalido\n");
    }

    return 0;
}
