#include <stdio.h>

int buscar (int lista[],int num);

int main() 

{
    int a[10]={1,3,3,4,5,7,7,7,9,10};
	int i,acum,pos,bus,z,enc;
	float prom;
	i=0;
	acum=0;
	enc=0;
	for (i=0;i<10;i++)
		printf("%i -",a[i]);
		
	for (i=0;i<10;i++)
		acum=acum+a[i];
	
	
	printf("\n\nTotal sumatoria arreglo:%i",acum);
	
	prom=acum/10;
	
	printf("\n\n Promedio:%f",prom);
	
	printf("\n\nIgrese posici n a buscar");
	scanf("%i",&pos);
		
	if (pos < 0 || pos >9) printf("\n Posici n fuera de rango");
	else printf("\n Valor %i en la posici n % i",a[pos],pos);
	
	printf("\n\nIgrese valor a buscar");
	scanf("%i",&bus);
	/*busqueda para un arreglo sin elementos repetidos*/
	i=0;
	
	z=buscar(a,bus);
	
	if (z==0) printf("Elemento no encontrado");
	else 
	    { 
		while(a[z]==bus)
		 {
		 enc=enc+1;
		 z++;
         }
	     
	     printf ("\n Elemento  encontrado %i veces ",enc);
	    }

return 0;

}  

int buscar (int lista[],int num)
{
	int inicio,final,medio; 
	
	inicio = 0;
	final = 9 - 1; /*n-1, n es la cantidad de elementos del arreglo*/
	
	medio=0;
	while ((inicio <= final) && num!=lista[medio])
	{
		medio = (inicio + final) / 2;
		if (num > lista[medio])
			inicio = medio + 1;
		else
			final = medio - 1;
	}
	
	if (num == lista[medio])
	{
		return medio;
		
	}
	
	else
		return 0;

}
