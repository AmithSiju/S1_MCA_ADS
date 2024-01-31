#include<stdio.h>
int a[50],b[50],n,m;
void merge();

void main()
{
    printf("Enter size of 1st array: ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter size of 2nd array : ");
    scanf("%d",&m);
    printf("Enter the elements : ");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("\nArray 1 : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nArray 2 : ");
    for(int i=0;i<m;i++)
    {
       printf("%d ",b[i]);
    }
    merge();
    printf("\nArray after merging : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void merge()
{
    if(n+m>50)
    {
        printf("Invalid");
    }
    for (int i = 0; i < m; i++)
    {
        a[n+i] = b[i];
    }
     n=n+m;
}