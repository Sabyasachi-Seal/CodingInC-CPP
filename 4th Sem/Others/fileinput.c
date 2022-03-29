#include <stdio.h>
int main(){
    int n;
    printf("Enter number of inputs: ");
    scanf("%d", &n);
    int arr[n][n];
    FILE *file = fopen("inputs.txt", "r");
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            fscanf(file, "%d", &arr[i][j]);
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}