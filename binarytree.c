#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree {
    int data;
    struct BinaryTree *left, *right;
} binaryTree;

binaryTree* insert(binaryTree *root, int data){
    if(root == NULL){
        binaryTree *newNode = (binaryTree*)malloc(sizeof(binaryTree));
        newNode -> data = data;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    } else {
        int ch = 2;
        printf("Left(1) / Right(2) ? (1/2) ");
        scanf("%d", &ch);
        if(ch == 2){
            root -> right = insert(root -> right, data);
        } else {
            root -> left = insert(root -> left, data);
        }
    }
}

void levelOrder(binaryTree *root){
    binaryTree *roots[100];
    int front = 0, rear = 0;
    roots[0] = root;
    while(front <= rear){
        binaryTree *pop = roots[front++];
        printf("%d ", pop -> data);
        if(pop -> left != NULL){
            roots[++rear] = pop -> left;
        }
        if(pop -> right != NULL){
            roots[++rear] = pop -> right;
        }
    }
}

int main() {
    binaryTree *root = NULL;
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int data;
        printf("Enter value to inserted: ");
        scanf("%d", &data);
        root = insert(root, data);
    }
    levelOrder(root);
}