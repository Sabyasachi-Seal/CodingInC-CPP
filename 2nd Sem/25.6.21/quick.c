#include<stdio.h>
void swap(int* , int*);
int partition_maker(int[], int, int);
void sort(int [], int, int);
int main() { 
	int num;
    printf("Enter limit:- ");
    scanf("%d", &num);
    int array[num];
    printf("Enter numbers:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &array[i]);
    }
	sort(array, 0, num);
	printf("Sorted array: \n");
	for (int i=0; i<num; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0; 
} 
void swap(int* num1, int* num2){ 
	int temp = *num1; 
	*num1 = *num2; 
	*num2 = temp; 
}
int partition_maker(int arr[], int l, int h){ 
	int p = arr[h];
	int i = (l - 1);
	for (int j = l; j <= h- 1; j++){
		if (arr[j] < p){ 
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]); 
	return (i + 1);   
}
void sort(int arr[], int l, int h){ 
	if (l < h){ 
		int pivot = partition_maker(arr, l, h); 
		sort(arr, l, pivot - 1); 
		sort(arr, pivot + 1, h); 
	} 
}
