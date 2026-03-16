#include <stdio.h>

/* Funciones para el manejo de cadenas de caracteres de la biblioteca stdio.h. */

int main(void)
{
    char *cad0 = "Buenos dias";  /* En este caso se reserva memoria para la cadena. */
    char cad1[20] = "Hola";
    char cad2[20], cad3[20], cad4[20];

    printf("\nLa cadena cad0 es: ");
    puts(cad0);     /* La función puts escribe la cadena y un salto de línea. */

    printf("\nLa cadena cad1 es: ");
    printf("%s", cad1);

    printf("\n\nIngrese una linea de texto (se lee con gets): \n");
    gets(cad2);     /* La función gets permite leer cadenas con espacios. */
    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nIngrese una linea de texto (se lee con scanf): \n");
    scanf("%s", cad3);  /* Scanf solo lee hasta encontrar el primer espacio. */
    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    fflush(stdin);
    printf("\nIngrese una linea de texto (se lee con getchar): \n");
    int i = 0;
    char p;
    while ((p = getchar()) != '\n' && i < 19)
    {
        cad4[i++] = p;
    }
    cad4[i] = '\0';
    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    return 0;
}