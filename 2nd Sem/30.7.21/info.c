#include <stdio.h>
struct info{
    char name[50];
    char id[10];
    char address[50];
    char phone[12];
};
int main(){
    struct info student;
    printf("Enter name: ");
    scanf("%s", &student.name);
    printf("\nEnter ID: ");
    scanf("%s", &student.id);
    printf("\nEnter Address: ");
    scanf("%s", &student.address);
    printf("\nEnter Phone: ");
    scanf("%s", &student.phone);
    
    printf("\n\n\nName: %s", student.name);
    printf("\nID: %s", student.id);
    printf("\nAddress: %s", student.address);
    printf("\nPhone No: %s", student.phone);
    return 0;
}