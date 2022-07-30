#include<stdio.h>
#include<stdlib.h>

void print(int *stack,int top)
{
    int i;
    if(top==-1){
        printf("Stack is now Empty... \n");
        goto end;
    }
    printf("The stack is :\n");
    for(i=0;i<=top;i++)
    {
        printf("%d\t",*(stack+i));
    }
    printf("\n\n");
    end:
        printf("");
}
void push(int *stack,int *top,int size)
{
        if(*top==size-1){
            printf("Stack Overflow...Elements cannot be pushed.\n\n");
            goto end;
    }
    else{
        int tmp;
        scanf("%d",&tmp);
        (*top)++;
        *(stack+*top)=tmp;
    }
    end:printf("");
}
void pop(int *stack,int *top,int size)
{
    if(*top==-1){
            printf("Stack Underflow...\n");
            goto end;
    }
    else{
        printf("Element popped : %d\n\n",*(stack+*top));
        (*top)--;
    }
    end:printf("");
}
int main()
{
    int size=10;
    int stack[size];
    int top=-1;
    int i;
    printf("Enter 10 values in the stack : \n");
    for(i=0;i<size;i++)
        push(stack,&top,size);
    print(stack,top);
    printf("Enter value in stack : ");
    push(stack,&top,size);
    print(stack,top);
    printf("Enter no. of elements to be popped : ");
    int x;
    scanf("%d",&x);
    for(i=0;i<x;i++)
        pop(stack,&top,size);
    print(stack,top);

    return 0;
}
