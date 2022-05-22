#include <stdio.h>
#define max 20
#define inf 99999
int bellmanford(int V, int E, int G[max][max], int edge[max][2]){
    int distance[max];
    int u, v;
    int i, j;
    for(i=0; i<V; i++){
        distance[i] = inf;
    }
    int s;
    printf("Enter the source: ");
    scanf("%d", &s);
    distance[s-1] = 0;
    for(i=0; i<V-1; i++){
        for(j=0; j<E; j++){
            u = edge[j][0];
            v = edge[j][1];
            if(distance[v] > distance[u] + G[u][v]){
                distance[v] = distance[u] + G[u][v];
            }
        }
    }
    for(j=0; j<E; j++){
        u = edge[j][0];
        v = edge[j][1];
        if(distance[v] > distance[u] + G[u][v]){
            return 0;
        }
    }
    for(i=0; i<V; i++){
        printf("Verted %d -> %d\n", i+1, distance[i]);
    }
    return 1;
}
int main(){
    int V, edge[max][2], G[max][max], i, j, k=0;
    printf("No of Vertices:");
    scanf("%d", &V);
    FILE *file = fopen("matrixbellman.txt", "r");
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            fscanf(file, "%d", &G[i][j]);
            if(G[i][j]!=0){
                edge[k][0] = i;
                edge[k][1] = j;
                k++;
            }
        }
    }
    (bellmanford(V, k, G, edge))?printf("No negeative weight cycle"):printf("Negative weight cycle");
    return 0;
}
