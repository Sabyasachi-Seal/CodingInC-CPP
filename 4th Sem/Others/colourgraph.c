#include <stdio.h>
#define max 99
void print(int colours[max], int n){
    int i;
    for(i=0; i<n; i++){
        printf("\nVertex %d -> %d", i+1, colours[i]);
    }
}
void change(int g[max][max], int colours[max], int vertex, int n){
    int i, j;
    for(i=0; i<n; i++){
        if(g[vertex][i]==1){
            colours[i] = !colours[i];
        }
    }
}
void colour(int g[max][max], int colours[max], int n){
    int vertex, i, j;
    for(i=0; i<n; i++){
        printf("\n[%d] -> Enter vertex number : ", i+1);
        scanf("%d", &vertex);
        change(g, colours, vertex-1, n);
        print(colours, n);
    }
}
int main(){
    FILE *input = fopen("matrixcolouring.txt", "r");
    int n;
    fscanf(input, "%d", &n);
    int g[max][max], i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    int colours[max];
    for(i=0; i<n; i++){
        fscanf(input, "%d", &colours[i]);
    }
    colour(g, colours, n);
}