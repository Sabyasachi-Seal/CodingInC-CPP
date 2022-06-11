#include <stdio.h>
#include <stdlib.h>
int maxer(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int weights[], int profits[], int  t, int n){
    int k[n+1][t+1];
    int i, j;
    for(i=0; i<=n; i++){
        for(j=0; j<=t; j++){
            if(i==0 || j==0){
                k[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                k[i][j] = maxer(k[i-1][j], profits[i-1]+k[i-1][j-weights[i-1]]);
            }
            else{
                k[i][j] = k [i-1][j];
            }
        }
    }
    return k[n][t];
}
int main()
{
    FILE *input = fopen("knapsackinput2.txt", "r");
    int n;
    fscanf(input, "%d", &n);
    int t;
    fscanf(input, "%d", &t);
    int i;
    int weights[n];
    int profits[n];
    for(i=0; i<n; i++){
        fscanf(input, "%d", &profits[i]);
        //printf("%d ", profits[i]);
    }
    for(i=0; i<n; i++){
        fscanf(input, "%d", &weights[i]);
        //printf("%d ", weights[i]);
    }
    int ans;
    ans = knapsack(weights, profits, t, n);
    printf("%d", ans);
    return 0;
}
