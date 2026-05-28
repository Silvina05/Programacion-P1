#include <stdio.h>

int main()
{
	int num1, num2, opcion;
	
	printf("Ingrese la operación que desea realizar:\n");
	printf("1. Suma\n");
	printf("2. Resta\n");
	printf("3. Multiplicación\n");
	printf("4. División\n");
	printf("Opción: ");
	scanf("%d", &opcion);
	
	if(opcion == 1 ){
		printf("Ingrese el primer número: ");
		scanf("%d", &num1);
		printf("Ingrese el segundo número: ");
		scanf("%d", &num2);
		int suma = num1 + num2;
		printf("%d + %d = %d\n", num1, num2, suma);
	}
	
	if(opcion == 2 ){
		printf("Ingrese el primer número: ");
		scanf("%d", &num1);
		printf("Ingrese el segundo número: ");
		scanf("%d", &num2);
		int resta = num1 - num2;
		printf("%d - %d = %d\n", num1, num2, resta);
	}
	
	if(opcion == 3 ){
		printf("Ingrese el primer número: ");
		scanf("%d", &num1);
		printf("Ingrese el segundo número: ");
		scanf("%d", &num2);
		int multiplicacion = num1 * num2;
		printf("%d * %d = %d\n", num1, num2, multiplicacion);
	}  
	
	if(num2 > 0 && opcion == 4){
		printf("Ingrese el primer número: ");
		scanf("%d", &num1);
		printf("Ingrese el segundo número: ");
		scanf("%d", &num2);
		float division = (float)num1 / num2;
		printf("%d / %d = %.2f\n", num1, num2, division);
	}
	
	return 0;
}
