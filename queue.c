#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int val)
{
    if(rear == MAX -1)
    {
        printf("The queue is full");
    }
    else if(front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear]=val;
    }
}

void dequeue()
{
    int val;
    if(front == -1)
    {
        printf("The queue is empty");
    }
    else if(front==rear)
    {
        val = queue[front];
        front = -1;
        rear = -1;
        printf("The deleted element is %d",val);

    }
    else
    {
        val = queue[front];
        front++;
    }
}
void display()
{
    if(front==-1)
    {
        printf("The queue is empty");
    }
    else
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch,val;
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
         case 3:
            display();
            break;
        }
    }while(ch!=4);
    return 0;
}
