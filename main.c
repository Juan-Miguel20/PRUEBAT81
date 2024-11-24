#include <stdio.h>
#include "funciones.h"

#define MAX_PRODUCTOS 5
#define MAX_RECURSOS 10

int main() {
    char nombres[MAX_PRODUCTOS][50];
    char tiempos[MAX_PRODUCTOS][50];
    int recursos[MAX_PRODUCTOS][MAX_RECURSOS];
    char nombres_recursos[MAX_PRODUCTOS][MAX_RECURSOS][50];
    int cantidades[MAX_PRODUCTOS];
    float costos[MAX_PRODUCTOS];
    int total_recursos[MAX_PRODUCTOS];
    int total_productos = 0;
    float costo_total_pedido = 0;
    float presupuesto = leerNumeroFlotante("Ingrese el presupuesto disponible: ");
    int opcion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Agregar Producto\n");
        printf("2. Mostrar Inventario\n");
        printf("3. Editar Producto\n");
        printf("4. Eliminar Producto\n");
        printf("5. Crear Pedido\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        opcion = leerNumeroEntero("");

        switch (opcion) {
            case 1:
                agregarProducto(nombres, tiempos, recursos, nombres_recursos, cantidades, costos, total_recursos, &total_productos);
                break;
            case 2:
                mostrarInventario(nombres, tiempos, recursos, nombres_recursos, cantidades, costos, total_recursos, total_productos);
                break;
            case 3:
                editarProducto(nombres, tiempos, recursos, nombres_recursos, cantidades, costos, total_recursos, total_productos);
                break;
            case 4:
                eliminarProducto(nombres, tiempos, recursos, nombres_recursos, cantidades, costos, total_recursos, &total_productos);
                break;
            case 5:
                crearPedido(nombres, cantidades, costos, recursos, nombres_recursos, total_recursos, total_productos, presupuesto);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}


