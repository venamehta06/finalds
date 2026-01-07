#include<stdio.h>
#include<ctype.h>
#include<string.h>

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
    char prefix[50];
    int op1, op2;

    printf("Enter the string: ");
    scanf("%s", prefix);

    for(int i=strlen(prefix) - 1; i>=0; i++)
    {
        if(isdigit(prefix[i]))
        {
            push(prefix[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(prefix[i])
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
