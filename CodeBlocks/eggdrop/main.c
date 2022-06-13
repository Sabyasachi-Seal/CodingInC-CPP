#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define maximum 99
int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
int eggdrop(int eggs[maximum][maximum], int egg, int floor){
    if(floor==0 || floor == 1) return floor;
    if(egg==1) return floor;
    if(eggs[egg][floor] != -1) return eggs[egg][floor];
    int minattempt = INT_MAX;
    int temp = INT_MAX;
    int curr;
    for(curr=1; curr<=floor; curr++){
        temp = 1 + max(eggdrop(eggs, egg, floor-curr), eggdrop(eggs, egg-1, curr-1));
        minattempt = min(minattempt, temp);
    }
    eggs[egg][floor] = minattempt;
    return minattempt;
}
int main()
{
    printf("Enter the number of floors: ");
    int f;
    scanf("%d", &f);
    printf("Enter the number of eggs: ");
    int e;
    scanf("%d", &e);
    int i, j;
    int eggs[maximum][maximum];
    for(i=0; i<=e; i++){
        for(j=0; j<=f; j++){
            eggs[i][j] = -1;
        }
    }
    printf("%d", eggdrop(eggs, e, f));
    return 0;
}
