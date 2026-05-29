#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTOS 1000

/** Definir la Estructura de los datos */
struct estudiante
{
  int dni;
  char nombre[20];
  char apellido[20];
  char carrera[20];
};

struct estudiante buscarestudiante(struct estudiante inventario[], int n);
void listarestudiante(struct estudiante inventario[], int n);
void eliminarestudiante(struct estudiante inventario[], int *n);
void agregarestudiante(struct estudiante inventario[], int *n);  // Corregido: "agreagarestudiante" -> "agregarestudiante"
void modificarestudiante(struct estudiante inventario[], int n);

int main()
{
  /** Inicializar los datos */
  struct estudiante inventario[MAX_PRODUCTOS] = {
      {389628,  "Jose",   "Garcia",    "TUP"},    // Corregido: apellidos y carreras reales
      {2716753, "Lopez",  "Martinez",  "FOL"},
      {128781,  "Carlos", "Rodriguez", "POLI"},
      {18738,   "Kike",   "Fernandez", "GABRIEL"},
      {187382,  "Jesus",  "Perez",     "RINO"},
      {182378,  "Alex",   "Gomez",     "FORN"}};

  int n = 6;
  int i, j;
  struct estudiante temp;

  // Ordenamiento burbuja inicial por DNI
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (inventario[j].dni > inventario[j + 1].dni)
      {
        temp = inventario[j];
        inventario[j] = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }

  /** Menu de opciones */
  int opcion;

  do
  {
    printf("\nMenu de opciones:\n");
    printf("1) Listar alumnos\n");
    printf("2) Buscar alumno\n");
    printf("3) Eliminar alumno\n");
    printf("4) Agregar alumno\n");
    printf("5) Modificar alumno\n");
    printf("6) Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      printf("\nEstudiantes ordenados por DNI:\n");
      listarestudiante(inventario, n);
      break;

    case 2:
    {
      struct estudiante estudianteEncontrado;
      estudianteEncontrado = buscarestudiante(inventario, n);
      if (estudianteEncontrado.dni != 0)
      {
        printf("\nEstudiante encontrado:\n");          // Corregido: "Producto encontrado" -> "Estudiante encontrado"
        printf("DNI: %d\n", estudianteEncontrado.dni);
        printf("Nombre: %s\n", estudianteEncontrado.nombre);
        printf("Apellido: %s\n", estudianteEncontrado.apellido);
        printf("Carrera: %s\n", estudianteEncontrado.carrera);
      }
      else
      {
        printf("\nNo se encontro el estudiante.\n");
      }
      break;
    }

    case 3:
      eliminarestudiante(inventario, &n);
      break;

    case 4:
      agregarestudiante(inventario, &n);  // Corregido: "agreagarestudiante" -> "agregarestudiante"
      break;

    case 5:
      modificarestudiante(inventario, n);
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

struct estudiante buscarestudiante(struct estudiante inventario[], int n)
{
  int dnibuscado;
  int inicio = 0;
  int fin = n - 1;

  printf("Ingrese el DNI a buscar: ");
  scanf("%d", &dnibuscado);

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;

    if (inventario[medio].dni == dnibuscado)
    {
      return inventario[medio];
    }

    if (inventario[medio].dni < dnibuscado)
    {
      inicio = medio + 1;
    }
    else
    {
      fin = medio - 1;
    }
  }

  // Devolver un estudiante vacio si no se encuentra
  struct estudiante vacio = {0, "", "", ""};
  return vacio;
}

void listarestudiante(struct estudiante inventario[], int n)
{
  for (int i = 0; i < n; i++)
  {
    // Corregido: agregado campo carrera que faltaba
    printf("%d \t %d \t %s \t %s \t %s\n",
           i + 1,
           inventario[i].dni,
           inventario[i].nombre,
           inventario[i].apellido,
           inventario[i].carrera);
  }
}

void eliminarestudiante(struct estudiante inventario[], int *n)
{
  int dnieliminar;
  printf("Ingrese el DNI del estudiante a eliminar: ");
  scanf("%d", &dnieliminar);

  int i, j;
  int encontrado = 0;

  for (i = 0; i < *n; i++)
  {
    if (inventario[i].dni == dnieliminar)
    {
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("\nNo se encontro un estudiante con ese DNI.\n");
    return;
  }

  for (j = i; j < *n - 1; j++)
  {
    inventario[j] = inventario[j + 1];
  }

  (*n)--;
  printf("\nEstudiante eliminado correctamente.\n");  // Corregido: "Producto eliminado" -> "Estudiante eliminado"
}

void agregarestudiante(struct estudiante inventario[], int *n)  // Corregido: "agreagarestudiante" -> "agregarestudiante"
{
  if (*n >= MAX_PRODUCTOS)
  {
    printf("\nNo se pueden agregar mas estudiantes. Lista llena.\n");
    return;
  }

  struct estudiante nuevoestudiante;

  printf("Ingrese el DNI del estudiante: ");
  scanf("%d", &nuevoestudiante.dni);

  // Verificar duplicados
  for (int k = 0; k < *n; k++)
  {
    if (inventario[k].dni == nuevoestudiante.dni)
    {
      printf("\nEse DNI ya existe en el sistema.\n");
      return;
    }
  }

  printf("Ingrese el nombre del estudiante: ");
  scanf(" %19[^\n]", nuevoestudiante.nombre);
  printf("Ingrese el apellido del estudiante: ");
  scanf(" %19[^\n]", nuevoestudiante.apellido);
  printf("Ingrese la carrera del estudiante: ");
  scanf(" %19[^\n]", nuevoestudiante.carrera);

  inventario[*n] = nuevoestudiante;
  (*n)++;

  // Reordenar por DNI despues de agregar
  int i, j;
  struct estudiante temp;

  for (i = 0; i < *n - 1; i++)
  {
    for (j = 0; j < *n - 1 - i; j++)
    {
      if (inventario[j].dni > inventario[j + 1].dni)
      {
        temp = inventario[j];
        inventario[j] = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }

  printf("\nAlumno agregado y ordenado correctamente.\n");
}

void modificarestudiante(struct estudiante inventario[], int n)
{
  int dnimodificar;
  printf("Ingrese el DNI del estudiante a modificar: ");
  scanf("%d", &dnimodificar);

  int indice = -1;
  for (int i = 0; i < n; i++)
  {
    if (inventario[i].dni == dnimodificar)
    {
      indice = i;
      break;
    }
  }

  if (indice == -1)
  {
    printf("\nNo se encontro el estudiante.\n");
    return;
  }

  printf("Datos actuales -> Nombre: %s | Apellido: %s | Carrera: %s\n",
         inventario[indice].nombre,
         inventario[indice].apellido,
         inventario[indice].carrera);

  printf("Ingrese el nuevo nombre: ");
  scanf(" %19[^\n]", inventario[indice].nombre);
  printf("Ingrese el nuevo apellido: ");
  scanf(" %19[^\n]", inventario[indice].apellido);
  printf("Ingrese la nueva carrera: ");
  scanf(" %19[^\n]", inventario[indice].carrera);

  printf("\nEstudiante modificado correctamente.\n");
}
