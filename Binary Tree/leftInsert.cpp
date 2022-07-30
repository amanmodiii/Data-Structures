#include <iostream>
#include <queue>
using namespace std;

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

node* insertNode(node* root,int data){
    if(root==NULL){
        root=createNode(data);               //if tree is empty
        return root;                          //create a root node
    }
    queue <node*>q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        if(tmp->left!=NULL)
            q.push(tmp->left);
        else{
            tmp->left = createNode(data);
            return root;
           }
        if (tmp->right != NULL)
           q.push(tmp->right);
        else
        {
           tmp->right = createNode(data);
           return root;
        }
    }
}

int main()
{
    node *root = insertNode(root,1);
    root->left = insertNode(root,2);
    root->right = insertNode(root,3);

    return 0;
}