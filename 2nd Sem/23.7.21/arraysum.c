#include <stdio.h>
void summer(int*, int[], int);
void main(){
    int i, sum = 0, num;
    printf("Enter limit:- ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    summer(&sum, arr, num);
    printf("Sum = %d", sum);
}
void summer(int *sum, int arr[], int num){
    int *point;
    point = arr;
    for (int i = 0; i < num; i++){
        *sum = *sum + *point;
        point++;
    }
}