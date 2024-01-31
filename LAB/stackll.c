#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int x;
    struct stack *next;
};

int size=0;
struct stack *top = NULL;

void push();
void pop();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\nSTACK OPERATIONS");
        printf("\n1. Push \n2. Pop \n3. Display \n4. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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

void push()
{
    struct stack *newnode;
    newnode =(struct stack*)malloc(sizeof(struct stack));
    printf("Enter element : ");
    scanf("%d",&newnode->x);
    newnode->next=top;
    top=newnode;
    size++;
    return;
}

void pop()
{
    struct stack *temp,*temp1;
    temp=top;
    top = temp->next;
    free(temp);
    size--;
    return;
}
void display()
{   
    struct stack* temp = top;
	while (temp!= NULL) 
    
    {
	printf("\n%d", temp->x);
    temp = temp->next;
    }
}


