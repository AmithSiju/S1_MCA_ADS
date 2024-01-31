#include<stdio.h>

#define MAX_NODES 100

void DFS(int n,int graph[n][n],int visited[],int source)
{
    printf("%d ",source);
    visited[source]=1;
    for (int i = 0; i < n; i++)
    {
        if (graph[source][i]!=0)
        {
            if (!visited[i])
            {
                DFS(n,graph,visited,i);
            }
            
        }
        
    }
    
}
void main()
{
    int n;
    printf("Enter number of nodes : ");
    scanf("%d",&n);

    int V[n];
    for (int i = 0; i < n; i++)
    {
        V[i]=0;
    }

    int A[n][n];
    printf("Enter adjacency matrix ");
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
    if(source<0 || source>=n)
    {
        printf("Invalid");
        return;
    }
    printf("DFS->");
    DFS(n,A, V,source);
    printf("\n");
}