#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int nro_cliente;
    char tipo;
    char nombre[50];
    char celular[20];
} Cliente;

void cargar(Cliente lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Cliente %d ---\n", i + 1);

        printf("Nro de cliente: ");
        scanf("%d", &lista[i].nro_cliente);

        do {
            printf("Tipo (E=Empresa / P=Particular): ");
            scanf(" %c", &lista[i].tipo);
            if (lista[i].tipo != 'E' && lista[i].tipo != 'P')
                printf("  Tipo invalido. Ingrese E o P.\n");
        } while (lista[i].tipo != 'E' && lista[i].tipo != 'P');

        printf("Nombre: ");
        scanf(" %[^\n]", lista[i].nombre);

        printf("Nro Celular: ");
        scanf(" %[^\n]", lista[i].celular);
    }
}

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

// ── BÚSQUEDA BINARIA ─────────────────────────────────────────────
// Requiere que el arreglo esté ordenado por nro_cliente
int busqueda_binaria(Cliente lista[], int n, int nro_buscado) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (lista[medio].nro_cliente == nro_buscado) {
            return medio;           // encontrado, devuelve el indice
        } else if (lista[medio].nro_cliente < nro_buscado) {
            inicio = medio + 1;     // busca en la mitad derecha
        } else {
            fin = medio - 1;        // busca en la mitad izquierda
        }
    }
    return -1;  // no encontrado
}

// ── SEPARAR EN DOS ARREGLOS ──────────────────────────────────────
void separar_por_tipo(Cliente lista[], int n,
                      Cliente empresas[], int *cant_e,
                      Cliente particulares[], int *cant_p) {
    *cant_e = 0;
    *cant_p = 0;

    for (int i = 0; i < n; i++) {
        if (lista[i].tipo == 'E') {
            empresas[*cant_e] = lista[i];
            (*cant_e)++;
        } else {
            particulares[*cant_p] = lista[i];
            (*cant_p)++;
        }
    }
}

int main() {
    Cliente clientes[MAX];
    Cliente empresas[MAX];
    Cliente particulares[MAX];
    int cant_e = 0, cant_p = 0;

    // 1. Cargar y ordenar
    cargar(clientes, MAX);
    ordenar(clientes, MAX);
    mostrar(clientes, MAX);

    // 2. Búsqueda binaria
    int nro_buscado;
    printf("\nIngrese Nro de cliente a buscar: ");
    scanf("%d", &nro_buscado);

    int resultado = busqueda_binaria(clientes, MAX, nro_buscado);

    if (resultado == -1) {
        printf("Cliente %d no encontrado.\n", nro_buscado);
    } else {
        char *tipo_str = (clientes[resultado].tipo == 'E') ? "Empresa" : "Particular";
        printf("\n── Cliente encontrado ──────────────────\n");
        printf("Nro    : %d\n", clientes[resultado].nro_cliente);
        printf("Tipo   : %s\n", tipo_str);
        printf("Nombre : %s\n", clientes[resultado].nombre);
        printf("Celular: %s\n", clientes[resultado].celular);
        printf("────────────────────────────────────────\n");
    }

    // 3. Separar por tipo y mostrar
    separar_por_tipo(clientes, MAX, empresas, &cant_e, particulares, &cant_p);

    printf("\n──── Clientes EMPRESA (%d) ────\n", cant_e);
    mostrar(empresas, cant_e);

    printf("\n──── Clientes PARTICULAR (%d) ────\n", cant_p);
    mostrar(particulares, cant_p);

    return 0;
}