void ordenarInsercion(int arr[], int n) {
    int i, j, actual;
    for (i = 1; i < n; i++) {
        actual = arr[i];
        j = i - 1;

        // Desplazamos los elementos que son mayores que el actual
        while (j >= 0 && arr[j] > actual) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = actual; // Insertamos el elemento en su lugar
    }
}