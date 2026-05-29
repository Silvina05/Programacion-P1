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
  char editorial[MAX_TEXTO];
  char genero[MAX_TEXTO];
  int isbn;
  int anioPublicacion;
  struct Autor autor;
};

void listarLibros(struct Libro libros[], int cantidad)
{
  printf("--------------------\n");

  printf("LISTADO DE LIBROS:\n");
  for (int i = 0; i < cantidad; i++)
  {
    printf("Título: %s", libros[i].titulo);
    printf("Editorial: %s", libros[i].editorial);
    printf("Género: %s", libros[i].genero);
    printf("ISBN: %d\n", libros[i].isbn);
    printf("Año de publicación: %d\n", libros[i].anioPublicacion);
    printf("Autor: %s\n", libros[i].autor.nombre);
    printf("Nacionalidad del autor: %s\n", libros[i].autor.nacionalidad);
    printf("Cantidad de libros publicados por el autor: %d\n", libros[i].autor.cantLibrosPublicados);
    printf("--------------------\n");
  }
}

void cargarLibro(struct Libro libros[], struct Autor autores[], int i)
{
  printf("Ingrese el título del libro %d: ", i + 1);
  fgets(libros[i].titulo, MAX_TEXTO, stdin);

  printf("Ingrese la editorial del libro %d: ", i + 1);
  fgets(libros[i].editorial, MAX_TEXTO, stdin);

  printf("Ingrese el género del libro %d: ", i + 1);
  fgets(libros[i].genero, MAX_TEXTO, stdin);

  printf("Ingrese el ISBN del libro %d: ", i + 1);
  scanf("%d", &libros[i].isbn);

  printf("Ingrese el año de publicación del libro %d: ", i + 1);
  scanf(" %d", &libros[i].anioPublicacion);
  getchar(); // Limpiar el buffer de entrada

  // Asignar un autor al libro (en este caso, se asigna el primer autor)
  printf("Ingrese el ID del autor para el libro %d: ", i + 1);
  int idAutor;
  scanf(" %d", &idAutor);
  libros[i].autor = autores[idAutor - 1];
  printf("--------------------\n");
}

void cargarAutor(struct Autor autores[], int i)
{
  printf("Ingrese el nombre del autor %d: ", i + 1);
  fgets(autores[i].nombre, MAX_TEXTO, stdin);

  printf("Ingrese la nacionalidad del autor %d: ", i + 1);
  fgets(autores[i].nacionalidad, MAX_TEXTO, stdin);

  printf("Ingrese la cantidad de libros publicados por el autor %d: ", i + 1);
  scanf(" %d", &autores[i].cantLibrosPublicados);
  getchar(); // Limpiar el buffer de entrada
  printf("--------------------\n");
}

void cargarAutores(struct Autor autores[], int cantidad)
{
  printf("CARGA DE AUTORES:\n");
  for (int i = 0; i < cantidad; i++)
  {
    cargarAutor(autores, i);
  }
}

void cargarLibros(struct Libro libros[], struct Autor autores[], int cantidad)
{
  printf("CARGA DE LIBROS:\n");
  for (int i = 0; i < cantidad; i++)
  {
    cargarLibro(libros, autores, i);
  }
}

int main()
{
  struct Autor autores[CANT_AUTORES];
  struct Libro libros[CANT_LIBROS];

  cargarAutores(autores, CANT_AUTORES);
  cargarLibros(libros, autores, CANT_LIBROS);
  listarLibros(libros, CANT_LIBROS);

  return 0;
}