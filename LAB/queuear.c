#include<stdio.h>
#include<stdlib.h>

int rear=-1,front=-1;
int queue[50];

void enqueue();
void dequeue();
void peak();
void display();


void main()
{
    int ch;
    while (1)
    {
        printf("\nQUEUE OPERATIONS");
        printf("\n1. Enqueue \n2. Dequeue \n3. Peak \n4. Display \n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peak();
            break;
        case 4:
            display();
            break;
        case 5:
            return;
        default:
            break;
        }
    }
    
}

void enqueue()
{
    int x;
    printf("Enter element : ");
    scanf("%d",&x);
    rear++;
    queue[rear]=x;
    printf("%d inserted into queue , rear=%d , front=%d",queue[rear],rear,front);
}

void dequeue()
{
    int x;
    x = queue[front];
    front++;
    printf("%d deleted from queue , rear=%d , front=%d",queue[front],rear,front);
}

void peak()
{
    int x;
    printf("Enter position to view : ");
    scanf("%d",&x);
    printf("%d",queue[x-1]);
}

void display()
{
    for (int i = front+1 ; i <= rear; i++)
    {
        printf(" %d ",queue[i]);
    }
   
}