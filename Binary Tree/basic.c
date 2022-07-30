#include<stdio.h>
#include<stdlib.h>

typedef struct node{                    //basic code for a tree node
    int data;
    struct node *left;
    struct node *right;
} node;

node* newNode(int data){
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode -> left = newnode -> right = NULL ;

    return newnode;
}

int main(){
    node *root = newnode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);

    return 0;
}