#include <stdio.h>
#include <stdlib.h>
struct pair{
    int min;
    int max;
};
struct pair maxmin(int arr[], int start, int end){
    struct pair ans;
    if(start ==  end){
        ans.max = arr[start];
        ans.min = arr[start];
    }
    else if(start == end + 1){
        if(arr[start] > arr[end]){
            ans.max = arr[start];
            ans.min = arr[end];
        }
        else{
            ans.min = arr[start];
            ans.max = arr[end];
        }
    }
    else{
        struct pair mml, mmr;
        int mid = (start+end)/2;
        mml = maxmin(arr, start, mid);
        mmr = maxmin(arr, mid+1, end);
        ans.max = (mml.max > mmr.max)?mml.max:mmr.max;
        ans.min = (mml.min < mmr.min)?mml.min:mmr.min;
    }
    return ans;

}
int main()
{
    printf("Enter the number of elements of the array: ");
    int n;
    scanf("%d", &n);
    int i;
    int arr[n];
    for(i=0; i<n; i++){
        printf("\n Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    struct pair ans = maxmin(arr, 0, n-1);
    printf("\nMax = %d \nMin = %d", ans.max, ans.min);
    getchar();
}
