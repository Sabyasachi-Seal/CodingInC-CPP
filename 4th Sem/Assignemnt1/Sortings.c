/* Implement Merge Sort, Quick Sort, and Heap Sort using Divide and Conquer
approach. */ 

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}
int partition(int arr[], int start, int end){//sub-fuction of quick sort
    int pivot = arr[end];
    int pivotindex = start;
    for(int i= start; i<= end-1/*since end is pivot itself*/; i++){
        if(arr[i]<=pivot){
            swap(&arr[i], &arr[pivotindex]);
            pivotindex++;
        }
    }
    swap(&arr[end], &arr[pivotindex]);
    return pivotindex;
}
void quicksort(int arr[], int start, int end){
    if(start<end){
        int pindex = partition(arr, start, end);
        quicksort(arr, start, pindex-1);
        quicksort(arr, pindex+1, end);
    }
}
void merge(int arr[], int low, int middle, int high, int size){
    int leftindex = low;
    int rightindex = middle+1;
    int temparrindex = low;
    int temp[size];//ignore the error
    while(leftindex<=middle && rightindex<=high){
        if(arr[leftindex] <= arr[rightindex]){
            temp[temparrindex] = arr[leftindex];
            leftindex++;
            temparrindex++;
        }
        else{
            temp[temparrindex] = arr[rightindex];
            rightindex++;
            temparrindex++;
        }
    }
    while(leftindex<=middle){
        temp[temparrindex] = arr[leftindex];
        leftindex++;
        temparrindex++;
    }
    while(rightindex<=high){
        temp[temparrindex] = arr[rightindex];
        rightindex++;
        temparrindex++;
    }
    for(int copy=low; copy<=high; copy++){
        arr[copy] = temp[copy];
    }
}
void mergesort(int arr[], int low, int high, int size){
    if(low<high){
        int middle = (high+low)/2;
        mergesort(arr, low, middle, size);
        mergesort(arr, middle+1, high, size);
        merge(arr, low, middle, high, size);
    }
}
void maxheapify(int arr[], int size, int i){
    int largest = i;
    int leftchild = 2*i +1;
    int rightchild = 2*i +2;
    if(leftchild<size && arr[leftchild]>arr[largest]){
        largest = leftchild;
    }
    if(rightchild<size && arr[rightchild]>arr[largest]){
        largest = rightchild;
    }
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        maxheapify(arr, size, largest);
    }
}
void heapsort(int arr[], int size){
    for(int i = (size/2)-1; i>=0; i--){
        maxheapify(arr, size, i);
    }
    for(int i=size-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        maxheapify(arr, i, 0);
    }
}
int main(){
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i<size; i++){
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal Array: ");
    display(arr, size);
    int choice;
    printf("\nEnter the choice of sorting: ");
    printf("\n1. Quick Sort\n2. Merge Sort\n3. Heap Sort\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            quicksort(arr, 0, size-1);
            printf("\nQuick Sorted Array: ");
            break;
        case 2:
            mergesort(arr, 0, size-1, size);
            printf("\nMerge Sorted Array: ");
            break;
        case 3:
            heapsort(arr, size);
            printf("\nHeap Sorted Array: ");
            break;
        default:
            printf("\nInvalid Choice");
    }
    display(arr, size); 
    return 0;
}