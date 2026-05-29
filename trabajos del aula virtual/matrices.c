#include <stdio.h>

int main()
{
int i,j;
int matriz[5][2] = { {0,0}, {1,2}, {2,4}, {3,6}, {4,8}};
int mat [5][2];

for (i = 0; i<5; i++)
{
	for (j=0; j<2; j++)
		{
			printf("matriz[%d] [%d] = ", i, j);
			printf("%d \t", matriz[i][j]);
			printf("\n");
		}
}		

/*Cargar matriz mat*/
for (i = 0; i<5; i++)
{
for (j=0; j<2; j++)
{
printf("Ingresar el elememto % i-%i= ", i, j);
scanf("%d", &matriz[i][j]);
}
}			
printf ("Segunda matriz\n");
for (i = 0; i<5; i++)
{
	for (j=0; j<2; j++)
	{
		printf("matriz[%d] [%d] = ", i, j);
		printf("%d \t", matriz[i][j]);
		printf("\n");
	}
}
return 0;
	

}
