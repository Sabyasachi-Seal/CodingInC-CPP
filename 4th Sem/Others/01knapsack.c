#include <stdio.h>
int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int profits[], int weights[], int target, int n){
    int k[n+1][target+1];
    int i, j;
    for(i=0; i<=n; i++){
        for(j=0; j<=target; j++){
            if(i==0 || j==0){
                k[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                k[i][j] = max(k[i-1][j], profits[i-1]+k[i-1][j-weights[i-1]]);
            }
            else{
                k[i][j] = k[i-1][j];
            }
        }
    }
    return k[n][target];
}
int main(){
    FILE *input = fopen("knapsackinput2.txt", "r");
    int n;
    fscanf(input, "%d", &n);
    int target;
    fscanf(input, "%d", &target);
    int profits[n], weights[n];
    int i;
    for(i=0; i<n; i++){
        fscanf(input, "%d", &profits[i]);
    }
    for(i=0; i<n; i++){
        fscanf(input, "%d", &weights[i]);
    }
    printf("%d", knapsack(profits, weights, target, n));
}