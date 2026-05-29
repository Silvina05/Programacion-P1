#include <stdio.h>
#define max 5

void mostrar(int a []);

int main() {
    int vec [max],p;
    int i;
    for (i=0;i<max; i++)
    {
        printf ("ingrese un numero entero\n");
        scanf ("%d", &vec[i]);
    }
    mostrar(vec);
    
    return 0;
}
void mostrar(int a [])
{
    int i;
    for (i=0;i<max; i++)
    printf("elemento%d:%d \n", i+1,a[i]);
    

}