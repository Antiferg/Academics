#include<stdio.h>
#include<stdlib.h>

void row_major(int r,int c)
{
    int **arr;
    arr=(int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)
    {
        *(arr+i)=(int*)malloc(c*sizeof(int));
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("arr[%d][%d]:",i,j);
            scanf("%d",&(*(*(arr+i)+j)));
        }
    }
        for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
}

int column_major(int r,int c)
{
    int **arr;
    arr=(int**)malloc(c*sizeof(int*));
    for(int i=0;i<c;i++)
    {
        *(arr+i)=(int*)malloc(r*sizeof(int));
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("arr[%d][%d]:",j,i);
            scanf("%d",&(*(*(arr+j)+i)));
        }
    }
        for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
}

int main()
{
    int r,c;
    printf("Enter the number of rows and columns:");
    scanf("%d%d",&r,&c);
    row_major(r,c);
    column_major(r,c);
}