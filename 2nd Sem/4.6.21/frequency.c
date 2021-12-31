#include <stdio.h>
 int main(){
	int arr[10], arrf[10], i, j, freq, s;
	printf("\nEnter elements of Array  :  ");
	for (i = 0; i < 10; i++){
    	scanf("%d", &arr[i]);
    	arrf[i] = 1;
   	}     
	for (i = 0; i < 10; i++){
		freq = 1;
		for(j = i + 1; j < 10; j++){
    		(arr[i] == arr[j])? freq++,arrf[j]=0 : 0;
    	}
    	arrf[i] = (arrf[i]!=0)?freq:0;
	}
 	printf("\nNumber = Frequency: \n");
 	for (i = 0; i < 10; i++){
  		if(arrf[i] != 0){
  			printf("%d = %d Times \n", arr[i], arrf[i]);
		}		
  	}	     
 	return 0;
}