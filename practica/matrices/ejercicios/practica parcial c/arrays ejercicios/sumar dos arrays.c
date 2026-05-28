#include <stdio.h>

int main() {
    int array1[3]= {1,4,6};
    int array2[3]= {5,2,2};
    int array3[3];
   
    for (int i = 0; i<3; i++){
        array3[i]= array1[i]+array2[i];
        printf ("%d", array3[i]);
    }

    return 0;
}