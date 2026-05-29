#include <stdio.h>
#include <string.h>

#define MAX 5

// Definicion del registro (struct)
typedef struct {
    int nro_cliente;
    char tipo;        // 'E' o 'P'
    char nombre[50];
    char celular[20];
} Cliente;

// Ordenamiento burbuja por Nro de Cliente (ascendente)
void ordenar(Cliente lista[], int n) {
    Cliente temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (lista[j].nro_cliente > lista[j + 1].nro_cliente) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void cargar(Cliente lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Cliente %d ---\n", i + 1);

        printf("Nro de cliente: ");
        scanf("%d", &lista[i].nro_cliente);

        // Validar tipo E o P
        do {
            printf("Tipo (E=Empresa / P=Particular): ");
            scanf(" %c", &lista[i].tipo);  // espacio antes de %c para ignorar el Enter
            if (lista[i].tipo != 'E' && lista[i].tipo != 'P')
                printf("  Tipo invalido. Ingrese E o P.\n");
        } while (lista[i].tipo != 'E' && lista[i].tipo != 'P');

        printf("Nombre: ");
        scanf(" %[^\n]", lista[i].nombre);  // permite espacios en el nombre

        printf("Nro Celular: ");
        scanf(" %[^\n]", lista[i].celular);
    }
}

void mostrar(Cliente lista[], int n) {
    printf("\n============================================\n");
    printf("        LISTADO DE CLIENTES\n");
    printf("============================================\n");
    printf("%-6s %-10s %-20s %-15s\n", "Nro", "Tipo", "Nombre", "Celular");
    printf("--------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        char *tipo_str = (lista[i].tipo == 'E') ? "Empresa" : "Particular";
        printf("%-6d %-10s %-20s %-15s\n",
               lista[i].nro_cliente,
               tipo_str,
               lista[i].nombre,
               lista[i].celular);
    }
    printf("============================================\n");
}

int main() {
    Cliente clientes[MAX];

    cargar(clientes, MAX);
    ordenar(clientes, MAX);
    mostrar(clientes, MAX);

    return 0;
}