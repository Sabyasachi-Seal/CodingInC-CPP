#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
/* Problem Lies in the dfs function. Cannot Take a 2D array as a parameter*/
void dfs(int arr[][MAX], int visited[], int node){
    printf("%d ", node);
    printf("%d\n", size);
    int i=0;
    int j=0;
    while(i<size){
        j = 0;
        while(j<size){
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }


    visited[node] = 1;
    for(int j=0; j<MAX; j++){
        if(arr[node][j] == 1 && visited[j] == 0){
            dfs(arr, visited, j);
        }
    }
}
int main(){
    int node, i =0, j=0;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &node);
    int visited [node];
    int arr [node][node];
    while(i<node){
        visited[i] = 0;
        printf("\nEnter the data for node %d: ", i+1);
        j =0;
        while(j<node){
            printf("\nEnter the value for node %d - %d: ",i+1, j+1);
            scanf("%d", &arr[i][j]);
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
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    printf("Enter Starting Vertex: ");
    scanf("%d", &node);
    dfs(arr, visited, node);
    return 0;
}