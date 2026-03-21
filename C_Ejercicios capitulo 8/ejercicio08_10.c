#include <stdio.h>
#include <string.h>

/* Vendedores.
 * El programa maneja información sobre las ventas de los vendedores de una empresa,
 * utilizando estructuras anidadas y uniones para la forma de pago. */

typedef struct {
    char noba[10]; /* Nombre del banco */
    char nucu[10]; /* Número de cuenta */
} banco;

typedef union {
    banco che;    /* Cheque: usa estructura banco */
    banco nomi;   /* Nómina: usa estructura banco */
    char venta;   /* Ventanilla: solo un caracter */
} fpago;

typedef struct {
    char cnu[20]; /* Calle y número */
    char col[20]; /* Colonia */
    char cp[5];   /* Código Postal */
    char ciu[15]; /* Ciudad */
} domicilio;

typedef struct {
    int num;           /* Número de vendedor */
    char nom[20];      /* Nombre del vendedor */
    float ven[12];     /* Ventas de los 12 meses del año */
    domicilio domi;    /* Estructura anidada domicilio */
    float sal;         /* Salario mensual */
    fpago pago;        /* Unión para forma de pago */
    int cla;           /* Clave forma de pago (1-Banco, 2-Nómina, 3-Ventanilla) */
} vendedor;

/* Prototipos de funciones */
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

void main(void) {
    vendedor VENDEDORES[100];
    int TAM;
    do {
        printf("Ingrese el número de vendedores (1-100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);
    printf("\n\tFIN DEL PROGRAMA\n");
}

void Lectura(vendedor A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nDatos del vendedor %d", I + 1);
        printf("\nNúmero de vendedor: ");
        scanf("%d", &A[I].num);
        fflush(stdin);
        printf("Nombre del vendedor: ");
        gets(A[I].nom);
        printf("Ventas del año:\n");
        for (J = 0; J < 12; J++) {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }
        printf("Domicilio (Calle y No, Colonia, CP, Ciudad):\n");
        fflush(stdin); gets(A[I].domi.cnu);
        gets(A[I].domi.col);
        gets(A[I].domi.cp);
        gets(A[I].domi.ciu);
        printf("Salario mensual: ");
        scanf("%f", &A[I].sal);
        printf("Forma de Pago (1-Banco, 2-Nómina, 3-Ventanilla): ");
        scanf("%d", &A[I].cla);
        
        switch (A[I].cla) {
            case 1: 
                printf("\tNombre del banco: "); fflush(stdin); gets(A[I].pago.che.noba);
                printf("\tNúmero de cuenta: "); gets(A[I].pago.che.nucu);
                break;
            case 2:
                printf("\tNombre del banco: "); fflush(stdin); gets(A[I].pago.nomi.noba);
                printf("\tNúmero de cuenta: "); gets(A[I].pago.nomi.nucu);
                break;
            case 3:
                A[I].pago.venta = 'S'; /* 'S' de Sí, cobra por ventanilla */
                break;
        }
    }
}

void F1(vendedor A[], int T) {
    /* Obtiene las ventas totales anuales de cada vendedor. */
    int I, J;
    float SUM;
    printf("\n\tVentas Totales de los Vendedores");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++) SUM += A[I].ven[J];
        printf("\nVendedor: %d \tVentas: %.2f", A[I].num, SUM);
    }
}

void F2(vendedor A[], int T) {
    /* Incrementa 5%% el salario si las ventas anuales superan $1,500,000. */
    int I, J;
    float SUM;
    printf("\n\n\tIncremento a Vendedores con Ventas > 1,500,000");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++) SUM += A[I].ven[J];
        if (SUM > 1500000.00) {
            A[I].sal *= 1.05;
            printf("\nVendedor: %d \tNuevo salario: %.2f", A[I].num, A[I].sal);
        }
    }
}

void F3(vendedor A[], int T) {
    /* Listado de vendedores que vendieron menos de $300,000 al año. */
    int I, J;
    float SUM;
    printf("\n\n\tVendedores con Ventas < 300,000");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++) SUM += A[I].ven[J];
        if (SUM < 300000.00) {
            printf("\nNúmero: %d \tNombre: %s \tVentas: %.2f", A[I].num, A[I].nom, SUM);
        }
    }
}

void F4(vendedor A[], int T) {
    /* Imprime los datos de quienes cobran mediante cuenta bancaria (Clave 1). */
    int I;
    printf("\n\n\tVendedores con Cuenta en el Banco");
    for (I = 0; I < T; I++) {
        if (A[I].cla == 1) {
            printf("\nVendedor: %d \tBanco: %s \tCuenta: %s", A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
        }
    }
}