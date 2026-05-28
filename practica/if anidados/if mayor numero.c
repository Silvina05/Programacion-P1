#include <stdio.h>

int main() {
    int n1;
    int n2;
    int n3;
    
    printf ("ingrese un numero ");
    scanf("%d", &n1);
    printf ("ingrese un numero ");
    scanf("%d", &n2);
    printf ("ingrese un numero ");
    scanf("%d", &n3);
    if (n1>= 0 && n2>=0 && n3>=0) {
    if (n1 >= n2 && n1>= n3){
        printf ("el mayor es %d", n1);
    } else if (n2>=n1 && n2>=n3){
        printf ("el mayor es %d", n2);
    } else printf ("el mayor es %d", n3);
 } else printf ("ingrese un numero positivo");
    




    return 0;
}