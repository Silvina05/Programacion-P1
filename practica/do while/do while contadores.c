#include <stdio.h>

int main() {
    int n;
    int num;
    int c15 = 0;
    int c50 = 0;
    int crango = 0;
    int cc=0;
    printf("ingrese la cantidad de numeros a ingresar\n");
        scanf("%d", &n);


    do {
        printf("ingrese numero\n");
        scanf("%d", &num);
        if (num<15) {
            c15++;
        }
        else if (num>50) {
           c50++;
        }
        else if (num>15 && num <45) {
            crango++;
        }
        cc++;
       
    } while (cc<n);

    printf("***********************************************");
    printf("\n************GRACIAS POR USAR*******************\n");
    printf("\n******NUMEROS MENOR A  15 %d********************\n", c15);
    printf("\n******NUMEROS MAYORES a 50 %d*******************\n", c50);
    printf("\n******NUMEROS ENTRE 25 y 45 %d******************\n", crango);
     printf("\n***********************************************\n");
   

    return 0;
}