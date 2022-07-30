#include<stdio.h>
#include<stdlib.h>

typedef struct node
{ // basic code for a tree node
    int data;
    struct node *left;
    struct node *right;
} node;

node* min(node *tmp){       //recursive method to find the smallest element in a BST
    if(tmp->left==NULL)
        return tmp;
    return min(tmp->left);
}

node* max(node* tmp){       // recursive method to find the largest element in a BST
    if(tmp->right == NULL)
        return tmp;
    return max(tmp->right);
}