#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define SALIR 0
#define NUEVO 100
#define SUMAR 1
#define DIVIDIR 2
#define MULTIPLICAR 3
#define RESTA 4
#define RAIZ 5      
#define ERR_DivByZero 101
#define ERR_NegRoot   102 
#define ERR_OK 0

// Prototipos de funciones
int sumar(float n1, float n2, float *res);
int dividir(float n1, float n2, float *res);
int multiplicar(float n1, float n2, float *res);
int restar(float n1, float n2, float *res);
int raiz_cuadrada(float n1, float *res);

int main(void)
{
    int menu = NUEVO;
    int cod_err = ERR_OK;
    float num1 = 0.0, num2 = 0.0, result = 0.0;

    do {
        printf("\n--- CALCULADORA ROBERT ---\n");
        printf("0-Salir\n1-Sumar\n2-Dividir\n3-Multiplicar\n4-Restar\n5-Raiz Cuadrada\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%i", &menu) != 1) {
            printf("Entrada invalida\n");
            while (getchar() != '\n'); 
            menu = NUEVO;
            continue;
        }

        if (menu == SALIR) break;

        // Lógica de entradas según la operación
        if (menu >= 1 && menu <= 4) {
            printf("Ingrese primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese segundo numero: ");
            scanf("%f", &num2);
        } else if (menu == RAIZ) {
            printf("Ingrese el numero: ");
            scanf("%f", &num1);
        }

        // Ejecución de funciones
        switch (menu) {
            case SUMAR: cod_err = sumar(num1, num2, &result); break;
            case DIVIDIR: cod_err = dividir(num1, num2, &result); break;
            case MULTIPLICAR: cod_err = multiplicar(num1, num2, &result); break;
            case RESTA: cod_err = restar(num1, num2, &result); break;
            case RAIZ: cod_err = raiz_cuadrada(num1, &result); break;
            default: continue;
        }

        // Manejo de resultados y errores
        if (cod_err == ERR_DivByZero) printf("Error: Division por cero.\n");
        else if (cod_err == ERR_NegRoot) printf("Error: Raiz de numero negativo.\n");
        else printf("Resultado: %.2f\n", result);

    } while (menu != SALIR);

    printf("Calculadora cerrada.\n");
    return 0;
}

// Implementaciones
int sumar(float n1, float n2, float *res) { *res = n1 + n2; return ERR_OK; }
int restar(float n1, float n2, float *res) { *res = n1 - n2; return ERR_OK; }
int multiplicar(float n1, float n2, float *res) { *res = n1 * n2; return ERR_OK; }
int dividir(float n1, float n2, float *res) {
    if (n2 == 0) return ERR_DivByZero;
    *res = n1 / n2;
    return ERR_OK;
}
int raiz_cuadrada(float n1, float *res) {
    if (n1 < 0) return ERR_NegRoot;
    *res = sqrt(n1);
    return ERR_OK;
}