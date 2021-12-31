#include <stdio.h>
void swapping(int *, int *);
int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("\nBEFORE SWAPPING A = %d , B = %d", a, b);
    swapping(&a, &b);
    printf("\nAFTER SWAPPING A = %d , B = %d", a, b);
}
void swapping(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}