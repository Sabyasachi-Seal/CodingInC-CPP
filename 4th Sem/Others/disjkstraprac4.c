#include <stdio.h>
#define max 20
#define inf 999
void dijkstra(int g[max][max], int source, int n){
    int distance[n], visited[n];
    int i, j, mindis, count, nextnode;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(g[i][j]==0){
                g[i][j] = inf;
            }
        }
    }
    for(i=0; i<n; i++){
        distance[i] = g[source][i];
        visited[i] = 0;
    }
    visited[source] = 1;
    distance[source] = 0;
    count = 1;
    while(count<n-1){
        mindis = inf;
        for(i=0; i<n; i++){
            if(!visited[i] && mindis>distance[i]){
                mindis = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for(i=0; i<n; i++){
            if(!visited[i]){
                if(mindis + g[nextnode][i] < distance[i]){
                    distance[i] = mindis + g[nextnode][i];
                }
            }
        }
        count++;
    }
    for(i=0; i<n; i++){
        printf("\nCost of %d = %d", i+1, distance[i]);
    }
}
int main(){
    FILE *input = fopen("matrixdijkstra.txt", "r");
    int source, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int g[n][n];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d", g[i][j]);
        }
    }
    printf("Enter source: ");
    scanf("%d", &source);
    dijkstra(g, source, n);
    return 0;
}