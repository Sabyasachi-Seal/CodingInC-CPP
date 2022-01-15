#include<stdio.h>  
#include<stdlib.h>  
struct node{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;   
void insertfront()  {  
    struct node *newnode;   
    int ele;  
    newnode = (struct node *)malloc(sizeof(struct node));  
    if(newnode == NULL)  {  
        printf("\nOVERFLOW");  
    }  
    else{  
    printf("\nEnter Element: ");  
    scanf("%d",&ele);   
    if(head==NULL){  
        newnode->next = NULL;  
        newnode->prev = NULL;  
        newnode->data = ele;  
        head = newnode;  
    }  
    else {  
        newnode->data = ele;  
        newnode->prev = NULL;  
        newnode->next = head;  
        head->prev = newnode;  
        head = newnode;  
    }
    }  
}  
void insertlast(){  
    struct node *newnode,*temp;  
    int ele;  
    newnode = (struct node *)malloc(sizeof(struct node));  
    if(newnode == NULL)  {  
        printf("\nOVERFLOW");  
    }  
    else  {  
        printf("\nEnter value: ");  
        scanf("%d",&ele);  
        newnode->data = ele;  
        if(head == NULL)  {  
            newnode->next = NULL;  
            newnode->prev = NULL;  
            head = newnode;  
        }  
        else {  
            temp = head;  
            while(temp->next!=NULL){  
                temp = temp->next;  
            }  
            temp->next = newnode;  
            newnode->prev = temp;  
            newnode->next = NULL;  
            }  
                
        } 
    }  
void insertposi() {  
    struct node *newnode,*temp;  
    int ele, posi, i;  
    newnode = (struct node *)malloc(sizeof(struct node));  
    if(newnode == NULL)  {  
        printf("\nOVERFLOW");  
    }  
    else{  
        temp=head;  
        printf("Enter the position: ");  
        scanf("%d",&posi);  
        for(i=0;i<posi;i++){  
            temp = temp->next;  
            if(temp == NULL){  
                printf("\nPosition Not Available");  
                return;  
            }  
        }  
        printf("Enter Data: ");  
        scanf("%d",&ele);  
        newnode->data = ele;  
        newnode->next = temp->next;  
        newnode-> prev = temp;  
        temp->next = newnode;  
        temp->next->prev=newnode;  
    }  
}  
void deletefront(){  
    struct node *newnode;  
    if(head == NULL)  {  
        printf("\nUnderflow Condition\n");  
    }  
    else if(head->next == NULL)  {  
        head = NULL;   
        free(head);  
    }  
    else{  
        newnode = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(newnode);  
    }  
}  
void deletelast()  {  
    struct node *newnode;  
    if(head == NULL)  {  
        printf("\nUnderflow Condition\n");  
    }  
    else if(head->next == NULL)  {  
        head = NULL;   
        free(head);   
    }  
    else   {  
        newnode = head;   
        if(newnode->next != NULL)  {  
            newnode = newnode -> next;   
        }  
        newnode -> prev -> next = NULL;   
        free(newnode);  
    }  
}  
void deleteposi()  {  
    struct node *newnode, *temp;  
    int val;  
    printf("\nEnter the data(node after this will be deleted): ");  
    scanf("%d", &val);  
    newnode = head;  
    while(newnode -> data != val)  {
        newnode = newnode -> next;  
    }
    if(newnode -> next == NULL)  {  
        printf("\nNode cannot be deleted.\n");  
    }  
    else if(newnode -> next -> next == NULL)  {  
        newnode ->next = NULL;  
    }  
    else{   
        temp = newnode -> next;  
        newnode -> next = temp -> next;  
        temp -> next -> prev = newnode;  
        free(temp);  
    }     
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
        printf("\nInsert\n1.Front\n2.Last\n3.Specified\n\nDelete\n4.Beginning\n5.Last\n6.Specified\n\n7.Search\n8.Display\n9.Exit\n");  
        printf("\nYour Choice: ");  
        scanf("\n%d",&ch);  
        switch(ch){  
            case 1:{
                insertfront();
                traverse();
                break;  
            }
            case 2:{
                insertlast();  
                traverse();
                break;  
            }
            case 3: {
                insertposi();  
                traverse();
                break;  
            }
            case 4:  {
                deletefront();  
                traverse();
                break;  
            }
            case 5:  {
                deletelast();  
                traverse();
                break;  
            }
            case 6:  {
                deleteposi();  
                traverse();
                break;  
            }
            case 7:  {
                search();  
                break;  
            }
            case 8:  {
                traverse();  
                break;  
            }
            case 9:  {
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