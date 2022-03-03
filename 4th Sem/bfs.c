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
    if(q->rear == q->size-1)
        return true;
    else
        return false;
}
bool isempty(struct queue *q){
    if(q->front == q->rear ){
        return true;
    }
    return false;
}
void enqueue(struct queue *q, int data){
    if(isfull(q)){
        printf("Overload\n");
        return;
    }
    else{
        // printf("%d enqueued\n", data);
        q->rear ++;
        q->array[q->rear] = data;

    }
}
int dequeue(struct queue *q){
    int a = -1;
    if(isempty(q)){
        printf("Underlfow\n");
    }
    else{
        q->front++;
        a = q->array[q->front];
    }
    return a;
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
    printf("\n");
}
int main(){
    struct queue q;
    q.size = 100;
    q.front = 0;
    q.rear = 0;
    q.array = (int *)malloc(sizeof(sizeof(int)*q.size));
    // int arr[] = {633,56,12,5,6,8,9,0,7,4,3,56,2,43,5,6,234,4,445,45};
    // for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
    //     enqueue(&q, arr[i]);
    // }

    // display(&q);

    // for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
    //     dequeue(&q);
    // }

    // display(&q);
    int node, i =0, j=0;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &node);
    int visited [node];
    int a [node][node];
    while(i<node){
        visited[i] = 0;
        printf("\nEnter the data for node %d: ", i+1);
        j =0;
        while(j<node){
            printf("\nEnter the value for node %d - %d: ",i+1, j+1);
            scanf("%d", &a[i][j]);
            j++;
        }
        i++;
    }
    printf("\n");
    i=0;
    j=0;
    while(i<node){
        j =0;
        while(j<node){
            printf("%d ", a[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    i = 1;
    j = 0;
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while(!(isempty(&q))){
        int node = dequeue (&q);
        for(j=0; j<(sizeof(a[0])/sizeof(a[0][0])); j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }

        }

    }
    return 0;
}