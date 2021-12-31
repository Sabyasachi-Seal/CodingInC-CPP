#include <stdio.h>
#include <stdlib.h>
typedef struct poly {
  int coef;
  int exp;
  struct poly *next;
} poly;
int main(void) {
    poly * po1, *head, *po2, *head2, *po3, *head3 = NULL;
    int sel, c = 1;
    head = NULL;
    printf("\nInsert elements for the first polynomial from the biggest to the smallest power of x. (Enter a power of zero (0) to stop)\n");
    while (1) {
    po1 = (poly *) malloc(sizeof(poly));
    printf("Give number: ");
    scanf("%d", &po1->coef);
    printf("Give power of x: ");
    scanf("%d", &po1->exp);
    po1->next = head;
    head = po1;
    if (po1->exp == 0) break;
    }
    head2 = NULL;
    printf("\nInsert elements for the second polynomial from the biggest to the smallest power of x. (Enter a power of zero (0) to stop)\n");
    while (1) {
    po2 = (poly *) malloc(sizeof(poly));
    printf("Give number: ");
    scanf("%d", &po2->coef);
    printf("Give power of x: ");
    scanf("%d", &po2->exp);
    po2->next = head2;
    head2 = po2;
        if (po2->exp == 0) 
            break;
    }
    po1 = head;
    po2 = head2;
    printf("Multiplied Polynomial");
    po1 = head;
    po2 = head2;
    while (po1 || po2){
        po2 = head2;
        while (po1 && po2) {
            po3 = (poly *) malloc(sizeof(poly));
            po3->coef = (po1->coef) * (po2->coef);
            po3->exp = (po1->exp) + (po2->exp);
            po3->next = head3;
            head3 = po3;
            po2 = po2->next;
        }
        po1 = po1->next;
    }
    while (po3){
        printf("%+d(x^%d)", po3->coef, po3->exp);
        po3 = po3->next;
    }
    printf("\n");
}
