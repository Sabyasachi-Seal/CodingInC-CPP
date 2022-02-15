#include<stdio.h>  
#include<stdlib.h>  
struct node{   
    struct node *next;  
    int data;  
};  
struct node *head;   
// void insertposi() {  
//     struct node *newnode,*temp;  
//     int i;  
//     newnode = (struct node *)malloc(sizeof(struct node));  
//     if(newnode == NULL)  {  
//         printf("\nOVERFLOW");  
//     }  
//     else{  
//         temp=head;  
//         int newdata;
//         printf("Enter the element: ");  
//         scanf("%d",&newdata);  
//         while(newdata>temp->data){  
//             temp = temp->next;  
//         }   
//         newnode->data = newdata;  
//         newnode->next = temp->next;  
//         temp->next = newnode; 
//     }  
// } 
void list(struct node** head, int data)//function to build linked list
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
struct node* newNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertion_sort(struct node** head, struct node* newNode)//function to insert data in sorted position
{
	if (*head == NULL || (*head)->data >= newNode->data){
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

void traverse(){  
    struct node *newnode; 
    newnode = head;  
    while(newnode != NULL){  
        printf("%d ",newnode->data);  
        newnode=newnode->next;  
    } 
    printf("\n");
}   
void search() {  
    struct node *newnode;  
    int ele, i=0, flag;  
    newnode = head;   
    if(newnode == NULL)  {  
        printf("\nUnderflow\n");  
    }  
    else  {   
        printf("\nEnter Search Element: ");   
        scanf("%d",&ele);  
        while (newnode!=NULL)  {  
            if(newnode->data == ele)  {  
                printf("\nPresent at Position %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  {  
                flag=1;  
            }  
            i++;  
            newnode = newnode -> next;  
        }  
        if(flag==1)  {  
            printf("\nItem not found\n");  
        }  
    }                
}  
void main (){  
    int ch;  
    while(1)  { 
        printf("\n1.Insert\n2.Search\n3.Display\n0.Exit\n");  
        printf("\nYour Choice: ");  
        scanf("\n%d",&ch);  
        switch(ch){  
            case 1: {
                insertposi();  
                traverse();
                break;  
            }
            case 2:  {
                search();  
                break;  
            }
            case 3:  {
                traverse();  
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