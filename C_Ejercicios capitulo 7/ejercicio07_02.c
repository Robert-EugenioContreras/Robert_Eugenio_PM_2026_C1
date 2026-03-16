#include <stdio.h>
#include <ctype.h>

/* Funciones para el manejo de caracteres de la biblioteca ctype.h. */

int main(void)
{
    char p1;
    printf("\nIngrese un caracter para analizar si es digito: ");
    fflush(stdin);
    scanf("%c", &p1);

    if (isdigit(p1))
        printf("%c es un digito \n", p1);
    else
        printf("%c no es un digito \n", p1);

    fflush(stdin);
    printf("\nIngrese un caracter para examinar si es letra: ");
    scanf("%c", &p1);

    if (isalpha(p1))
        printf("%c es una letra \n", p1);
    else
        printf("%c no es una letra \n", p1);

    fflush(stdin);
    printf("\nIngrese un caracter para examinar si es minúscula: ");
    scanf("%c", &p1);

    if (isalpha(p1))
    {
        if (islower(p1))
            printf("%c es una letra minuscula \n", p1);
        else
            printf("%c no es una letra minuscula \n", p1);
    }
    else
    {
        printf("%c no es una letra \n", p1);
    }

    fflush(stdin);
    printf("\nIngrese una letra para convertirla de mayúscula a minúscula: ");
    scanf("%c", &p1);

    if (isalpha(p1))
    {
        if (isupper(p1))
            printf("%c fue convertida a: %c \n", p1, tolower(p1));
        else
            printf("%c ya es minuscula \n", p1);
    }
    else
    {
        printf("%c no es una letra \n", p1);
    }

    return 0;
}