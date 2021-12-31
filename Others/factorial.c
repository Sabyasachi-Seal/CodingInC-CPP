#include <stdio.h>
int main(){
    int n, fac=1;
    printf("Enter the number=");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        fac*=i;
    }
    printf("Factorial=%d", fac);
    return 0;
}