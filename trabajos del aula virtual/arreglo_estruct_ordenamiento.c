#include <stdio.h>  
#include <conio.h> 
# define nro 3



struct cuentas
{
	int nro_cuenta;  
	int saldo;
	
};

int main()
	
{
	struct cuentas cuen[nro]; 
	struct cuentas t[nro]; 
	int i,j;
	int total;
	
	//Carga del Arreglo Cuentas
	for(i=0;i<nro;i++)
	{
		printf("Ingrese datos Estructura: %d\n",i+1);
		
		printf("\nIngrese Nro de Cuenta\n");  
		scanf("%i",&cuen[i].nro_cuenta);
		printf("Ingrese Saldo del Cliente\n");  
		scanf("%d",&cuen[i].saldo); 
		printf("\n");
	}
	//Mostramos por pantalla los registros cargados
	
	for(i=0;i<nro;i++)
	{
		printf("Nro Cuenta= %d\n",cuen[i].nro_cuenta);
		printf("Saldo= %d\n",cuen[i].saldo);
	}
	
/*ordenar_estructura*/

	for(i = 0; i < nro; i++)
		for(j = nro-1; j >= i; j--)
		if (cuen[j].nro_cuenta > cuen[j+1].nro_cuenta) /* orden ascendente */
	{
			t[0].nro_cuenta = cuen[j].nro_cuenta;
			t[0].saldo = cuen[j].saldo;
			
			cuen[j].nro_cuenta=cuen[j+1].nro_cuenta;
			cuen[j].saldo=cuen[j+1].saldo;
			
			cuen[j+1].nro_cuenta = t[0].nro_cuenta;
			cuen[j+1].saldo = t[0].saldo;

	}//Mostramos por pantalla los registros con formato de informe
	printf("------------------------------------------------\n"); 
	printf("------------Listado de clientes -----------------\n");
	printf("------------------------------------------------\n");
	printf("-Nro Cuenta----------Saldo---------------\n");
	total=0;
	for(i=0;i<nro;i++)
	{
		printf("%d" , cuen[i].nro_cuenta);
		printf("             %d\n",cuen[i].saldo);
		total=total+cuen[i].saldo;
	}
	printf("------------------------------------------------\n");
	printf(" Total Saldo:%d\n",total);
	//Informamos por Cliente Estados de las Cuentas.  

	
	}




