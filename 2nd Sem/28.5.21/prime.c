#include <stdio.h>
int main() {
  int num, i, prime = 0;
  printf("Enter integer: ");
  scanf("%d", &num);
  for (i=2; i<=num-1; i++){
    if(num % i == 0){
      prime = 1;
      break;
    }
  }
    (prime==0)?printf("prime number"):printf("not a prime number");
    return 0;
}