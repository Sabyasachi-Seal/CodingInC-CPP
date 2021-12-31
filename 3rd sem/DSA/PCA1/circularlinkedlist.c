/* Sabyasachi Seal, 13005320003 */
#include <stdio.h>
#include <stdlib.h>
typedef struct clist{
    int n;
    struct clist *next;
}node;
node* make(node *front){
        node *ptr;
        char ch;
        while(1){
            printf("\nContinue adding?\n");
            scanf(" %c",&ch);
            if(ch=='n'||ch=='N')
                break;
            else{
                node *newnode=(node*)(malloc(sizeof(node)));
                printf("Enter Number?\n");
                scanf("%d",&newnode->n);
                if(front==NULL){
                    newnode->next=newnode;
                    front=newnode;
                    }
                else{
                    ptr=front;
                    while(ptr->next!=front)
                        ptr=ptr->next;
                    newnode->next=front;
                    ptr->next=newnode;
            }
        }
    }
    return front;
}
void display(node *front)
{
        if(front==NULL)
            printf("\nUnderflow\n");
        else
            {
            node *ptr=front;
            while(ptr->next!=front)
                {
                    printf("%d ",ptr->n);
                    ptr=ptr->next;
                }
            printf("%d ",ptr->n);
            }
}
node* insert_beginning(node *front){
        if(front==NULL)
            printf("\nUnderflow\n");
        else
            {
                node *new_node, *ptr;
                int num;
                printf("\n Enter the data : ");
                scanf("%d",&num);
                new_node =(node*)malloc(sizeof(node));
                new_node->n = num;
                ptr = front;
                while(ptr->next != front)
                ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = front;
                front=new_node;
                return front;
    }
}
void insert_end(node *front)
    {
        node *ptr=front;
        if(front==NULL)
            printf("\nUnderflow\n");
        else
        {
            node *newnode=(node*)(malloc(sizeof(node)));
            printf("Enter the number in the node: \n");
            scanf("%d",&newnode->n);
            while(front->next!= ptr)
                front=front->next;
            newnode->next=ptr;
            front->next=newnode;
     }
}
void insert_mid(node *front){
        int num,flag=1;
        node *ptr=front;
        printf("Creating a new node....\n");
        node *newnode=(node*)(malloc(sizeof(node)));
        if(newnode==NULL){
                printf("Failure in creating Node....");
                exit(0);
        }
        printf("Enter the content of the new node: \n");
        scanf("%d",&newnode->n);
        printf("\nEnter the number\n");
        scanf("%d",&num);
        while(ptr->next!=front){
                if(ptr->n==num)
                    {
                        newnode->next=ptr->next;
                        ptr->next=newnode;
                        flag = 23;
                        break;
                    }
                else
                    ptr=ptr->next;
                }
                if(flag==1)
                {
                if(ptr->n==num){
                        newnode->next=ptr->next;
                        ptr->next=newnode;
                    }
                else
                    printf("Number not found\n");
                }
}
void delete(node *front){
    int num;
    if(front==NULL)
        printf("\nUnderflow\n");
    else
    {
        node *ptr=front,*ptr1=front;
        printf("\nEnter the number:\n");
        scanf("%d",&num);
        while(ptr->n!=num){
                ptr=ptr1;
                ptr1=ptr1->next;
        }
        ptr->next=ptr1->next;
        free(ptr1);
    }
}
int main(){
        int ch;
        char choice;
        node *head = NULL;
        while(1){
                printf("\n1.Make List");
                printf("\n2.Add node at beginning");
                printf("\n3.Add a node at end");
                printf("\n4.Add a node at the middle");
                printf("\n5.Deletion of a node after a given node");
                printf("\n6.Display the entire list");
                printf("\n\nEnter your choice: \n");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                            head=make(head);
                            printf("\nList Made:\n");
                            display(head);
                            break;

                    case 2:
                            head = insert_beginning(head);
                            break;

                    case 3:
                            insert_end(head);
                            break;

                    case 4: 
                            insert_mid(head);
                            break;

                    case 5:
                            delete(head);
                            break;

                    case 6: 
                            display(head);
                            break;
                    default: printf("\nWrong Choice");
                }
                printf("\n\nContinue ? \n");
                scanf(" %c",&choice);
                if(choice=='n'||choice=='N'){
                    break;
                }
        }
    return 0;
}

