#include <stdio.h>
int main(){
    int s=0;
    printf("enter size: ");
    scanf("%d", &s);
    int arr[s], sum=0, i;
    for(i=0; i<=s-1; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<=s-1; i++){
        sum+=arr[i];
    }
    printf("\nsum = %d", sum);
    return 0;
}