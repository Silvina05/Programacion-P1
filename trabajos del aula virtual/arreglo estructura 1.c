#include <stdio.h> 
 #define ELEMENTOS 3 

 struct estructura_amigo
{
	char nombre[30]; 
	char apellido[40]; 
	char telefono[10]; 
	int edad;
 };

int main()
{
	struct estructura_amigo amigo[ELEMENTOS]; 
	int num_amigo;
	
	for( num_amigo=0; num_amigo<ELEMENTOS; num_amigo++ )
	{
		printf( "\nDatos del amigo n mero %i:\n", num_amigo+1 ); 
		printf( "Nombre: " );
		gets(amigo[num_amigo].nombre); 
		printf( "Apellido: " ); 
		gets(amigo[num_amigo].apellido);  
		printf( "Tel fono: " ); 
		gets(amigo[num_amigo].telefono); 
		printf( "Edad: " );
		scanf( "%i", &amigo[num_amigo].edad );
		
		while(getchar()!= '\n'); /* Vac a el buffer de entrada */ }
	/* Impresi n de los datos */
	
	for( num_amigo=0; num_amigo<ELEMENTOS; num_amigo++ )
	{
		printf( "Mi amigo %s ", amigo[num_amigo].nombre ); 
		printf( "%s tiene ", amigo[num_amigo].apellido ); 
		printf( "%i a os ", amigo[num_amigo].edad );
		printf( "y su tel fono es el %s.\n" , amigo[num_amigo].telefono );
	}
	return 0;
}
