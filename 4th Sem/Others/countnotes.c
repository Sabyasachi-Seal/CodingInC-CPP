#include <stdio.h>
#define max 20
// https://www.geeksforgeeks.org/find-number-currency-notes-sum-upto-given-amount/
int knapsack(int notes[max], int target, int n){
    int mincash = 0;
    int i;
    for(i = n-1; i>=0;){
        if(notes[i] <= target && target>0){
            mincash++;
            target = target - notes[i];
            printf("\n%d", notes[i]);
        }
        else{
            i--;
        }
    }
    return mincash;
}
int main(){
    int notes[] = {1,2,5,10,50,100,500};
    int n = sizeof(notes)/sizeof(notes[0]);
    int target = 500;
    printf("\n%d\n", knapsack(notes, target, n));
}