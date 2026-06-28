#include <stdio.h>
#include <string.h>
#define MAX_ALUMNOS 100

struct Persona
{
  int dni;
  char nombre[30];
  char apellido[30];
};

// Prototipos
void ordenarAlumnosPorDNI(struct Persona alumnos[], int cantidad);
void ordenarAlumnosPorApellidoYNombre(struct Persona alumnos[], int cantidad);
void buscarAlumno(struct Persona alumnos[], int cantidad);
void listarAlumnos(struct Persona alumnos[], int cantidad);
void agregarAlumno(struct Persona alumnos[], int *cantidad);
void eliminarAlumno(struct Persona alumnos[], int *cantidad);
void mostrarMenu();

int main()
{
  struct Persona alumnos[MAX_ALUMNOS] = {
      {40234567, "Ana", "Gomez"},
      {30123456, "Luis", "Perez"},
      {50345678, "Mariana", "Lopez"},
      {20111222, "Carlos", "Sanchez"},
      {45123400, "Sofia", "Diaz"},
      {35000000, "Jorge", "Martinez"},
      {27567890, "Lucia", "Garcia"},
      {48000000, "Diego", "Fernandez"},
      {32000000, "Valentina", "Rodriguez"}};

  int cantidad = 9;

  // Ordenar al inicio para que la búsqueda binaria funcione
  ordenarAlumnosPorDNI(alumnos, cantidad);

  int opcion;

  do
  {
    mostrarMenu();
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      listarAlumnos(alumnos, cantidad);
      break;
    case 2:
      buscarAlumno(alumnos, cantidad);
      break;
    case 3:
      ordenarAlumnosPorDNI(alumnos, cantidad);
      printf("Alumnos ordenados por DNI.\n");
      listarAlumnos(alumnos, cantidad);
      break;
    case 4:
      ordenarAlumnosPorApellidoYNombre(alumnos, cantidad);
      printf("Alumnos ordenados por apellido y nombre.\n");
      listarAlumnos(alumnos, cantidad);
      break;
    case 5:
      agregarAlumno(alumnos, &cantidad);
      break;
    case 6:
      eliminarAlumno(alumnos, &cantidad);
      break;
    case 7:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opcion invalida.\n");
    }

  } while (opcion != 7);

  return 0;
}

void mostrarMenu()
{
  printf("\nMenu de opciones:\n");
  printf("1. Listar alumnos\n");
  printf("2. Buscar alumno por DNI\n");
  printf("3. Ordenar y listar por DNI\n");
  printf("4. Ordenar y listar por apellido y nombre\n");
  printf("5. Agregar alumno\n");
  printf("6. Eliminar alumno\n");
  printf("7. Salir\n");
}

// CORREGIDO: Bubble Sort por DNI extraido del main a su propia funcion
void ordenarAlumnosPorDNI(struct Persona alumnos[], int cantidad)
{
  int i, j;
  struct Persona aux;

  for (i = 0; i < cantidad - 1; i++)
  {
    for (j = 0; j < cantidad - i - 1; j++)
    {
      if (alumnos[j].dni > alumnos[j + 1].dni)
      {
        aux = alumnos[j];
        alumnos[j] = alumnos[j + 1];
        alumnos[j + 1] = aux;
      }
    }
  }
}

// CORREGIDO: usa strcmp() en lugar de comparar solo la primera letra
void ordenarAlumnosPorApellidoYNombre(struct Persona alumnos[], int cantidad)
{
  int i, j;
  struct Persona aux;

  for (i = 0; i < cantidad - 1; i++)
  {
    for (j = 0; j < cantidad - i - 1; j++)
    {
      int cmpApellido = strcmp(alumnos[j].apellido, alumnos[j + 1].apellido);

      if (cmpApellido > 0 ||
          (cmpApellido == 0 && strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0))
      {
        aux = alumnos[j];
        alumnos[j] = alumnos[j + 1];
        alumnos[j + 1] = aux;
      }
    }
  }
}

// CORREGIDO: Busqueda Binaria extraida del main a su propia funcion
// El DNI ya no esta hardcodeado, se pide por teclado
void buscarAlumno(struct Persona alumnos[], int cantidad)
{
  int dniBuscado;
  printf("Ingrese el DNI a buscar: ");
  scanf("%d", &dniBuscado);

  // Ordenar antes de buscar (requisito de la busqueda binaria)
  ordenarAlumnosPorDNI(alumnos, cantidad);

  int inicio = 0;
  int fin = cantidad - 1;
  int encontrado = 0;

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;

    if (alumnos[medio].dni == dniBuscado)
    {
      printf("Alumno encontrado: %s %s, DNI: %d\n",
             alumnos[medio].nombre, alumnos[medio].apellido, alumnos[medio].dni);
      encontrado = 1;
      break;
    }
    else if (alumnos[medio].dni < dniBuscado)
    {
      inicio = medio + 1;
    }
    else
    {
      fin = medio - 1;
    }
  }

  if (!encontrado)
  {
    printf("Alumno con DNI %d no encontrado.\n", dniBuscado);
  }
}

// NUEVO: listar alumnos extraido del main a su propia funcion
void listarAlumnos(struct Persona alumnos[], int cantidad)
{
  if (cantidad == 0)
  {
    printf("No hay alumnos cargados.\n");
    return;
  }
  printf("\nLista de alumnos:\n");
  for (int i = 0; i < cantidad; i++)
  {
    printf("\t%d \t %s \t %s\n",
           alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellido);
  }
}

// NUEVO: agregar alumno
void agregarAlumno(struct Persona alumnos[], int *cantidad)
{
  if (*cantidad >= MAX_ALUMNOS)
  {
    printf("No se pueden agregar mas alumnos. Capacidad maxima alcanzada.\n");
    return;
  }

  struct Persona nuevo;
  printf("Ingrese el DNI: ");
  scanf("%d", &nuevo.dni);
  printf("Ingrese el nombre: ");
  scanf("%s", nuevo.nombre);
  printf("Ingrese el apellido: ");
  scanf("%s", nuevo.apellido);

  alumnos[*cantidad] = nuevo;
  (*cantidad)++;

  // Reordenar por DNI despues de agregar
  ordenarAlumnosPorDNI(alumnos, *cantidad);

  printf("Alumno agregado correctamente.\n");
}

// NUEVO: eliminar alumno por DNI
void eliminarAlumno(struct Persona alumnos[], int *cantidad)
{
  int dniEliminar;
  printf("Ingrese el DNI del alumno a eliminar: ");
  scanf("%d", &dniEliminar);

  int i, j;
  int encontrado = 0;

  for (i = 0; i < *cantidad; i++)
  {
    if (alumnos[i].dni == dniEliminar)
    {
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("Alumno con DNI %d no encontrado.\n", dniEliminar);
    return;
  }

  for (j = i; j < *cantidad - 1; j++)
  {
    alumnos[j] = alumnos[j + 1];
  }

  (*cantidad)--;
  printf("Alumno con DNI %d eliminado correctamente.\n", dniEliminar);
}