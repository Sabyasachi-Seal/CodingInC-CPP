#include <stdio.h> 
#define MAX 10
#define INFINITE 99999

void dijkstra(int Graph[MAX][MAX], int n, int source){

    int cost[MAX][MAX], distance[MAX], visited[MAX], pred[MAX];

    int count, mindistance, nextnode;

    for(int i=0; i<n; i++){//initialized cost matrix
        for(int j=0; j<n ; j++){
            if(Graph[i][j] == 1){// if there is a connection
                cost[i][j] = Graph[i][j];
            }
            else{
                cost[i][j] = INFINITE; 
            }
        }
    }

    for(int i=0; i<n; i++){
        distance[i] = cost[source][i];//putting distance from source
        pred[i] = source;// predesessor
        visited[i] = 0;
    }

    distance[source] = 0; // distance of source from itself is 0
    visited[source] = 1; // Source is visited
    count = 1;// selects a node

    while(count < n-1){
        mindistance = INFINITE;

        for(int i=0; i<n; i++){// finding shortest distance for a node
            if(distance[i] < mindistance && !visited[i]){
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1; // putting the shortest node as visited

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(mindistance + cost[nextnode][i] < distance[i]){
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }

        count++;
    }

    for(int i=0; i<n; i++){
        if(i != source){
            printf("Distance of %d from %d = %d", i, source, distance[i]);
        }
    }
}

int main() {
  int Graph[MAX][MAX], i, j, n, u;
  printf("\nEnter the number of nodes: ");
  scanf("%d", &n);
  FILE *fp = fopen("matrixdijkstra.txt", "r");
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
        fscanf(fp, "%d", &Graph[i][j]);
    }
  }
  printf("Enter source vertex: ");
  scanf("%d", &u);
  dijkstra(Graph, n, u);

  return 0;
}