#include <stdio.h>

/* Ordenación de un archivo de acceso directo. 
   El programa ordena de menor a mayor un archivo de acceso directo, 
   considerando la matrícula como clave de ordenación. Se utiliza el 
   método de la burbuja. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *);           /* Prototipo de función. */

int main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r+")) != NULL)
    {
        ordena(ar);
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void ordena(FILE *ap1)
/* Esta función ordena los registros de un archivo de acceso directo 
   por el método de la burbuja. */
{
    alumno alu1, alu2;
    int a, b, n;
    fseek(ap1, 0, SEEK_END);
    n = ftell(ap1) / sizeof(alumno);
    /* Se calcula el número de registros que tiene el archivo. */

    for (a = 0; a < (n - 1); a++)
    {
        for (b = (a + 1); b < n; b++)
        {
            fseek(ap1, a * sizeof(alumno), SEEK_SET);
            fread(&alu1, sizeof(alumno), 1, ap1);
            fseek(ap1, b * sizeof(alumno), SEEK_SET);
            fread(&alu2, sizeof(alumno), 1, ap1);
            if (alu1.matricula > alu2.matricula)
            {
                fseek(ap1, a * sizeof(alumno), SEEK_SET);
                fwrite(&alu2, sizeof(alumno), 1, ap1);
                fseek(ap1, b * sizeof(alumno), SEEK_SET);
                fwrite(&alu1, sizeof(alumno), 1, ap1);
            }
        }
    }
}