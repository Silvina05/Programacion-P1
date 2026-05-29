#include <stdio.h>  
#include <conio.h>

int main()
{
	char cadena[5]={'h','o','l','a','\0'}; 
	int i,cont;
	char cad[5];
	char car;
	
	printf("La cadena es:\n ");  i=0;
	
	while (i< 5)
	{
		printf("car cter %d:%c\n",i,cadena[i]);  i++;
	}
	
	for (i=0;i<5;i++)
	{
		printf("Ingrese un caracter\n");
		scanf (" %c",&car);
		cad[i]=car;
	}
	i=0;
	while (i< 5)
	{
		printf("car cter %d:%c\n",i,cad[i]); 
		i++;
	}
	
	printf("Ingrese un caracter a buscar\n");
	scanf (" %c",&car);
	
	cont=0;
	for (i=0;i<5;i++)
	{
		if (cad[i]==car) cont++;
	}
	printf ("Caracter encontrado: %i\n",cont);
	
	cont=0;
	i=0;
	while (i<5)
	{
		if (cad[i]=='c' && cad[i+1]=='a')
			{cont++;
			 i=i+2;
		    }
		else i++;
	}
	
	printf ("Caracter encontrado: %i\n",cont);
	return 0;
}
