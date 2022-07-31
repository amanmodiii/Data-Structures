#include<stdio.h>
#include<stdlib.h>
//tempelate code for right and left rotation

typedef struct node{
    int key;
    struct node left;
    struct node right;
    int balance;
} node;

node* rightRotate(node* n){         //clockwise rotation
    node* x = n->left;
    node* T = x->right;

    x->right = n;
    n->left = T;

    //write code to update the balance factor of x and n

    return x;
}

node *leftRotate(node *n){         // anti-clockwise rotation
    node *x = n->right;
    node *T = x->left;

    x->left = n;
    n->right = T;

    // write code to update the balance factor of x and n

    return x;
}