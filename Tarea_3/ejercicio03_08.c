#include <stdio.h>

int main(void)
{
    int I, NUM;
    long FAC = 1;

    printf("Ingrese un numero entero: ");
    scanf("%d", &NUM);

    if (NUM < 0) {
        printf("Error: numero negativo\n");
    } else {
        for (I = 1; I <= NUM; I++) {
            FAC *= I;
        }
        printf("El factorial de %d es %ld\n", NUM, FAC);
    }

    return 0;
}
