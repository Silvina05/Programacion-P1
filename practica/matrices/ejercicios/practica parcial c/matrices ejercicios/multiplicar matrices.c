#include <stdio.h>

int main() {
    int A[2][2], B[2][2], C[2][2];

    // Cargar A
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("ingrese valores primer matriz ");
            scanf("%d",&A[i][j]);
        }
    }

    // Cargar B
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("ingrese valores segunda matriz " );
            scanf("%d",&B[i][j]);
        }
    }

    // Multiplicación real
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j] = 0;
            for(int k=0;k<2;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Mostrar
    printf("Resultado:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}