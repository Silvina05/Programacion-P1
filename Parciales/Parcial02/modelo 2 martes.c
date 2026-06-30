/* función ordenarAlumnos,ordene el arreglo por DNI usando el Método de la Burbuja*/
void ordenarAlumnos(struct Persona alumnos[], int cantidad)
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

/* función buscarAlumno,busque un alumno por DNI usando Búsqueda Binaria: */
struct Persona buscarAlumno(struct Persona alumnos[], int cantidad, int dni)
{
    ordenarAlumnos(alumnos, cantidad);

    int inicio = 0;
    int fin = cantidad - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (alumnos[medio].dni == dni)
        {
            return alumnos[medio];
        }
        else if (alumnos[medio].dni < dni)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }

    struct Persona alumnoNoEncontrado = {-1, "", ""};
    return alumnoNoEncontrado;
}


/*función listarAlumnos, que muestre todos los alumnos ordenados: */
void listarAlumnos(struct Persona alumnos[], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay alumnos cargados.\n");
        return;
    }

    printf("\nAlumnos ordenados por DNI:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("\t%d \t %s \t %s\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellido);
    }
}



/*función agregarAlumno, que permita agregar un nuevo alumno:*/
void agregarAlumno(struct Persona alumnos[], int *cantidad)
{
    if (*cantidad >= 100)
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

    ordenarAlumnos(alumnos, *cantidad);
    printf("Alumno agregado correctamente.\n");
}


/*función eliminarAlumno, que elimine un alumno por DNI: */
void eliminarAlumno(struct Persona alumnos[], int *cantidad, int dni)
{
    int i, j;
    int encontrado = 0;

    for (i = 0; i < *cantidad; i++)
    {
        if (alumnos[i].dni == dni)
        {
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
    {
        for (j = i; j < *cantidad - 1; j++)
        {
            alumnos[j] = alumnos[j + 1];
        }
        (*cantidad)--;
        printf("Alumno con DNI %d eliminado.\n", dni);
    }
    else
    {
        printf("Alumno con DNI %d no encontrado.\n", dni);
    }
}


/*función ordenarAlumnosPorApellidoYNombre, que ordene alfabéticamente:  */

void ordenarAlumnosPorApellidoYNombre(struct Persona alumnos[], int cantidad)
{
    int i, j;
    struct Persona aux;

    for (i = 0; i < cantidad - 1; i++)
    {
        for (j = 0; j < cantidad - i - 1; j++)
        {
            int cmp = strcmp(alumnos[j].apellido, alumnos[j + 1].apellido);
            if (cmp > 0 || (cmp == 0 && strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0))
            {
                aux = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = aux;
            }
        }
    }
}


 /*función mostrarEstadisticas, que muestre la cantidad total de alumnos:*/
void mostrarEstadisticas(struct Persona alumnos[], int cantidad)
{
    printf("Total de alumnos: %d\n", cantidad);
}



