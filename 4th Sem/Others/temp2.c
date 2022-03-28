#include <stdio.h>
#define max 999
int mcm(int arr[], int size){
    int q[size][size];
    int i, j, k, i1, i2;
    for(i=1; i<size; i++){
        q[i][i] = 0;
    }
    int temp, min;
    for(i1=1; i1<size-1; i1++){
        for(i2=1; i2<size-i1; i2++){
            j = i1+i2;
            min = max;
            for(k=i2; k<j; k++){
                temp = q[i][k] + q[k+1][j] + (arr[i2-1] * arr[j] * arr[k]);
                if(temp<min){
                    min = temp;
                }
            }
            q[i2][j] = min;
        }
    }
    return q[1][size-1];
}
int main(){
    int arr[] = { 5 ,10, 3, 12, 5, 50, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d", mcm(arr, size));
    return 0;
}