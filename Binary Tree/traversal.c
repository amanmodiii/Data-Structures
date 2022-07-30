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
void inOrder(node* tmp){
    if(tmp==NULL)return;
    inOrder(tmp->left);
    printf("%d\t",tmp->data);
    inOrder(tmp->right);
}

void preOrder(node *tmp)
{
    if (tmp == NULL)
        return;
    printf("%d\t", tmp->data);
    preOrder(tmp->left);
    preOrder(tmp->right);
}

void postOrder(node *tmp)
{
    if (tmp == NULL)
        return;
    postOrder(tmp->left);
    postOrder(tmp->right);
    printf("%d\t", tmp->data);
}

int main()
{
    node *root = newnode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    return 0;
}