#include <stdio.h>
#define max 10
#define infinite 9999

void dijkstra(int graph[max][max], int n, int source){
    int cost[max][max], distance[max], visited[max];
    int i, j, count, nextnode, mindis;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(graph[i][j] == 1){
                cost[i][j] = graph[i][j];
            }
            else{
                cost[i][j] = infinite;
            }
        }
    }

    for(i=0; i<n; i++){
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;
    count = 1;

    while(count < n-1){
        mindis = infinite;

        for(i=0; i<n; i++){
            if(distance[i] < mindis && !visited[i]){
                mindis = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i=0; i<n; i++){
            if(mindis + cost[nextnode][i] < distance[i]){
                distance[i] = mindis + cost[nextnode][i];
            }
        }
        count++;
    }

    for(int i=0; i<n; i++){
        printf("\nDistance of %d from %d = %d", i, source, distance[i]);
    }
}

int main(){
    int graph[max][max];
    int source,n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("\nGraph[%d][%d] = ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}