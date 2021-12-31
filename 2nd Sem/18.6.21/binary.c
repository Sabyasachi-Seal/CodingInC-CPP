#include <stdio.h>
int search(int *, int, int);
int main(){
    int sr, limit;
    printf("Enter limit:- ");
    scanf("%d", &limit);
    int numbers[limit];
    printf("Enter numbers:- \n");
    for(int i=0; i<limit; i++){
        scanf("%d", &numbers[i]);
    }
    printf("Enter search element:- ");
    scanf("%d", &sr);
    int ind = search(numbers, limit, sr);
    if(ind == -1){
        printf("Element not present in array.\n");
    }
    else{
        printf("Present at Position = %d\n", ind);
    }
    return 0;
}
int search(int arr[], int limit, int sr){
  int low = 0, high = limit, mid = 0;
  while(low < high) {
    mid = (low+high)/2;
    if(sr > arr[mid]){
        low = mid+1;
    }
    else if(sr < arr[mid]){
        high = mid;
    }
    else if(sr == arr[mid]){
        low = mid;
        break;
    }
  }
  return (sr == arr[low])? (low+1) : -1;
}