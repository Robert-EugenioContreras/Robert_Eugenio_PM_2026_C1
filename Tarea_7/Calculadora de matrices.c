#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de funciones
double** crear_matriz(int filas, int cols);
void liberar_matriz(double** matriz, int filas);
void imprimir_matriz(double** matriz, int filas, int cols);
void llenar_teclado(double** matriz, int filas, int cols);
double** leer_desde_archivo(const char* nombre_archivo, int *filas, int *cols);
double** sumar_matrices(double** A, double** B, int filas, int cols);
double** multiplicar_matrices(double** A, double** B, int fA, int cA, int cB);

int main() {
    int filas1, cols1, filas2, cols2, opcion;
    double **matrizA = NULL, **matrizB = NULL, **resultado = NULL;

    printf("--- SISTEMA DE CALCULO MATRICIAL ---\n");
    printf("1. Entrada por teclado\n2. Cargar desde archivos (.txt)\nSeleccione: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Dimensiones Matriz A (f c): ");
        scanf("%d %d", &filas1, &cols1);
        matrizA = crear_matriz(filas1, cols1);
        llenar_teclado(matrizA, filas1, cols1);

        printf("Dimensiones Matriz B (f c): ");
        scanf("%d %d", &filas2, &cols2);
        matrizB = crear_matriz(filas2, cols2);
        llenar_teclado(matrizB, filas2, cols2);
    } else {
        matrizA = leer_desde_archivo("matrizA.txt", &filas1, &cols1);
        matrizB = leer_desde_archivo("matrizB.txt", &filas2, &cols2);
        if (!matrizA || !matrizB) return 1;
    }

    // Menu de operaciones
    printf("\n1. Sumar (A+B)\n2. Multiplicar (A*B)\nSeleccione operacion: ");
    scanf("%d", &opcion);

    if (opcion == 1 && filas1 == filas2 && cols1 == cols2) {
        resultado = sumar_matrices(matrizA, matrizB, filas1, cols1);
    } else if (opcion == 2 && cols1 == filas2) {
        resultado = multiplicar_matrices(matrizA, matrizB, filas1, cols1, cols2);
    } else {
        printf("Error: Dimensiones incompatibles.\n");
    }

    if (resultado) {
        printf("\nResultado:\n");
        imprimir_matriz(resultado, filas1, (opcion == 1 ? cols1 : cols2));
    }

    // Limpieza de memoria
    liberar_matriz(matrizA, filas1);
    liberar_matriz(matrizB, filas2);
    if(resultado) liberar_matriz(resultado, filas1);

    return 0;
}

// --- IMPLEMENTACION DE FUNCIONES ---

double** crear_matriz(int filas, int cols) {
    double** m = (double**)malloc(filas * sizeof(double*));
    for (int i = 0; i < filas; i++) {
        m[i] = (double*)malloc(cols * sizeof(double));
    }
    return m;
}

void liberar_matriz(double** matriz, int filas) {
    for (int i = 0; i < filas; i++) free(matriz[i]);
    free(matriz);
}

void llenar_teclado(double** matriz, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }
}

double** leer_desde_archivo(const char* nombre_archivo, int *filas, int *cols) {
    FILE* file = fopen(nombre_archivo, "r");
    if (!file) {
        printf("No se pudo abrir %s\n", nombre_archivo);
        return NULL;
    }
    
    // El archivo debe tener filas y columnas en la primera linea: "f,c"
    fscanf(file, "%d,%d", filas, cols);
    double** m = crear_matriz(*filas, *cols);

    for (int i = 0; i < *filas; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, " %lf,", &m[i][j]);
        }
    }
    fclose(file);
    return m;
}

double** sumar_matrices(double** A, double** B, int filas, int cols) {
    double** res = crear_matriz(filas, cols);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
    return res;
}

double** multiplicar_matrices(double** A, double** B, int fA, int cA, int cB) {
    double** res = crear_matriz(fA, cB);
    for (int i = 0; i < fA; i++) {
        for (int j = 0; j < cB; j++) {
            res[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

void imprimir_matriz(double** matriz, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}