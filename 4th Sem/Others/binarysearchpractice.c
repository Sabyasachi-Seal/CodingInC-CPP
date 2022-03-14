#include <stdio.h>

int binary(int arr[], int start, int end, int x){
    int mid = (start+end)/2;
    if(start>end){
        return -1;
    }
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]<x){
        return binary(arr, mid+1, end, x);
    }
    else if(arr[mid]>x){
        return binary(arr, start, mid-1, x);
    }
}

int main(){
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    int search = 34;
    int index = binary(arr, 0, size, search);
    printf("\nIndex = %d\n", index);
}

