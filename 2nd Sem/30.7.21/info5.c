#include <stdio.h>
struct info{
    char name[50];
    char id[10];
    char address[50];
    char phone[12];
};
int main() {
    struct info student[5];
    for (int i = 0; i < 5; i++) {
        printf("\n\n\nFor Student %d:-", i+1);
        printf("\nEnter name: ");
        scanf("%s", &student[i].name);
        printf("\nEnter ID: ");
        scanf("%s", &student[i].id);
        printf("\nEnter Address: ");
        scanf("%s", &student[i].address);
        printf("\nEnter Phone: ");
        scanf("%s", &student[i].phone);
    }
    printf("\n\n---------Information----------\n");
    for (int i = 0; i < 5; i++){
        printf("\n\n\nFor Student %d:", i+1);
        printf("\nName: %s", student[i].name);
        printf("\nID: %s", student[i].id);
        printf("\nAddress: %s", student[i].address);
        printf("\nPhone No: %s", student[i].phone);
    }
    return 0;
}
