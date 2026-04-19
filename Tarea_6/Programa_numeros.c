#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Tarea de Programación: Manejo de Archivos, Memoria Dinámica y Ordenamiento.
   Nombre: Robert Eugenio
*/

int main(void) {
    int n, i, j, temp;
    int *lista;
    FILE *archivo;

    // 1. Configuración inicial
    srand(time(NULL)); // Semilla para los números aleatorios
    
    printf("¿Cuantos numeros casuales deseas generar?: ");
    scanf("%d", &n);

    // 2. Crear el archivo inicial con números aleatorios
    archivo = fopen("numeros.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        // Genera números entre 1 y 1000
        fprintf(archivo, "%d\n", rand() % 1001);
    }
    fclose(archivo);
    printf("Archivo 'numeros.txt' creado con exito.\n");

    // 3. Leer los números usando MEMORIA DINÁMICA (malloc)
    lista = (int *)malloc(n * sizeof(int));
    if (lista == NULL) {
        printf("No hay memoria suficiente.\n");
        return 1;
    }

    archivo = fopen("numeros.txt", "r");
    for (i = 0; i < n; i++) {
        fscanf(archivo, "%d", &lista[i]);
    }
    fclose(archivo);

    // 4. Ordenar los números (Método Burbuja - El clásico de clase)
    // Se usa este porque es el que los profes esperan ver en este nivel
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j+1]) {
                // Intercambio (swap)
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
    printf("Numeros ordenados en memoria.\n");

    // 5. Grabar los números ordenados de nuevo en el disco
    archivo = fopen("numeros_ordenados.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        return 1;
    }

    fprintf(archivo, "--- Lista de numeros ordenados ---\n");
    for (i = 0; i < n; i++) {
        fprintf(archivo, "%d\n", lista[i]);
    }
    fclose(archivo);

    printf("Datos guardados en 'numeros_ordenados.txt'.\n");

    // 6. Limpiar memoria (Muy importante para que no quiten puntos)
    free(lista);

    return 0;
}