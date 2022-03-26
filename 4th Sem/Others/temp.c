#include <stdio.h>
#define max 10
#define infinite 999

int bellman(int g[max][max], int V, int E, int edges[max][2]){
    int dist[max], parent[max];
    int i, j, k, u, v, flag=1;

    for(i=0; i<V; i++){
        dist[i] = infinite;
        parent[i] = -1;
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dist[source - 1] = 0;

    for(i=0; i<V-1; i++){
        for(j=0; j<E; j++){
            u = edges[j][0];
            v = edges[j][1];
            if(dist[u] + g[u][v] < dist[v]){
                dist[v] = dist[u] + g[u][v];
                parent[v] = u;
            }
        }
    }

    for(j=0; j<E; j++){
        u=edges[j][0];
        v=edges[j][1];
        if(dist[u] + g[u][v] < dist[v]){
            flag = 0;
        }
    }

    if(flag){
        for(i=0; i<V; i++)
            printf("\nVertex = %d || Cost = %d || Parent = %d", i+1, dist[i], parent[i]+1);
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
    if (bellman(G, V, k, edge)){
        printf("\nNo negative weight cycle\n");
    }
    else{
        printf("\nNegative weight cycle exists\n");
    }
    return 0;
}