#include<stdio.h>
#include<stdlib.h>

void print(int *queue,int front,int rear)
{
    int i;
    if(front==-1){
        printf("Queue is now Empty... \n");
        goto end;
    }
    printf("The queue is :\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d\t",*(queue+i));
    }
    printf("\n\n");
    end:
        printf("");
}
void enqueue(int *queue,int *front,int *rear,int size)
{
        if(*rear==size-1){
            printf("Queue Overflow...Elements cannot be enqueued.\n\n");
            goto end;
    }
    else if(*front==-1&&*rear==-1){
        int tmp;
        scanf("%d",&tmp);
        *front=0;
        *rear=0;
        *(queue+*rear)=tmp;
    }
    else{
        int tmp;
        scanf("%d",&tmp);
        (*rear)++;
        *(queue+*rear)=tmp;
    }
    end:printf("");
}
void dequeue(int *queue,int *front,int *rear,int size)
{
    if(*rear==-1&&*front==-1){
            printf("Stack Underflow...\n");
            goto end;
    }
    else if(*front==0&&*rear==0){
        printf("Element dequeued : %d\n\n",*(queue+*rear));
        (*rear)=-1;
        (*front)=-1;
    }
    else{
        printf("Element dequeued : %d\n\n",*(queue+*rear));
        (*rear)--;
    }
    end:printf("");
}

int main()
{
    int size=10;
    int front=-1,rear=-1;
    int queue[size];
    int i;
    printf("Enter 10 values in the queue : \n");
    for(i=0;i<size;i++)
        enqueue(queue,&front,&rear,size);
    print(queue,front,rear);
    printf("Enter value in queue : ");
    enqueue(queue,&front,&rear,size);
    print(queue,front,rear);
    printf("Enter no. of elements to be dequeued : ");
    int x;
    scanf("%d",&x);
    for(i=0;i<x;i++)
        dequeue(queue,&front,&rear,size);
    print(queue,front,rear);

    return 0;
}
