#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo, SIN usar typedef
struct Nodo {
	int dato;
	struct Nodo* siguiente; // Apunta al siguiente nodo de la lista
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

// Función para insertar un nodo al inicio de la lista
void insertarInicio(struct Nodo** cabeza, int dato) {
	struct Nodo* nuevoNodo = crearNodo(dato);
	nuevoNodo->siguiente = *cabeza;
	*cabeza = nuevoNodo;
}

// Función para insertar un nodo al final de la lista
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

// Función para eliminar un nodo con un valor específico
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

// Función para buscar un valor en la lista
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

// Función para mostrar todos los valores de la lista
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

// Función principal
int main() {
	struct Nodo* lista = NULL;
	int opcion, valor;
	
	do {
		printf("\nOperaciones con Listas:\n");
		printf("1. Insertar al inicio\n");
		printf("2. Insertar al final\n");
		printf("3. Eliminar un nodo\n");
		printf("4. Buscar un valor\n");
		printf("5. Mostrar todos los valores\n");
		printf("6. Salir\n");
		printf("Seleccione una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			printf("Ingrese el valor a insertar al inicio: ");
			scanf("%d", &valor);
			insertarInicio(&lista, valor);
			break;
		case 2:
			printf("Ingrese el valor a insertar al final: ");
			scanf("%d", &valor);
			insertarFinal(&lista, valor);
			break;
		case 3:
			printf("Ingrese el valor del nodo a eliminar: ");
			scanf("%d", &valor);
			eliminarNodo(&lista, valor);
			break;
		case 4:
			printf("Ingrese el valor a buscar: ");
			scanf("%d", &valor);
			buscarValor(lista, valor);
			break;
		case 5:
			mostrarValores(lista);
			break;
		case 6:
			printf("Saliendo del programa.\n");
			break;
		default:
			printf("Opción no válida. Intente de nuevo.\n");
		}
		
	} while (opcion != 6);
	
	return 0;
}
