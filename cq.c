#include <stdio.h>
#define max 5

int cq[max];
int front = -1, rear = -1;

void enqueue(int val)
{
    if ((rear + 1) % max == front)
        printf("Queue is full\n");
    else if (front == -1)
    {
        front = rear = 0;
        cq[rear] = val;
    }
    else
    {
        rear = (rear + 1) % max;
        cq[rear] = val;
    }
}

void dequeue()
{
    int val;
    if (front == -1)
        printf("Queue is empty\n");
    else if (front == rear)
    {
        val = cq[front];
        front = rear = -1;
        printf("Deleted value is %d\n", val);
    }
    else
    {
        val = cq[front];
        front = (front + 1) % max;
        printf("Deleted value is %d\n", val);
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements: ");
        i = front;
        while (1)
        {
            printf("%d ", cq[i]);
            if (i == rear)
                break;
            i = (i + 1) % max;
        }
        printf("\n");
    }
}

int main()
{
    int ch, val;
    do
    {
        printf("\n1.Insert using Front\n2.Insert using Rear\n3.Delete using Front\n4.Delete using Rear\n5.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 6);

    return 0;
}
