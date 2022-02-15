//bst code from assingment 5.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;//for tracking height
}tree;
tree* newnode(int data){
    tree* new = (tree*)malloc(sizeof(tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;//leaf nodes have height 1
    return new;
}
int getheight(tree* root){//returns the height for balance factor
    if(root==NULL){
        return 0;
    }
    else{
        return root->height;
    }
}
int balancefactor(tree* root){
    if(root == NULL){
        return 0;
    }
    return getheight(root->left)-getheight(root->right);
}
tree* rightrotate(tree* root){
    tree* rootleft = root->left;
    tree* rightofrootleft = rootleft->right;
    //performing rotation
    rootleft->right = root;
    root->left = rightofrootleft;//breaking link between root and rootleft
    return rootleft;
}
tree* leftrotate(tree* root){
    tree* rootright = root->right;
    tree* leftofrootright = rootright->left;
    //performing rotating
    rootright->left = root;
    root->right = leftofrootright;//breaking link between root and rootright
    return rootright;
}
tree* Search(tree* root, int data){
    if(root == NULL){
        return NULL;
    }
    else if (root->data == data){
        return root;
    }
    else if (data < root->data){
        return Search(root->left, data);
    }
    else if(data > root->data){
        return Search(root->right, data);
    }
}
int max(int a, int b){//function for finding max element
    return (a>b)?a:b;
}
int height(tree* root){
    if(root==NULL){
        return -1;
    }
    return (max(height(root->left), height(root->right))+1);
}
tree* Insert(tree* root, int data){
    if(Search(root, data) != NULL){
        printf("\nDuplicate element\n");
        return NULL;
    }
    if(root == NULL){
        return newnode(data);
    }
    else if(data<=root->data){
        root->left = Insert(root->left, data);
    }
    else if(data>root->data){
        root->right = Insert(root->right, data);
    }

    root->height = height(root);// calculating height oof each node

    if(balancefactor(root)>1 && root->left->data > data){//LL condition
        return rightrotate(root);
    }
    else if(balancefactor(root)<-1 && root->right->data < data){//RR condition
        return leftrotate(root);
    }
    else if(balancefactor(root)<-1 && root->right->data > data){//RL condition
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    else if(balancefactor(root)>1 && root->left->data < data){//LR condition
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    return root;
}
tree* findmax(tree* root){
    tree* temp = root;
    while(temp && temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
tree* findmin(tree* root){
    tree* temp = root;
    while(temp && temp->left != NULL){
        temp = temp->left;
        
    }
    return temp;
}
void preorder(tree* root){
    if(root==NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(tree* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(tree* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
tree* delete(tree* root, int data){
    if(root == NULL){
        return root;
    }
    if(data<root->data){
        root->left = delete(root->left, data);
    }
    else if(data>root->data){
        root->right = delete(root->right, data);
    }
    else{
        if(root->left==NULL && root->right==NULL){//no child condition
            tree* temp = NULL;
            free(root);
            return temp;
        }
        else if(root->left == NULL && root->right != NULL){//has right child
            tree* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL && root->left != NULL){//has left child
            tree* temp = root->left;
            free(root);
            return temp;
        }
        else{//has 2 children
            if(height(root->left) < height(root->right)){
                tree* min = findmin(root->right);
                root->data = min->data;//finding minimun element
                root->right = delete(root->right, min->data);
            }
            else{
                tree* max = findmax(root->left);
                root->data = max->data;//finding maximum element
                root->left = delete(root->left, max->data);
            }
        }
        
        int bf = balancefactor(root);

        if(bf == 2 && balancefactor(root->left) >= 0){
            return rightrotate(root);
        }
        else if(bf == 2 && balancefactor(root->left) == -1){
            root->left = leftrotate(root);
            return rightrotate(root);
        }
        else if(bf == -2 && balancefactor(root->right) == -1){
            return leftrotate(root);
        }
        else if(bf == -2 && balancefactor(root->right) >= 0){
            root->right = rightrotate(root);
            return leftrotate(root);
        }
        
    }
    return root;
}
int main(){
    tree* root = NULL;
    while(1){
        printf("\n1-Insert Element\n2-Search Element\n3-Delete Element\n4-Minimum Element\n5-Maximum Element\n6-Find Height\n7-Traverse Tree\n0-Exit\nEnter your choice: ");
        int choice, x, cont;
        scanf("%d", &choice);
        switch(choice){
            case 0:{
                exit(0);
                break;
            }
            case 1:{
                do{
                    printf("\nEnter the element to be entered: ");
                    scanf("%d", &x);
                    if(root == NULL){
                        root = Insert(root, x);
                    }
                    else{
                        Insert(root, x);
                    }
                    printf("Do you want to continue? 1-Yes/0-No: ");
                    scanf("%d", &cont);
                }while(cont);
                break;
            }
            case 2:{
                printf("\nEnter a number to be searched: ");
                scanf("%d", &x);
                if(Search(root, x)!=NULL){
                    printf("\nNumber found");
                }
                else{
                    printf("\nNumber not found");
                }
                printf("\n");
                break;
            }
            case 3:{
                printf("\nEnter a number to be deleted: ");
                scanf("%d", &x);
                if(Search(root, x)!=NULL){
                    root = delete(root, x);
                    printf("\n%d has been deleted.\n", x);
                }
                else{
                    printf("Element Not Found!");
                }
                break;
            }
            case 4:{
                printf("Min element  = %d", findmin(root)->data);
                break;
            }
            case 5:{
                printf("Max Element = %d", findmax(root)->data);
                break;
            }
            case 6:{
                printf("\nHeight of the tree is: %d", height(root));
                break;
            }
            case 7:{
                printf("\n\n1-Level Order\n2-Preorder\n3-Inorder\n4-Postorder\nEnter your choice: ");
                int traversechoice;
                scanf("%d", &traversechoice);
                switch(traversechoice){
                    case 1:{
                        printf("\n\nLevel order traversal not implemented yet.\n\n");
                        break;
                    }
                    case 2:{
                        printf("\n\nRoot -> Left Subtree -> Right Subtree: \n\n");
                        preorder(root);
                        break;
                    }
                    case 3:{
                        printf("\n\nLeft Subtree -> Root -> Right Subtree: \n\n");
                        inorder(root);
                        break;
                    }
                    case 4:{
                        printf("\n\nLeft Subtree -> Right Subtree -> Root: \n\n");
                        postorder(root);
                        break;
                    }
                    default:{
                        printf("\nWrong Choice.\n");
                        break;
                    }
                }
                break;
            }
            default:{
                printf("\nWrong choice, try again.\n\n");
                break;
            }
        }
    }
    return 0;
}