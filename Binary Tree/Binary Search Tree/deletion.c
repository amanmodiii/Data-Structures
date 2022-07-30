#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ // basic code for a tree node
    int val;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

node *insertNode(node *root, int data)
{
    if (root == NULL)
        root = createNode(data);
    else if (data > root->val)
        root->right = insertNode(root->right, data);
    else if (data < root->val)
        root->left = insertNode(root->left, data);
    return root;
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree
   and a val, this function
   deletes the val and
   returns the new root */
struct node *deleteNode(struct node *root, int val)
{
    // base case
    if (root == NULL)
        return root;

    // If the val to be deleted
    // is smaller than the root's
    // val, then it lies in left subtree
    if (val < root->val)
        root->left = deleteNode(root->left, val);

    // If the val to be deleted
    // is greater than the root's
    // val, then it lies in right subtree
    else if (val > root->val)
        root->right = deleteNode(root->right, val);

    // if val is same as root's val,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}