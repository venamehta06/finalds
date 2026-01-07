#include<stdio.h>
#include<conio.h>
int stack[50];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int match(char a, char b)
{
    if(a=="(" && b ==")")
    {
        return 1;
    }
    else if(a=="{" && b =="}")
    {
        return 1;
    }
    else if(a=="[" && b =="]")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
char exp[50];
printf("Enter the expression ");
scanf("%s",exp);

for(int i = 0;exp[i];i++)
{
    if(exp[i] == "(" || exp[i] == "{" || exp[i] == "[")
    {
        push(exp[i]);
    }
    else if(exp[i] == ")" || exp[i] == "}" || exp[i] == "]")
    {
        if(top == -1 || !match(pop(),exp[i]))
            printf("Unbalanced");
            return 0;

    }
}
if(top == -1)
{
    printf("Parenthesis Balanced");
}
else
{
    printf("Unbalanced");
}
return 0;
}
