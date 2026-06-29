//entidad :el nombre del struct . y define el nombre de todas las funciones
//CAMPOS: son lo que está adentro del struct


/* ejemplo:

struct Empleado
{
    int legajo;    es el ID se usa para buscar ,eliminar , habilitar/deshabilitar, modificar
    char nombre[30];   es el DATO, se modifica 
    char sector[30];   es el DATO, se modifica
    float salario;    es el VALOR NUMERICO, se ordena, se modifica con & en scanf
    int activo;  es el ESTADO, se usa en habilitar/deshabilitar/listar activos
};

*/

/* 
ID: Es un int único, suele llamarse dni, nroProducto, codigo...
Para buscar, eliminar, habilitar

DATO: Es un char[], suele ser nombre, apellido, descripción...
Se modifica en modificar     scanf("%s", arr[i].nombre);

VALOR NUMERICO: Es float o int, suele ser saldo, precio, valor...
Se ordena en listarPorValor Y  se modifica en modificar   scanf("%f", &arr[i].saldo); 

ESTADO: Es int con valor 0 o 1, suele llamarse habilitado, activo...
Se cambia en habilitar/deshabilitar
*/




/*Ordenar — NUNCA cambia la lógica, solo el campo 
>   orden ascendente
<   orden descendente */

void ordenarXXX(struct Entidad arr[], int cantidad) 
{
    struct Entidad aux;
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            // CAMBIA: el campo a comparar
            if (arr[j].CAMPO > arr[j+1].CAMPO)
            {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}




//Buscar (Búsqueda Binaria) — NUNCA cambia la lógica
struct Entidad buscarXXX(struct Entidad arr[], int cantidad, int id)
{
    ordenarXXX(arr, cantidad);   // SIEMPRE ordena primero

    int inicio = 0;
    int fin = cantidad - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio].id == id)
            return arr[medio];
        else if (arr[medio].id < id)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }

    // CAMBIA: el centinela según el tipo de ID
    // Si ID es int:   struct Entidad vacio = {-1, "", "", 0.0, 0};
    // Si ID es 0:     struct Entidad vacio = {0, "", "", 0.0, 0};
    struct Entidad vacio = {-1, "", "", 0.0, 0};
    return vacio;
}


//Listar por campo numérico — NUNCA cambia la lógica
void listarXXXPorCAMPO(struct Entidad arr[], int cantidad)
{
    // Bubble Sort propio (no llama a ordenarXXX porque ordena por otro campo)
    struct Entidad aux;
    for (int i = 0; i < cantidad - 1; i++)
        for (int j = 0; j < cantidad - i - 1; j++)
            if (arr[j].CAMPO < arr[j+1].CAMPO) // < para descendente
            {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }

    // CAMBIA: los campos que se imprimen
    for (int i = 0; i < cantidad; i++)
        printf("...", arr[i].campo1, arr[i].campo2 ...);
}


//Listar por ID — SIEMPRE llama a ordenar
void listarXXXPorID(struct Entidad arr[], int cantidad)
{
    ordenarXXX(arr, cantidad);  // reutiliza la función de ordenar

    for (int i = 0; i < cantidad; i++)
        printf("...", arr[i].campo1, arr[i].campo2 ...);
}


void listarXXXPorVALOR(struct ENTIDAD arr[], int cantidad)
{
    struct ENTIDAD aux;
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if (arr[j].VALOR < arr[j + 1].VALOR)  // < = descendente (mayor a menor)
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

    printf("XXX ordenados por VALOR (de mayor a menor):\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("ID: %d, DATO1: %s, DATO2: %s, VALOR: %.2f\n",
               arr[i].ID,
               arr[i].DATO1,
               arr[i].DATO2,
               arr[i].VALOR);
    }
}



//Listar activos/habilitados — SIEMPRE filtra por estado
void listarXXXActivos(struct Entidad arr[], int cantidad)
{
    if (cantidad == 0)          // verificar si hay datos
    {
        printf("No hay datos cargados.\n");
        return;
    }

    int encontrados = 0;
    for (int i = 0; i < cantidad; i++)
    {
        // CAMBIA: el nombre del campo estado (habilitado, activo, disponible...)
        if (arr[i].estado == 1)
        {
            printf("...", arr[i].campo1 ...);
            encontrados++;
        }
    }

    if (encontrados == 0)
        printf("No hay elementos activos.\n");
    else
        printf("Total: %d\n", encontrados);  // siempre mostrar total
}



//Habilitar/Deshabilitar — SIEMPRE verificar estado previo
void habilitarXXX(struct Entidad arr[], int cantidad, int id)
{
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (arr[i].id == id)
        {
            encontrado = 1;
            // CAMBIA: el nombre del campo estado
            if (arr[i].estado == 1)
                printf("Ya se encuentra habilitado.\n");
            else
            {
                arr[i].estado = 1;  // 0 para deshabilitar
                printf("Habilitado correctamente.\n");
            }
            break;
        }
    }
    if (!encontrado)
        printf("No encontrado.\n");
}



//Modificar — SIEMPRE busca, muestra, pide nuevos valores
void modificarXXX(struct Entidad arr[], int cantidad, int id)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (arr[i].id == id)
        {
            // Mostrar datos actuales
            printf("Encontrado: %s %s\n", arr[i].campo1, arr[i].campo2);

            // CAMBIA: los campos que se pueden modificar
            printf("Nuevo campo1: ");
            scanf("%s", arr[i].campo1);
            printf("Nuevo campo2: ");
            scanf("%s", arr[i].campo2);
            printf("Nuevo valor: ");
            scanf("%f", &arr[i].valorNumerico);  // ojo el & en float/int

            printf("Modificado correctamente.\n");
            return;
        }
    }
    printf("No encontrado.\n");
}



