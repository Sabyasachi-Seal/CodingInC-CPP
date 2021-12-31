#include <stdio.h>
int main(){
    int i, sum = 0, num;
    printf("Enter limit of array: ");
    scanf("%d", &num);
    int arr[num][num];
    printf("Enter numbers of array:- \n");
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int *ptr;
    ptr = arr;
    for (int i = 0; i < num; i++){
        for(int j=0; j<num; j++){
            sum = sum + *ptr;
            ptr++;
        }
    }
    printf("Sum = ", sum);
    return 0;
}