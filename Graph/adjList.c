#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct list{
    node* head;
}list;

typedef struct graph{
    int V;
    list *array;
}graph;

node* newNode(int data){
    node* newnode= (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

graph* createGraph(int V){
    graph* G =(graph*) malloc(sizeof(graph));
    G->V = V;

    G->array=(list*) malloc(V * sizeof(list));
    int i;
    for(i=0; i<V ;i++){
        G->array[i].head = NULL;
    }
    return G;
}

void insertEdge(graph *G, int src, int data){
    node* check = NULL;
    node* newnode = newNode(data);
    if(G->array[src].head!=NULL){
        check = G->array[src].head;
        while(check->next != NULL)
            check = check->next;
        check->next = newnode;
    }
    else{
        newnode->next = NULL;
        G->array[src].head = newnode;
    }
    newnode = newNode(src);
    if (G->array[data].head != NULL)
    {
        check = G->array[data].head;
        while (check->next != NULL)
            check = check->next;
        check->next = newnode;
    }
    else
    {
        newnode->next = NULL;
        G->array[data].head = newnode;
    }
}

void printGraph(graph* G)
{
    int V;
    for (V = 0; V <= G->V ; V++)
    {
        node* traverse = G->array[V].head;
        printf("\n Adjacency list of vertex %d\n head ", V);
        while (traverse)
        {
            printf("-> %d", traverse->data);
            traverse = traverse->next;
        }
        printf("\n");
    }
}


int main(){
    int v, e;
    printf("Enter the number of vertices and edges : ");
    scanf("%d %d", &v, &e);
    graph* G = createGraph(v);
    int i,s,d;
    for(i=0; i<e; i++){
        printf("Enter the vertices where you want to insert an edge : ");
        scanf("%d %d", &s, &d);
        insertEdge(G,s,d);
    }

    printGraph(G);

    return 0;
}