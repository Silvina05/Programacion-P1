int busquedaBinaria(int arr[], int n, int buscado) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == buscado) {
            return medio;
        }

        if (arr[medio] < buscado) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1; // No se encontró
}