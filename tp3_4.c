#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_LARGO 50
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;


float costoTotal(float precio, int cantidad);

int main()
{
    srand(time(NULL));
    int cant_clientes;
    Cliente *clientes;

    printf("Ingrese la cantidad de Clientes: ");
    scanf("%d", &cant_clientes);

    clientes = (Cliente *)malloc(cant_clientes*sizeof(Cliente));

    for(int i=0; i<cant_clientes; i++){
        printf("Ingrese el nombre del cliente:");
        clientes[i].NombreCliente=(char*)malloc(MAX_LARGO*sizeof(char));
        gets(clientes[i].NombreCliente);
        clientes[i].ClienteID=i;
        clientes[i].CantidadProductosAPedir=rand()%5+1;
        clientes[i].Productos=(Producto*)malloc(clientes[i].CantidadProductosAPedir*sizeof(Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad = rand()%10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
            clientes[i].Productos[j].PrecioUnitario = rand()%(100-10) + 10 + 1;

        }
        
    }

   for (int i = 0; i < cant_clientes; i++) {
        float totalProdu=0;

        printf("\n-----------------Cliente Numero %d ------------------\n", i+1);

        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("ID: %d\n", clientes[i].ClienteID);
        printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("Producto numero %d:\n", j+1);
            printf("ID: %d\n", clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("Precio Total: %.2f\n", costoTotal(clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario));
            totalProdu += costoTotal(clientes[i].Productos[j].PrecioUnitario,clientes[i].Productos[j].Cantidad);
        }

        printf("\nTOTAL A PAGAR: %.2f\n", totalProdu);
    }

    return 0;
}


float costoTotal(float precio, int cantidad){
    return precio*cantidad;
}