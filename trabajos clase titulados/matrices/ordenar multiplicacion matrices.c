#include <stdio.h>

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int array1 [9];
    int array2 [9];
    int k=0;
    int i=0;
    int n=9;
    int aux=0;
    int j=0;

// convertir en array
    k = 0; 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            array1[k] = A[i][j];
            k++; 
        }
    }

     k = 0; 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            array2[k] = B[i][j];
            k++; 
        }
    }

// ordenamiento
     for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (array1[j] > array1[j + 1]) {
               
                aux = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = aux;
            }
        }
    }

     for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (array2[j] > array2[j + 1]) {
               
                aux = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = aux;
            }
        }
    }
// vover a matriz
        k = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            A[i][j] = array1[k];
            k++;
        }
    }

        k = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            B[i][j] = array2[k];
            k++;
        }
    }

//mostrar
     for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
     printf("\n");

       for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d", B[i][j]);
        }
        printf("\n");
    }



    int C[3][3];

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            C[x][y] = 0;
            for (int k = 0; k < 3; k++) {
                C[x][y] += A[x][k] * B[k][y];
            }
        }
    }
    
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            printf("%d\t ", C[x][y]);
        }
        printf("\n");
    }

    return 0;
}