#include <stdio.h>

/* Biblioteca.
   El programa maneja información sobre las bajas de libros en una 
   biblioteca. Utiliza un archivo de acceso directo. */

typedef struct {
    int clave;
    char titulo[20];
    int carrera;
    int nent;           /* Número de ejemplares que entran. */
    int nsal;           /* Número de ejemplares que salen. */
} libro;

void f1(FILE *);        /* Prototipos de funciones. */
void f2(FILE *);
void f3(FILE *);

int main(void)
{
    int ope;
    FILE *ar;
    if ((ar = fopen("lib.dat", "r+")) != NULL)
    {
        printf("\nIngrese la operación a realizar\n1: Altas\n2: Bajas\n3: Lista de bajas\n0: Salir: ");
        scanf("%d", &ope);
        while (ope != 0)
        {
            switch (ope)
            {
                case 1: f1(ar);
                        break;
                case 2: f2(ar);
                        break;
                case 3: f3(ar);
                        break;
            }
            printf("\nIngrese la operación a realizar\n1: Altas\n2: Bajas\n3: Lista de bajas\n0: Salir: ");
            scanf("%d", &ope);
        }
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void f1(FILE *ap)
/* Esta función sirve para registrar las altas de libros que entran a 
   la biblioteca. */
{
    libro lib;
    fseek(ap, 0, SEEK_END);
    printf("\nClave: ");
    scanf("%d", &lib.clave);
    fflush(stdin);
    printf("Título: ");
    gets(lib.titulo);
    printf("Carrera: ");
    scanf("%d", &lib.carrera);
    printf("Cantidad que entra: ");
    scanf("%d", &lib.nent);
    lib.nsal = 0;
    fwrite(&lib, sizeof(libro), 1, ap);
}

void f2(FILE *ap)
/* Esta función sirve para registrar las bajas de libros de la biblioteca. */
{
    libro lib;
    int cla, n, ban = 0;
    printf("\nIngrese clave del libro: ");
    scanf("%d", &cla);
    rewind(ap);
    fread(&lib, sizeof(libro), 1, ap);
    while (!feof(ap) && !ban)
    {
        if (lib.clave == cla)
        {
            printf("Cantidad que sale: ");
            scanf("%d", &n);
            if (lib.nent >= (lib.nsal + n))
            {
                lib.nsal += n;
                fseek(ap, (long)-sizeof(libro), SEEK_CUR);
                fwrite(&lib, sizeof(libro), 1, ap);
                ban = 1;
            }
            else
                printf("\nNo hay suficientes ejemplares");
        }
        else
            fread(&lib, sizeof(libro), 1, ap);
    }
    if (!ban)
        printf("\nNo se encontró el libro");
}

void f3(FILE *ap)
/* Esta función genera un listado de los libros que han tenido bajas. */
{
    libro lib;
    rewind(ap);
    fread(&lib, sizeof(libro), 1, ap);
    while (!feof(ap))
    {
        if (lib.nsal > 0)
        {
            printf("\nClave: %d", lib.clave);
            printf("\tTítulo: %s", lib.titulo);
            printf("\tCantidad de bajas: %d", lib.nsal);
        }
        fread(&lib, sizeof(libro), 1, ap);
    }
}