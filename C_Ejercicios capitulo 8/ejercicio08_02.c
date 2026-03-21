#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Estructuras-2. 
El programa muestra la manera en que se declara una estructura, así como la 
forma en que se tiene acceso a los campos de las variables de tipo estructura 
tanto para lectura como para escritura. Se utiliza además una función que 
recibe como parámetro un apuntador de tipo estructura. */

struct alumno           /* Declaración de la estructura. */
{
    int matricula;
    char nombre[20];
    char carrera[20];   /* Campos de la estructura. */
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *);  /* Prototipo de función. */

int main(void)
{
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
    struct alumno *a3, *a4, *a5, a6;
    /* Observa que las variables a3, a4 y a5 se declaran como apuntadores de 
    tipo estructura alumno. a6 es una variable de tipo estructura alumno. */

    a3 = &a0;   /* Se asigna la dirección de a0 al apuntador a3. */

    a4 = (struct alumno *) malloc(sizeof(struct alumno));
    /* Nota: Es necesario asignar memoria dinámicamente para a4. */
    
    printf("\nIngrese la matricula del alumno 4: ");
    scanf("%d", &(*a4).matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno 4: ");
    gets(a4->nombre);
    printf("Ingrese la carrera del alumno 4: ");
    gets(a4->carrera);
    printf("Ingrese el promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    fflush(stdin);
    printf("Ingrese la dirección del alumno 4: ");
    gets(a4->direccion);

    a5 = (struct alumno *) malloc(sizeof(struct alumno));
    Lectura(a5);    /* Se pasa el apuntador a la función. */

    Lectura(&a6);   /* Se pasa la dirección de la variable a la función. */

    /* Impresión de datos */
    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);

    printf("\nDatos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);

    printf("\nDatos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);

    printf("\nDatos del alumno 6\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);

    return 0;
}

void Lectura(struct alumno *a)
/* Esta función permite leer los campos de un apuntador de tipo estructura alumno. */
{
    printf("\nIngrese la matricula del alumno: ");
    scanf("%d", &a->matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno: ");
    gets(a->nombre);
    printf("Ingrese la carrera del alumno: ");
    gets(a->carrera);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese la dirección del alumno: ");
    gets(a->direccion);
}