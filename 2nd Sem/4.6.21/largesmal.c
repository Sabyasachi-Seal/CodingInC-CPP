#include <stdio.h>
int main(){
    int i, n, largest, smallest, size;
    printf ("Enter size:");
    scanf ("%d", &size);
    printf ("Enter numbers:");
    scanf ("%d", &n);
    largest=n;
    smallest=n;
    for (i=1; i<= size-1 ; i++){
        scanf ("%d",&n);
        largest=(n>largest)?largest=n: largest;
        smallest=(n<smallest)?smallest=n: smallest;
    }
    printf ("largest number = %d\n", largest);
    printf ("smallest number = %d", smallest);
    return 0;
}