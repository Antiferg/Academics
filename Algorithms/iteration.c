#include<stdio.h>
#include<stdlib.h>
int main()
{
    int **arr;
    arr=(int**)malloc(4*sizeof(int*));
    for(int i=0;i<4;i++)
    {
        *(arr+i)=(int*)malloc(3*sizeof(int));
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("arr[%d][%d]:",i,j);
            scanf("%d",&(*(*(arr+i)+j)));
        }
    }
        for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
}