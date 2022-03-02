#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct queue{
    int size;
    int front;
    int rear;
    int *array;
};
bool isfull(struct queue *q){
    if(q->size -1 == q->rear)
        return true;
    else
        return false;
}
bool isempty(struct queue *q){
    if(q->front == q->rear){
        return true;
    }
    return false;
}
void enqueue(struct queue *q, int data){
    if(isfull(q)){
        printf("Overload\n");
        return;
    }
    else if(q->front == -1 && q->rear == -1){
        q->front ++;
        q->rear ++;
        q->array[q->rear] = data;
        printf("%d enqueued\n", data);
    }
    else{
        printf("%d enqueued\n", data);
        q->rear ++;
        q->array[q->rear] = data;

    }
}
void dequeue(struct queue *q){
    if(isempty(q)){
        printf("Underlfow\n");
    }
    else{
        q->front++;
        printf("%d dequeued\n", q->array[q->front]);
    }
}
void display(struct queue *q){
    if(isempty(q)){
        printf("Empty\n");
    }
    else{
        for (int i = q->front; i<=q->rear; i++){
            printf("%d ", q->array[i]);
        }
    }
}
int main(){
    struct queue q;
    q.size = 100;
    q.front = -1;
    q.rear = -1;
    q.array = (int *)malloc(sizeof(sizeof(int)*q.size));
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        enqueue(&q, arr[i]);
    }

    display(&q);

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        dequeue(&q);
    }
    display(&q);
    return 0;
}