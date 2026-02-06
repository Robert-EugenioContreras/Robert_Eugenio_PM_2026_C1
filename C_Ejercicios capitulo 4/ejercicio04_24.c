#include <stdio.h>

int mayor(int v[], int n);

int main(void)
{
    int n, i;
    int v[100];

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    printf("El mayor elemento es: %d\n", mayor(v, n));

    return 0;
}

int mayor(int v[], int n)
{
    int i, max = v[0];

    for (i = 1; i < n; i++)
    {
        if (v[i] > max)
            max = v[i];
    }

    return max;
}
