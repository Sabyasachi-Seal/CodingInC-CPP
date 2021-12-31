#include <stdio.h>
int main(){
    int n=0;
    printf("Enter the number=");
    scanf("%d", &n);
    while(n>0){
        printf("%d ", n);
        n--;
    }
    return 0;
}