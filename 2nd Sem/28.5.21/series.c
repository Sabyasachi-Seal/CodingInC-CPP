#include<stdio.h>
int main(){
   int n, sum=0;
   printf("Enter n value: ");
   scanf("%d",&n);
   for(int i=1; i<=n; i++){
     sum += i*i;
   }
   printf("Sum= %d",sum);
   return 0;
}