#include <stdio.h>
#define max 20
#define infinite 999
int bellmanford(int graph[max][max], int V, int E, int edges[max][2]){
    int distance[max];
    int i, j, k, u, v, s, flag=1;

    for(i=0; i<V; i++){
        distance[i] = infinite;
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);
    distance[s-1] = 0;

    for(i=0; i<V-1; i++){
        for(j=0; j<E; j++){
            u = edges[j][0];
            v = edges[j][1];
            if(distance[u] + graph[u][v] < distance[v]){
                distance[v] = distance[u] + graph[u][v];
            } 
        }
    }

    for(j=0; j<E; j++){
        u = edges[j][0];
        v = edges[j][0];
        if(distance[u] + graph[u][v] < distance[v]){
            flag = 0;
        }
    }

    if(flag){
        for(i=0; i<V; i++){
            printf("Vertex %d -> cost = %d\n", i + 1, distance[i]);
        }
    }
    return flag;
}
int main(){
    int V, edge[max][2], G[max][max], i, j, k = 0;
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d", &V);
    printf("Given input graph in matrix form:\n");
    FILE *fp = fopen("matrixbellman.txt", "r");
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            fscanf(fp, "%d", &G[i][j]);
            if (G[i][j] != 0){
                edge[k][0] = i;// source
                edge[k][1] = j;// destination
                k++;
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",G[i][j]);
        }printf("\n");
    }
    if (bellmanford(G, V, k, edge)){
        printf("\nNo negative weight cycle\n");
    }
    else{
        printf("\nNegative weight cycle exists\n");
    }
    return 0;
}