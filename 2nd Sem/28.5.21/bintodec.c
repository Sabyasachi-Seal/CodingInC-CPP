#include <stdio.h>
int main(){
    int b, d = 0, base = 1, rem;
    printf("Enter Number = ");
    scanf("%d", &b);
    int temp = b;
    while(temp>0){
        rem = temp % 10;
        d+=(rem*base);
        temp/=10;
        base*=2;
    }
    printf("Decimal= %d\n", d);
    return 0;
}