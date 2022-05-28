#include <stdio.h>
#define max 20
#define inf 999
void dijkstra(int g[max][max], int n, int s){
    int distance[n], visited[n];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(g[i][j]==0){
                g[i][j] = inf;
            }
        }
    }
    for(i=0; i<n; i++){
        distance[i] = g[s][i];
        visited[i] = 0;
    }
    visited[s] = 1;
    distance[s] = 0;
    int count = 1;
    int nextnode, mindis;
    while(count<n-1){
        mindis = inf;
        for(i=0; i<n; i++){
            if(!visited[i] && (distance[i]<mindis)){
                nextnode = i;
                mindis = distance[i];
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
    int n = 5;
    int s = 1;
    int i, j;
    int g[n][n];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    dijkstra(g, n, s-1);
    return 0;
}