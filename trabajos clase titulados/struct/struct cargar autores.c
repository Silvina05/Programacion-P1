#include <stdio.h>

#define CANT_LIBROS 3
#define MAX_TEXTO 100
#define CANT_AUTORES 2

struct Autor
{
  char nombre[MAX_TEXTO];
  char nacionalidad[MAX_TEXTO];
  int cantLibrosPublicados;
};

struct Libro
{
  char titulo[MAX_TEXTO];
  struct Autor autor;
  char editorial[MAX_TEXTO];
  char genero[MAX_TEXTO];
  int isbn;
  int anioPublicacion;
};

int main()
{
  struct Autor autores[CANT_AUTORES];

  printf("CARGA DE AUTORES:\n");
  for (int i = 0; i < CANT_AUTORES; i++)
  {
    printf("Ingrese el nombre del autor %d: ", i + 1);
    fgets(autores[i].nombre, MAX_TEXTO, stdin);

    printf("Ingrese la nacionalidad del autor %d: ", i + 1);
    fgets(autores[i].nacionalidad, MAX_TEXTO, stdin);

    printf("Ingrese la cantidad de libros publicados por el autor %d: ", i + 1);
    scanf("%d", &autores[i].cantLibrosPublicados);
    getchar(); // Limpiar el buffer
  }

  struct Libro libros[CANT_LIBROS];

  printf("CARGA DE LIBROS:\n");
  for (int i = 0; i < CANT_LIBROS; i++)
  {
    printf("Ingrese el título del libro %d: ", i + 1);
    fgets(libros[i].titulo, MAX_TEXTO, stdin);

    printf("Ingrese el nombre del autor del libro %d: ", i + 1);
    fgets(libros[i].autor.nombre, MAX_TEXTO, stdin);

    printf("Ingrese la nacionalidad del autor del libro %d: ", i + 1);
    fgets(libros[i].autor.nacionalidad, MAX_TEXTO, stdin);

    printf("Ingrese la cantidad de libros publicados por el autor del libro %d: ", i + 1);
    scanf("%d", &libros[i].autor.cantLibrosPublicados);
    getchar(); // Limpiar el buffer

    printf("Ingrese la editorial del libro %d: ", i + 1);
    fgets(libros[i].editorial, MAX_TEXTO, stdin);

    printf("Ingrese el género del libro %d: ", i + 1);
    fgets(libros[i].genero, MAX_TEXTO, stdin);

    printf("Ingrese el ISBN del libro %d: ", i + 1);
    scanf("%d", &libros[i].isbn);
    getchar(); // Limpiar el buffer

    printf("Ingrese el año de publicación del libro %d: ", i + 1);
    scanf("%d", &libros[i].anioPublicacion);
    getchar(); // Limpiar el buffer
  }
  return 0;
}