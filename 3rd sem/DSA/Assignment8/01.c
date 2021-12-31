#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef node *addrnode;
typedef struct graph
{
    int nodes;
    addrnode *array; // the array stores the addresses of nodes.
} graph;
node *creation(int data)
{
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
node *insertion(node *head, int data)
{
    if (head == NULL)
    {
        node *ptr = creation(data);
        head = ptr;
    }
    else
    {
        node *p = head;
        node *ptr = creation(data);
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}
void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void adjacencymatrix(int arr[][10], int n, int p, int q)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            if (i == p && j == q)
            {

                arr[i][j] = 1;
                arr[j][i] = 1;
                break;
            }
        }
    }
}
void printgraph(int arr[][10], int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter number of nodes in the graph\n");
    scanf("%d", &n);
    int arr[10][10];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            arr[i][j] = 0;
        }
    }

    graph *gr = malloc(sizeof(graph));
    gr->nodes = n;
    gr->array = malloc(n * sizeof(node)); // array of the addresses (node*) of the head nodes.
    for (int i = 1; i <= n; i++)
    {
        (gr->array[i]) = NULL;
    }
    int i = 1;
    while (i)
    {
        int p, q;
        printf("ENTER THE NODES YOU WANT TO CREATE AN EDGE IN BETWEEN\n");
        scanf("%d", &p);
        scanf("%d", &q);
        adjacencymatrix(arr, n, p, q);
        gr->array[p] = insertion(gr->array[p], q);
        gr->array[q] = insertion(gr->array[q], p);
        printf("CONTINUE? if not (0)\n");
        int choice;
        scanf("%d", &choice);
        if (!choice)
        {
            i = 0;
        }
    }
    printf("ADJACENCY MATRIX\n");
    printgraph(arr, n);
    printf("ADJACENCY LIST\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d->", i);
        display(gr->array[i]);
    }
}
