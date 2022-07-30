#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ // basic code for a tree node
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

node* insertNode(node* root, int data){
    if(root==NULL)
        root=createNode(data);
    else if(data>root->data)
        root->right = insertNode(root->right,data);
    else if(data<root->data)
        root->left = insertNode(root->left, data);
    return root;
}