#include <stdio.h>
#include <string.h>
#define MAX_NUMEROS 1000

int buscarNumero(int inventario[], int n);
void listarNumero(int inventario[], int n);
void eliminarNumero(int inventario[], int *n);
void agregarNumero(int inventario[], int *n);  // Corregido: "agreagarNumero" -> "agregarNumero"

int main()
{
  int inventario[MAX_NUMEROS] = {87126, 87127, 87128, 87129, 87130, 87131, 87132, 87133, 87134, 87135, 87136, 87137, 87138, 87139, 87140, 87141, 87142, 87143, 87144, 87145};
  int n = 20;
  int i, j, temp;

  // Ordenamiento burbuja inicial
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (inventario[j] > inventario[j + 1])
      {
        temp = inventario[j];
        inventario[j] = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }

  int opcion;
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
      printf("\nInventario ordenado y actualizado:\n");
      listarNumero(inventario, n);
      break;

    case 2:
    {
      int numeroEncontrado;
      numeroEncontrado = buscarNumero(inventario, n);
      if (numeroEncontrado != 0)
      {
        printf("Numero encontrado: %d\n", numeroEncontrado);  // Corregido: "Numero de Numero" -> "Numero encontrado"
      }
      else
      {
        printf("\nNo se encontro el Numero.\n");
      }
      break;
    }

    case 3:
      eliminarNumero(inventario, &n);
      break;

    case 4:
      agregarNumero(inventario, &n);  // Corregido: "agreagarNumero" -> "agregarNumero"
      break;

    case 5:
      printf("\nSaliendo del programa...\n");
      break;

    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
      break;
    }
  } while (opcion != 5);

  return 0;
}

int buscarNumero(int inventario[], int n)
{
  int nroNumeroBuscado;
  int inicio = 0;
  int fin = n - 1;

  printf("Ingrese el numero a buscar: ");
  scanf("%d", &nroNumeroBuscado);

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    if (inventario[medio] == nroNumeroBuscado)
    {
      return inventario[medio];
    }
    if (inventario[medio] < nroNumeroBuscado)
    {
      inicio = medio + 1;
    }
    else
    {
      fin = medio - 1;
    }
  }
  return 0;
}

void listarNumero(int inventario[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d \t %d \n", i + 1, inventario[i]);
  }
}

void eliminarNumero(int inventario[], int *n)
{
  int nroEliminar;
  printf("Ingrese el numero a eliminar: ");
  scanf("%d", &nroEliminar);

  int i, j;
  int encontrado = 0;

  for (i = 0; i < *n; i++)
  {
    if (inventario[i] == nroEliminar)
    {
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("\nNo se encontro el numero.\n");
    return;
  }

  for (j = i; j < *n - 1; j++)
  {
    inventario[j] = inventario[j + 1];
  }
  (*n)--;
  printf("\nNumero eliminado correctamente.\n");
}

void agregarNumero(int inventario[], int *n)  // Corregido: "agreagarNumero" -> "agregarNumero"
{
  if (*n >= MAX_NUMEROS)
  {
    printf("\nNo se pueden agregar mas Numeros. Inventario lleno.\n");
    return;
  }

  int nuevoNumero;
  printf("Ingrese el numero: ");
  scanf("%d", &nuevoNumero);

  // Verificar duplicados  (agregado)
  for (int k = 0; k < *n; k++)
  {
    if (inventario[k] == nuevoNumero)
    {
      printf("\nEse numero ya existe en el inventario.\n");
      return;
    }
  }

  inventario[*n] = nuevoNumero;
  (*n)++;

  // Reordenar el inventario despues de agregar un nuevo numero
  int i, j, temp;
  for (i = 0; i < *n - 1; i++)
  {
    for (j = 0; j < *n - 1 - i; j++)
    {
      if (inventario[j] > inventario[j + 1])
      {
        temp = inventario[j];
        inventario[j] = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }
  printf("\nNumero agregado y ordenado correctamente.\n");
}
