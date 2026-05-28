#include <stdio.h>

int main()
{

    int a,b,option, r;
    printf ("seleccione la opcion que desea:");
    printf ("1. suma\n");
    printf ("2. resta\n");
    printf ("3. division\n");
    printf ("4. multiplicacion\n");
    printf ("option: ");
    scanf ("%d", &option);

    if (option > 0 && option < 5){

    printf ("ingrese el primer numero\n");
    scanf ("%d", &a);
    printf ("ingrese el segundo numero\n");
    scanf ("%d", &b);

   switch (option)
   {
   case  1:;
   r= a+b;
   break;
   case 2:;
   r= a-b;
   break;
   case 3:;
   r=a/b;
   break;
   default:;
   r=a*b;
    break;
   }

printf ("su resultado es %d", r);
    }
else printf ("valor no valido");
    return 0;
}
