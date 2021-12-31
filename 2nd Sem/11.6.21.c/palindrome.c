#include <stdio.h>
#include <string.h>
int palindrome(char *s){
    int i,c=0,n;
    n=strlen(s);
	for(i=0;i<n/2;i++){
    	if(s[i]==s[n-i-1])
    	c++;
 	}
 	return (c==i)?1:0;
 }
int main()
{   char s[100];
    printf("Enter string: ");
    gets(s);
    (palindrome(s))?printf("palindrome"):printf("not palindrome");
    return 0;
}