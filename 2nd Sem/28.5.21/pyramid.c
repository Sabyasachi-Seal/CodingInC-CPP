#include <stdio.h>
int main(){
    int n,i,j,lim,t;
    printf("Enter the rows: ");
    scanf("%d", &n);
    lim=2*n-1;
    for(i=0;i<=n;i+=1){
        for(j= 1 ;j<=(n-i);j+=1){
            printf(" ");
        }
        for(t=0;t<=i;t++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}