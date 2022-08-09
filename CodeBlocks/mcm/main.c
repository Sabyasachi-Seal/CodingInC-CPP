#include <stdio.h>
#include <stdlib.h>
#define inf 999
int matrixchain(int arr[], int size){
    int m[size][size];
    int i;
    for(i=0; i<size; i++){
        m[i][i] = 0; // set diagonals as 0
    }
    int l, j, k, q;
    int n = size;
    for(l = 2; l<n; l++){
        for(i=1; i<n-l+1; i++){
            j = i + l - 1;
            m[i][j] = inf;
            for(k = i; k<j; k++){
                q = m[i][k] + m[k+1][j] + arr[i-1]*arr[j]*arr[k];
                m[i][j] = (m[i][j]<q)?q:m[i][j];
            }

        }
    }
    return m[1][n-1];
}

int main(){
    int arr[] = {10, 20, 30, 20, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = matrixchain(arr, size);
    printf("%d ", ans);
    return 0;
}
