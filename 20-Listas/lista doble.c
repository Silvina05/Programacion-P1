#include <stdio.h>
#include <stdlib.h>

// Definición del nodo de lista DOBLEMENTE enlazada
struct Nodo {
	int dato;                  // Valor almacenado
	struct Nodo *anterior;     // Puntero al nodo anterior
	struct Nodo *posterior;    // Puntero al nodo siguiente
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int valor) {
	struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevo->dato = valor;
	nuevo->anterior = NULL;
	nuevo->posterior = NULL;
	return nuevo;
}

// -----------------------------------------------------------------------------
// 1. Insertar al inicio
// -----------------------------------------------------------------------------
void insertarAlInicio(struct Nodo **cabeza, int valor) {
	struct Nodo *nuevo = crearNodo(valor);
	
	if (*cabeza == NULL) {
		*cabeza = nuevo;
	} else {
		nuevo->posterior = *cabeza;
		(*cabeza)->anterior = nuevo;
		*cabeza = nuevo;
	}
	printf("? Insertado %d al inicio\n", valor);
}

// -----------------------------------------------------------------------------
// 2. Insertar al final
// -----------------------------------------------------------------------------
void insertarAlFinal(struct Nodo **cabeza, int valor) {
	struct Nodo *nuevo = crearNodo(valor);
	
	if (*cabeza == NULL) {
		*cabeza = nuevo;
		return;
	}
	
	// Recorremos hasta el último nodo
	struct Nodo *temp = *cabeza;
	while (temp->posterior != NULL) {
		temp = temp->posterior;
	}
	
	temp->posterior = nuevo;
	nuevo->anterior = temp;
	printf("? Insertado %d al final\n", valor);
}

// -----------------------------------------------------------------------------
// 3. Insertar en posición determinada
// -----------------------------------------------------------------------------
void insertarEnPosicion(struct Nodo **cabeza, int posicion, int valor) {
	// Si la posición es 1, usamos la función de insertar al inicio
	if (posicion == 1) {
		insertarAlInicio(cabeza, valor);
		return;
	}
	
	struct Nodo *temp = *cabeza;
	struct Nodo *anterior = NULL;
	int contador = 1;
	
	// Buscamos hasta llegar a la posición
	while (temp != NULL && contador < posicion) {
		anterior = temp;
		temp = temp->posterior;
		contador++;
	}
	
	// Si llegamos al final sin encontrar la posición
	if (temp == NULL) {
		printf("?? Posición %d no válida. Se insertará al final\n", posicion);
		insertarAlFinal(cabeza, valor);
		return;
	}
	
	struct Nodo *nuevo = crearNodo(valor);
	
	// Enlazamos los nodos
	nuevo->anterior = anterior;
	nuevo->posterior = temp;
	anterior->posterior = nuevo;
	temp->anterior = nuevo;
	
	printf("? Insertado %d en la posición %d\n", valor, posicion);
}

// -----------------------------------------------------------------------------
// 4. Eliminar un elemento por valor
// -----------------------------------------------------------------------------
void eliminarElemento(struct Nodo **cabeza, int valor) {
	if (*cabeza == NULL) {
		printf("?? La lista está vacía\n");
		return;
	}
	
	struct Nodo *temp = *cabeza;
	
	// Buscamos el nodo con el valor indicado
	while (temp != NULL && temp->dato != valor) {
		temp = temp->posterior;
	}
	
	if (temp == NULL) {
		printf("? Valor %d no encontrado\n", valor);
		return;
	}
	
	// Caso 1: Es el primer nodo
	if (temp->anterior == NULL) {
		*cabeza = temp->posterior;
		if (*cabeza != NULL) {
			(*cabeza)->anterior = NULL;
		}
	}
	// Caso 2: Es el último nodo
	else if (temp->posterior == NULL) {
		temp->anterior->posterior = NULL;
	}
	// Caso 3: Está en el medio
	else {
		temp->anterior->posterior = temp->posterior;
		temp->posterior->anterior = temp->anterior;
	}
	
	free(temp);
	printf("? Valor %d eliminado correctamente\n", valor);
}

