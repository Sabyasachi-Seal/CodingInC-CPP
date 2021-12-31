#include <stdio.h>
void sort(int[], int,  int);
void join(int[], int, int, int);
int main(){
	int num;
    printf("Enter limit:- ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers:- \n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
	sort(arr, 0, num);
	printf("Sorted array: \n");
	for (int i=0; i<num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
void sort(int a[], int low, int high){
	int mid;
	if(low<high){
		mid=(low + high) / 2;
		sort(a,low,mid);
		sort(a,mid+1,high);
		join(a, low,mid,high);
	}
}
void join(int arr[], int l, int m, int h){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0, j =0, k = l;
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}