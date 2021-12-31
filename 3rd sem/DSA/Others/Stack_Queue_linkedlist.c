#include <stdio.h>
#include <stdlib.h>
typedef struct stack_node{
    int data;
    struct stack_node *next;
}stack;
typedef struct queue_node{
    int data;
    struct queue_node *next;
}queue;
queue *front = NULL;//front of queue
queue *rear = NULL;//rear of queue
stack *top = NULL;//top of stack
//start of stack functions 
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
void display_stack(){
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
void topper(){
    if(top==NULL){
        printf("\n!Stack Is Empty!\n");
    }
    else{
        printf("\n%d\n", top->data);
    }
}
//end of stack functions
//start of queue functions
void enqueue(int num){
    queue *newnode;
    newnode = (queue *)malloc(1*sizeof(queue));
    newnode->data = num;
    newnode->next = NULL;
    if(front==0 && rear==0){
        front = newnode;
        rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    printf("\n%d has been Enqueued.\n", num);
}
void dequeue(){
    queue *temp;
    temp = front;
    if(front==NULL){
        printf("\n!Underflow Condition!\n");
    }
    else{
        printf("\n%d has been dequeued\n", front->data);
        front = front->next;
        free(temp);
    }
}
void display_queue(){
    queue *temp;
    temp = front;
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
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
void peek(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("\n%d\n", front->data);
    }
}
//end of queue functions
int main();//main fucntion written at last
void stack_menu(){
    int choice, num;
    do{
        printf("\n1 - Push\n2 - Pop\n3 - Display\n4 - Top\n5 - Exit From Stack\nYour Choice: ");
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
                display_stack();
                break;
            }
            case 4:{
                topper();
                break;
            }
            case 5:{
                main();
                break;
            }
            default:{
                printf("\n!! Wrong Choice, Try Again !!\n");
                stack_menu();
                break;
            }
        }
    }while(1);
}
void queue_menu(){
    int choice, num;
    do{
        printf("\nEnter your choice\n1-Enqueue\n2-Dequeue\n3-Peek\n4-Display\n5-Exit From Queue\nYour choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("\nEnter data: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                display_queue();
                break;
            }
            case 5:{
                main();
                break;
            }
            default:{
                printf("\n!! Wrong Choice, Try Again !!\n");
                queue_menu();
                break;
            }
        }
    }while(1);
}
int main(){
    int choice;
    printf("\n1-Stack\n2-Queue\n3-Exit\nYour Choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:{
            stack_menu();
            break;
        }
        case 2:{
            queue_menu();
            break;
        }
        case 3:{
            exit(0);
            break;
        }
        default:{
            printf("\n!! Wrong Choice, Try again !!\n");
            main();
            break;
        }
    }
    return 0;
}