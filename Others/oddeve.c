#include <stdio.h>
void swap(int *,int *);
int main(){
    int a, b;
    printf("Enter numbers: ");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("A is %d and B is %d", a, b);
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}