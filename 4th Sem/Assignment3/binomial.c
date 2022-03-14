#include <stdio.h>
int binomial(int, int);
int main(){
    printf("Enter the value of n:");
    int n;
    scanf("%d", &n);
    printf("Enter the value of k:");
    int k;
    scanf("%d", &k);
    printf("The value of %dC%d is %d\n", n, k, binomial(n, k));
}
int binomial(int n, int k){
    if (k>n){
        return 0;
    }
    if(k == 0 || n==k){
        return 1;
    }
    return binomial(n-1, k-1) + binomial(n-1, k);
}