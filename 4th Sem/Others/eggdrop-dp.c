#include <stdio.h>
#include <limits.h>
#define maxi 1000
int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
int eggdrop(int eggs[maxi][maxi], int f, int e){
    if(f==0 || f==1){
        return f;
    }
    if(e==1){
        return f;
    }
    if(eggs[e][f]!=-1){
        return eggs[e][f];
    }
    int minattempt = INT_MAX;
    int temp = minattempt;
    for(int currfloor=1; currfloor<=f; currfloor++){
        temp = 1 + max(eggdrop(eggs, f-currfloor, e), eggdrop(eggs, currfloor-1, e-1));
        minattempt = min(temp, minattempt);
    }
    eggs[e][f] = minattempt;
    return minattempt;
}
int main(){
    printf("\nEnter the number of floors: ");
    int f;
    scanf("%d", &f);
    printf("\nEnter the number of eggs: ");
    int e;
    scanf("%d", &e);
    int eggs[maxi][maxi];
    for(int i=0; i<=e; i++){
        for(int j=0; j<=f; j++){
            eggs[i][j] = -1;
        }
    }
    int ans = eggdrop(eggs, f, e);
    printf("\nMinimum Attempts: %d\n", ans);
    return 0;
}