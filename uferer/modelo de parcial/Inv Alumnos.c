#include <stdio.h>
#include <string.h>   /* strcmp() para comparar strings completos */

struct Persona
{
  int  dni;
  char nombre[30];
  char apellido[30];
};

/* ── Prototipo de la función (AGREGADO) ─────────────────── */
void ordenarAlumnosNombreyApellido(struct Persona alumnos[], int cantidad);

int main()
{
  struct Persona alumnos[] = {
      {40234567, "Ana",       "Gomez"},
      {30123456, "Luis",      "Perez"},
      {50345678, "Mariana",   "Lopez"},
      {20111222, "Carlos",    "Sanchez"},
      {45123400, "Sofia",     "Diaz"},
      {35000000, "Jorge",     "Martinez"},
      {27567890, "Lucia",     "Garcia"},
      {48000000, "Diego",     "Fernandez"},
      {32000000, "Valentina", "Rodriguez"}};

  int cantidad = sizeof(alumnos) / sizeof(alumnos[0]);

  int i, j;
  struct Persona aux;

  /* ── 1. Ordenar por DNI (Brbuja) ───────────────────── */
  for (i = 0; i < cantidad - 1; i++)
  {
    for (j = 0; j < cantidad - i - 1; j++)
    {
      if (alumnos[j].dni > alumnos[j + 1].dni)
      {
        aux          = alumnos[j];
        alumnos[j]   = alumnos[j + 1];
        alumnos[j + 1] = aux;
      }
    }
  }

  /* ── 2. Búsqueda binaria por DNI  */
  int dniBuscado = 20111222;
  int inicio     = 0;
  int fin        = cantidad - 1;
  int encontrado = 0;

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;

    if (alumnos[medio].dni == dniBuscado)
    {
      printf("Alumno encontrado: %s %s, DNI: %d\n",
             alumnos[medio].nombre,
             alumnos[medio].apellido,
             alumnos[medio].dni);
      encontrado = 1;
      break;
    }
    else if (alumnos[medio].dni < dniBuscado)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }

  if (!encontrado)
    printf("Alumno con DNI %d no encontrado.\n", dniBuscado);

  /* ── 3. Mostrar alumnos ordenados por DNI  */
  printf("\nAlumnos ordenados por DNI:\n");
  for (i = 0; i < cantidad; i++)
  {
    printf("\t %d \t %-15s \t %s\n",
           alumnos[i].dni,
           alumnos[i].nombre,
           alumnos[i].apellido);
  }

  /* ── 4. Ordenar y mostrar por Apellido y Nombre  */
  ordenarAlumnosNombreyApellido(alumnos, cantidad);   /* LLAMADA AGREGADA */

  printf("\nAlumnos ordenados por Apellido y Nombre:\n");
  for (i = 0; i < cantidad; i++)
  {
    printf("\t %-15s \t %s\n",
           alumnos[i].apellido,
           alumnos[i].nombre);
  }

  return 0;
}

/* ============================================================
 *  ordenarAlumnosNombreyApellido
 *  Ordena alfabéticamente por apellido completo;
 *  en caso de empate, ordena por nombre completo.
 *
 *  CORRECCIÓN: se usa strcmp() en lugar de comparar solo
 *  el primer carácter ([0]), que daba orden incorrecto
 *  para apellidos como "Garcia" vs "Gomez".
 * ============================================================ */
void ordenarAlumnosNombreyApellido(struct Persona alumnos[], int cantidad)
{
  int i, j;
  struct Persona aux;

  for (i = 0; i < cantidad - 1; i++)
  {
    for (j = 0; j < cantidad - i - 1; j++)
    {
      int cmpApellido = strcmp(alumnos[j].apellido, alumnos[j + 1].apellido);
      int cmpNombre   = strcmp(alumnos[j].nombre,   alumnos[j + 1].nombre);

      /* Ordenar por apellido; si son iguales, desempatar por nombre */
      if (cmpApellido > 0 || (cmpApellido == 0 && cmpNombre > 0))
      {
        aux              = alumnos[j];
        alumnos[j]       = alumnos[j + 1];
        alumnos[j + 1]   = aux;
      }
    }
  }
}