/*  I) Implement Binary Search using the Divide and Conquer
approach. */

#include <stdio.h>
int Search(int[], int, int, int);
int main(){
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i<size; i++){
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched: ");
    int element;
    scanf("%d", &element);
   int index = Search(arr, 0, size-1, element);
   if(index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Present at index : %d",index);
   }
   return 0;
}
int Search(int arr[], int start, int end, int element){
   if (end >= start){
      int middle = start + (end - start )/2;
      if (arr[middle] == element)
         return middle;
      if (arr[middle] > element)
         return Search(arr, start, middle-1, element);
      return Search(arr, middle+1, end, element);
   }
   return -1;
}