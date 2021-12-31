#include <stdio.h>
int main() {
    int num1, num2, i, smaller, gdc=0;
    printf("Enter integers: ");
    scanf("%d%d", &num1, &num2);
    smaller = (num1>num1)? num2:num1;
    for (i=1; i<=smaller; i++){
      if(num1%i==0 && num2%i==0){
        gdc=i;
     }
    }
    printf("GDC = %d", gdc);
    return 0;
}