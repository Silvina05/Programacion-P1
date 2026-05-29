#include <stdio.h> 
#include <conio.h>
int main()
{
char cadena[5]={'h','o','l','a','\0'}; 
int i;
printf("La cadena es:\n "); 
i=0;
while (i< 5)
{
printf("\ncaracter %d:%c\n",i,cadena[i]); 
i++;
}
getch();
return 0;
}
