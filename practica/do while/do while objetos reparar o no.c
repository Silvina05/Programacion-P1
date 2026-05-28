#include <stdio.h>

int main() {
    int opcion1;
    int opcion2;

    do {
        printf("el objeto se mueve?(1 si) (2 no) (0 para salir)\n");
        scanf("%d", &opcion1);
        printf("el objeto deberia moverse? (0 para salir)\n");
        scanf("%d", &opcion2);

        if (opcion1 != 0){
        
        if (opcion1==1 && opcion2==1) {
            printf(" no hace falta reparar.\n");
        }
        else if (opcion1==1 && opcion2==2) {
            printf(" utilizar cinta americana.\n");
        }
        else if (opcion1==2 && opcion2==2) {
            printf(" no hace falta reparar.\n");
        }
        else if (opcion1==2 && opcion2==1) {
            printf(" utilizar aceite 3 en 1 .\n");
        }
    }
    } while (opcion1 != 0 );

    printf("gracias por usar, fin del programa");

    return 0;
}