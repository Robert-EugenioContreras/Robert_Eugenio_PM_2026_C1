#include <stdio.h>
#include <string.h>

/* Comercializadora farmacéutica.
 * El programa maneja información sobre ventas, inventario, reabastecimiento y
 * nuevos productos de una comercializadora farmacéutica. */

typedef struct {
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

// Prototipos de funciones
void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

void main(void) {
    producto INV[100];
    int TAM, OPE;
    
    // Validación del tamaño inicial
    do {
        printf("Ingrese el número de productos (1-100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(INV, TAM);

    do {
        printf("\nIngrese operación a realizar.\n1 - Ventas\n2 - Reabastecimiento\n3 - Nuevos Productos\n4 - Inventario\n0 - Salir: ");
        scanf("%d", &OPE);
        
        switch (OPE) {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break; // Se pasa TAM por referencia para poder incrementarlo
            case 4: Inventario(INV, TAM); break;
        }
    } while (OPE != 0);
}

void Lectura(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese información del producto %d", I + 1);
        printf("\nClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);
        printf("Nombre: ");
        gets(A[I].nombre);
        printf("Precio: ");
        scanf("%f", &A[I].precio);
        printf("Existencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T) {
    int CLA, CAN, I, RES;
    float TOT = 0.0, PAR;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while (CLA) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        I = 0;
        while ((I < T) && (A[I].clave < CLA)) I++;
        
        if ((I == T) || (A[I].clave > CLA)) {
            printf("\nLa clave del producto es incorrecta");
        } else {
            if (A[I].existencia >= CAN) {
                A[I].existencia -= CAN;
                PAR = A[I].precio * CAN;
                TOT += PAR;
            } else {
                printf("\nNo existe en inventario la cantidad solicitada. Solo hay %d", A[I].existencia);
                printf("\n¿Los lleva? 1 - Si / 0 - No: ");
                scanf("%d", &RES);
                if (RES) {
                    PAR = A[I].precio * A[I].existencia;
                    A[I].existencia = 0;
                    TOT += PAR;
                }
            }
        }
        printf("\nIngrese siguiente clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
    printf("\nTotal de la venta: %.2f", TOT);
}

void Reabastecimiento(producto A[], int T) {
    int CLA, CAN, I;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while (CLA) {
        I = 0;
        while ((I < T) && (A[I].clave < CLA)) I++;
        
        if ((I == T) || (A[I].clave > CLA)) {
            printf("\nLa clave del producto ingresada es incorrecta");
        } else {
            printf("\tCantidad: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }
        printf("\nIngrese otra clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T) {
    int CLA, I, J;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while ((*T < 100) && (CLA)) {
        I = 0;
        while ((I < *T) && (A[I].clave < CLA)) I++;
        
        if (I < *T && A[I].clave == CLA) {
            printf("\nEl producto ya se encuentra en el inventario");
        } else {
            for (J = *T; J > I; J--) A[J] = A[J-1]; // Desplazamiento para mantener orden
            A[I].clave = CLA;
            printf("\tNombre: ");
            fflush(stdin);
            gets(A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            *T = *T + 1; // Incrementamos el contador global
        }
        printf("\nIngrese otra clave de producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
    if (*T == 100) printf("\nYa no hay espacio para incorporar nuevos productos");
}

void Inventario(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nClave: %d", A[I].clave);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tPrecio: %.2f", A[I].precio);
        printf("\tExistencia: %d", A[I].existencia);
    }
    printf("\n");
}