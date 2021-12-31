#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
typedef node *addnode;
typedef struct graph{
    int nodes;
    addnode *array;
}graph;
typedef struct queue{
    int size;
    int *arr;
    int front, rear;
}queue;
node *newnode(int);
node *insert(node *, int);
void display(node *);
void adjmat(int[][10], int, int, int);
void displaygraph(int[][10], int);
int isFull(queue *);
void enqueue(queue *, int);
void enqueue(queue *, int);
int isEmpty(queue *);
int dequeue(queue *);
void depthfirst(int[][10], int, int *, int);
int main(){
    int n;
    printf("\nEnter the Limit of nodes: ");
    scanf("%d", &n);
    int arr[10][10];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){

            arr[i][j] = 0;
        }
    }
    graph *gr = malloc(sizeof(graph));
    gr->nodes = n;
    gr->array = malloc(n * sizeof(node)); // array of the addresses (node*) of the head nodes.
    for (int i = 1; i <= n; i++){
        (gr->array[i]) = NULL;
    }
    int i = 1;
    while (i){
        int p, q;
        printf("Enter the nodes that have an edge berween them: \n");
        scanf("%d", &p);
        scanf("%d", &q);
        adjmat(arr, n, p, q);
        gr->array[p] = insert(gr->array[p], q);
        gr->array[q] = insert(gr->array[q], p);
        printf("1-Continue\n0-Exit\n");
        int choice;
        scanf("%d", &choice);
        if (!choice){
            i = 0;
        }
    }
    printf("Adjacency Matrix\n");
    displaygraph(arr, n);
    printf("Adjacency List\n");
    for (int i = 1; i <= n; i++){
        printf("%d->", i);
        display(gr->array[i]);
    }
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->size = n;
    q->arr = (int *)malloc(sizeof(int) * n);
    int *visited = malloc(sizeof(int));
    for (int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    int k = 1;
    printf("\nBreadth First Search:\n");
    printf("%d ", k);
    visited[k] = 1;
    enqueue(q, k);
    while (!isEmpty(q)){
        int node = dequeue(q);
        for (int j = 1; j <= n; j++){
            if (arr[node][j] == 1 && visited[j] != 1){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    printf("\nDepth First Search:\n");
    depthfirst(arr, n, visited, 1);
}
node *newnode(int data){
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
node *insert(node *head, int data){
    if (head == NULL){
        node *ptr = newnode(data);
        head = ptr;
    }
    else{
        node *p = head;
        node *ptr = newnode(data);
        while (p->next != NULL){
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}
void display(node *head){
    node *ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void adjmat(int arr[][10], int n, int p, int q){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == p && j == q){
                arr[i][j] = 1;
                arr[j][i] = 1;
                break;
            }
        }
    }
}
void displaygraph(int arr[][10], int n){
    for (int i = 1; i <= n; i++){

        for (int j = 1; j <= n; j++){

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int isFull(queue *q){
    if (q->rear == q->size - 1){
        return 1;
    }
    return 0;
}
void enqueue(queue *q, int data){
    if (isFull(q)){
        printf("Overflow\n");
    }
    else{

        q->arr[++q->rear] = data;
    }
}
int isEmpty(queue *q){
    if (q->front == q->rear){
        return 1;
    }
    return 0;
}
int dequeue(queue *q){
    int a = -1;
    if (isEmpty(q)){
        printf("Underflowed\n");
    }
    else{
        a = q->arr[++(q->front)];
    }
    return a;
}
void depthfirst(int a[][10], int n, int *visited, int i){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 1; j <= n; j++){
        if (a[i][j] == 1 && visited[j] == 0){
            depthfirst(a, n, visited, j);
        }
    }
}