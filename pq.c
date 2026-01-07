#include<stdio.h>
#define max 5
int pq[max];
int rear = -1;
void enqueue(int val)
{
    if(rear == max -1)
    {
        printf("The queue is full");
    }
    else
    {
        int i;
        for(i=rear;i>=0 && pq[i]<val;i--)

            pq[i+1] = pq[i];
        pq[i+1]=val;
        rear++;

    }
}
void dequeue()
{
    int val;
    if(rear == -1)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("Deleted element :\n",pq[rear--]);
    }
}
void display()
{
    if(rear==-1)
    {
        printf("The queue is empty");
    }
    else
    {
        int i;
        for(i=0;i<=rear;i++)
        {
            printf("%d ",pq[i]);
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

