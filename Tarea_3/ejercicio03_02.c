#include <stdio.h>

int main(void)
{
    int n, i, num, suma = 0;

    printf("Cantidad de numeros: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Numero %d: ", i);
        scanf("%d", &num);

        if (num > 0)
            suma += num;
    }

    printf("Suma de positivos: %d\n", suma);
    return 0;
}
