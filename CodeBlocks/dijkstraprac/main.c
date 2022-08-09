#include <stdio.h>
#include <stdlib.h>
#define max 99
#define inf 999
void dijkstra(int g[max][max], int n, int s){
    int distance[max], visited[max];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(g[i][j] == 0){
                g[i][j] = inf;
            }
        }
    }
    for(i=0; i<n; i++){
        distance[i] = g[s][i];
        visited[i] = 0;
    }
    distance[s] = 0;
    visited[s] = 1;
    int count =0, nextnode, mindis=inf;
    while(count<n-1){
        for(i=0; i<n; i++){
            if(!visited[i] && distance[i] < mindis){
                mindis = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for(i=0; i<n; i++){
            if(mindis + g[nextnode][i] < distance[i]){
                distance[i] = mindis + g[nextnode][i];
            }
        }
        count++;
    }
    for(i=0; i<n; i++){
        printf("\nDistance of %d from %d = %d", i+1, s+1, distance[i]);
    }
}
int main()
{
    FILE *ip = fopen("matrixdijkstra.txt", "r");
    int n;
    fscanf(ip, "%d", &n);
    int i, j;
    int g[max][max];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(ip, "%d", &g[i][j]);
        }
    }
    int s;
    printf("\nEnter the source: ");
    scanf("%d", &s);
    dijkstra(g, n, s-1);
}
