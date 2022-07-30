#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int stack[50];
int top=-1;

void push(int tmp)
{
    if(top==49){
        printf("Overflow...\n");
        exit(0);
    }
        top++;
        *(stack+top)=tmp;
}
int pop()
{
    if(top==-1){
        printf("Underflow...\n");
        exit(0);
    }
    else{
        return *(stack+(top--));
    }
}

int main()
{
    char exp[50];
    printf("Enter the Postfix Expression : \n");
    scanf("%s",exp);
    int i=0;
    while(exp[i]!='\0'){
        char ch=exp[i];
        if(ch>=48&&ch<=57)push(ch-48);
        else{
            int c1=pop();
            int c2=pop();
            int res=0;
            switch(ch)
            {
            case '+':
                res=c1+c2;
                break;
            case '-':
                res=c2-c1;
                break;
            case '*':
                res=c1*c2;
                break;
            case '/':
                res=c2/c1;
                break;
            case '^':
                res=(int)pow(c1,c2);
                break;
            }
            push(res);
        }
        i++;
    }
    int res=pop();
    printf("\n Evaluated Result is : %d\n",res);

    return 0;
}
