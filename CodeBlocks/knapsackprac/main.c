#include <stdio.h>
#include <stdlib.h>
int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int w[], int p[], int n, int t){
    int k[n+1][t+1];
    int i, j;
    for(i=0; i<=n; i++){
        for(j=0; j<=t; j++){
            if(i==0 || j==0){
                k[i][j] = 0;
            }
            else if(j >= w[i-1]){
                k[i][j] = max(k[i-1][j], p[i-1] + k[i-1][j-w[i-1]]);
            }
            else{
                k[i][j] = k[i-1][j];
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
    int target;
    fscanf(input, "%d", &target);
    int weight[n];
    int profit[n];
    int i;
    for(i=0; i<n; i++){
        fscanf(input, "%d", &profit[i]);
    }
    for(i=0; i<n; i++){
        fscanf(input, "%d", &weight[i]);
    }
    int ans = knapsack(weight, profit, n, target);
    printf("%d", ans);
    return 0;
}
