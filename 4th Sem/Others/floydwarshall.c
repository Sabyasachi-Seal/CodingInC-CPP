#include <stdio.h>
#define max 99
#define inf 9999
int floyd(int g[max][max], int n){
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
                if(g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("\nDistance of %d from %d = %d", i+1, j+1, g[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int g[max][max], i, j, n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    FILE *fp = fopen("matrixdijkstra.txt", "r");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            fscanf(fp, "%d", &g[i][j]);
        }
    }
    floyd(g, n);
    return 0;
}