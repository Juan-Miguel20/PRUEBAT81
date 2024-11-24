#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Las funciones de leer, validar nombre, y convertir tiempo permanecen igual

// Agregar un producto
void agregarProducto(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int *total_productos) {
    if (*total_productos >= 5) {
        printf("No se pueden agregar mas productos.\n");
        return;
    }

    char nombre[50];
    do {
        printf("Ingrese el nombre del producto (solo letras): ");
        scanf(" %[^\n]", nombre);
        if (!validarNombre(nombre)) {
            printf("Nombre invalido. Debe contener solo letras.\n");
        }
    } while (!validarNombre(nombre));
    strcpy(nombres[*total_productos], nombre);

    printf("Ingrese el tiempo de fabricacion por unidad (ejemplo: '2 dias', '1 semana'): ");
    scanf(" %[^\n]", tiempos[*total_productos]);

    printf("Ingrese la cantidad demandada: ");
    cantidades[*total_productos] = leerNumeroEntero("");
    
    printf("Ingrese el costo de produccion por unidad: ");
    costos[*total_productos] = leerNumeroFlotante("");

    printf("Ingrese la cantidad de tipos de recursos necesarios (maximo 10): ");
    total_recursos[*total_productos] = leerNumeroEntero("");
    if (total_recursos[*total_productos] > 10) {
        printf("Cantidad de recursos excede el limite. Se ajustara a 10.\n");
        total_recursos[*total_productos] = 10;
    }

    for (int i = 0; i < total_recursos[*total_productos]; i++) {
        printf("Ingrese el nombre del recurso %d: ", i + 1);
        scanf(" %[^\n]", nombres_recursos[*total_productos][i]);

        printf("Ingrese la cantidad necesaria del recurso %d: ", i + 1);
        recursos[*total_productos][i] = leerNumeroEntero("");
    }

    (*total_productos)++;
    printf("Producto agregado correctamente.\n");
}
float leerNumeroFlotante(const char *mensaje) {
    float numero;
    printf("%s", mensaje);
    while (scanf("%f", &numero) != 1) {
        printf("Entrada invalida. Intente de nuevo: ");
        while (getchar() != '\n'); // Limpiar buffer
    }
    return numero;
}
int leerNumeroEntero(const char *mensaje) {
    int numero;
    printf("%s", mensaje);
    while (scanf("%d", &numero) != 1) {
        printf("Entrada invalida. Intente de nuevo: ");
        while (getchar() != '\n'); // Limpiar buffer
    }
    return numero;
}
int validarNombre(const char *nombre) {
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') || (nombre[i] >= 'a' && nombre[i] <= 'z') || nombre[i] == ' ')) {
            return 0; // No es válido
        }
    }
    return 1; // Es válido
}


// Mostrar inventario
void mostrarInventario(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int total_productos) {
    if (total_productos == 0) {
        printf("No hay productos registrados en el inventario.\n");
        return;
    }

    printf("\n--- Inventario ---\n");
    for (int i = 0; i < total_productos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Tiempo: %s\n", tiempos[i]);
        printf("  Cantidad: %d\n", cantidades[i]);
        printf("  Costo por unidad: $%.2f\n", costos[i]);
        printf("  Recursos:\n");
        for (int j = 0; j < total_recursos[i]; j++) {
            printf("    - %s: %d unidades\n", nombres_recursos[i][j], recursos[i][j]);
        }
        printf("-------------------\n");
    }
}

// Editar un producto
void editarProducto(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int total_productos) {
    if (total_productos == 0) {
        printf("No hay productos para editar.\n");
        return;
    }

    int indice;
    printf("Ingrese el indice del producto a editar (1-%d): ", total_productos);
    indice = leerNumeroEntero("") - 1;

    if (indice < 0 || indice >= total_productos) {
        printf("Indice invalido.\n");
        return;
    }

    printf("Editando producto '%s'\n", nombres[indice]);

    printf("Ingrese el nuevo nombre del producto: ");
    scanf(" %[^\n]", nombres[indice]);

    printf("Ingrese el nuevo tiempo de fabricacion: ");
    scanf(" %[^\n]", tiempos[indice]);

    printf("Ingrese la nueva cantidad demandada: ");
    cantidades[indice] = leerNumeroEntero("");

    printf("Ingrese la nueva cantidad de tipos de recursos: ");
    total_recursos[indice] = leerNumeroEntero("");

    for (int i = 0; i < total_recursos[indice]; i++) {
        printf("Ingrese el nombre del recurso %d: ", i + 1);
        scanf(" %[^\n]", nombres_recursos[indice][i]);

        printf("Ingrese la cantidad necesaria del recurso %d: ", i + 1);
        recursos[indice][i] = leerNumeroEntero("");
    }

    printf("Producto editado correctamente.\n");
}

// Eliminar un producto
void eliminarProducto(char nombres[][50], char tiempos[][50], int recursos[][10], char nombres_recursos[][10][50], int cantidades[], float costos[], int total_recursos[], int *total_productos) {
    if (*total_productos == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }

    int indice;
    printf("Ingrese el indice del producto a eliminar (1-%d): ", *total_productos);
    indice = leerNumeroEntero("") - 1;

    if (indice < 0 || indice >= *total_productos) {
        printf("Indice invalido.\n");
        return;
    }

    for (int i = indice; i < *total_productos - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        strcpy(tiempos[i], tiempos[i + 1]);
        cantidades[i] = cantidades[i + 1];
        total_recursos[i] = total_recursos[i + 1];
        for (int j = 0; j < total_recursos[i]; j++) {
            strcpy(nombres_recursos[i][j], nombres_recursos[i + 1][j]);
            recursos[i][j] = recursos[i + 1][j];
        }
    }

    (*total_productos)--;
    printf("Producto eliminado correctamente.\n");
}

void crearPedido(char nombres[][50], int cantidades[], float costos[], int recursos[][10], char nombres_recursos[][10][50], int total_recursos[], int total_productos, float presupuesto) {
    float costo_total_pedido = 0; // Declarar la variable local

    printf("\n--- Crear Pedido ---\n");
    for (int i = 0; i < total_productos; i++) {
        costo_total_pedido += costos[i] * cantidades[i];
    }

    printf("Costo total del pedido: $%.2f\n", costo_total_pedido);
    if (costo_total_pedido <= presupuesto) {
        printf("El pedido puede realizarse.\n");
    } else {
        printf("El pedido no puede realizarse. Falta $%.2f.\n", costo_total_pedido - presupuesto);
    }
}

