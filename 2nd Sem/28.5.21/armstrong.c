#include <stdio.h>  
int main() {    
    int num,rem,sum=0,t;    
    printf("enter number= ");    
    scanf("%d",&num);    
    t=num;    
    while(num>0){    
        rem=num%10;    
        sum=sum+(rem*rem*rem);    
        num/=10;
    }    
    (t==sum)? printf("armstrong"):printf("not armstrong");    
    return 0;  
}