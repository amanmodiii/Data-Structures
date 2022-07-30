#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[50];
int top=-1;

void push(char tmp)
{
        top++;
        *(stack+top)=tmp;
}
void pop()
{
    if(top==-1)
            goto end;
    else{
        printf("%c",*(stack+top));
        top--;
    }
    end:printf("");
}
int priority(char ch)
{
    if(ch=='(')return 0;
    else if(ch=='+'||ch=='-')return 1;
    else if(ch=='*'||ch=='/')return 2;
    else if(ch=='^')return 3;
    return 0;
}

int main()
{
    char exp[50];
    printf("Enter the Infix Expression : \n");
    scanf("%s",exp);
    int size=strlen(exp);
    printf("\n\nThe Postfix Expression is :\n");
    int i;
    for(i=0;i<size;i++){
        char ch = exp[i];
        if(ch>=65 && ch<=90)printf("%c",ch);
        else if(ch=='(')push(ch);
        else if(ch==')'){
            while(stack[top]!='(')pop();
            push(ch);
        }
        else{
            while(priority(stack[top])>=priority(ch))
                pop();
            push(ch);
        }
    }
    while(top!=-1)pop();

    return 0;
}
