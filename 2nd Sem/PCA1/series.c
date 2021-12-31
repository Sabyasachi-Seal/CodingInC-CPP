#include<stdio.h>
int main(){
   int n;
   float sum = 0.0;
   printf("Enter no of terms: ");
   scanf("%d",&n);
   for(int i = 1; i<=n; i++){
      int fac =1;
      for(int j=0; j<=i;j++){
         fac *= j;
      }
      sum += i/fac;
   }
   printf("Sum of series = %f", sum);
   return 0;
}