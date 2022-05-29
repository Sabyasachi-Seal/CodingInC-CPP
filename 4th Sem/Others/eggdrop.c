#include <stdio.h>
#include <limits.h>
int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
int eggdrop(int f, int e){
    if(f==0 || f==1){
        return f;
    }
    if(e==1){
        return f;
    }
    int currfloor;
    int minattempt = INT_MAX;
    int temp = minattempt;
    for(currfloor=1; currfloor<=f; currfloor++){
        temp = 1 + max(eggdrop(f-currfloor, e), eggdrop(currfloor-1, e-1));
        minattempt = min(temp, minattempt);
    }
    return minattempt;
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