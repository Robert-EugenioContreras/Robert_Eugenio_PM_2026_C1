#include <stdio.h>
#include <string.h>

/* Uniones.
 * El programa muestra la manera como se declara una unión, así como la forma de
 * acceso a los campos de las variables de tipo unión tanto para asignación
 * de valores como para lectura y escritura. */

union datos {
    char celular[15];
    char correo[20];
};

typedef struct {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales; // La unión dentro de la estructura
} alumno;

void Lectura(alumno *a); // Prototipo

void main(void) {
    // Alumno 1: Asignación directa en la declaración
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, "5-158-40-50"}, a2, a3;

    /* Para que puedas observar las diferentes formas en que los campos de las
    variables de tipo alumno reciben valores, ingresamos los valores de los
    campos de tres formas diferentes. */

    // Alumno 2: Lectura directa en el programa principal
    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electrónico: ");
    gets(a2.personales.correo);
    /* Observa que en la variable a2 el segundo campo de la unión recibe un valor. */

    // Alumno 3: Lectura a través de una función
    printf("\nAlumno 3\n");
    Lectura(&a3);

    /* Impresión de resultados */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular); 
    /* Observa que escribe el valor del teléfono celular asignado. */
    puts(a1.personales.correo); 
    /* Observa que si tratamos de imprimir el campo correo, escribe basura. */

    // Prueba de comportamiento de la unión con a0 (usando la lógica del libro)
    strcpy(a1.personales.correo, "hgimenez@hotmail.com");
    printf("\nNuevo correo de Alumno 1 asignado.\n");
    puts(a1.personales.celular); // Escribirá basura
    puts(a1.personales.correo);  // Escribirá el correo correctamente

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular); // Escribe basura
    puts(a2.personales.correo);  // Escribe el contenido del segundo campo

    printf("\nIngrese el teléfono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular);
    puts(a2.personales.celular); // Escribe el celular ingresado
    puts(a2.personales.correo);  // Ahora escribe basura

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo); // Escribe basura
}

void Lectura(alumno *a) {
    printf("Ingrese la matricula: ");
    scanf("%d", &a->matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);
    printf("Ingrese la carrera: ");
    gets(a->carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese el telefono celular: ");
    gets(a->personales.celular);
}