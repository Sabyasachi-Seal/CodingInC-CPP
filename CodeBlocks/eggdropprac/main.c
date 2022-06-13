#include <stdio.h>
#include <stdlib.h>
#define inf 99999
#define maxi 99
int max(int a, int b){
    return a>b?a:b;
}
int min(int a, int b){
    return a<b?a:b;
}
int eggdrop(int eggs[maxi][maxi], int e, int f){
    if(f==1 || f==0){
        return f;
    }
    if(e == 1){
        return f;
    }
    if(eggs[e][f]!=-1){
        return eggs[e][f];
    }
    int minatt = inf;
    int temp = inf;
    int curf = 0;
    for(curf=1; curf<=f; curf++){
        temp = 1 + max(eggdrop(eggs, e-1, curf-1), eggdrop(eggs, e, f-curf));
        minatt = min(minatt, temp);
    }
    eggs[e][f] = minatt;
    return minatt;
}
int main()
{
    printf("\nEnter the number of floors: ");
    int f;
    scanf("%d", &f);
    printf("Enter the number of eggs: ");
    int e;
    scanf("%d", &e);
    int eggs[maxi][maxi];
    int i, j;
    for(i=0; i<=e; i++){
        for(j=0; j<=f; j++){
            eggs[i][j] = -1;
        }
    }
    printf("\nMinimum Attempts: %d", eggdrop(eggs, e, f));
    return 0;
}
