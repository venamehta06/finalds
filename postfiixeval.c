#include<stdio.h>
#include<ctype.h>

int stack[50];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[50];
    int op1, op2;

    printf("Enter the string: ");
    scanf("%s", postfix);

    for(int i = 0; postfix[i]; i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(postfix[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }

    printf("%d\n", pop());
    return 0;
}
