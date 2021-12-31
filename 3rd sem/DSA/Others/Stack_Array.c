#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1;
void push(){
    int data;
    printf("Enter the element to be pushed: ");
    scanf("%d", &data);
    if (top==(N-1)){
        printf("\nStack is full.\n");
    }
    else{
        top += 1;
        stack[top]=data;
        printf("\n%d has been pushed\n", data);
    }
}
void pop(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        top--;
        printf("Top item has been popped.\n");
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        for(int i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}
void peek(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        printf("Top element is %d\n", stack[top]);
    }
}
int main(){
    int choice;
    while(1){
        printf("\nEnter your choice:-\n");
        printf("1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit\nYour Choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter a valid choice!!!");
            break;
        }
    }
    return 0;
}
