
/* Sabyasachi Seal, 13005320003 */
#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[5];
int top = -1;
void push(int digit){
    int data = digit;
    top += 1;
    stack[top]=data;
}
void pop(){
    printf("%d", stack[N - top - 1]);
    top--;
}
int main(){
    int num, digit, size=0, temp;
    scanf("%d", &num);
    temp = num;
    while (temp>0){
        size++;
        temp /= 10;
    }
    temp = num;
    while(temp>0){
        digit = temp%10;
        push(digit);
        temp /= 10;
    }
    while(top>-1){
        pop();
    }
    return 0;
}
