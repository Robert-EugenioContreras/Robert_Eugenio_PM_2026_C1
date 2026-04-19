#include <stdio.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
   El programa, al recibir como dato un archivo de texto, determina el
   porcentaje de minúsculas y mayúsculas que existen en el archivo. */

void minymay(FILE *);          /* Prototipo de función. */

int main(void)
{
    FILE *ap;
    if ((ap = fopen("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void minymay(FILE *ap1)
/* Esta función determina el porcentaje de minúsculas y mayúsculas que
   existen en el archivo. */
{
    char p;
    int mi = 0, ma = 0, tot = 0;
    while (!feof(ap1))
    {
        p = getc(ap1);
        if (islower(p))
            mi++;
        else
            if (isupper(p))
                ma++;
        tot++;
    }
    printf("\n\nPorcentaje de minúsculas: %5.2f%%", (float)mi / tot * 100);
    printf("\nPorcentaje de mayúsculas: %5.2f%%", (float)ma / tot * 100);
}