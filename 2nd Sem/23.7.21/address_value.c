#include <stdio.h>
int main(){
    int a = 5;
    int *point = &a;
    printf("Address of A using * = %p\n", point);
    printf("Address of A using & = %p\n", &a);
    printf("Value of A using * = %d\n", *point);
    printf("Value of A using * and & = %d\n", *(&a));
}