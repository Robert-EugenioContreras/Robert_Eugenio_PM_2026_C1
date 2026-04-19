#include <stdio.h>

/* Cadena invertida resuelta en forma recursiva. */

void inverso(char *);     /* Prototipo de función. */

int main(void)
{
    char fra[50];
    printf("\nIngrese la línea de texto: ");
    gets(fra);
    printf("\nEscribe la línea de texto en forma inversa: ");
    inverso(fra);
    printf("\n");

    return 0;
}

void inverso(char *cadena)
/* La función inverso obtiene precisamente el inverso de la cadena. La solución 
presentada es simple, pero para comprenderla es necesario tener conocimientos 
tanto de pilas como de recursividad. */
{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}