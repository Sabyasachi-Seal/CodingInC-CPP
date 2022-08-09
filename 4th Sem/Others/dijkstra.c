#include <stdio.h>
#define INFINITY 9999
#define MAX 10
void Dijkstra(int cost[MAX][MAX], int n, int start){

  int distance[MAX], pred[MAX];

  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      if (cost[i][j] == 0){
        cost[i][j] = INFINITY;
      }
    }
  }

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++){
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }
    }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++){
      if (!visited[i]){
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
      }
    }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}

int main() {
  int Graph[MAX][MAX], i, j, n, u;
  printf("\nEnter the number of nodes: ");
  scanf("%d", &n);
  // for(i=0; i<n; i++){
  //   for(j=0; j<n; j++){
  //     printf("Enter the value of Graph[%d][%d] : ", i, j);
  //     scanf("%d", &Graph[i][j]);
  //   }
  // }
  FILE *fp = fopen("matrixdijkstra.txt", "r");
  for (i = 0; i < n; i++){
      for (j = 0; j < n; j++){
          fscanf(fp, "%d", &Graph[i][j]);
      }
  }
  printf("Enter source vertex: ");
  scanf("%d", &u);
  Dijkstra(Graph, n, u);

  return 0;
}