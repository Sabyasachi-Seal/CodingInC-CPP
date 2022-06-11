#include <stdio.h>
#include <stdlib.h>
#define max 99
#define inf 99999
void show(int g[max][max], int distance[max], int v, int s){
    int i;
    int j;
    for(i=0; i<v; i++){
        printf("\nDistance of %d to %d = %d", i+1, s+1, distance[i]);
    }
}

void bellman(int g[max][max], int edges[max][2], int v, int e, int s){
    int i, j;
    int distance[max];
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            if(g[i][j]==0){
                g[i][j] = inf;
            }
        }
    }
    for(i=0; i<v; i++){
        distance[i] = g[s][i];
    }
    distance[s] = 0;
    for(i=0; i<v-1; i++){
        for(j=0; j<e; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            if(g[u][v] + distance[u] < distance[v]){
                distance[v] = g[u][v] + distance[u];
            }
        }
    }
    show(g, distance, v, s);
}

int main(){
    FILE *f = fopen("matrixbellman.txt", "r");
    int v;
    fscanf(f, "%d", &v);
    int g[max][max];
    int edges[max][2];
    int i, j, e=0;
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            fscanf(f, "%d", &g[i][j]);
            if(g[i][j]!=0){
                edges[e][0] = i;
                edges[e][1] = j;
                e++;
            }
        }
    }
    printf("\nEnter the source: ");
    int s;
    scanf("%d", &s);
    bellman(g, edges, v, e, s-1);
    return 0;
}
