#include <stdio.h>
int min(int a, int b){
    return (a,b)?a:b;
}

int binomial(int n, int k){
    int c[n+1][k+1];
    int i, j;
    for(i=0; i<=n; i++){
        for(j=0; j<=min(i, k); j++){
            if(j==0 || i==j){
                c[i][j] = 1;
            }
            else{
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
    }
    return c[n][k];
}