// buscar pieza por posicion usando Busqueda Binaria
struct Pieza buscarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
    // La busqueda binaria requiere que los datos esten ordenados
    ordenarPiezas(piezas, cantidad);

    int inicio = 0;
    int fin = cantidad - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (piezas[medio].posicion[0] == fila && piezas[medio].posicion[1] == columna)
        {
            return piezas[medio];
        }
        else if (piezas[medio].posicion[0] < fila ||
                (piezas[medio].posicion[0] == fila && piezas[medio].posicion[1] < columna))
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }

    // Si no se encuentra, devolvemos con fila = -1 como indicador
    struct Pieza noEncontrada = {{-1, -1}, "", ' ', 0, 0};
    return noEncontrada;
}


// listar piezas ordenadas de mayor a menor valor
void listarPiezasPorValor(struct Pieza piezas[], int cantidad)
{
    struct Pieza aux;

    // Ordenamos con metodo Burbuja
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if (piezas[j].valor < piezas[j + 1].valor)
            {
                aux = piezas[j];
                piezas[j] = piezas[j + 1];
                piezas[j + 1] = aux;
            }
        }
    }

    printf("Piezas ordenadas por valor (de mayor a menor):\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d\n",
               piezas[i].posicion[0], piezas[i].posicion[1],
               piezas[i].tipo, piezas[i].color, piezas[i].valor);
    }
}



// listar piezas ordenadas por posicion (fila primero, luego columna)
void listarPiezasPorPosicion(struct Pieza piezas[], int cantidad)
{
    ordenarPiezas(piezas, cantidad);

    printf("Piezas ordenadas por posicion:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d\n",
               piezas[i].posicion[0], piezas[i].posicion[1],
               piezas[i].tipo, piezas[i].color, piezas[i].valor);
    }
}



// listar solo las piezas que estan en juego
void listarPiezasActivas(struct Pieza piezas[], int cantidad)
{
    printf("Piezas activas en el tablero:\n");
    int contador = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (piezas[i].activa == 1)
        {
            printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d\n",
                   piezas[i].posicion[0], piezas[i].posicion[1],
                   piezas[i].tipo, piezas[i].color, piezas[i].valor);
            contador++;
        }
    }

    if (contador == 0)
    {
        printf("No hay piezas activas en este momento.\n");
    }
}



// cambiar estado de pieza a capturada
void capturarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna)
        {
            if (piezas[i].activa == 0)
            {
                printf("La pieza en (%d,%d) ya esta capturada.\n", fila, columna);
                return;
            }
            piezas[i].activa = 0;
            printf("Pieza en posicion (%d,%d) capturada correctamente.\n", fila, columna);
            return;
        }
    }
    printf("Pieza en posicion (%d,%d) no encontrada.\n", fila, columna);
}



// modificar tipo, color y valor de una pieza por su posicion
void modificarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna)
        {
            printf("Pieza encontrada: Tipo: %s, Color: %c, Valor: %d\n",
                   piezas[i].tipo, piezas[i].color, piezas[i].valor);
            
            int numeroPieza;
            printf("Seleccione nuevo tipo:\n");
            printf("1. Peon\n2. Torre\n3. Caballo\n4. Alfil\n5. Reina\n6. Rey\n");
            printf("Ingrese opcion: ");
            scanf("%d", &numeroPieza);

            strcpy(piezas[i].tipo, seleccionarTipoDePieza(numeroPieza));

            printf("Nuevo color ('b' blanco, 'n' negro): ");
            scanf(" %c", &piezas[i].color);

            piezas[i].valor = obtenerValorDePieza(numeroPieza);

            printf("Pieza modificada correctamente.\n");
            return;
        }
    }
    printf("Pieza en posicion (%d,%d) no encontrada.\n", fila, columna);
}
