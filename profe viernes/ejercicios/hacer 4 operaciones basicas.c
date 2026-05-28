#include <stdio.h>

int main()
{
    int a, b;
    int suma, resta, multi;
    float divi;
   printf ("ingrese el primer numero\n");
   scanf ("%d", &a);
   printf ("ingrese el segundo numero\n");
   scanf ("%d", &b);
   suma= a+b;
   resta=a-b;
   multi=a*b;
   divi=(float)a/b;
   printf("\nla suma es %d\n", suma );
   printf("\nla resta es %d\n", resta);
   printf("\nla division es %.2f\n", divi );
   printf("\nla multiplicacion es %d\n", multi );



    return 0;
}
