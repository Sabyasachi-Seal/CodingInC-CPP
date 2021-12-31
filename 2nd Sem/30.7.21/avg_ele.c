#include <stdio.h>
void sumofelements(int*, int[], int);
void main(){
    int i, sum = 0, num=0;
    printf("Enter limit of array: ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers of array:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    sumofelements(&sum, arr, num);
    printf("Average = %f", (float)sum/num);
}
void sumofelements(int *sum, int arr[], int num){
    int *point;
    point = arr;
    for (int i = 0; i < num; i++){
        *sum = *sum + *point;
        point++;
    }
}