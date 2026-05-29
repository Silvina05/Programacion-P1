#include <stdio.h>  
#include <conio.h> 
# define nro 3

struct alumno
{
	int dni;  
	char apellido[30];  
	char nombre[30];  
	int edad;
	float prom;
	
};

int main()
	
{
	struct alumno alum[nro]; 
	float total;
	int i;
	
	//Carga del Arreglo Cuentas
	for(i=0;i<nro;i++)
	{
		printf("Ingrese datos Estructura: %d\n",i+1);
		
		printf("\nIngrese DNI alumno\n");  
		scanf("%i",&alum[i].dni);
		printf("Ingrese apellido  del alumno\n"); 
		scanf("%s",&alum[i].apellido);
		printf("Ingrese nombre  del alumno\n"); 
		scanf("%s",&alum[i].nombre);
		printf("Ingrese edad  del alumno\n"); 
		scanf("%i",&alum[i].edad);
		printf("Ingrese promedio del alumno\n"); 
		scanf("%f",&alum[i].prom);
		printf("\n");
	}
	//Mostramos por pantalla los registros con formato de informe
	printf("------------------------------------------------\n"); 
	printf("------------Listado de alumnos -----------------\n");
	printf("------------------------------------------------\n");
	printf("-DNI------Apellido--------Nombre-----Edad--------Promedio-------\n");
	total=0;
	for(i=0;i<nro;i++)
	{
		printf("%d" , alum[i].dni);
		printf("	%s",alum[i].apellido);
		printf("	         %s",alum[i].nombre);
		printf("                      %d\n",alum[i].edad);
		printf("                               %f\n",alum[i].prom);
		total=total+alum[i].prom;
	}
	printf("------------------------------------------------\n");
	printf(" Promedio:%d\n",total/nro);
	
	return 0;
	
}
