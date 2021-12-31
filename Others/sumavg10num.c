#include <stdio.h>
int main(){
    int n, sum=0;
    float avg = 0;
    printf("Enter numbers:-\n");
    for(int count =1; count<=10; count+=1){
        scanf("%d", &n);
        sum+=n;
    }
    avg = (sum/10.0);
    printf("Sum= %d\n", sum);
    printf("Average= %f", avg);
    return 0;
}