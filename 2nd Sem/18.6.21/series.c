#include <stdio.h>
int main(){
   int n;
   float sum = 0.0, i = 1;
   printf("Enter no of terms: ");
   scanf("%d", &n);
   for(i = 1; i<=n; i++){
      int fac =1;
      for(int j = 1; j<=i;j++){
         fac *= j;
      }
      sum += (i/fac);
   } printf("Sum = %f", sum);
   return 0;
}