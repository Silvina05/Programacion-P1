#include <stdio.h>  
#include <conio.h> 
# define nro 5

struct cuentas
{
	int nro_cuenta;  
	int saldo;
	
};

int main()
	
{
	struct cuentas cuen[nro]; 
	struct cuentas t[nro]; 
	
	int i,j,total,inicio,final,medio,num; 
	
	/*Cargar el arreglo */
	
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
	getch();
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
		
		
	getch();
	
	/*busqueda binaria*/
	printf("Ingresar el numero a buscar:\n");
	scanf("%d",&num);
	inicio = 0;
	final = nro - 1; /*n-1, n es la cantidad de elementos del arreglo*/
	
	medio=0;
	while ((inicio <= final) && num!=cuen[medio].nro_cuenta)
	{
		medio = (inicio + final) / 2;
		if (num > cuen[medio].nro_cuenta)
			inicio = medio + 1;
		else
			final = medio - 1;
	}
	
	if (num == cuen[medio].nro_cuenta)
	{
		printf(" %d encontrado en la posicion %d\n",num,medio);
		final=nro;
	
	}
	
	else
		printf(" %d no esta en el arreglo\n",num);
		
	
	
	return 0;
 }
