#include <stdio.h>  
#include <conio.h> 
# define nro 3

struct cuentas
{
	int nro_cuenta;  
	char nombre[30];  
	int saldo;
	
};

int main()
	
{
	struct cuentas cuen[nro]; 
	int i,deudor=0,acreedor=0;
	int total;
	
	//Carga del Arreglo Cuentas
	for(i=0;i<nro;i++)
	{
		printf("Ingrese datos Estructura: %d\n",i+1);
		
		printf("\nIngrese Nro de Cuenta\n");  
		scanf("%i",&cuen[i].nro_cuenta);
		printf("Ingrese nombre del Cliente\n"); 
		scanf("%s",&cuen[i].nombre);
		printf("Ingrese Saldo del Cliente\n");  
		scanf("%d",&cuen[i].saldo); 
		printf("\n");
	}
	//Mostramos por pantalla los registros cargados
	
	for(i=0;i<nro;i++)
	{
		printf("Nro Cuenta= %d\n",cuen[i].nro_cuenta);
		printf("Cliente= %s\n",cuen[i].nombre); 
		printf("Saldo= %d\n",cuen[i].saldo);
	}
	
	//Mostramos por pantalla los registros con formato de informe
	printf("------------------------------------------------\n"); 
	printf("------------Listado de clientes -----------------\n");
	printf("------------------------------------------------\n");
	printf("-Nro Cuenta------Nombre-----Saldo---------------\n");
	total=0;
	for(i=0;i<nro;i++)
	{
		printf("%d" , cuen[i].nro_cuenta);
		printf("	%s",cuen[i].nombre);
		printf("             %d\n",cuen[i].saldo);
		total=total+cuen[i].saldo;
	}
	printf("------------------------------------------------\n");
	printf(" Total Saldo:%d\n",total);
	//Informamos por Cliente Estados de las Cuentas.  
	printf("\n");
	for(i=0;i<nro;i++)
	{
		if (cuen[i].saldo<0)
		{
			printf("El estado de la cuenta para el cliente: %s es: DEUDOR\n",cuen[i].nombre);
			deudor++;
		}
		else
		{
			printf("El estado de la cuenta para el cliente: %s es:ACREEDOR\n",cuen[i].nombre);
			acreedor++;
		}
	}
	
	printf("Hay %d Ciientes Deudores\n",deudor);
	printf("Hay %d Clientes Acreedores\n",acreedor);
	
	return 0;
	
}
