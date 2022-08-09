#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {2, 3, -1, 5, 6, 2, -1001, 6, 5, 3, 4, -9, 6, -5, 2, 10, 59, 9, -10, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = 0;
    int currsum = 0;
    int start;
    int end;
    int i;
    for(i=0; i<n; i++){
        if(currsum < 0){
            currsum = 0;
            start = i;
        }
        else{
            currsum += arr[i];
        }
        if(currsum > max){
            max = currsum;
            end = i;
        }
    }
    printf("\nMax Subarray is: ");
    for(i=start; i<=end; i++){
        printf("%d ", arr[i]);
    }
    printf("\nMax Value = %d", max);
    return 0;
}
