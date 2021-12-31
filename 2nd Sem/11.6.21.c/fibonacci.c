#include<stdio.h>
void fibonacci(int);
int main(){
   int n;
   printf("\nEnter limit:\n",n);
   scanf("%d",&n);
   fibonacci(n);
}
void fibonacci(int n){
   int i,c=0, a=0, b=1;
   for(i=0;i<n;i++){
       printf("%d\n",c);
       a=b;
       b=c;
       c=a+b;
       if(c>n){
           break;
       }
   }
   return 0;
}