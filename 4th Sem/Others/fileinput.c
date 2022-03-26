#include <stdio.h>
int main(){
    int arr[5][5];
    FILE *file = fopen("inputs.txt", "r");
    for(int i=0; i<5; i++){
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