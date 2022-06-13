#include <stdio.h>
#include <stdlib.h>
int max(int a, int b){
    return (a>b)?a:b;
}

int knapsack(int profits[], int weights[], int n, int target){
    int i, j;
    int k[n+1][target+1];
    for(i=0; i<=n; i++){
        for(j=0; j<=target; j++){
            if(i==0 || j==0){
                k[i][j] = 0;
            }
            else if(weights[i] < j){
                k[i][j] = max(k[i-1][j-1], profits[i]+k[i-1][j-weights[i-1]]);
            }
            else{
                k[i][j] = k[i-1][j-1];
            }
        }
    }
    return k[n][target];
}

int main()
{
    FILE *input = fopen("knapsackinput2.txt", "r");
    int n;
    fscanf(input, "%d", &n);
    int t;
    fscanf(input, "%d", &t);
    int i;
    int profits[n], weights[n];
    for(i=0; i<n; i++){
        fscanf(input, "%d", &profits[i]);
    }
    for(i=0; i<n; i++){
        fscanf(input, "%d", &weights[i]);
    }
    printf("%d", knapsack(profits, weights, n, t));
    return 0;
}
