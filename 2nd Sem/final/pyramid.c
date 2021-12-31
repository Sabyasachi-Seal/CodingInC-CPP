#include <stdio.h>
int main(){
    int n, i, j, t;
    printf("Enter the rows: ");
    scanf("%d", &n);
    for (i = 0; i < n; i += 1){
        for (j = 1; j <= (n - i); j += 1){
            printf(" ");
        }
        for (t = 0; t <= i; t++){
            printf("%d ",i+1);
        }
        printf("\n");
    }
    return 0;
}