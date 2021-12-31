#include <stdio.h>
#include <string.h>
#define MAX 100
int top=-1;
int item;
void push(char item,char* stack){
    top=top+1;
    stack[top]=item;
}
 char pop(char* stack){
    item = stack[top];
    top=top-1;
    return item;
}
int main(){
    char str[MAX];
    char stack[MAX];
    int i;
    printf("Input Number: ");
    scanf("%[^\n]s",str);
    for(i=0;i<strlen(str);i++){
        push(str[i],stack);
    }
    for(i=0;i<strlen(str);i++){
        str[i]=pop(stack);
    }
    printf("Reversed Number: %s\n",str);
    return 0;
}