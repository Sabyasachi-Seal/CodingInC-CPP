#include <stdio.h>
// kaydens algorithm
int main(){
    int arr[] = {4, 3, -1 , 105, 45, -100, 23, 64, -1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i;
    int sum = arr[0];
    int max = sum;
    int start = 0, end=0;
    for(i=1; i<size; i++){
        if(sum<0){
            start = i;
            sum = 0;
        }
        else{
           sum += arr[i];
        }
        if(sum>max){
            end = i;
            max = sum;
        }
    }
    for(i=start; i<=end; i++){
        printf("%d ", arr[i]);
    }
    printf("\n%d\n", max);
}