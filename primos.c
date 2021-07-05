#include <math.h>
#include <stdio.h>

int main(){
    int i = 2;
    int raiz = 0;
    int flag;
    while(i) {
        flag = 1;
        raiz = sqrt(i);
        for(int j = 2; j <= raiz; j++){
            if(i%j == 0 && i!=j) {
                flag = 0;
                break;
            }
        }

        if(flag == 1) {
            printf("%d eh primo\n", i);
        }

        i++;
    }
    return 0;
}