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
	
	printf("Ingrese el primer número: ");
	scanf("%d", &num1);
	
	printf("Ingrese el segundo número: ");
	scanf("%d", &num2);
	
	if (opcion == 1) {
		int suma = num1 + num2;
		printf("%d + %d = %d\n", num1, num2, suma);
		
	} else if (opcion == 2) {
		int resta = num1 - num2;
		printf("%d - %d = %d\n", num1, num2, resta);
		
	} else if (opcion == 3) {
		int multiplicacion = num1 * num2;
		printf("%d * %d = %d\n", num1, num2, multiplicacion);
		
	} else if (opcion == 4 && num2 > 0) {
		float division = (float)num1 / num2;
		printf("%d / %d = %.2f\n", num1, num2, division);
	}
	
	return 0;
}
