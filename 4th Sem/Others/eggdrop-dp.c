#include <stdio.h>
#include <limits.h>
int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
int eggdrop(int f, int e){
    int eggs[e+1][f+1];
    // if(f==0 || f==1){
    //     return f;
    // }
    for(int i=1; i<=e; i++){
        eggs[i][0] = 1;
        eggs[i][1] = 0;
    }
    // if(e==1){
    //     return f;
    // }
    for(int i=1; i<=f; i++){
        eggs[1][i] = i;
    }
    int temp = 0;
    // for(currfloor=1; currfloor<=f; currfloor++){
    //     temp = 1 + max(eggdrop(f-currfloor, e), eggdrop(currfloor-1, e-1));
    //     minattempt = min(temp, minattempt);
    // }
    for(int i=2; i<=e; i++){
        for(int j=2; j<=f; j++){
            eggs[i][j] = INT_MAX;
            for(int k=1; k<=j; k++){
                temp = 1 + max(eggs[i-1][k-1], eggs[i][j-k]);
                eggs[i][j] = min(temp, eggs[i][j]);
            }
        }
    }
    return eggs[e][f];
}
int main(){
    printf("\nEnter the number of floors: ");
    int f;
    scanf("%d", &f);
    printf("\nEnter the number of eggs: ");
    int e;
    scanf("%d", &e);
    int ans = eggdrop(f, e);
    printf("\nMinimum Attempts: %d\n", ans);
    return 0;
}