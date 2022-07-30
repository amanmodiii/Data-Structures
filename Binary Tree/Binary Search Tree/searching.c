#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ // basic code for a tree node
    int data;
    struct node *left;
    struct node *right;
} node;

node* search(node* root,int val){
    if(root==NULL || root->data == val)
        return root;
    else if(root->data<val)
        return search(root->right,val);
    else
        return search(root->left,val);
}