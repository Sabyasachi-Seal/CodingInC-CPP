#include <stdio.h>
#define max 99
#define inf 999
void floyd(int g[max][max], int v){
    int i, j;
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            if(g[i][j]==0){
                g[i][j] = inf;
            }
        }
    }
    int k;
    for(k=0; k<v; k++){
        for(i=0; i<v; i++){
            for(j=0; j<v; j++){
                if(g[i][k]+g[k][j]<g[i][j]){
                    g[i][j] = g[i][k]+g[k][j];
                }
            }
        }
    }
}
void print(int g[max][max], int v){
    int i, j;
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            if(i!=j) printf("\nDistance of %d from %d = %d", i, j, g[i][j]);
        }
        printf("\n");
    }
}
int main(){
    FILE *input = fopen("matrixfloyd.txt", "r");
    int v;
    fscanf(input, "%d", &v);
    int i, j;
    int g[max][max];
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    floyd(g, v);
    print(g, v);
    return 0;
}
