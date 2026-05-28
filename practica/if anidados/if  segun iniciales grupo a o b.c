#include <stdio.h>

int main() {
    char nombre[40];
    char sexo;
    char inicial;
    printf ("ingrese su sexo");
    scanf("%s", &sexo);
    printf ("ingrese su nombre");
    scanf("%s", &nombre);
    inicial= nombre[0];
    if (sexo == 'm'){
        if (inicial < 'm'){
            printf ("sos de grupo A");
        } else  printf ("sos de grupo B");

    } else if (sexo == 'h'){
        if (inicial > 'n'){
            printf ("sos de grupo A");
        } else  printf ("sos de grupo B");
    }




    return 0;
}