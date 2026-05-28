#include <stdio.h>

int main()
{

    int a,b,s,r,m,option;
    float g;
    printf ("seleccione la opcion que desea:");
    printf ("1. suma\n");
    printf ("2. resta\n");
    printf ("3. division\n");
    printf ("4. multiplicacion\n");
    printf ("option: ");
    scanf ("%d", &option);

    printf ("ingrese el primer numero\n");
    scanf ("%d", &a);
    printf ("ingrese el segundo numero\n");
    scanf ("%d", &b);

    if (option==1){
        s= a+b;
        printf ("la suma es: %d\n", s);
    }
    else if (option==2){
        r= a-b;
        printf ("la resta es: %d\n", r);
    }
    else if (option==3){
        g= (float) a/b;
        printf ("la division es= %.2f\n", g);
    }
    else if (option==4 ){
        m=  a*b;
        printf ("la multiplicacion es= %d\n", m);
    }
    else if (option > 4){
        printf ("opcion invalida");
    }




    return 0;
}
