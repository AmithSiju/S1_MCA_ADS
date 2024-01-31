#include<stdio.h>

int isPresent(int arr[],int size,int value);
void readSet(int set[],int universal[],int size);
void printSet(int set[],int size);

int n,n1,n2;

void main()
{
    printf("Enter size of Universal set : ");
    scanf("%d",&n);
    int U[n];
    printf("Enter elements");
    readSet(U,NULL,n);
    printf("Enter size of Set1 : ");
    scanf("%d",&n1);
    int Set1[n1];
    printf("Enter elements of Set1 : ");
    readSet(Set1,U,n1);
    printf("Enter size of Set2 : ");
    scanf("%d",&n2);
    int Set2[n2];
    printf("Enter elements of Set2 : ");
    readSet(Set2,U,n2);


    int S1[n],S2[n];
    for (int i = 0; i < n; i++)
    {
        S1[i]=0,S2[i]=0;
        for (int j = 0; j < n1; j++)
        {
            if(U[i]==Set1[j])
            {
                S1[i]=1;
                break;
            }
        }
        for (int j = 0; j < n2; j++)
        {
            if(U[i]==Set2[j])
            {
                S2[i]=1;
                break;
            }
        }
    }
    
    int S1UnionS2[n];
    for (int i = 0; i < n; i++)
    {
        if(S1[i]==1 || S2[i]==1)
        {
            S1UnionS2[i]=1;
        }
        else
        {
            S1UnionS2[i]=0;
        }
    }
     int S1InterS2[n];
    for (int i = 0; i < n; i++)
    {
        if(S1[i]==1 && S2[i]==1)
        {
            S1InterS2[i]=1;
        }
        else
        {
            S1InterS2[i]=0;
        }
    }

    printf("\nUniversal Set : ");
    printSet(U,n);
    printf("\nSet 1 : ");
    printSet(S1,n1);    
    printf("\nSet 2 : ");
    printSet(S2,n2);
    printf("\nS1US2 : ");
    printSet(S1UnionS2,n);
    printf("\nS1nS2 : ");
    printSet(S1InterS2,n);
}

int isPresent(int arr[],int size,int value)
{
    for (int i = 0; i <size ; i++)
    {
        if(arr[i]==value)
            return 1;
    }
    return 0;
}

void readSet(int set[],int universal[],int size)
{
    int element;
    for (int i = 0; i < size; i++)
    {
        printf("\nElement %d : ",i+1);
        scanf("%d",&element);
        if(!isPresent(set,i,element) && (universal==NULL || isPresent(universal,n,element)))
        {
            set[i]=element;
        }
        else
        {
            printf("\nInvalid");
            i--; 
        }
    }
}
void printSet(int set[],int size)
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ,",set[i]);
    }
    printf("}");
}