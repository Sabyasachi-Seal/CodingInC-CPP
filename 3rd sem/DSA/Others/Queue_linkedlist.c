#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}queue;
queue *front = NULL;
queue *rear = NULL;
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
int main(){
    int ch;
    do{
        printf("\nEnter your choice\n1-Enqueue\n2-Dequeue\n3-Peek\n4-Display\n5-Exit\nYour choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int num;
                printf("\nEnter the number you want to enter: ");
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
                exit(0);
                break;
            }
            default:{
                printf("Wrong Choice, Try Again");
                break;
            }
        }
    }while(1);
}