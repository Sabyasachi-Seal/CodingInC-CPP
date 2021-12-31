#include <stdio.h>
void fact(int, int *);
int main(){
    int fac, num;
    printf("Enter number: ");
    scanf("%d", &num);
    fact(num, &fac);
    printf("Factorial = %d", fac);
    return 0;
}
void fact(int num, int *fac){
    *fac = 1;
    for (int i = 1; i <= num; i++){
        *fac = *fac * i;
    }
}