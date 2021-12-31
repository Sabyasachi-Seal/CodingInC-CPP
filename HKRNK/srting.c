//Given a string, , consisting of alphabets and digits, 
//find the frequency of each digit in the given string.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char *s = (char *) malloc(1024*sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s , strlen(s) + 1);
    int *arr = (int *) calloc(9, sizeof(int));
    for(int i=0; i<strlen(s); i++){
        ((int)s[i]>=48 && (int)s[i]<=57)?arr[(int)s[i]-48]++:0;
    }
    for(int i=0; i<=9; i++){
        printf("%d ", arr[i]);
    }
    free(arr), free(s);
}