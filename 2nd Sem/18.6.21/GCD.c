#include <stdio.h>
int gcd(int, int);
int main(){
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);
    printf("GCD = %d", gcd(num1, num2));
    return 0;
}
int gcd(int num1, int num2){
    if (num1%num2==0)
        return num2;
    else
        return gcd(num2, num1%num2);
}