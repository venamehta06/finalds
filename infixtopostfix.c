#include<stdio.h>
#include<conio.h>
char stack[50];
int top = -1;

void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    return stack[top--];
}
int priority(char x)
{
    if(x=="%")
    {
    return 3;}
    else if(x=="*"||x=="/"){
    return 2;}
    else if(x=="+"||x=="-"){
    return 1;}
    else{
    return 0;}
}
void InfixToPostfix(char infix[],char postfix[])
{
    int i = 0, k = 0;
    while(infix[i])
    {
        if(isalnum(infix[i]))
        {
            postfix[k++]=infix[i];
        }
        else if(infix[i]=="(")
        {
            push(infix[i]);
        }
        else if(infix[i]==")")
        {
            while(stack[top]!="(")

                postfix[k++] = pop();
            pop();
        }
        else
        {
            while(top!=-1 && priority(stack[top]>=priority(infix[i])))

                postfix[k++] = pop();
            push(infix[i]);

        }
        i++;
    }
    while(top!=-1)
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}

int main()
{
char infix[50],postfix[50];
printf("Enter the string");
scanf("%s",&infix);
InfixToPostfix(infix,postfix);
printf("\n%s",postfix);
return 0;

}
