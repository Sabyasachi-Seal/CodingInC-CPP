#include <stdio.h>
#include <math.h>
int main(){
    int limit, x, factorial, j=0;
    int total = 0;
    printf("Enter the limit:");
    scanf("%d",&limit);
    for(int i = 0; i<=limit; i++){
        j = (j*10)+1;
        total += j;
    }
    printf("The sum is : %d", total);
}