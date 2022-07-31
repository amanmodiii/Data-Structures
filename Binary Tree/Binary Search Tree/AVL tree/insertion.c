#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ // basic code for a tree node
    int data;
    struct node *left;
    struct node *right;
    int balance;
} node;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

int max(int a,int b){
    return a>b?a:b;
}

int height(node* n){
    if(n==NULL)return 0;
    else{
        return (1+max(height(n->left),height(n->right)));
    }
}

int getBalance(node* n){
    return (height(n->left)-height(n->right));
}

node *rightRotate(node *n)
{ // clockwise rotation
    node *x = n->left;
    node *T = x->right;

    x->right = n;
    n->left = T;

    x->balance = getBalance(x);
    n->balance = getBalance(n);

    return x;
}

node *leftRotate(node *n)
{ // anti-clockwise rotation
    node *x = n->right;
    node *T = x->left;

    x->left = n;
    n->right = T;

    x->balance = getBalance(x);
    n->balance = getBalance(n);

    return x;
}

node *insertNode(node *root, int data)
{ // standard BST insertion
    if (root == NULL)
        root = createNode(data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else if (data < root->data)
        root->left = insertNode(root->left, data);
    
    root->balance = getBalance(root);
    if(root->balance > 1 && data < root->left->data)
        return rightRotate(root);       //RR
    else if (root->balance < 1 && data > root->right->data)
        return leftRotate(root);        //LL
    else if (root->balance > 1 && data > root->left->data)
    {       //LR
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else{       //RL
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}