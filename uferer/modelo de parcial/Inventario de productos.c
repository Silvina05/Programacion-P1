#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTOS 1000

/** Definir la Estructura de los datos */
struct Producto
{
  int nroProducto;
  char nombre[20];
  float precio;
};

//Prototipos
struct Producto buscarProducto(struct Producto inventario[], int n, int nroBuscado);
void listarProductos(struct Producto inventario[], int n);
void eliminarProducto(struct Producto inventario[], int *n);
void agreagarProducto(struct Producto inventario[], int *n);
void modificarProducto(struct Producto inventario[], int n);  /* <-- AGREGADO */

int main()
{
  /** Inicializar los datos  */
  struct Producto inventario[MAX_PRODUCTOS] = {
      {58293012, "Monitor",      120.00},
      {19485726, "Mousepad",      10.00},
      {83746501, "Procesador",   200.00},
      {37482910, "Teclado",       25.50},
      {92837465, "Fuente ATX",    75.00},
      {48291037, "Webcam",        55.00},
      {10293847, "Silla Gamer",  250.00},
      {74659283, "Impresora",     85.00},
      {29384756, "Disco SSD",     95.00},
      {65748392, "Mouse Choco",   15.75},
      {51928374, "Parlantes",     40.20},
      {84756291, "Cables HDMI",    8.50},
      {38475629, "Auriculares",   65.50},
      {91028374, "Gabinete",      60.00},
      {27384950, "Microfono",     30.00},
      {46573829, "Adaptador USB",  5.99},
      {15263748, "Memoria RAM",   50.00},
      {73849506, "Pendrive",      12.99},
      {62738495, "Placa Video",  350.00},
      {39485761, "Escritorio",   150.00}};

  int n = 20;

  /* Ordenar el inventario inicial por nroProducto (Burbuja) */
  int i, j;
  struct Producto temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (inventario[j].nroProducto > inventario[j + 1].nroProducto)
      {
        temp           = inventario[j];
        inventario[j]  = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }

  int opcion;

  do
  {
    printf("\nMenu de opciones:\n");
    printf("1) Listar Productos\n");
    printf("2) Buscar Producto\n");
    printf("3) Eliminar Producto\n");
    printf("4) Agregar un producto\n");
    printf("5) Modificar Producto\n");
    printf("6) Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      printf("\nInventario ordenado y actualizado:\n");
      listarProductos(inventario, n);
      break;

    case 2:
    {
      int nroBuscado;
      printf("Ingrese el numero de producto a buscar: ");
      scanf("%d", &nroBuscado);

      struct Producto productoEncontrado = buscarProducto(inventario, n, nroBuscado);

      if (productoEncontrado.nroProducto != 0)
      {
        printf("\nProducto encontrado:\n");
        printf("Numero de Producto: %d\n", productoEncontrado.nroProducto);
        printf("Nombre: %s\n",            productoEncontrado.nombre);
        printf("Precio: %.2f\n",          productoEncontrado.precio);
      }
      else
      {
        printf("\nNo se encontro el producto.\n");
      }
      break;
    }

    case 3:
      eliminarProducto(inventario, &n);
      break;

    case 4:
      agreagarProducto(inventario, &n);
      break;

    case 5:
      modificarProducto(inventario, n);   /* <-- AHORA FUNCIONA */
      break;

    case 6:
      printf("\nSaliendo del programa...\n");
      break;

    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
      break;
    }
  } while (opcion != 6);

  return 0;
}

/* ============================================================
 *  buscarProducto  –  Búsqueda binaria
 *  Recibe el número a buscar como parámetro
 *  Retorna el producto encontrado, o uno vacío si no existe.
 * ============================================================ */
struct Producto buscarProducto(struct Producto inventario[], int n, int nroBuscado)
{
  int inicio = 0;
  int fin    = n - 1;

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;

    if (inventario[medio].nroProducto == nroBuscado)
      return inventario[medio];

    if (inventario[medio].nroProducto < nroBuscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }

  struct Producto productoVacio = {0, "", 0.0};
  return productoVacio;
}

