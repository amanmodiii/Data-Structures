#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ // basic code for a tree node
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

int max(int a, int b){
    return (a>b?a:b);
}

int height(node* root){
    if(root==NULL)
        return 0;
    return (1 + max(height(root->left),height(root->right)));
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    int ht = height(root);
    printf("%d\n",ht);

    return 0;
}