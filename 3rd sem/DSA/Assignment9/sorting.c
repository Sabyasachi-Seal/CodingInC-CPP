#include<stdio.h>
#include<stdlib.h>
void bubble(int[], int);
void selection(int[], int);
void insertion(int[], int);
void quick(int[],int, int);
void mergesort(int[], int, int);
void heap(int[], int);
void display(int[], int);

int main()
{
    int n = 20,choice,i,element;
    int original[20],modified[20];
    printf("\nEnter the total number of elements: ");
    scanf("%d",&n);
    for(i = 0;i < n; i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&element);
        original[i] = modified[i] = element;
    }
    while(1)
    {
        printf("\n1-Bubble sort");
        printf("\n2-Selection sort");
        printf("\n3-Insertion sort");
        printf("\n4-Quick sort");
        printf("\n5-Merge sort");
        printf("\n6-Heap sort");
        printf("\n7-Show original arr");
        printf("\n0-Exit from program");
        printf("\n Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: 
                printf("\n Bubble sort:");
                bubble(modified,n);
                display(modified,n);
                break;
            case 2: 
                printf("\n Selection sort:");
                selection
            (modified,n);
                display(modified,n);
                break;
            case 3: 
                printf("\n Insertion sort:");
                insertion(modified,n);
                display(modified,n);
                break;
            case 4: 
                printf("\n Quick sort:");
                quick(modified,0,n-1);
                display(modified,n);
                break;
            case 5: 
                printf("\n Merge sort:");
                mergesort(modified,0,n-1);
                display(modified,n);
                break;
            case 6: 
                printf("\n Heap sort:");
                heap(modified,n);
                display(modified,n);
                break;
            case 7:
                printf("Original arr: ");
                display(original,n);
                break;
            case 0:
                exit(0);
            default:
                break;
        }
        for(i = 0;i < n; i++)
        { modified[i] = original[i]; }
    }
}
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int arr[], int n) 
{
    int i,temp;
    for(i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {  
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j],&arr[j+1]);
        }
    }
}
void selection(int arr[], int n) 
{
    int i,j,pos;
    for (i = 0; i < n - 1; i++) 
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {  
            if (arr[j] < arr[pos])
                pos = j;
        }
        swap(&arr[pos], &arr[i]);
    }
}
void insertion(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0) 
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    
    int i = (low - 1);

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quick(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quick(arr, low, pi - 1);    
        quick(arr, pi + 1, high);
    }
}
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}
void heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify(arr, i, 0);
    }
}
void display(int arr[], int n) 
{
    int i;
    for (i = 0; i < n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}