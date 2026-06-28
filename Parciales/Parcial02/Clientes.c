// habilitar un cliente por DNI
void habilitarCliente(struct Cliente clientes[], int cantidad, int dni)
{
    // Recorremos todo el arreglo de clientes
    for (int i = 0; i < cantidad; i++)
    {
        // Si encontramos el DNI buscado
        if (clientes[i].dni == dni)
        {
            // Cambiamos el estado a habilitado (valor 1)
            clientes[i].habilitado = 1;
            printf("Cliente con DNI %d habilitado.\n", dni);
            return; // Salimos de la función una vez hecho el cambio
        }
    }
    // Si terminamos el recorrido y no se encontró
    printf("Cliente con DNI %d no encontrado.\n", dni);
}

// deshabilitar un cliente por DNI
void deshabilitarCliente(struct Cliente clientes[], int cantidad, int dni)
{
    // Recorremos todos los clientes cargados
    for (int i = 0; i < cantidad; i++)
    {
        // Comparamos el DNI ingresado con el de cada cliente
        if (clientes[i].dni == dni)
        {
            // Cambiamos el estado a deshabilitado (valor 0)
            clientes[i].habilitado = 0;
            printf("Cliente con DNI %d deshabilitado.\n", dni);
            return; // Terminamos la función al encontrar y modificar
        }
    }
    // Si no se encontró ningún cliente con ese DNI
    printf("Cliente con DNI %d no encontrado.\n", dni);
}


// listar los clientes de mayor saldo
void listarClientesPorSaldo(struct Cliente clientes[], int cantidad)
{
    struct Cliente aux;

    // Ordenamos con el método Burbuja, de mayor a menor saldo
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            // Si el saldo actual es menor que el siguiente, los intercambiamos
            if (clientes[j].saldo < clientes[j + 1].saldo)
            {
                aux = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = aux;
            }
        }
    }

    // Mostramos el listado ordenado
    printf("Clientes ordenados por saldo (de mayor a menor):\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("DNI: %d, Nombre: %s %s, Saldo: %.2f\n",
               clientes[i].dni, clientes[i].nombre, clientes[i].apellido, clientes[i].saldo);
    }
}


// buscar clientes con el metodo de Busqueda Binaria (Binary Search)
struct Cliente buscarCliente(struct Cliente clientes[], int cantidad, int dni)
{
    // La busqueda binaria requiere que los datos esten ordenados, usamos la funcion ya existente
    ordenarClientes(clientes, cantidad);

    int inicio = 0;
    int fin = cantidad - 1;

    while (inicio <= fin)
    {
        // Calculamos el punto medio para evitar desbordamiento
        int medio = inicio + (fin - inicio) / 2;

        if (clientes[medio].dni == dni)
        {
            // Si encontramos el cliente, lo devolvemos
            return clientes[medio];
        }
        else if (clientes[medio].dni < dni)
        {
            // Si el DNI buscado es mayor, buscamos en la mitad derecha
            inicio = medio + 1;
        }
        else
        {
            // Si es menor, buscamos en la mitad izquierda
            fin = medio - 1;
        }
    }

    // Si no se encuentra, devolvemos un cliente con DNI = -1 como indicador
    struct Cliente clienteNoEncontrado = {-1, "", "", 0.0, 0};
    return clienteNoEncontrado;
}


// listar los clientes ordenados por DNI
void listarClientesPorDNI(struct Cliente clientes[], int cantidad)
{
    // Llamamos a la función ya existente para ordenar por DNI
    ordenarClientes(clientes, cantidad);

    // Mostramos todos los clientes en orden
    printf("Clientes ordenados por DNI:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("DNI: %d, Nombre: %s %s, Saldo: %.2f\n",
               clientes[i].dni, clientes[i].nombre, clientes[i].apellido, clientes[i].saldo);
    }
}


// modificar nombre, apellido o saldo de un cliente por DNI
void modificarCliente(struct Cliente clientes[], int cantidad, int dni)
{
    // Recorremos la lista para buscar el cliente por DNI
    for (int i = 0; i < cantidad; i++)
    {
        if (clientes[i].dni == dni)
        {
            // Mostramos los datos actuales antes de modificar
            printf("Cliente encontrado: %s %s\n", clientes[i].nombre, clientes[i].apellido);
            
            // Solicitamos y guardamos los nuevos valores
            printf("Nuevo nombre: ");
            scanf("%s", clientes[i].nombre);
            printf("Nuevo apellido: ");
            scanf("%s", clientes[i].apellido);
            printf("Nuevo saldo: ");
            scanf("%f", &clientes[i].saldo);
            
            printf("Cliente modificado.\n");
            return; // Salimos de la función una vez finalizado
        }
    }

    // Si terminamos el recorrido sin encontrar el DNI
    printf("Cliente con DNI %d no encontrado.\n", dni);
}


// listar solo los clientes habilitados
void listarClientesHabilitados(struct Cliente clientes[], int cantidad)
{
    printf("Clientes habilitados:\n");
    int encontrados = 0;

    // Recorremos todos los clientes
    for (int i = 0; i < cantidad; i++)
    {
        // Verificamos si el estado es habilitado (valor 1)
        if (clientes[i].habilitado == 1)
        {
            printf("DNI: %d, Nombre: %s %s, Saldo: %.2f\n",
                   clientes[i].dni, clientes[i].nombre, clientes[i].apellido, clientes[i].saldo);
            encontrados++;
        }
    }

    // Si no hay clientes habilitados, mostramos el aviso
    if (encontrados == 0)
    {
        printf("No hay clientes habilitados.\n");
    }
}


