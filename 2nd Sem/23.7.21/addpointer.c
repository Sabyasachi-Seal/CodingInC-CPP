#include <stdio.h>
int pointer(int *, int *);
int main(){
    int num1, num2;
    printf("Enter two integer values :");
    scanf("%d%d", &num1, &num2);
    int *point1 = &num1, *point2 = &num2;
    pointer(point1, point2);
    return 0;
}
int pointer(int *point1, int *point2){
    int sum = *point1 + *point2;
    printf("Sum = %d", sum);
    return 0;
}
