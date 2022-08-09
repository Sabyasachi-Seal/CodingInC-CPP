#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int matrixchain(int arr[], int n){
    int m[n][n];
    int i;
    for(i=0; i<n; i++){
        m[i][i] = 0;
    }
    int l, k, q, j;
    for(l=2; l<=n; l++){
        for(i=1; i<n-l+1; i++){
            j = l+i-1;
            m[i][j] = INT_MAX;
            for(k=i; k<j; k++){
                q = m[i][k] + m[k+1][j] + arr[i-1]*arr[j]*arr[k];
                if(q<m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int main()
{
    int arr[] = {10, 20, 30, 20, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = matrixchain(arr, n);
    printf("%d", ans);
}
