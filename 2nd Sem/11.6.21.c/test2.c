#include <stdio.h>
int search(int arr[], int, int);
int main(){
    int num, sr;
    printf("Enter limit:- ");
    scanf("%d", &num);
    int arr[num], index[num];
    printf("Enter numbers:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter search element:- ");
    scanf("%d", &sr);
    index[num] = search(arr, num, sr);
    for(int i = 0; i<=num; i++){
    printf("%d", index[i]);}
    return 0;
}
int search(int arr[], int num, int sr){
    int ind=0, lst[num];
    for(int j=0; j<num;j++){
        if(arr[j]==sr){
            lst[ind]=j;
            ind++;
        }
    return lst;
    }
}
