#include<stdio.h>
#include<stdlib.h>

int top=-1;
int a[50];

void push();
void pop();
void peak();
void display();


void main()
{
    int ch;
    while (1)
    {
        printf("\nSTACK OPERATIONS");
        printf("\n1. Push \n2. Pop \n3. Peak \n4. Display \n5. Exit");
        printf("\nEnter your choice : ");
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

void push()
{
    int x;
    printf("\nEnter element to insert : ");
    scanf("%d", &x);
    top++;
    a[top]=x;
    printf("\n %d pushed , top = %d",a[top],top);
}
void pop()
{
    if(top==-1)
    {
        printf("\n Invalid !!!");
    }
    int x;
    x = a[top];
    top--;
    printf("\n %d poped , top = %d",x,top);
    
}
void peak()
{
    int x;
    printf("Enter position to peak : ");
    scanf("%d",&x);
    if(x<=top)
    {
    printf("%d",a[x-1]);
    }
    else
    {
        printf("Invalid Position");
    }
}
void display()
{
    printf("Stack :");
    for (int i = 0; i < top+1; i++)
    {
        printf("\n%d",a[i]);
    }
    
}