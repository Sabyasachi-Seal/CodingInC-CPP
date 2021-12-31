#include <stdio.h>
#include <stdlib.h>
#define N 3
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int num){
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear]=num;
    }
    else if(((rear+1)%N)==front){
        printf("Overflow Condition\n");
    }
    else{
        rear = (rear+1)%N;
        queue[rear] = num;
    }
}
void dequeue(){
    if(front<0){
        printf("Underflow Condition\n");
    }
    else if(front==rear){
        printf("%d has been dequeued.\n", queue[front]);
        front=rear=-1;
    }
    else{
        printf("%d has been dequeued.\n", queue[front]);
        front = (front+1)%N;
    }
}
void display(){
    int i = 0;
    printf("Rear = %d", rear);
    printf("\nFront = %d", front);
    if(rear>=0){
        for(i = front; i!=rear; i = (i+1)%(N)){
            printf("\nQueue[%d] = %d", i, queue[i]);
            if (i==rear-1){
                printf("\nQueue[%d] = %d", i+1, queue[i+1]);
            }
        }
    }
    else{
        printf("Queue is empty\n");
    }
    printf("\n");
}
void peek(){
    if(rear>=0){
        printf("%d\n", queue[front]);
    }
    else{
        printf("No elements to print\n");
    }
}
int main(){
    int ch;
    do{
        printf("Enter your choice\n1-Enqueue\n2-Dequeue\n3-Peek\n4-Display\n5-Exit\nYour choice: ");
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
                display();
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