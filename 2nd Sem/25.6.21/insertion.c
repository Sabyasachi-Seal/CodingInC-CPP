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
    int i, key, j;
    for (i = 1; i < num; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}