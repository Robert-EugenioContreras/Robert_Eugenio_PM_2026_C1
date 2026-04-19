#include <stdio.h>
#include <ctype.h>

/* Letras en el archivo. 
   El programa, al recibir como dato un archivo de texto, determina 
   cuántas letras minúsculas y mayúsculas hay en el archivo. */

void minymay(FILE *);           /* Prototipo de función. */

int main(void)
{
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL)
    {
        minymay(ar);
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void minymay(FILE *arc)
/* Esta función cuenta el número de minúsculas y mayúsculas que hay 
   en el archivo arc. */
{
    int min = 0, may = 0;
    char p;
    while (!feof(arc))
    {
        p = getc(arc);
        if (islower(p))
            min++;
        else
            if (isupper(p))
                may++;
    }
    printf("\nNúmero de minúsculas: %d", min);
    printf("\nNúmero de mayúsculas: %d", may);
}