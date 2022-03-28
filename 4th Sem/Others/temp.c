#include <stdio.h>
#define max 20
#define infinite 999
void bellman(int g[max][max], int V, int E, int edges[max][2]){
    int distance[max], cost[max][max];
    int i, j, u, v;
    for(i=0; i<V; i++){
        distance[i] = infinite;
    }
    int s;
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    for(i=0; i<V; i++){
        for(j=0; j<E; j++){
            if(g[i][j]==0){
                cost[i][j] = infinite;
            }
            else{
                cost[i][j] = g[i][j];
            }
        }
    }
    distance[s-1] = 0;
    for(i=0; i<V-1; i++){
        for(j=0; j<E; j++){
            u = edges[j][0];
            v = edges[j][1];
            if(distance[u] + cost[u][v] < distance[v]){
                distance[v] = distance[u] + cost[u][v];
            } 
        }
    }
    int flag=1;
    for(j=0; j<E; j++){
        u = edges[j][0];
        v = edges[j][1];
        if(distance[u] + g[u][v] < distance[v]){
            flag = 0;
        }
    }
    for(i=0; i<V; i++){
        printf("\nVertex %d -> cost = %d ", i+1, distance[i]);
    }
}
void main(){
    FILE *fp = fopen("matrixbellman.txt", "r");
    int n, k=0, i, j;
    scanf("%d", &n);
    int g[max][max], edges[max][2];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(fp, "%d", &g[i][j]);
            if(g[i][j]!=0){
                edges[k][0]=i;
                edges[k][1]=j;
                k++;
            }
        }
    }
    bellman(g, n, k, edges);
    return;
}