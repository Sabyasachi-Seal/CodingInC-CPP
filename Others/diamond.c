#include <stdio.h>
int main(){
    int n,i,j,lim,t;
    printf("Enter the rows: ");
    scanf("%d", &n);
    lim=2*n-1;
    for(i=0;i<=lim;i+=2){
        for(j=(n-i+((n>4)?(n-3):0));j>=0;j-=2){
            printf(" ");}
        for(t=0;t<=i;t++){
            printf("*");}
        printf("\n");}
    for(i=lim-2;i>=0;i-=2){
        for(j=0;j<=(n-i+((n>4)?(n-3):0));j+=2){
            printf(" ");}
        for(t=0;t<=i-1;t++){
            printf("*");}
        printf("\n");}
    return 0;}