#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void printList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }
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
    while (tmp->next != *head)
    {
        tmp = tmp->next;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *head;
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
    while (last->next != *head)
    {
        tmp = tmp->next;
        last = last->next;
    }
    tmp->next = *head;
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

int main()
{
    node *head = NULL;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the element : ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;

    // inserting 9 to 0 at head of LL
    insertAtHead(&head, 9);

    printf("\n\n The Linked List : ");
    printList(head);

    insertAtPosition(&head, 5, 2);

    printf("\n\n The Linked List : ");
    printList(head);

    deleteAtPosition(&head, 3);

    printf("\n\n The Linked List : ");
    printList(head);

    deleteAtEnd(&head);

    printf("\n\n The Linked List : ");
    printList(head);
}
