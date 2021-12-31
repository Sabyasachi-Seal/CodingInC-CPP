#include <stdio.h>
int main(){
    int sum = 0;
    for(int i=100;i<=200;i++){
        if(i%9==0){
            printf("%d\n",i);
            sum+=i;
        }
    }
    printf("Sum=%d", sum);
}