#include <stdio.h>
void search(int arr[], int, int);
int main(){
    int num, sr;
    printf("Enter limit:- ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter search element:- ");
    scanf("%d", &sr);
    search(arr, num, sr);
    return 0;
}
void search(int arr[], int num, int sr){
    int ind=0;
    for(int j=0; j<num;j++){
        if(arr[j]==sr){
            printf("Present at postion = %d\n", (j+1));
        }
    }
}
