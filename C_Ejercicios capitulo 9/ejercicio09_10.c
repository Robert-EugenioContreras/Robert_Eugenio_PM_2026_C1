#include <stdio.h>
#include <string.h>

/* Alumnos y matrículas.
 * El programa busca la matrícula de un alumno en un archivo y, si la encuentra,
 * permite modificar su nombre. */

void main(void) {
    int mat, m, ban = 0;
    char nom[20];
    FILE *ar;
    
    if ((ar = fopen("ad1.dat", "r+")) != NULL) {
        /* Se abre el archivo para lectura y escritura (r+) */
        printf("Ingrese la matrícula del alumno: ");
        scanf("%d", &mat);
        
        while (!feof(ar) && !ban) {
            fscanf(ar, "%d", &m);
            if (mat == m) {
                ban = 1;
                /* Si encuentra la matrícula, pide el nuevo nombre */
                printf("Ingrese el nuevo nombre del alumno: ");
                fflush(stdin);
                gets(nom);
                /* Se posiciona el puntero para sobrescribir el nombre */
                fseek(ar, - (long)sizeof(int), SEEK_CUR); 
                fprintf(ar, "%d %s\n", m, nom);
            } else {
                /* Si no es la matrícula, salta el nombre para seguir buscando */
                fscanf(ar, "%s", nom);
            }
        }
        
        if (ban) {
            printf("\nEl nombre ha sido modificado con éxito.");
        } else {
            printf("\nLa matrícula no se encuentra en el archivo.");
        }
        
        fclose(ar);
    } else {
        printf("No se pudo abrir el archivo");
    }
}