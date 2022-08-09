#include <stdio.h>
#include <stdlib.h>
#define max 99
#define inf 9999
void floyd(int g[max][max],int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(g[i][j] == 0){
                g[i][j] = inf;
            }
        }
    }
    int k;
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(g[i][k] + g[k][j] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("\nDistance of %d to %d = %d", i+1, j+1, g[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    FILE *ip = fopen("matrixfloyd.txt", "r");
    int n;
    fscanf(ip, "%d", &n);
    int i, j;
    int g[max][max];
    for(i=0; i<n;i++){
        for(j=0; j<n; j++){
            fscanf(ip, "%d", &g[i][j]);
        }
    }
    floyd(g, n);
    return 0;
}
