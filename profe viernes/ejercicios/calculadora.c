#include <stdio.h>

int main( )
{
	int a, b;
	printf ("ingrese el primer numero:\n");
	scanf("%d",&a);
	printf ("\ningrese el segundo numero:\n");
	scanf("%d", &b);
	int s=a+b;
	int r= a-b;
	int m=a*b;
	float d=(float)a/b;
	
	printf("suma=%d\n",s);
	printf("resta=%d\n",r);
	printf("multiplicacion=%d\n",m);
	printf("division=%.2f\n",d);
	
	
	return 0;
}

