
/* Sabyasachi Seal , 13005320003 */
#include <stdio.h>
#include <stdlib.h>
void push(int digit, int top, int stack[]){
    int data = digit;
    top += 1;
    stack[top]=data;
}
void pop(int top, int stack[]){
    int temp = stack[top];
    top--;
}
int main(){
    int num, digit, size=0, temp;
    int top = -1;
    scanf("%d", &num);
    temp = num;
    while (temp>0){
        size++;
        temp /= 10;
    }
    int stack[size];
    temp = num;
    while(temp>0){
        digit = temp%10;
        push(digit, top, stack);
        temp /= 10;
    }
    temp = size;
    while(temp){
        printf("%d", stack[top]);
        pop(top, stack);
        temp--;
    }
    return 0;
}