// -----------------------------------------------------------------------------
// 5. Buscar un elemento
// -----------------------------------------------------------------------------
void buscarElemento(struct Nodo *cabeza, int valor) {
	struct Nodo *temp = cabeza;
	int encontrado = 0;
	
	while (temp != NULL) {
		if (temp->dato == valor) {
			encontrado = 1;
			break;
		}
		temp = temp->posterior;
	}
	
	if (encontrado) {
		printf("? Valor %d encontrado en la lista\n", valor);
	} else {
		printf("? Valor %d NO está en la lista\n", valor);
	}
}

// -----------------------------------------------------------------------------
// 6. Recorrer de izquierda a derecha (inicio ? final)
// -----------------------------------------------------------------------------
void recorrerHaciaAdelante(struct Nodo *cabeza) {
	if (cabeza == NULL) {
		printf("?? La lista está vacía\n");
		return;
	}
	
	printf("?? Recorrido de inicio a fin: ");
	while (cabeza != NULL) {
		printf("%d ", cabeza->dato);
		cabeza = cabeza->posterior;
	}
	printf("\n");
}

// -----------------------------------------------------------------------------
// 7. Recorrer de derecha a izquierda (final ? inicio)
// -----------------------------------------------------------------------------
void recorrerHaciaAtras(struct Nodo *cabeza) {
	if (cabeza == NULL) {
		printf("?? La lista está vacía\n");
		return;
	}
	
	// Primero vamos hasta el último nodo
	while (cabeza->posterior != NULL) {
		cabeza = cabeza->posterior;
	}
	
	// Ahora recorremos hacia atrás
	printf("?? Recorrido de fin a inicio: ");
	while (cabeza != NULL) {
		printf("%d ", cabeza->dato);
		cabeza = cabeza->anterior;
	}
	printf("\n");
}

// -----------------------------------------------------------------------------
// 8. Liberar toda la lista
// -----------------------------------------------------------------------------
void liberarLista(struct Nodo **cabeza) {
	struct Nodo *aux;
	while (*cabeza != NULL) {
		aux = *cabeza;
		*cabeza = (*cabeza)->posterior;
		free(aux);
	}
	printf("?? Memoria liberada correctamente\n");
}

// -----------------------------------------------------------------------------
// Menú principal
// -----------------------------------------------------------------------------
void mostrarMenu() {
	printf("\n===== LISTA DOBLEMENTE ENLAZADA =====\n");
	printf("1. Insertar al inicio\n");
	printf("2. Insertar al final\n");
	printf("3. Insertar en posición determinada\n");
	printf("4. Eliminar un elemento\n");
	printf("5. Buscar un elemento\n");
	printf("6. Recorrer de inicio a fin\n");
	printf("7. Recorrer de fin a inicio\n");
	printf("8. Salir\n");
	printf("Seleccione una opción: ");
}

// -----------------------------------------------------------------------------
// Función principal
// -----------------------------------------------------------------------------
int main() {
	struct Nodo *lista = NULL;
	int opcion, valor, posicion;
	
	do {
		mostrarMenu();
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			printf("Ingrese el valor a insertar: ");
			scanf("%d", &valor);
			insertarAlInicio(&lista, valor);
			break;
			
		case 2:
			printf("Ingrese el valor a insertar: ");
			scanf("%d", &valor);
			insertarAlFinal(&lista, valor);
			break;
			
		case 3:
			printf("Ingrese el valor a insertar: ");
			scanf("%d", &valor);
			printf("Ingrese la posición: ");
			scanf("%d", &posicion);
			insertarEnPosicion(&lista, posicion, valor);
			break;
			
		case 4:
			printf("Ingrese el valor a eliminar: ");
			scanf("%d", &valor);
			eliminarElemento(&lista, valor);
			break;
			
		case 5:
			printf("Ingrese el valor a buscar: ");
			scanf("%d", &valor);
			buscarElemento(lista, valor);
			break;
			
		case 6:
			recorrerHaciaAdelante(lista);
			break;
			
		case 7:
			recorrerHaciaAtras(lista);
			break;
			
		case 8:
			printf("Saliendo del programa...\n");
			break;
			
		default:
			printf("?? Opción no válida. Intente nuevamente\n");
		}
		
	} while (opcion != 8);
	
	liberarLista(&lista);
	return 0;
}
