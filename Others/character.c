#include <stdio.h>
int main(){
    char input;
    printf("Enter digit/letter/special: ");
    scanf("%c", &input);
    if((input>='a'&&input<='z')||(input>='A'&&input<='Z')){
        printf("alphabet");
    }
    else if(input>='0'&&input<= '9'){
        printf("digit");
    }
    else {
        printf("special character");
    }
    return 0;
}