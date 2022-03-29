#include <stdio.h>
int main(){
    int n;
    FILE *file = fopen("inputs.txt", "r");
    fscanf(file, "%d", &n);
    int arr[n][n];
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &arr[i]);
    }
    for(int i=1; i<n; i++){
        printf("%d ", arr[i]);
    }
}