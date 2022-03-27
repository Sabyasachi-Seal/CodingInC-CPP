#include <stdio.h>
int mcm(int[],int);
void main(){
    FILE *input = fopen("inputs.txt", "r");
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        fscanf(input, "%d", &arr[i]);
    }
    printf("%d", mcm(arr, n));
}
int mcm(int arr[], int n){
    int q[n][n];
    int i1, i2, j, k, temp;
    for(int i=1; i<n; i++){
        q[i][i] = 0;
    }
    for(i1=1; i1<n-1; i1++){
        for(i2=1; i2<n-i1; i2++){
            j = i2 + i1;
            q[i2][j] = 99999;
            for(k=i2; k<j; k++){
                temp = q[i2][k] + q[k+1][j] + arr[i2-1] * arr[j] *arr[k];
                if (temp < q[i2][j]){
                    q[i2][j] = temp;
                }
            }
        }
    }
    return q[1][n-1];
}