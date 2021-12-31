#include <stdio.h>
int main(){
    int n,i,j,lim,t;
    printf("Enter the rows: ");
    scanf("%d", &n);
    lim=2*n-1;
    for(i=lim;i>=0;i-=2){
        for(j=0;j<=lim-i;j+=2){
            printf(" ");}
        for(t=0;t<=i-1;t++){
            printf("*");}
        printf("\n");}
    for(i=0;i<=lim;i+=2){
        for(j=lim-i;j>=0;j-=2){
            printf(" ");}
        for(t=0;t<=i;t++){
            printf("*");}
        printf("\n");}
    return 0;}