#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXCLIENTES 5
#define MAXPRODUCTOS 10

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto{        
    int ProductoID;    //Numerado en ciclo iterativo        
    int Cantidad;    // entre 1 y 10        
    char *TipoProducto;  // Algún valor del arreglo TiposProductos            
    float PrecioUnitario; // entre 10 - 100 
};

struct Cliente{    
    int ClienteID;    // Numerado en el ciclo iterativo    
    char *NombreCliente;    // Ingresado por usuario    
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)    
    Producto *Productos; //El tamaño de este arreglo depende de la variable // “CantidadProductosAPedir”   
}; 

int cantidad_clientes();
void carga_de_clientes();
void carga_de_productos(Producto *Productos, int cant_productos);
void MostrarClientes(Cliente *Parr_clientes, int cant_productos);

int main(){
    srand(time(NULL));
    carga_de_clientes();
    printf("Fin");
    getchar();
}

int cantidad_clientes(){
    unsigned int numero_de_clientes;
    do{
        printf("Ingrese cantidad de clientes (No mayor a 5): ");
        scanf("%d", &numero_de_clientes);
    } while (numero_de_clientes > MAXCLIENTES);
    printf("%d\n", numero_de_clientes);
    return numero_de_clientes;
    getchar();
}

void carga_de_clientes(){
    int cantidad_clientes();
    int numero_de_clientes = cantidad_clientes();
    int i = 0;
    Cliente *Parr_clientes;
    Parr_clientes = (Cliente *)malloc(sizeof(Cliente) * numero_de_clientes);

    for (i = 0; i < numero_de_clientes; i++){
        (Parr_clientes + i)->ClienteID = i;
        
        char nombre_cliente[MAXCLIENTES];
        printf("Ingrese nombre de cliente #%d: ", (Parr_clientes + i)->ClienteID);
        scanf("%s", nombre_cliente);
        (Parr_clientes + i)->NombreCliente = (char*) malloc(strlen(nombre_cliente) * sizeof(char));
        strcpy((Parr_clientes + i)->NombreCliente, nombre_cliente);
        
        int cant_productos = 0;
        printf("Ingrese cantidad de productos: ");
        scanf("%d", &cant_productos);
        (Parr_clientes + i)->CantidadProductosAPedir = cant_productos;
        (Parr_clientes + i)->Productos = (struct Producto *) malloc((Parr_clientes + i)->CantidadProductosAPedir * sizeof(struct Producto));
        for (int j = 0; j < cant_productos; j++){
            char *pTipos = TiposProductos[0];
            (Parr_clientes + i)->Productos[j].ProductoID = j;
        
            int unidades = 0;
            int aux = rand() % 5;
            (Parr_clientes + i)->Productos[j].TipoProducto = (char *)(int *)pTipos + aux;
        
            printf("Producto #%d\n", (Parr_clientes + i)->Productos[j].ProductoID);
            printf("Ingrese cantidad de %s: ", (Parr_clientes + i)->Productos[j].TipoProducto);
            scanf("%d", &unidades);
            (Parr_clientes + i)->Productos[j].Cantidad = unidades;
            float precio = 0;
            do{
                printf("Ingrese precio de %s: (valores entre 10 y 100)", (Parr_clientes + i)->Productos[j].TipoProducto);
                scanf("%f", &precio);
            } while ((precio < 10) || (precio > 100));
            (Parr_clientes + i)->Productos[j].PrecioUnitario = (int)precio;
        }
    }
    MostrarClientes(Parr_clientes, numero_de_clientes);
    getchar();
}

void MostrarClientes(Cliente *Parr_clientes, int cant_productos){
    for (int i = 0; i < cant_productos; i++){
        printf("\n/////////////////////////////////////////////////////\n");

        printf("\nCliente ID: %d\n", (Parr_clientes + i)->ClienteID);
        printf("Nombre: %s\n", (Parr_clientes + i)->NombreCliente);

        printf("Cantidad de Productos: %d\n\n", (Parr_clientes + i)->CantidadProductosAPedir);

        float Total = 0;

        for (int j = 0; j < (Parr_clientes + i)->CantidadProductosAPedir; j++){
           
            printf("Producto ID: %d\n", Parr_clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d \n", Parr_clientes[i].Productos[j].Cantidad);
            printf("Tipo de Producto: %s \n", Parr_clientes[i].Productos[j].TipoProducto);
            printf("Precio Unitario: $%.2f \n", Parr_clientes[i].Productos[j].PrecioUnitario);

            //float costo_producto = (Parr_clientes + i)->Productos[j].Cantidad * (Parr_clientes + i)->Productos[j].PrecioUnitario;
            float CostoTotalPorProducto(Producto Productos);
            float costo_producto = CostoTotalPorProducto((Parr_clientes + i)->Productos[j]);
            printf("Costo Total del Producto: $%.2f\n\n",  costo_producto);
            Total += costo_producto;
        }
        printf("Total a Pagar del Cliente: $%.2f\n\n",  Total);
    }
}

float CostoTotalPorProducto(Producto Productos)
{
    return Productos.Cantidad * Productos.PrecioUnitario;
}