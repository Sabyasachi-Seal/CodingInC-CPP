#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}stack;
stack *top = NULL;
void push(int num){
    stack *newnode;
    newnode = (stack *)malloc(1*sizeof(stack));
    newnode->data = num;
    newnode->next = NULL;
    if(top == NULL){
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode; 
    }
    printf("\n%d has been pushed\n", num);
}
void display(){
    stack *temp;
    temp = top;
    if(top==NULL){
        printf("\n!Empty Stack!\n");
    }
    else{
        printf("\n");
        while(temp!=NULL){
            printf(" %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void pop(){
    stack *temp;
    temp = top;
    if(top==NULL){
        printf("\n!Underflow Condition!\n");
    }
    else{
        printf("\n%d has been popped\n", top->data);
        top = top->next;
        free(temp);
    }
}
void topper(){
    if(top==NULL){
        printf("\n!Stack Is Empty!\n");
    }
    else{
        printf("\n%d\n", top->data);
    }
}
int main(){
    int choice, num;
    do{
        printf("\n1 - Push\n2 - Pop\n3 - Display the Stack\n4 - Top\n5 - Exit\nYour Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                printf("\nEnter data: ");
                scanf("%d", &num);
                push(num);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                topper();
                break;
            }
            case 5:{
                exit(0);
                break;
            }
            default:{
                printf(" Try again ");
                break;
            }
        }
    }while(1);
    return 0;
}

