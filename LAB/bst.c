#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

int display();
void insertion();
void deletion();

void main()
{
    int ch;
    while (1)
    {
        printf("\nBinary Search Tree : ");
        printf("\n1.Insert \n2. Delete \n3. Display \n4. Exit");
        printf("\nEnter a choice : ");
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

struct node *insert(struct node *root,struct node *newnode)
{
    if (root==NULL)
    {
        root=newnode;
    }
    else if(root->data > newnode->data)
    {
        root->left = insert(root->left,newnode);
    }
    else
    {
        root->right = insert(root->right,newnode);
    }
    return root;
    
}

void insertion()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d",&newnode->data);
    newnode->left = newnode->right = NULL;
    root = insert(root,newnode);
    display();
}

struct node *find_min(struct node *root)
{
    if(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node *delete(struct node *root,int value)
{
    if(root==NULL)
    {
        printf("NULL");
        return root;
    }
    struct node *temp;

    if(value < root->data)
    {
        root->left=delete(root->left,value);        
    }
    else if(value > root->data)
    {
        root->right=delete(root->right,value);
    }
    else
    {
        if(root->left = NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right = NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        
        root->data = find_min(root->right)->data;
        root->right = delete(root->right,root->data);
        
    }
    return root;
} 

void deletion()
{
    int x;
    printf("Enter element to delete : ");
    scanf("%d",&x);
    root =  delete(root,x);
    display();
}

void preOrder(struct node *root)
{
    if(root==NULL)
        return;

    printf("%d->",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    printf("%d->",root->data);
    inOrder(root->right);
}

void postOrder(struct node *root)
{
    if(root==NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d->",root->data);
}

int display()
{
    if(root==NULL)
    {
        printf("Tree is empty");
        return 1;
    }
    printf("PreOrder : \n");
    preOrder(root);
    printf("NULL \ninOrder : \n");
    inOrder(root);
    printf("NULL \nPostOrder : \n");
    postOrder(root);
}
