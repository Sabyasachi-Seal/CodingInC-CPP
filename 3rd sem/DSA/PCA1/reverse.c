#include <stdio.h>
#include <string.h>
#define MAX 15
int top=-1;
int data;
void push(char, char*);
char pop(char*);

// main function takes input and passed the number to the push and pop function
int main(){
    char string [MAX];
    char stack [MAX];
    int i;
    printf("Input Number: ");
    scanf("%[^\n]s",string );
    for(i=0;i<strlen(string );i++){
        push(string [i],stack);
    }
    for(i=0;i<strlen(string );i++){
        string [i]=pop(stack);
    }
    printf("Reversed Number: %s\n",string );
    return 0;
}
// used to push each element into the stack
void push(char data,char* stack){
    top=top+1;
    stack[top] = data;
}
// used to pop the element one by one from the stack
char pop(char* stack){
    data = stack[top];
    top = top-1;
    return data;
}
