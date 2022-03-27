#include <stdio.h>
void swap(int *a, int *b){
    int temp= *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int size, int i){
    int largest = i;
    int lc = 2*i +1;
    int rc = 2*i +2;
    while(lc<size && arr[largest]<arr[lc]){
        largest = lc;
    }
    while(rc<size && arr[largest]<arr[rc]){
        largest = rc;
    }
    if(largest!=i){
        swap(&arr[largest], &arr[i]);
        heapify(arr, size, largest);
    }
}
void heapsort(int arr[], int size){
    for(int i = (size/2)-1; i>=0; i--){
        heapify(arr, size, i);
    }
    for(int i=size-1; i>=0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}
int main(){
    int arr[] = {3, 5, 2, 1, 6, 8, 4, 10, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr, size-1);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}