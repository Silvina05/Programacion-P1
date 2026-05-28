#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
int n;
int u;
srand(time(0)); n = (rand()%10)+1; 
printf ("intente adivinar el numero 1 al 10, ingrese numero\n");
do {
scanf("%d", &u);
if (u>n){
    printf("el numero es menor\n");

 } else if (u<n){
    printf("el numero es mayor\n");
 }


 } while (u!=n);
printf ("correcto ese el numero\n");
 


return 0;
}