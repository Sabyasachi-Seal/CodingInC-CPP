#include <stdio.h>
void sort(int[], int);
int main(){
	int num;
    printf("Enter limit:- ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
	sort(arr, num);
	printf("Sorted array: \n");
	for (int i=0; i<num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
void sort(int arr[], int num){
for (int i = 0; i < num-1; i++){
	for (int j = 0; j < num-i-1; j++)
		if (arr[j] > arr[j+1]){
			int temp = arr[j];
	        arr[j] = arr[j+1];
	        arr[j+1] = temp;
        }
	}
}