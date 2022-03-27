#include <stdio.h>
struct minmax{
    int min;
    int max;
};
int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
struct minmax min_max(int arr[], int high, int low){
    struct minmax values;
    if(high == low){
        values.max = arr[0];
        values.min = arr[0];
    }
    else if(high == low+1){
        values.min = min(arr[high], arr[low]);
        values.max = max(arr[high], arr[low]);
    }
    else{
        int mid = (high + low)/2;
        struct minmax mmr = min_max(arr, mid, low);
        struct minmax mml = min_max(arr, high, mid+1);

        values.max = max(mmr.max, mml.max);
        values.min = min(mmr.min, mml.min);
    }
    return values;
}
void main(){
    int arr[] = {4, 3, 1, 66, 23, 11, 1, 0, 5, 43};
    int n = sizeof(arr)/ sizeof(arr[0]);
    struct minmax values = min_max(arr, n, 0);
    printf("MAX = %d \n MIN = %d", values.max, values.min);
}