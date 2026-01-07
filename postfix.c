#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[50];
    scanf("%s", postfix);

    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("%d\n", pop());
    return 0;
}
