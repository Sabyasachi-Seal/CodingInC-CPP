#include <stdio.h>
void prime(int, int);
int main(){
    int a = 1, b = 100;
    prime(a, b);
    return 0;
}
void prime(int a, int b){
    int i, j, fact = 0;
    for (i = a; i <= b; i++){
        fact = 0;
        for (j = 1; j <= b; j++){
            if (i % j == 0)
                fact++;
        }
        if (fact == 2){
            printf("%d\n", i);}
    }
}