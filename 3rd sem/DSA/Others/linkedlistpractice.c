#include <stdio.h>
#include <stdlib.h>
struct llist{
    int data;
    struct llist *next;
};
typedef struct llist node;
node *head;
node *create(){
    int i, nos;
    node *temp, *head;
    printf("Enter the number of elements you want to enter:-\n");
    scanf("%d", &nos);
    for(i=0; i<nos; i++){
        if(i==0){
            head = (node *)malloc(sizeof(node));
            temp = head;
        }
        else{
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
        }
        printf("Enter element %d: \n", (i+1));
        scanf("%d", &temp->data);
    }
    temp->next=NULL;
    return (head);
}
void insert(node **head){
    int k=1, pos, length;
    node *p, *tempp, *new;
    printf("Enter what to insert: ");
    scanf("%d", &new->data);
    printf("\n Enter where to insert: ");
    scanf("%d", &pos);
    length = sizer(head);
    p = *head;
    if(pos>length){
        printf("Enter a valid position.\n");
    }
    else if(pos == 0){
        new->next = *head;
        *head = new;
    }
    else if(pos==length){
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = new;
        new->next = NULL;
    }
    else{
        while(k<=pos){
            p = p->next;
            k++;
        }
        new->next = p->next;
        p->next = new;
    }
}
void display(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete(node *head){
    int ele;
    node *new = head;
    node *curr = new;
    node *nxt = curr->next;
    printf("Enter the element to delete: ");
    scanf("%d", &ele);
    while(curr->next!=NULL){
        if(nxt->data==ele){
            curr->next = nxt->next;
            break;
        }
        else{
            nxt = curr->next;
        }
    }
}
int sizer(node *head){
    node *temp = head;
    int count;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{
    int choice = 1, task;
    while(choice){
        printf("What do you want to do?\n");
        printf("1.Create/Add\n2.Delete\n3.Display\n4.Exit\nYour Choice: ");
        scanf("%d", &task);
        switch(task){
            case 1:
                head = create();
                break;
            case 2:
                delete(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Choice\n");
                break;
        }
        printf("Do you want to continue?: ");
        scanf("%d", &choice);
    }
    return 0;
}
