#include <stdio.h>
void fibonacci(int, int, int, int);
int main(){
    int num, n1=0, n2=1, c=0;
    printf("Enter the terms: ");
    scanf("%d", &num);
    fibonacci(num, n1, n2, c);
}
void fibonacci(int num, int n1, int n2, int c){
    c++;
    if(num>c){
        if(n1<1){
            printf("%d\n%d\n", n1, n2);
        }
        else{
            printf("%d\n", n2);
        }
    return fibonacci(num, n2, (n1+n2), c);
    }
}