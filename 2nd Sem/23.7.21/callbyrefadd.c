#include <stdio.h>
int addnos(int *, int *);
int main(){
    int num1, num2;
    printf("Enter two integer values :");
    scanf("%d%d", &num1, &num2);
    addnos(&num1, &num2);
    return 0;
}
int addnos(int *num1, int *num2){
    int sum = *num1 + *num2;
    printf("Sum = %d", sum);
    return 0;
}
