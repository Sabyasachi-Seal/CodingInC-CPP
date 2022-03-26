#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define infinite 999
int Bellman_Ford(int G[MAX][MAX], int V, int E, int edge[MAX][2]){

    int i, u, v, j, distance[MAX], parent[MAX], S, flag = 1;

    for (i = 0; i < V; i++){
        distance[i] = infinite;
        parent[i] = -1;
    }

    printf("Enter source: ");
    scanf("%d", &S);
    distance[S - 1] = 0;

    for (i = 0; i < V - 1; i++){
        for (j = 0; j < E; j++){
            u = edge[j][0];
            v = edge[j][1];
            if (distance[u] + G[u][v] < distance[v]){
                distance[v] = distance[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    for (j = 0; j < E; j++){
        u = edge[j][0];
        v = edge[j][1];
        if (distance[u] + G[u][v] < distance[v])
            flag = 0;
    }

    if (flag){
        for (i = 0; i < V; i++){
            printf("Vertex %d -> cost = %d parent = %d\n", i + 1, distance[i], parent[i] + 1);
        }
    }
    return flag;
}
int main(){
    int V, edge[MAX][2], G[MAX][MAX], i, j, k = 0;
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
    if (Bellman_Ford(G, V, k, edge)){
        printf("\nNo negative weight cycle\n");
    }
    else{
        printf("\nNegative weight cycle exists\n");
    }
    return 0;
}