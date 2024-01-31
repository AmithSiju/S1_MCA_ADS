#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int x;
    struct queue *next;
};

int size=0;
struct queue *rear=NULL;
struct queue *front=NULL;

void enqueue();
void dequeue();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\nQUEUE OPERATIONS");
        printf("\n1. Enqueue \n2. Dequeue \n3. Dsiplay \n4. Exit");
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
            display();
            break;
        case 4:
            return;
        default:
            break;
        }
    }
    
}

void enqueue()
{
    struct queue *newnode;
    newnode=(struct queue*)malloc(sizeof(struct queue));
    printf("Enter element : ");
    scanf("%d",&newnode->x);
    newnode->next=rear;
    rear=newnode;
    size++;
    return;
}

void dequeue()
{
    struct queue *temp,*temp1;
    temp=rear;
    while (temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    free(temp);
}
void display()
{
    struct queue *temp = rear;
    while(temp!=NULL)
    {
    printf(" %d ",temp->x);
    temp=temp->next;
    }
}


