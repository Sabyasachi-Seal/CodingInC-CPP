#include <stdio.h>
#include <stdlib.h>
int hasher(int data, int size){
    return data%size;
}
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("Arr[%d] = %d\t", i, arr[i]);
    }
}
int search_empty(int arr[], int data, int size){
    int posi = hasher(data, size);
    if(arr[posi]<0) {
        return posi;
    }
    else{
        for(int i=(posi-1) ;; i--) {
            if(arr[i]<0){
                return i;
            }
            else if(i<0) {
                i = size;
            }
            else if(i==posi) {
                return -1;
            }
        }
    }
}
int search_element(int arr[], int data, int size){
    int posi = hasher(data, size);
    if(arr[posi]==data) {
        return posi;
    }
    else{
        for(int i=(posi-1) ;; i--) {
            if(arr[posi]==data){
                return i;
            }
            else if(i<0) {
                i = size;
            }
            else if(i==posi) {
                return -1;
            }
        }
    }
}
void insert(int arr[], int data, int size){
    int posi = search_empty(arr, data, size);
    if(posi>=0) {
        arr[posi] = data;
        printf("\n%d Element Inserted.\n", data);
    }
    else {
        printf("Full\n");
    }
    return;
}
void delete(int arr[], int data, int size){
    int posi = search_element(arr, data, size);
    if(posi>=0) {
        arr[posi] = -1;
        printf("\n%d Element Deleted.\n", data);
    }
    else {
        printf("\nEmpty / Element Not Found\n");
    }
    return;
}
int main(){
    printf("Enter size of hash table: ");
    int size = 0;
    scanf("%d", &size);
    int *arr = (int*)calloc(size, sizeof(int));
    int data;
    for(int i=0; i<size; i++) {
        arr[i]=-2;
    }
    int choice = 1;
    while(choice>0){
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n0.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        data = 0;
        switch(choice){
            case 1:{
                printf("\nEnter the element to insert: ");
                scanf("%d", &data);
                insert(arr, data, size);
                display(arr, size);
                break;
            }
            case 2:{
                printf("\nEnter the element to delete: ");
                scanf("%d", &data);
                delete(arr, data, size);
                display(arr, size);
                break;
            }
            case 3:{
                printf("\nEnter search element: ");
                scanf("%d", &data);
                int posi = search_element(arr, data, size);
                if(posi>=0) {
                    printf("Found at array position %d\n", posi);
                }
                else {
                    printf("Not Found");
                }
                break;
            }
            case 4:{
                display(arr, size);
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("\nTry Again!\n");
                choice = 5;
                break;
            }
        }
        
    }
    return 0;
}