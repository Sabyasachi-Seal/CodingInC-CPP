#include <stdio.h>
 int main(){
	int i, j, k, s;
	printf("\nEnter Size:   ");
	scanf("%d", &s);
	int numbers[s];
	printf("\nEnter number: \n", s);
	for (i = 0; i < s; i++){
    	scanf("%d", &numbers[i]);
   	}     
    for (i = 0; i < s; i++){
		for(j = i+1; j < s; j++){
    		if(numbers[i] == numbers[j]){
    			for(k = j; k<s; k++){
    				numbers[k] = numbers[k + 1];
				}
				s = s - 1;
				j = j - 1;
	}}}
 	printf("\nFinal Array is:\n");
 	for (i = 0; i < s; i++){
 		printf("%d\n", numbers[i]);
  	}	     
 	return 0;
}