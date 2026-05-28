#include <stdio.h>

int main() {
    int array[5]= {10,7,3,5,4};
    int suma;
    for (int i = 0; i< 5; i++){
        if (array[i] % 2 ==0){
            printf("el numero es par %d\n", array[i]);
        }
    }


    return 0;
}