#include<stdio.h>
#include<stdlib.h>

void print(int *queue,int front,int rear,int size)
{
    int i;
    if(front==-1){
        printf("Queue is now Empty... \n");
        goto end;
    }
    else if(front<=rear){
        printf("The queue is :\n");
        for(i=front;i<=rear;i++)
            printf("%d\t",*(queue+i));
        printf("\n\n");
    }
    else{
        printf("The queue is :\n");
        for(i=front;i<size;i++)
            printf("%d\t",*(queue+i));
        for(i=0;i<=rear;i++)
            printf("%d\t",*(queue+i));
        printf("\n\n");
    }
    end:
        printf("");
}
void enqueue(int *queue,int *front,int *rear,int size)
{
    if(*front==-1&&*rear==-1){
        int tmp;
        scanf("%d",&tmp);
        *front=0;
        *rear=0;
        *(queue+*rear)=tmp;
    }
    else if((*front==0 && *rear==size-1)||(*front==(*rear+1))){
        printf("Queue Overflow...Elements cannot be enqueued.\n\n");
        goto end;
    }

    else if(*rear==size-1 && *front!=0){
        int tmp;
        scanf("%d",&tmp);
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
    else if(*front==*rear&&*rear!=-1){
        printf("Element dequeued : %d\n\n",*(queue+*front));
        (*rear)=-1;
        (*front)=-1;
    }
    else if(*front==size-1){
        printf("Element dequeued : %d\n\n",*(queue+*front));
        *front=0;
    }
    else{
        printf("Element dequeued : %d\n\n",*(queue+*front));
        (*front)++;
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
    print(queue,front,rear,size);
    while(1){
    printf("Enter 1 to display queue, 2 to enqueue ,3 to dequeue and 4 to exit :\n");
    int ch;
    scanf("%d",&ch);
    switch(ch){
    case 1:
        print(queue,front,rear,size);
        break;
    case 2:
        printf("Enter a number : \n");
        enqueue(queue,&front,&rear,size);
        break;
    case 3:
        printf("Enter no. of elements to be dequeued : ");
        int tmp;
        scanf("%d",&tmp);
        while(tmp--)
            dequeue(queue,&front,&rear,size);
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Invalid choice try again....!\n");
    }
    }

    return 0;
}

