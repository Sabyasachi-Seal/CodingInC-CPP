#include <stdio.h>
void towerofhanoi(int , char, char, char);
int main(){
    int n ;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}
void towerofhanoi(int towers, char from, char to, char temp){
    if(towers == 1){
        printf("\nMove disk %d from %c to %c.", towers, from, to);
        return;
    }
    towerofhanoi(towers-1, from, temp, to);
    printf("\nMove disk %d from %c to %c.", towers, from, to);
    towerofhanoi(towers-1, temp, to, from);
    return;
}