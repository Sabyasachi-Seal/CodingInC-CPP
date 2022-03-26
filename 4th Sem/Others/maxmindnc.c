#include <stdio.h>
struct minmax{
    int max;
    int min;
};
int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
struct minmax maxmincalc(int arr[], int low, int high){
    struct minmax values;
    if(high==low){//single element
        values.min = arr[low];
        values.max = arr[low];
    }
    else if(high==low+1){// 2 elemment
        values.max = max(arr[low], arr[high]);
        values.min = min(arr[low], arr[high]);
    }
    else{//more than 2 element
        int mid = (high+low)/2;
        struct minmax leftsubarray = maxmincalc(arr, low, mid);
        struct minmax rightsubarray = maxmincalc(arr, mid+1, high);
        values.min = min(leftsubarray.min, rightsubarray.min);
        values.max = max(leftsubarray.max, rightsubarray.max);
    }
    return values;
}

int main(){
    struct minmax values;
    printf("Enter the value of n:");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    values = maxmincalc(arr, 0, n-1);
    printf("Minimum: %d\nMaximum: %d\n", values.min, values.max);
}
