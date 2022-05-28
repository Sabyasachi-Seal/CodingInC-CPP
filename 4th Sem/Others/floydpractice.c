#include <stdio.h>
#define max 20
#define inf 999
void floyd(int g[max][max], int n){
    int i, j, k;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(g[i][j]==0){
                g[i][j] = inf;
            }
        }
    }
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
            if(i!=j) printf("\nDistance of %d from %d = %d", i+1, j+1, g[i][j]);
        }
        printf("\n");
    }

}
int main(){
    FILE *input = fopen("matrixfloyd.txt", "r");
    int n = 5;
    fscanf(input, "%d", &n);
    int i, j;
    int g[max][max];
    for(i=0; i<n; i++){
        for(j=0; j<n ;j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    floyd(g, n);
}