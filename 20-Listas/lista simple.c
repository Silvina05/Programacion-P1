#include <stdio.h>
#include <stdlib.h>

// Definición solo con struct, sin typedef
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No hay memoria disponible\n");
        exit(1);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Insertar al inicio
void insertarInicio(struct Nodo** cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Insertar al final
void insertarFinal(struct Nodo** cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    struct Nodo* temp = *cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
}

// ✅ FUNCIÓN CORREGIDA: Insertar en POSICIÓN ESPECÍFICA (al medio)
void insertarEnPosicion(struct Nodo** cabeza, int dato, int posicion) {
    // Si la posición es 1 o lista vacía → insertar al inicio
    if (*cabeza == NULL || posicion == 1) {
        insertarInicio(cabeza, dato);
        printf("Insertado en la posición %d\n", posicion);
        return;
    }

    struct Nodo* nuevoNodo = crearNodo(dato);
    struct Nodo* actual = *cabeza;
    int contador = 1;

    // Recorremos hasta llegar a la posición anterior donde queremos insertar
    while (actual != NULL && contador < posicion - 1) {
        actual = actual->siguiente;
        contador++;
    }

    // Verificamos si la posición existe
    if (actual == NULL) {
        printf("❌ Posición inválida. Se insertará al final.\n");
        insertarFinal(cabeza, dato);
        free(nuevoNodo); // Liberamos el nodo que no usamos
        return;
    }

    // Enlazamos el nuevo nodo en el medio
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    printf("✅ Insertado correctamente en la posición %d\n", posicion);
}

void eliminarNodo(struct Nodo** cabeza, int valor) {
    struct Nodo* temp = *cabeza;
    struct Nodo* anterior = NULL;
    while (temp != NULL && temp->dato != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        printf("Valor no encontrado en la lista.\n");
        return;
    }
    if (anterior == NULL) {
        *cabeza = temp->siguiente;
    } else {
        anterior->siguiente = temp->siguiente;
    }
    free(temp);
    printf("Nodo con valor %d eliminado.\n", valor);
}

void buscarValor(struct Nodo* cabeza, int valor) {
    struct Nodo* temp = cabeza;
    while (temp != NULL) {
        if (temp->dato == valor) {
            printf("Valor %d encontrado en la lista.\n", valor);
            return;
        }
        temp = temp->siguiente;
    }
    printf("Valor %d no encontrado en la lista.\n", valor);
}

void mostrarValores(struct Nodo* cabeza) {
    struct Nodo* temp = cabeza;
    if (temp == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("Valores en la lista: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

void liberarLista(struct Nodo** cabeza) {
    struct Nodo* aux;
    while (*cabeza != NULL) {
        aux = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(aux);
    }
    printf("Memoria liberada.\n");
}

int main() {
    struct Nodo* lista = NULL;
    int opcion, valor, posicion;

    do {
        printf("\n=== OPERACIONES CON LISTA SIMPLE ===\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar en posición / al medio\n");
        printf("4. Eliminar un nodo\n");
        printf("5. Buscar un valor\n");
        printf("6. Mostrar todos los valores\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor: ");
                scanf("%d", &valor);
                insertarInicio(&lista, valor);
                break;
            case 2:
                printf("Ingrese el valor: ");
                scanf("%d", &valor);
                insertarFinal(&lista, valor);
                break;
            case 3:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                printf("Ingrese la posición donde insertar: ");
                scanf("%d", &posicion);
                insertarEnPosicion(&lista, valor, posicion);
                break;
            case 4:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(&lista, valor);
                break;
            case 5:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                buscarValor(lista, valor);
                break;
            case 6:
                mostrarValores(lista);
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 7);

    liberarLista(&lista);
    return 0;
}
