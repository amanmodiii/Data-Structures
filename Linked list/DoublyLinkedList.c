#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    tmp->prev = NULL ;
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
    newnode->prev = tmp;
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
    node *next=tmp->next;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = tmp->next;
    newnode->prev = tmp;
    newnode->data = data;
    next->prev = newnode;
    tmp->next = newnode;
}

void deleteAtHead(node **head)
{
    node *tmp;
    tmp = *head;
    *head = tmp->next;
    (*head)->prev = NULL;  //cmnt
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
    node *next = tmp->next;
    next->prev = tmp1;
    tmp1->next = tmp->next;
    free(tmp);
} //doesnt work when we delete the last node with it

int main()
{
    node *head = NULL;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the element : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    head = newnode;

    // inserting 9 to 0 at head of LL
    insertAtHead(&head, 9);

    printf("\n\n The Linked List : ");
    printList(head);

    deleteAtHead(&head);


    printf("\n\n The Linked List : ");
    printList(head);

    // inserting 9 to 0 at head of LL
    insertAtHead(&head, 9);

    insertAtPosition(&head, 5, 2);

    printf("\n\n The Linked List : ");
    printList(head);

    deleteAtPosition(&head, 3);

    printf("\n\n The Linked List : ");
    printList(head);
}
