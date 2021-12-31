#include <stdio.h>

int main(){
    int n = 10, sum=0, i=0;
    while(i<=10){
        sum+=i;
        i++;
    }
    printf("%d", sum);
    return 0;
}