#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

Node* tree_root = NULL;

int max(int a, int b) { return (a > b) ? a : b; }

int height(Node* N) {
    if(N == NULL)
        return 0;
    return N->height;
}

Node* new_Node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

void preorder(Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

Node* rotate_right(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* rotate_left(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int get_balance(Node* N) {
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int data) {
    if(node == NULL)
        return (new_Node(data));
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = get_balance(node);
    if(balance > 1 && data < node->left->data)
        return rotate_right(node);
    if(balance < -1 && data > node->right->data)
        return rotate_left(node);
    if(balance > 1 && data > node->left->data) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if(balance < -1 && data < node->right->data) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

Node* min_node(Node* node) {
    Node* current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

Node* delete(Node* root, int data) {
    if(root == NULL)
        return root;
    if(data < root->data)
        root->left = delete(root->left, data);
    else if(data > root->data)
        root->right = delete(root->right, data);
    else {
        if((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if(temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = min_node(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    if(root == NULL)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance(root);
    if(balance > 1 && get_balance(root->left) >= 0) {
        Node* node = rotate_right(root);
        printf("\nRotated right, preorder: ");
        preorder(tree_root);
        return node;
    }
    if(balance > 1 && get_balance(root->left) < 0) {
        root->left = rotate_left(root->left);
        Node* node = rotate_right(root);
        printf("\nRotated right, preorder: ");
        preorder(tree_root);
        return node;
    }
    if(balance < -1 && get_balance(root->right) <= 0) {
        Node* node = rotate_left(root);
        printf("\nRotated left, preorder: ");
        preorder(tree_root);
        return node;
    }
    if(balance < -1 && get_balance(root->right) > 0) {
        root->right = rotate_right(root->right);
        Node* node = rotate_left(root);
        printf("\nRotated left, preorder: ");
        preorder(tree_root);
        return node;
    }
    return root;
}

int main() {
    tree_root = insert(tree_root, 20);
    tree_root = insert(tree_root, 10);
    tree_root = insert(tree_root, 30);
    tree_root = insert(tree_root, 5);
    tree_root = insert(tree_root, 15);
    tree_root = insert(tree_root, 25);
    tree_root = insert(tree_root, 35);
    tree_root = insert(tree_root, 3);
    tree_root = insert(tree_root, 7);
    tree_root = insert(tree_root, 18);
    tree_root = insert(tree_root, 40);
    tree_root = insert(tree_root, 9);
    printf("Original tree, preorder: ");
    preorder(tree_root);


    int choice,value;
    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Preorder display\n");
        printf("0. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {

            case 1:

                printf("Enter the value to be inserted: ");
                scanf("%d", &value);

                tree_root = insert(tree_root, value);

                break;

            case 2:

                printf("Enter the value to be deleted: ");
                scanf("%d", &value);

                tree_root = delete(tree_root, value);

                break;
            case 3:
                printf("Preorder traversal of the AVL tree is \n");
                preorder(tree_root);
                break;
            case 0:
            printf("\nFinal tree, preorder: ");
            preorder(tree_root);
            printf("\n\n Exiting...");
                exit(1);
            default:
			printf("Invalid choice\n");
        }

    }
    return 0;
}