/* ====== listarProductos */
void listarProductos(struct Producto inventario[], int n)
{
  printf("%-5s %-12s %-20s %s\n", "Pos.", "Nro.Prod.", "Nombre", "Precio");
  printf("%-5s %-12s %-20s %s\n", "-----","------------","--------------------","-------");

  for (int i = 0; i < n; i++)
  {
    printf("%-5d %-12d %-20s $%.2f\n",
           i + 1,
           inventario[i].nroProducto,
           inventario[i].nombre,
           inventario[i].precio);
  }
}

/* ======= eliminarProducto */
void eliminarProducto(struct Producto inventario[], int *n)
{
  int nroProductoEliminar;
  printf("Ingrese el numero de producto a eliminar: ");
  scanf("%d", &nroProductoEliminar);

  int i, j;
  int encontrado = 0;

  for (i = 0; i < *n; i++)
  {
    if (inventario[i].nroProducto == nroProductoEliminar)
    {
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("\nNo se encontro un producto con ese numero.\n");
    return;
  }

  for (j = i; j < *n - 1; j++)
    inventario[j] = inventario[j + 1];

  (*n)--;
  printf("\nProducto eliminado correctamente.\n");
}

/* ==== agreagarProducto */
void agreagarProducto(struct Producto inventario[], int *n)
{
  if (*n >= MAX_PRODUCTOS)
  {
    printf("\nNo se pueden agregar mas productos. Inventario lleno.\n");
    return;
  }

  struct Producto nuevoProducto;

  printf("Ingrese el numero de producto: ");
  scanf("%d", &nuevoProducto.nroProducto);
  printf("Ingrese el nombre del producto: ");
  scanf(" %19[^\n]", nuevoProducto.nombre);
  printf("Ingrese el precio del producto: ");
  scanf("%f", &nuevoProducto.precio);

  inventario[*n] = nuevoProducto;
  (*n)++;

  /* Reordenar el inventario después de agregar (Burbuja) */
  int i, j;
  struct Producto temp;

  for (i = 0; i < *n - 1; i++)
  {
    for (j = 0; j < *n - 1 - i; j++)
    {
      if (inventario[j].nroProducto > inventario[j + 1].nroProducto)
      {
        temp              = inventario[j];
        inventario[j]     = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }

  printf("\nProducto agregado y ordenado correctamente.\n");
}

/* ============================================================
 *  modificarProducto  
 *
 *  Flujo correcto:
 *    1. Pide el número de producto a modificar (un solo scanf).
 *    2. Lo busca con buscarProducto (ya no hace scanf interno).
 *    3. Muestra los datos actuales.
 *    4. Pide nuevos nombre y precio.
 *    5. Actualiza el registro directamente en el arreglo.
 * ============================================================ */
void modificarProducto(struct Producto inventario[], int n)
{
  int nroProductoModificar;
  printf("Ingrese el numero de producto a modificar: ");
  scanf("%d", &nroProductoModificar);

  /* Buscar usando la versión que recibe el número por parámetro */
  struct Producto productoEncontrado = buscarProducto(inventario, n, nroProductoModificar);

  if (productoEncontrado.nroProducto == 0)
  {
    printf("\nNo se encontro el producto.\n");
    return;
  }

  /* Mostrar datos actuales antes de modificar */
  printf("\nDatos actuales del producto:\n");
  printf("  Numero : %d\n",   productoEncontrado.nroProducto);
  printf("  Nombre : %s\n",   productoEncontrado.nombre);
  printf("  Precio : %.2f\n", productoEncontrado.precio);

  /* Leer nuevos valores */
  printf("\nIngrese el nuevo nombre del producto: ");
  scanf(" %19[^\n]", productoEncontrado.nombre);
  printf("Ingrese el nuevo precio del producto: ");
  scanf("%f", &productoEncontrado.precio);

  /* Actualizar el registro en el arreglo original */
  for (int i = 0; i < n; i++)
  {
    if (inventario[i].nroProducto == nroProductoModificar)
    {
      inventario[i] = productoEncontrado;
      break;
    }
  }

  printf("\nProducto modificado correctamente.\n");
}