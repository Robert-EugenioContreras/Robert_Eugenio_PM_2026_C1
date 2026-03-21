#include <stdio.h>

/* Archivo de acceso directo y actualización de registros.
   El programa permite actualizar los promedios de los alumnos de un
   archivo de acceso directo. La matrícula —que es la clave de 
   ordenación— se utiliza para localizar el registro. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void f1(FILE *);           /* Prototipo de función. */

int main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r+")) != NULL)
    {
        f1(ar);
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void f1(FILE *ap1)
/* Esta función permite actualizar el promedio de los alumnos. */
{
    alumno alu;
    int j, n, mat;
    float pro;
    fseek(ap1, 0, SEEK_END);
    n = ftell(ap1) / sizeof(alumno);
    /* Se calcula el número de registros que tiene el archivo. */

    printf("\nIngrese la matrícula del alumno: ");
    scanf("%d", &mat);
    printf("Ingrese el nuevo promedio: ");
    scanf("%f", &pro);

    /* Se realiza una búsqueda binaria para localizar el registro. */
    int i = 0;
    int der = n - 1;
    int ban = 0;
    while ((i <= der) && !ban)
    {
        j = (i + der) / 2;
        fseek(ap1, j * sizeof(alumno), SEEK_SET);
        fread(&alu, sizeof(alumno), 1, ap1);
        if (alu.matricula == mat)
        {
            alu.promedio = pro;
            fseek(ap1, j * sizeof(alumno), SEEK_SET);
            fwrite(&alu, sizeof(alumno), 1, ap1);
            ban = 1;
        }
        else
        {
            if (alu.matricula > mat)
                der = j - 1;
            else
                i = j + 1;
        }
    }
    if (ban)
        printf("\nEl promedio se actualizó con éxito");
    else
        printf("\nLa matrícula no se encuentra en el archivo");
}