#include <stdio.h>
void swap(int *a, int *b){
    int temp= *a;
    *a = *b;
    *b = temp;
}
void merge(int arr[], int start, int middle, int end, int size){
    int left = start;
    int right = middle+1;
    int ti = start;
    int t[size];
    while(left<=middle && right<=end){
        if(arr[left]>=arr[right]){
            t[ti] = arr[left];
            left++;
        }
        else{
            t[ti] = arr[right];
            right++;
        }
        ti++;
    }
    while(left<=middle){
        t[ti] = arr[left];
        left++;
        ti++;
    }
    while(right<=end){
        t[ti] = arr[right];
        right++;
        ti++;
    }
    for(int i = start; i<=end; i++){
        arr[i] = t[i];
    }
}
void mergesort(int arr[], int start, int end, int size){
    if(start<end){
        int mid = (start+end)/2;
        mergesort(arr, start, mid, size);
        mergesort(arr, mid+1, end, size);
        merge(arr, start, mid, end, size);
    }
}
int main(){
    int arr[] = {3, 5, 2, 1, 6, 8, 4, 10, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, size-1, size);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}