#include <stdio.h>
int main()
{
    int arr[30] = {0};
    int i = 0, n = 0;
    printf("Enter the numbers of digits: ");
    scanf("%d", &n);
    printf("\nEnter each digit \n");
    for (i = 0; i < n; i++){
       scanf("%d", &arr[i]);
    }
    int temp;
    temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n-i-1] = temp;
    printf("\nThe array after swap is..\n");
    printf("\nFirst is %d and last: %d", arr[i], arr[n]);
    return 0;
}