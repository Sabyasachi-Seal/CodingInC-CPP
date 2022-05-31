#include <stdio.h>
#include <stdlib.h>
#define bitsize 4
int numtobinary(int n){// decimal to binary
    int i;
    int index = 0;
    int binary[bitsize];
    for(i=0; i<bitsize; i++){
        binary[i] = 0;
    }
    while(n>0){
        binary[bitsize-index-1] = n%2;
        n /= 2;
        index++;
    }
    int number = 0;
    for(i=0; i<bitsize; i++){
        number = number*10 + binary[i];
    }
    return number;
}
int ispalindrome(int n){// checks palindrome
    int reverse = 0;
    int temp=n, rem;
    while(temp>0){
        rem = temp%10;
        reverse = (reverse*10) + rem;
        temp /= 10;
    }
    if(reverse == n){
        return 1;
    }
    return 0;
}
int minsteps(int n){// checks the min steps to change
    int binary;
    int increase;
    int decrease;
    for(increase=0; increase<=n; increase++){
        binary = numtobinary(n+increase);
        if(ispalindrome(binary)){
            break;
        }
    }
    for(decrease=0; decrease<=n; decrease++){
        binary = numtobinary(n-decrease);
        if(ispalindrome(binary)){
            break;
        }
    }
    return (increase<decrease)?increase:decrease;
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int ans = minsteps(n);
    printf("\nMin Steps for Palindrome in Binary = %d", ans);
    return 0;
}