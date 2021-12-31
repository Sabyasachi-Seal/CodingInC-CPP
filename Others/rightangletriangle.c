#include <stdio.h>
int main(){
    int n;
    printf("Enter rows: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            (i%2==0)? (j%2==1)?printf("$"):printf("*") : (j%2==0)?printf("$"):printf("*");
        }
        printf("\n");
    }
    return 0;
}