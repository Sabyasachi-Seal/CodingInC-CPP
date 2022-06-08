#include <stdio.h>
#include <stdlib.h>
#define max 99
void show(int colours[max], int v){
    int i;
    for(i=0; i<v; i++){
        printf("\nVertex %d -> %d", i+1, colours[i]);
    }
}
void change(int g[max][max], int colours[max], int v, int ver){
    int i;
    for(i=0; i<v; i++){
        if(g[ver][i] == 1){
            colours[i] = !colours[i];
        }
    }
}
void graphcolour(int g[max][max], int colours[max], int v){
    int i;
    int ver;
    for(i=0; i<10; i++){
        printf("\nEnter the vertex[%d]: ", i+1);
        scanf("%d", &ver);
        change(g, colours, v, ver-1);
        show(colours, v);
    }
}
int main()
{
    FILE *input = fopen("matrixcolouring.txt", "r");
    int v;
    fscanf(input, "%d", &v);
    int i, j;
    int g[max][max];
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            fscanf(input, "%d", &g[i][j]);
        }
    }
    int colours[max];
    graphcolour(g, colours, v);
    return 0;
}
