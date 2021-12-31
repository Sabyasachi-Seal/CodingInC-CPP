#include <stdio.h>
int main(){
    int sum=0, i=100;
    while(i<=200){
        (i%9==0)?printf("%d\n",i),sum+=i,i++:i++;}
    printf("Sum=%d", sum);
}