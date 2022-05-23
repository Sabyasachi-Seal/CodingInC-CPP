#include <stdio.h>
int nonzero(int n, int k){
    int i;
    for(i=1; i<=n; i++){
        int temp = i;
        int count = 0;
        while(temp>0){
            count += (temp%10!=0)?1:0;
            temp /= 10;
        }
        if(count == k){
            printf("%d ", i);
        }
    }
}
int main(){
    printf("Enter N: ");
    int n;
    scanf("%d", &n);
    printf("Enter K: ");
    int k;
    scanf("%d", &k);
    nonzero(n , k);
}