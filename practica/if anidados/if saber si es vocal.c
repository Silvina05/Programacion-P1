#include <stdio.h>

int main() {
    char vocal;
    printf ("ingrese un caracter para saber si es una vocal ");
    scanf("%s", &vocal);
    if (vocal== 'a'|| vocal== 'e' ||vocal== 'i'||vocal== 'o'||vocal== 'u'){
        printf ("es una vocal");
    } else printf ("no es una vocal");
    




    return 0;
}