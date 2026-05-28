#include <stdio.h>

int main( )
{
	int a, b, h ;
	printf ("ingrese la base:\n");
	scanf(" %i",&a);
	printf ("ingrese la altura:\n");
	scanf(" %i",&b);
	h=b*a;
	printf("\narea del rectangulo=%i", h);
	return 0;
}
