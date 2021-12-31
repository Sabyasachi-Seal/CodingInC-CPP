#include <stdio.h>
int main(){
    int n;
    printf("Enter rows: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=i; j>=1; j--){
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}