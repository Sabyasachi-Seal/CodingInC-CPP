#include<stdio.h>
int main()
{
    int x = 0,y = 0;
    int ss = 0;
    printf("Enter Side Length= ");
    scanf("%u",&ss);
    for(x = 0; x < ss; ++x){
        for(y = 0; y<ss; ++y){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}