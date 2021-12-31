#include <stdio.h>  
int main(){    
    int num,c=0;    
    printf("enter number= ");    
    scanf("%d",&num);        
    while(num>0){   
        c++;    
        num/=10;
    }
    printf("no of digits = %d", c);    
    return 0;  
}