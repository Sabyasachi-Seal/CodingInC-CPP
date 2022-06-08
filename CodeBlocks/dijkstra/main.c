#include <stdio.h>
#include <stdlib.h>
#define max 99
#define inf 999
void show(int distance[max], int v, int s){
    int i;
    for(i=0; i<v; i++){
        printf("\nDistance of %d from %d = %d", i+1, s+1, distance[i]);
    }
}
void dijkstra(int g[max][max], int v, int s){
    int distance[max], visited[max];
    int i, j;
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            if(g[i][j]==0){
                g[i][j] = inf;
            }
        }
    }
    for(i=0; i<v; i++){
        distance[i] = g[s][i];
        visited[i] = 0;
    }
    distance[s] = 0;
    visited[s] = 1;
    int mindis = inf;
    int nextnode = s;
    int count = 1;
    while(count<v-1){
        for(i=0; i<v; i++){
            if(!visited[i] && distance[i] < mindis){
                mindis = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for(i=0; i<v; i++){
            if(mindis + g[nextnode][i] < distance[i]){
                distance[i] = g[nextnode][i] + mindis;
            }
        }
        count++;
    }
    show(distance, v, s);
}
int main()
{
    FILE *input = fopen("matrixdijkstra.txt", "r");
    int v;
    fscanf(input, "%d", &v);
    int i, j;
    int g[max][max];
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    int s;
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    dijkstra(g, v, s-1);
    return 0;
}
