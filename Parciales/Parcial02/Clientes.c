// habilitar un cliente por DNI
void habilitarCliente(struct Cliente clientes[], int cantidad, int dni)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (clientes[i].dni == dni)
        {
            clientes[i].habilitado = 1;
            printf("Cliente con DNI %d habilitado.\n", dni);
            return; 
        }
    }
    printf("Cliente con DNI %d no encontrado.\n", dni);
}

// deshabilitar un cliente por DNI
void deshabilitarCliente(struct Cliente clientes[], int cantidad, int dni)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (clientes[i].dni == dni)
        {
            clientes[i].habilitado = 0;
            printf("Cliente con DNI %d deshabilitado.\n", dni);
            return; 
        }
    }
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

    printf("Clientes ordenados por saldo (de mayor a menor):\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("DNI: %d, Nombre: %s %s, Saldo: %.2f\n",
               clientes[i].dni, clientes[i].nombre, clientes[i].apellido, clientes[i].saldo);
    }
}




//****************************************************** */
//si es que pide de manor a mayor , por lo general en este caso NO se usa
//******************************************************** */

// listar los clientes de menor a mayor saldo
void listarClientesPorSaldo(struct Cliente clientes[], int cantidad)
{
    struct Cliente aux;

    // Ordenamos con el método Burbuja, de menor a mayor saldo
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            // Si el saldo actual es mayor que el siguiente, los intercambiamos
            if (clientes[j].saldo > clientes[j + 1].saldo)
            {
                aux = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = aux;
            }
        }
    }

    // Mostramos el listado ordenado
    printf("Clientes ordenados por saldo (de menor a mayor):\n");
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
    ordenarClientes(clientes, cantidad);

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
            return; 
        }
    }
    printf("Cliente con DNI %d no encontrado.\n", dni);
}


// listar solo los clientes habilitados
void listarClientesHabilitados(struct Cliente clientes[], int cantidad)
{
    printf("Clientes habilitados:\n");
    int encontrados = 0;

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

    if (encontrados == 0)
    {
        printf("No hay clientes habilitados.\n");
    }
}


