#include <stdio.h>
void pr(char *, char *);
int main(){
    char initial[100];
    char final[100];
    printf("Enter any string: ");
    gets(initial);
    pr(initial, final);
    printf("Initial= %s\n", initial);
    printf("Final= %s\n", final);
}
void pr(char *initial,char *final){
    int i;
    for(i=0; initial[i]!='\0'; i++){
        final[i] = initial[i];
    }
    final[i] = '\0';
}