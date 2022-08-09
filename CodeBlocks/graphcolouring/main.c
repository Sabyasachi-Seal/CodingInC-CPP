#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10
void print(int colour[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", colour[i]);
    }
}
bool issafe(bool g[max][max], int colour[], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(g[i][j]==1 && colour[j]==colour[i]){
                return false;
            }
        }
    }
    return true;
}
bool colourgraph(bool g[max][max], int colour[], int m, int n, int i){
    if(i==m){
        if(issafe(g, colour, n)){
            print(colour, n);
            return true;
        }
        return false;
    }
    int j;
    for(j=1; j<=m; j++){
        colour[i] = j;
        if(colourgraph(g, colour, m, n, j+1)){
            return true;
        }
        colour[i] = 0;
    }
    return false;
}
int main()
{
    int g[max][max] =
    {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 1, 0},
    };
    int m = 4;
    int size = 5;
    int i;
    int colour[size];
    for(i=0; i<size; i+=1){
        colour[i] = 0;
    }
    colourgraph(g, colour, m, size, 0);
    return 0;
}
