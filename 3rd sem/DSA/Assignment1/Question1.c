/*
Question 1:-
Implement a list using array with following ADT(operation at least)
->Insertion (default at the last available position otherwise as specified by user)
->Deletion
->Searching
*/
#include<stdio.h>
#include<stdlib.h>
void specified_insert();
void default_insert();
int search();
void delete();
void print();
int top = -1, i, n, *arr;
int main(){
    int choice, posi;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("\nEnter element %d: ", (i+1));
        scanf("%d",&arr[i]);
    }
    top=n-1;
    do{
    printf("\n1-Insert Element\n2-Search\n3-Delete Element\n4-Show List\n5-Exit\nYour Choice: ");
    scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                int choice2;
                printf("\n1-Specific Position\n2-Default Position. ");
                scanf("%d",&choice2);
                if(choice2==1){
                    specified_insert();
                }
                else{
                    default_insert();
                }
                break;
            }
            case 2:
            {
                posi = search();
                if(posi == -1){ 
                    printf("\nValue doesnt exist\n");
                }
                else{ 
                    printf("\nPresent at %d position\n", posi+1);
                }
                break;
            }
            case 3:
            {
                delete();
                break;
            }
            case 4:
            {
               print();
               break;
            }
            case 5:
            {
                exit(0);
                break;
            }
        }
    }while(1);
    return 0;
}
void specified_insert(){
    int data, pos;
    printf("Enter the element to be inserted and its position: ");
    scanf("%d %d",&data, &pos);
    if(pos>n && pos<0){
        printf("Invalid Position");
    }
    else{
        if(top<n-1){
            int j=top;
            while(j>=pos){
                arr[j+1]=arr[j];
                j--;
            }
            arr[pos]=data;
            top++;
        }
        else{
            printf("Your list is full\n");
        }
    }
}
void default_insert(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    if(top<n-1){
        top++;
        arr[top]=data;
    }
    else{ 
        printf("Your list is full\n");
    }
}
void delete(){
    int key;
    printf("Enter the value you want to delete: ");
    scanf("%d",&key);
    int flag=0;
    if(top==-1) printf("Your list is empty\n");
    else{
        for(i=0;i<=top;i++){
            if(arr[i]==key){
                flag=1;
                i++;
            while(i<=top){
                arr[i-1]=arr[i];
                i++;
            }
            top--;
            break;
            }
        }
        if(flag==0){
            printf("Value not found\n");
        }
        else{
            printf("Value successfully deleted\n");
        }
    }
}
int search(){
    int key;
    printf("Enter the value you want to search: ");
    scanf("%d",&key);
    for(i=0;i<=top;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
void print(){
    printf("Your list: ");
    for(i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}