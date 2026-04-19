#include <stdio.h>
#include <stdlib.h>

/* * Programa de Amortización/Depreciación de Vehículos
 * Estudiante: Robert Eugenio Contreras
 * Descripción: Calcula la pérdida de valor mensual de un activo 
 * y genera un reporte en un archivo de texto .txt
 */

// Estructura para organizar los datos del vehículo
typedef struct {
    float valorInicial;
    float valorFinal; // Valor de rescate
    int tiempoMeses;
    float depreciacionMensual;
} Vehiculo;

// Prototipos de funciones
void calcularDepreciacion(Vehiculo *v);
void generarReporteTabla(Vehiculo v);

int main(void) {
    Vehiculo miCarro;

    printf("--- Sistema de Cálculo de Depreciación ---\n");
    
    printf("Ingrese el valor inicial del vehiculo: ");
    scanf("%f", &miCarro.valorInicial);
    
    printf("Ingrese el valor de rescate (precio final estimado): ");
    scanf("%f", &miCarro.valorFinal);
    
    printf("Ingrese el tiempo de amortizacion (en meses): ");
    scanf("%d", &miCarro.tiempoMeses);

    // Lógica de cálculo
    calcularDepreciacion(&miCarro);
    
    // Generar el archivo
    generarReporteTabla(miCarro);

    return 0;
}

void calcularDepreciacion(Vehiculo *v) {
    // La depreciación lineal: (Valor Inicial - Valor Final) / Tiempo
    v->depreciacionMensual = (v->valorInicial - v->valorFinal) / v->tiempoMeses;
}

void generarReporteTabla(Vehiculo v) {
    FILE *archivo;
    archivo = fopen("tabla_amortizacion.txt", "w");
    
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return;
    }

    float valorActual = v.valorInicial;

    // Encabezado del archivo
    fprintf(archivo, "TABLA DE DEPRECIACION DE VEHICULO\n");
    fprintf(archivo, "====================================================\n");
    fprintf(archivo, "%-10s | %-15s | %-15s\n", "Mes", "Depreciacion", "Valor Contable");
    fprintf(archivo, "----------------------------------------------------\n");

    // Mes 0 (Estado inicial)
    fprintf(archivo, "%-10d | %-15.2f | %-15.2f\n", 0, 0.0, valorActual);

    // Ciclo para llenar la tabla mes a mes
    for (int i = 1; i <= v.tiempoMeses; i++) {
        valorActual -= v.depreciacionMensual;
        
        // Validar que el valor no sea menor al valor de rescate por errores de redondeo
        if (valorActual < v.valorFinal) valorActual = v.valorFinal;

        fprintf(archivo, "%-10d | %-15.2f | %-15.2f\n", i, v.depreciacionMensual, valorActual);
    }

    fprintf(archivo, "====================================================\n");
    fclose(archivo);

    printf("\n[OK] La tabla de amortizacion ha sido guardada en 'tabla_amortizacion.txt'\n");
}