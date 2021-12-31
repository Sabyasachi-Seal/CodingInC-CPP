#include<stdio.h>
 int main()
{
 int s, i;
 int evens = 0, odds = 0;
 printf("\nEnter the size  :  ");
 scanf("%d", &s);
 int arr[s];
 printf("\nEnter Array Elements: \n");
 for(i = 0; i < s; i++){
   scanf("%d", &arr[i]);
 }
 for(i = 0; i < s; i ++){
   (arr[i] % 2 == 0)?++evens:++odds;
 }
 printf("\nEven Numbers = %d ", evens);
 printf("\nOdd Numbers  = %d ", odds);
 return 0;
}