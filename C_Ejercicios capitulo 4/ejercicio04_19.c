#include <stdio.h>

void fibonacci(int n);

int main(void)
{
    int n;

    printf("Ingrese la cantidad de terminos: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}

void fibonacci(int n)
{
    int a = 0, b = 1, c, i;

    for (i = 1; i <= n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}
