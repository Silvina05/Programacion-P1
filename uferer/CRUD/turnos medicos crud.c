#include <stdio.h>
#define max_turnos 3

struct tur {
    int nroturno;
    char paciente [30];
    int hora;
};

//procedimientos 
void cargar (struct tur turno [], int n);
void listar (struct tur turno [], int n);
void buscaro (struct tur turno [], int n);
void ordenar (struct tur turno [], int n);



int main() {
    struct tur turno [max_turnos];
    struct tur t;
    int i, j, ninterc = 0;
    int buscar;
    int opcion;
do{
    printf("=== menu ===\n");
    printf("1. cargar 5 turnos\n");
    printf("2. listar todos los turnos\n");
    printf("3. buscar por numero de turno\n");
    printf("4. ordenar por hora y mostrar\n");
    printf("5. salir \n");
    printf("Seleccione la opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Elegiste cargar turnos\n");
            cargar (turno, max_turnos);
            break;
        case 2:
            printf("Elegiste listar turnos\n");
            listar (turno, max_turnos);
            break;
        case 3:
            printf("Elegiste buscar por numero de turno\n");
            buscaro (turno, max_turnos);
            break;
        case 4:
            printf("Elegiste ordenar por hora y mostrar\n");
            ordenar (turno, max_turnos);
            break;
        case 5:
            printf("gracias por utilizar este programa \n");
            break;
        default:
            printf("Opcion invalida\n");
    }
} while (opcion != 5);

    return 0;
}

void cargar (struct tur turno [], int n){

    int i=0;
    //cargar datos
     for (i=0; i< n; i++){
          printf("ingresar numero de turno del paciente numero: %d \n", i );
          scanf(" %d", &turno[i].nroturno);
          printf("ingresar nombre del paciente numero %d \n", i );
          scanf(" %s", turno[i].paciente);
          printf("ingresar hora de turno del paciente numero %d \n", i );
          scanf(" %d", &turno[i].hora);
    }
}
void listar (struct tur turno [], int n){
        int i=0;
    // mostrar elementos del arreglo
     for (i=0; i<n; i++){
          printf("numero de turno del paciente numero: %d es %d \n", i, turno[i].nroturno);
          printf("nombre del paciente numero %d es %s \n", i, turno[i].paciente );
          printf("hora de turno del paciente numero %d es %d \n", i, turno[i].hora);
          printf("---------------------------------------------- \n");
    }
}

void buscaro (struct tur turno [], int n){
    int i=0;
    int buscar=0;
    // buscar 
    printf("ingrese numero de turno para buscar \n");
    scanf (" %d", &buscar);
    i=0;
    for (i=0; i<n; i++){
          if (buscar == turno[i].nroturno){
            printf ("el turno %d esta guardado con los siguientes datos: \n", turno[i].nroturno );
            printf ("el nombre del paciente es: %s \n", turno[i].paciente );
            printf ("la hora es: %d \n", turno[i].hora );
          }
    }


}

void ordenar (struct tur turno [], int n){
    int i=0;
    int j=0;
    struct tur t;
    //ordenar por hora y mostrar 
     for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            // Compara el elemento actual con el Siguiente de forma segura
            if (turno[j].hora > turno[j+1].hora) /* Cambié < por > para que realmente sea ascendente */
            {
                t = turno[j];
                turno[j] = turno[j+1];
                turno[j+1] = t;
           
            }
        }
    }

    printf(" ordenado por hora \n");
    printf("---------------------------------------------- \n");

    // Mostrar el resultado
    for(i = 0; i < n; i++)
    {
          printf("numero de turno del paciente numero: %d es %d \n", i, turno[i].nroturno);
          printf("nombre del paciente numero %d es %s \n", i, turno[i].paciente );
          printf("hora de turno del paciente numero %d es %d \n", i, turno[i].hora);
          printf("---------------------------------------------- \n");

    }
        
    
}


