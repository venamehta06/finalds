#include<stdio.h>
#define max 5
int DQ[max];
int front = -1, rear = -1;
void insertFront(int val)
{
    if((front== 0 && rear == max-1)|| (front == rear +1))
    {
        printf("Queue is full");
    }
    else if(front == -1)
    {
        front = 0;
        rear = 0;
        DQ[front] = val;
    }
    else if(front == 0)
    {
        front = max - 1;
        DQ[front] = val;
    }
    else
    {
        DQ[--rear] = val;;
    }
}
void insertRear(int val)
{
    if((front == 0 && rear == max -1) || (front ==  rear + 1))
    {
        printf("Queue is full");
    }
    else if(rear == -1)
    {
        front = 0;
        rear = 0;
        DQ[rear] = val;
    }
    else if(rear = max - 1)
    {
        rear == 0;
        DQ[rear] = val;
    }
    else{
        DQ[++rear] = val;
    }

}
void deleteFront()
{
    if(front == -1)
    {
        printf("The queue is empty");
    }
    else if(front == rear)
    {
        printf("Deleted : %d\n",DQ[front]);
        front = -1;
        rear = -1;
    }
    else if(front == max - 1)
    {
        printf("Deleted : %d\n",DQ[front]);
        front = 0;
    }
    else
    {
        printf("Deleted : %d\n",DQ[front++]);
    }
}
void deleteRear()
{
    if(rear==-1)
    {
        printf("The queue is empty");
    }
    else if(front == rear)
    {
        printf("Deleted : %d\n",DQ[rear]);
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    {
        printf("Deleted : %d\n",DQ[rear]);
        rear = max - 1;
    }
    else
    {
        printf("Deleted : %d\n",DQ[rear--]);
    }

}
int main()
{
    int ch, val;
    do
    {
        printf("\n1.Insert Front");
        printf("\n2.Insert Rear");
        printf("\n3.Delete Front");
        printf("\n4.Delete Rear");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insertFront(val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insertRear(val);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 5);

    return 0;
}


