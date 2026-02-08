#include <stdio.h>
#include <stdlib.h>

#define SALIR 0
#define NUEVO 100
#define SUMAR 1
#define DIVIDIR 2
#define MULTIPLICAR 3
#define RESTA 4
#define RAIZ 5
#define ERR_DivByZero 100
#define ERR_OK 0

//concepto de funcion
//concepto de puntero
//concepto del ambito de una variable (ciclo de vida de la variable)
 
//& el operador de direccion
//* el operador de in direccion

// Declaración de funciones
int sumar(float num1, float num2, float *resultado);
int dividir(float numerador, float denominador, float *resultado);
int multiplicar(float num1, float num2, float *resultado);
int restar(float num1, float num2, float *resultado);

int main(void)
{
    int menu = NUEVO;
    int cod_err = ERR_OK;
    float num1 = 0.0;
    float num2 = 0.0;
    float result = 0.0;

    do
    {
        printf("\n0-Salir\n1-Sumar\n2-Dividir\n3-Multiplicar\n4-Restar\n");
        printf("Seleccione una opcion: ");
        if (scanf("%i", &menu) != 1)
{
    printf("Entrada invalida\n");
    while (getchar() != '\n'); // limpiar buffer
    menu = NUEVO;
    continue;
}

        if(menu == SUMAR)
        {
            printf("\nEscriba el primer numero a sumar: ");
            scanf("%f", &num1);

            printf("Escriba el segundo numero a sumar: ");
            scanf("%f", &num2);

            cod_err = sumar(num1, num2, &result);

            if(cod_err == ERR_OK)
                printf("Suma de %f + %f = %f\n", num1, num2, result);
            else
                printf("Error en suma\n");
        }

        if(menu == DIVIDIR)
        {
            printf("\nEscriba el numerador: ");
            scanf("%f", &num1);

            printf("Escriba el denominador: ");
            scanf("%f", &num2);

            cod_err = dividir(num1, num2, &result);

            if(cod_err == ERR_DivByZero)
                printf("===== Error: division por cero =====\n");
            else
                printf("Division de %f / %f = %f\n", num1, num2, result);
        }

        if(menu == MULTIPLICAR)
        {
            printf("\nEscriba el primer numero a multiplicar: ");
            scanf("%f", &num1);

            printf("Escriba el segundo numero a multiplicar: ");
            scanf("%f", &num2);

            cod_err = multiplicar(num1, num2, &result);

            if(cod_err == ERR_OK)
                printf("Multiplicacion de %f * %f = %f\n", num1, num2, result);
            else
                printf("Error en multiplicacion\n");
        }

        if(menu == RESTA)
        {
            printf("\nEscriba el primer numero: ");
            scanf("%f", &num1);

            printf("Escriba el segundo numero: ");
            scanf("%f", &num2);

            cod_err = restar(num1, num2, &result);

            if(cod_err == ERR_OK)
                printf("Resta de %f - %f = %f\n", num1, num2, result);
            else
                printf("Error en resta\n");
        }

    }
    while(menu != SALIR);

    return 0;
}

// Implementación de funciones

int sumar(float n1, float n2, float *resultado)
{
    *resultado = n1 + n2;
    return ERR_OK;
}

int dividir(float numerador, float denominador, float *resultado)
{
    if(denominador == 0)
        return ERR_DivByZero;

    *resultado = numerador / denominador;
    return ERR_OK;
}

int multiplicar(float n1, float n2, float *resultado)
{
    *resultado = n1 * n2;
    return ERR_OK;
}

int restar(float n1, float n2, float *resultado)
{
    *resultado = n1 - n2;
    return ERR_OK;
}
