#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n;
#define MAX_NODES 100
int queue[MAX_NODES];
int front=-1,rear=-1;

void enqueue(int value);
int dequeue();

void BFS(int n,int graph[][MAX_NODES],int visited[],int source)
{
    enqueue(source);
    visited[source]=1;
    while(front <= rear)
     {
        int node = dequeue();
        printf("%d",node);
     
        for (int i = 0; i < n; i++)
        {
            if(graph[node][i]!=0 && !visited[i])
            {
                enqueue(i);
                visited[i]=1;
            }
        }
     }
     
}

void main()
{
    printf("Enter no of nodes : ");
    scanf("%d",&n);

    int V[n];
    for (int i = 0; i < n; i++)
    {
        V[i]=0;
    }

    int A[MAX_NODES][MAX_NODES];
    printf("Enter adjacency matrix : ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] : ",i,j);
            scanf("%d",&A[i][j]);
        }
        
    }

    int source;
    printf("Enter starting node : ");
    scanf("%d",&source);
    if (source<0 || source>=n)
    {
        printf("Invalid\n");
        return;
    }
    printf("BFS ->");
    BFS(n,A,V,source);
    printf("\n");
    
    
}

void enqueue(int value)
{
    if(rear==n-1)
        return;
    if (front==-1)
        font=0;
    rear++;
    queue[rear]=value;
}
int dequeue()
{  
    if(front==-1)
        return -1;
    int value = queue[front];
    front++;
    return value;
}