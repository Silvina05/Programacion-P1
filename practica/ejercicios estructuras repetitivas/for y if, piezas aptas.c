#include <stdio.h>

int main() {
int n;
int con;
float lon;
con=0;
printf ("ingrese la cantidad de piezas ");
scanf("%d", &n);
for (int i=1; i<=n; i++){
    printf ("ingrese la longitud ");
    scanf("%f", &lon);
    if (lon == 1.20f || lon == 1.30f){
    con++;
        
    }


}
 printf ("cantidad de piezas aptas %d", con);

    return 0;
}