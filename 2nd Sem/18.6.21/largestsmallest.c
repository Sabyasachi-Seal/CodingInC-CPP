#include <stdio.h>
int largest(int arr[], int);
int smallest(int arr[], int);
int main(){
    int num;
    printf("Enter limit:- ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    printf("Smallest = %d\n", smallest(arr, num));
    printf("Largest = %d", largest(arr, num));
    return 0;
}
int largest(int arr[], int num){
    int lar=arr[0];
    for(int j=0; j<num;j++ ){
        lar = (arr[j]>=lar)?arr[j]:lar;
    }
    return lar;
}
int smallest(int arr[], int num){
    int sml=arr[0];
    for(int j=0; j<num;j++ ){
        sml= (arr[j]<=sml)?arr[j]:sml;
    }
    return sml;
}