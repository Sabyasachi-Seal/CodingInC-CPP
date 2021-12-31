#include <stdio.h>
int fact(int);
int main(){
    int n, fac=1;
    printf("Enter the number = ");
    scanf("%d", &n);
    fac = fact(n);
    printf("Factorial = %d", fac);
    return 0;
}
int fact(int n){
    int f = 1;
    if(n==0){
        return f;
    }
    f = n * fact(n-1);
}