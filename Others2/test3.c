#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
};
void list(struct node** head, int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void display(struct node* head){
	struct node* ptr = head;
	while (ptr)
	{
	     printf("%d  ",ptr->data);
		ptr = ptr->next;
	}
}
void minimum(struct node* head){
	struct node* ptr = head;
    int minimum = head->data;
	while (ptr)
	{
        if(ptr->data<minimum){
            minimum = ptr->data;
        }
		ptr = ptr->next;
	}
    printf("Minimum is %d", minimum);
}
struct node* newNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insertion_sort(struct node** head, struct node* newNode){
	if (*head == NULL || (*head)->data >= newNode->data)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}
	struct node* current = *head;
	while (current->next != NULL && current->next->data < newNode->data)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;
}
void main (){  
    int ch;  
	struct node* head = NULL;
    while(1)  { 
        printf("\n1.Insert\n2.Display\n3.Minimum Element\n0.Exit\n");  
        printf("\nYour Choice: ");  
        scanf("\n%d",&ch);  
        switch(ch){  
            case 1: {
                int newdata;
                printf("Enter the element: ");  
                scanf("%d",&newdata); 
                insertion_sort(&head, newNode(newdata));
                display(head);
                break;  
            }
            case 2:  {
                display(head);
                break;  
            }
            case 3:{
                minimum(head);
                break;
            }
            case 0:  {
                exit(0);  
                break;  
            }
            default:  {
                printf("Please enter valid choice..");  
                break;
            }
        }  
    }  
}