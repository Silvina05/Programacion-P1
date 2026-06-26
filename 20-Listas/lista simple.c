#include <stdio.h>
#include <stdlib.h>

// Definición del nodo - SOLO con struct, sin typedef
struct Nodo {
	int dato;
	struct Nodo* siguiente;
};

// Crear nuevo nodo
struct Nodo* crearNodo(int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
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

// ?? NUEVA FUNCIÓN: Insertar al medio (en orden ascendente)
void insertarEnOrden(struct Nodo** cabeza, int dato) {
	struct Nodo* nuevoNodo = crearNodo(dato);
	
	// Caso 1: lista vacía o el nuevo va antes del primer elemento
	if (*cabeza == NULL || (*cabeza)->dato >= dato) {
		nuevoNodo->siguiente = *cabeza;
		*cabeza = nuevoNodo;
		return;
	}
	
	// Caso 2: buscar la posición correcta
	struct Nodo* actual = *cabeza;
	// Recorremos hasta encontrar dónde insertar
	while (actual->siguiente != NULL && actual->siguiente->dato < dato) {
		actual = actual->siguiente;
	}
	
	// Enlazamos el nuevo nodo
	nuevoNodo->siguiente = actual->siguiente;
	actual->siguiente = nuevoNodo;
}

// Eliminar nodo por valor
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

// Buscar valor
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

// Mostrar lista
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

// Liberar toda la lista (buena práctica final)
void liberarLista(struct Nodo** cabeza) {
	struct Nodo* aux;
	while (*cabeza != NULL) {
		aux = *cabeza;
		*cabeza = (*cabeza)->siguiente;
		free(aux);
	}
	printf("Memoria liberada correctamente.\n");
}

// Función principal
int main() {
	struct Nodo* lista = NULL;
	int opcion, valor;
	
	do {
		printf("\n=== OPERACIONES CON LISTA SIMPLE ===\n");
		printf("1. Insertar al inicio\n");
		printf("2. Insertar al final\n");
		printf("3. Insertar en orden / al medio\n");  // ? Nueva opción
		printf("4. Eliminar un nodo\n");
		printf("5. Buscar un valor\n");
		printf("6. Mostrar todos los valores\n");
		printf("7. Salir\n");
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
		case 3:  // ? Usamos la nueva función
			printf("Ingrese el valor a insertar en orden: ");
			scanf("%d", &valor);
			insertarEnOrden(&lista, valor);
			break;
		case 4:
			printf("Ingrese el valor del nodo a eliminar: ");
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
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opción no válida. Intente de nuevo.\n");
		}
		
	} while (opcion != 7);
	
	liberarLista(&lista);
	return 0;
}
