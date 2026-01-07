#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
char stack[50][50];
int top = -1;
void push(char x[])
{
    strcpy(stack[++top],x);
}
char* pop()
{
    return stack[top--];
}
int main()
{
char prefix[50];
printf("Enter the string");
scanf("%s",prefix);

for (int i=strlen(prefix)-1;i>=0;i--)
{
    if(isalnum(prefix[i]))
    {
        char temp[2] = {prefix[i],'\0'};
        push(temp);
    }
    else
    {
        char a[50],b[50],exp[50];
        strcpy(a,pop());
        strcpy(b,pop());
        sprintf(exp,"%s%s%c",a,b,prefix[i]);
        push(exp);
    }
}
printf("%s",stack[top]);
return 0;

}
