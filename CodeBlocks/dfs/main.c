#include <stdio.h>
#include <stdlib.h>
#define max 99
void dfs(int g[max][max], int visited[max], int n, int node){
    printf("%d ", node+1);
    visited[node] = 1;
    int i;
    for(i=0; i<n; i++){
        if(!visited[i] && g[node][i] == 1){
            dfs(g, visited, n, i);
        }
    }
}

int main()
{
    FILE *ip = fopen("dfsinput.txt", "r");
    int n;
    fscanf(ip, "%d", &n);
    int g[max][max];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(ip, "%d", &g[i][j]);
        }
    }
    int visited[max];
    for(i=0 ; i<n; i++){
        visited[i] = 0;
    }
    dfs(g, visited, n, 0);
}
