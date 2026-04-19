#include <stdio.h>
#include <string.h>

/* Reemplaza palabras.
   El programa, al recibir como dato un archivo de texto y dos cadenas de 
   caracteres, reemplaza la primera cadena por la segunda cada vez que 
   aparezca en el archivo. */

void cambia(FILE *, FILE *, char *, char *);

int main(void)
{
    FILE *ar, *ap;
    char cad1[20], cad2[20];
    printf("\nIngrese la cadena a buscar: ");
    gets(cad1);
    printf("\nIngrese la cadena por la que se va a reemplazar: ");
    gets(cad2);
    if ((ar = fopen("arc.txt", "r")) != NULL)
    {
        if ((ap = fopen("arc1.txt", "w")) != NULL)
        {
            cambia(ar, ap, cad1, cad2);
            fclose(ar);
            fclose(ap);
        }
        else
            printf("No se pudo abrir el archivo arc1.txt");
    }
    else
        printf("No se pudo abrir el archivo arc.txt");

    return 0;
}

void cambia(FILE *ap1, FILE *ap2, char *ca1, char *ca2)
/* Esta función reemplaza la cadena ca1 por ca2 en el archivo ap2, el cual 
   contiene la misma información que el archivo ap1. */
{
    char cad[30];
    while (!feof(ap1))
    {
        fgets(cad, 30, ap1);
        if (strcmp(cad, ca1) == 0)
            fputs(ca2, ap2);
        else
            fputs(cad, ap2);
    }
}