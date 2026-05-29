#include <stdio.h>
#define MAX_NumeroS 1000

// PROTOTIPOS DE FUNCIONES
int buscarNumero(int inventario[], int n, int numeroBuscado);
void listarNumero(int inventario[], int n);
void eliminarNumero(int inventario[], int *n);
void agregarNumero(int inventario[], int *n);

void ordenarInventario(int inventario[], int n);

int main()
{
    // Arreglo inicial de numeros cargados en el sistema
    int inventario[MAX_NumeroS] = {87126, 87127, 87128, 87129, 87130, 87131, 87132, 87133, 87134, 87135, 87136, 87137, 87138, 87139, 87140, 87141, 87142, 87143, 87144, 87145};

    int n = 20; // Cantidad actual de elementos guardados
    int opcion;

    // ORDENAMIENTO INICIAL: Se ejecuta aunque los datos ya esten ordenados,
    ordenarInventario(inventario, n);

    /** Menu de opciones */
    do
    {
        printf("\nMenu de opciones:\n");
        printf("1) Listar Numeros\n");
        printf("2) Buscar Numero\n");
        printf("3) Eliminar Numero\n");
        printf("4) Agregar un Numero\n");
        printf("5) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            // Opcion para ver todos los elementos almacenados
            printf("\nInventario ordenado y actualizado:\n");
            listarNumero(inventario, n);
            break;

        case 2:
        {
            int numeroEncontrado;
            int numeroABuscar;
            
        
            printf("Ingrese el numero a buscar: ");
            scanf("%d", &numeroABuscar);
            
            // Se envia el valor ingresado como parametro a la funcion
            numeroEncontrado = buscarNumero(inventario, n, numeroABuscar);
            
            if (numeroEncontrado != -1)
            {
                printf("Numero encontrado: %d\n", inventario[numeroEncontrado]);
            }
            else
            {
                printf("\nNo se encontro el Numero.\n");
            }
            break;
        }
        case 3:
        {
            // Opcion para borrar un elemento y reorganizar la lista
            eliminarNumero(inventario, &n);
            break;
        }

        case 4:
        {
            // Opcion para agregar un nuevo elemento y ordenar nuevamente
            agregarNumero(inventario, &n);
            break;
        }

        case 5:
            // Salida del bucle y fin del programa
            printf("\nSaliendo del programa...\n");
            break;

        default:
            // Manejo de ingreso de opciones incorrectas
            printf("\nOpcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 5);

    return 0;
}

//Funcion: Realiza una busqueda binaria (requiere que el arreglo este ordenado)
int buscarNumero(int inventario[], int n, int numeroBuscado)
{
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (inventario[medio] == numeroBuscado)
        {
            return medio; // Devuelve la posicion donde esta el dato
        }

        if (inventario[medio] < numeroBuscado)
        {
            inicio = medio + 1; // Busca en la mitad derecha
        }
        else
        {
            fin = medio - 1; // Busca en la mitad izquierda
        }
    }
    return -1; // Valor estandar para indicar "no encontrado"
}

// Funcion:  Muestra en pantalla todos los numeros con su posicion
void listarNumero(int inventario[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t %d \n",
               i + 1,
               inventario[i]);
    }
}

/* Funcion: eliminarNumero. 
 Busca un numero, si lo encuentra lo elimina y corre los demas elementos para no dejar huecos */
void eliminarNumero(int inventario[], int *n)
{
    int nroEliminar;
    printf("Ingrese el numero a eliminar: ");
    scanf("%d", &nroEliminar);

    int i, j;
    // Se inicializa en -1 para indicar que aun no se ha encontrado
    int encontrado = -1;

    // Busqueda secuencial para ubicar la posicion
    for (i = 0; i < *n; i++)
    {
        if (inventario[i] == nroEliminar)
        {
            encontrado = i; // Guarda el indice donde esta el dato
            break;
        }
    }

    if (encontrado == -1)
    {
        printf("\nNo se encontro el numero.\n");
        return;
    }

    // Desplaza todos los elementos una posicion hacia atras para sobrescribir el eliminado
    for (j = encontrado; j < *n - 1; j++)
    {
        inventario[j] = inventario[j + 1];
    }

    (*n)--; // Disminuye la cantidad logica de elementos
    printf("\nNumero eliminado correctamente.\n");
}

//Funcion: Agrega un nuevo numero al final del arreglo y llama al ordenamiento
void agregarNumero(int inventario[], int *n)
{
    if (*n >= MAX_NumeroS)
    {
        printf("\nNo se pueden agregar mas Numeros. Inventario lleno.\n");
        return;
    }

    int nuevoNumero;
    printf("Ingrese el numero: ");
    scanf("%d", &nuevoNumero);

    inventario[*n] = nuevoNumero; // Agrega el dato en la ultima posicion libre
    (*n)++; // Aumenta el contador de cantidad

    // MEJORA: Se llama a la funcion unica de ordenamiento, evitando duplicar el codigo Burbuja
    ordenarInventario(inventario, *n);

    printf("\nNumero agregado y ordenado correctamente.\n");
}

//Funcion: ordenarInventario - Algoritmo de ordenamiento Burbuja.
void ordenarInventario(int inventario[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (inventario[j] > inventario[j + 1])
            {
                // Intercambio de valores
                temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
}