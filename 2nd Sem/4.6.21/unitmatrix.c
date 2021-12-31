#include<stdio.h>
int main(){
 	int i, j, rows, columns, unit = 1;
 	printf("Enter rows and columns :  ");
 	scanf("%d %d", &i, &j);
	int a[i][j];
 	printf("Enter the Matrix:\n");
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0; columns < j; columns++){
      		scanf("%d", &a[rows][columns]);
    	}
  	} 
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0; columns < j; columns++){
    		if(a[rows][columns] != 1 && a[columns][rows] != 0){
    			unit = 0;
    			break;
			}
   	 	}
  	}
  	(unit == 1)?printf("Unit Matrix "):printf("Not an Unit Matrix ");
 	return 0;
}