#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
int size = 0;

void display();
void insertion();
void deletion();

void main()
{
    printf("Linked List");
    int ch;
    while (1)
    {
        printf("\n1. Insert \n2. Delete \n3.Display \n4.Exit");
        printf("\n Enter a choice : ");
        scanf("%d",&ch);    
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
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

void insertion()
{
    int in;
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n1. At beginning \n2. At end \n3. At any position");
    printf("\nEnter choice : ");
    scanf("%d", &in);
    temp=head;
    printf("\nElement : ");
    scanf("%d",&newnode->data); 
    
    void beginning()
    {
        newnode->next=head;
        head=newnode;
        return;
    }

    void end()
    {
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        return;
    }

    void pos()
    {
        int pos;
        printf("\nEnter position : ");
        scanf("%d",&pos);
        if (pos<= 1 || pos>size)
        {
            printf("Invalid size\n");
            return;
        }
        int i=2;
        while(i<pos)
        {
            if(temp->next!=NULL)
            {
                temp=temp->next;
            }
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        size++;
        return;
        
    }
    switch (in)
    {
        case 1:
            beginning();
            break;
        case 2:
            end();
            break;
        case 3:
            pos();
            break;          
        default:
            break;
    }
    size++;
    display();
    return;
}

void deletion()
{
    int in;
    struct node *delnode,*temp,*temp1;
    temp=head;
    printf("\n1. At beginning \n2. At end \n3. At any position");
    printf("\nEnter choice : ");
    scanf("%d",&in);
    void begin()
    {
        head=temp->next;
        free(temp);
    }

    void end()
    {
        while (temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
    }

    void pos()
    {
        int pos;
        printf("\nEnter position : ");
        scanf("%d",&pos);
        if(pos <=1|| pos>size)
        {
            printf("Invalid");
            return;
        }
        int i =2;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        delnode = temp->next;
		temp->next = delnode->next;
        free(delnode);
    
    }
     switch (in)
    {
        case 1:
            begin();
            break;
        case 2:
            end();
            break;
        case 3:
            pos();
            break;          
        default:
            break;
    }
    display();
    return;
}
void display()
{
    struct node *temp = head;
    printf("Head->");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}