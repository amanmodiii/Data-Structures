#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void printList(node *head)
{
    printf("The Linked List : \n \n");
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void searchList(node *head, int val)
{
    node *tmp = head;
    int c = -1, flag = 0;
    while (tmp != NULL)
    {
        c++;
        if (val == tmp->data)
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }
    if (flag)
        printf("\n%d is present at position %d . \n", val, c + 1);
    else
        printf("\n%d is not present in the linked list. \n", val);
}

void insertAtHead(node **head, int data)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = *head;
    *head = tmp;
}

void insertAtEnd(node **head, int data)
{
    node *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    tmp->next = newnode;
}

void insertAtPosition(node **head, int data, int pos)
{
    node *tmp = *head;
    int i;
    for (i = 1; i < pos - 1; i++)
    {
        tmp = tmp->next;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = tmp->next;
    newnode->data = data;
    tmp->next = newnode;
}

void deleteAtHead(node **head)
{
    node *tmp;
    tmp = *head;
    *head = tmp->next;
    free(tmp);
}

void deleteAtEnd(node **head)
{
    node *tmp = *head, *last = tmp->next;
    while (last->next != NULL)
    {
        tmp = tmp->next;
        last = last->next;
    }
    tmp->next = NULL;
    free(last);
}

void deleteAtPosition(node **head, int pos)
{
    node *tmp = *head, *tmp1 = NULL;
    int i;
    for (i = 1; i < pos; i++)
    {
        tmp1 = tmp;
        tmp = tmp->next;
    }
    tmp1->next = tmp->next;
    free(tmp);
}

void reverseList(node **head){
    node *prev = NULL , *current = *head , *next ;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("\n\nList Reversed...\n\n");
}

int main()
{
    node *head = NULL;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter 10 elements : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    head = newnode;
    int i;
    int input;
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &input);
        insertAtEnd(&head, input);
    }
    printList(head);
    reverseList(&head);
    printList(head);
   
    return 0;
}
