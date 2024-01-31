#include<stdio.h>
#include<string.h>
#include<limits.h>
#define MAX_NODES 100
int inDegree(int graph[][MAX_NODES],int n,int node);
void main()
{
    int n;
    printf("Number of nodes : ");
    scanf("%d",&n);
    int A[MAX_NODES][MAX_NODES];
    printf("\n Enter adjacency matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] : ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    int V[n];
    for (int i = 0; i < n; i++)
    {
        V[i]=0;
    }
    int count=0;
    while (count<n)
    {
        for (int i = 0; i < n; i++)
        {
            if (inDegree(A,n,i)==0 && !V[i])
            {
                printf("%d\n",i);
                V[i]=1;
                for (int j = 0; j < n; j++)
                {
                    A[i][j]=0; 
                }
                break;
            }
        }
        count++;   
    } 
}
int inDegree(int graph[][MAX_NODES],int n,int node)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+= graph[i][node];
    }
    return sum;
}
