#include <stdio.h>
#include <stdlib.h>
void ratiosort(float ratio[], int indexes[], int ratiosize){
    int i, j;
    for(i=0; i<ratiosize; i++){
        for(j=0; j<ratiosize-1; j++){
            if(ratio[j] < ratio[j+1]){
                ratio[j] = ratio[j] + ratio[j+1];
                ratio[j+1] = ratio[j] - ratio[j+1];
                ratio[j] = ratio[j] - ratio[j+1];
                indexes[j] = indexes[j] + indexes[j+1];
                indexes[j+1] = indexes[j] - indexes[j+1];
                indexes[j] = indexes[j] - indexes[j+1];
            }
        }
    }
}
float fractional(int weight[], int profit[], int ratiosize, int cap){
    float ratio[ratiosize];
    int indexes[ratiosize];
    int i;
    float max =0.0;
    for(i=0; i<ratiosize; i++){
        ratio[i] = (float)profit[i]/weight[i];
        indexes[i] = i;
    }
    ratiosort(ratio, indexes, ratiosize);
    for(i=0; i<ratiosize; i++){
        if(cap>0){
            if(cap >= weight[indexes[i]]){
                cap -= weight[indexes[i]];
                max += profit[indexes[i]];
                printf("\nIncluded Object %d\n", indexes[i]+1);
            }
            else{
                float frac = (float)cap/weight[indexes[i]];
                cap -= weight[indexes[i]];
                max += frac*profit[indexes[i]];
                printf("\nIncluded %.2f%% of Object %d\n",frac*100, indexes[i]+1);
            }
        }
        else{
            break;
        }
    }
    return max;
}
int main(){
    FILE *fp = fopen("knapsackinput.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    int weight[n];
    int profit[n];
    int i;
    for(i=0; i<n; i++){
        fscanf(fp, "%d", &weight[i]);
    }
    for(i=0; i<n; i++){
        fscanf(fp, "%d", &profit[i]);
    }
    int cap;
    fscanf(fp, "%d", &cap);
    float max =fractional(weight, profit, n, cap);
    printf("\nMax Profit: %.2f\n", max);
    return 0;
}