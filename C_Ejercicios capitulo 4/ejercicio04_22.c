#include <stdio.h>

void tabla(int n);

int main(void)
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    tabla(num);

    return 0;
}

void tabla(int n)
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}
