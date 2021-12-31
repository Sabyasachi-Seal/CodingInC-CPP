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
		int min_ind = i;
		for (int j = i+1; j <num; j++){
		    if (arr[j] < arr[min_ind]){
			    min_ind = j;
            }
        }
		int temp = arr[min_ind];
	    arr[min_ind] = arr[i];
	    arr[i] = temp;
	}
}