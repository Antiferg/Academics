#include<stdio.h>
int Regionsize(int Matrix[][10],int row,int column,int matrow,int matcolumn)
{
  if(row<0 || column<0 || row>=matrow || column>=matcolumn)
    return 0;
  if(Matrix[row][column]==0)
    return 0;
  Matrix[row][column]=0;
  int size=1;
  for(int rows=row-1;rows<=row+1;rows++)
  {
    for(int columns=column-1;columns<=column+1;columns++)
    {
      if (Matrix[rows][columns] == 1)
      {
        size+= Regionsize(Matrix,rows,columns,matrow,matcolumn);
      }
    }
  }
  return size;
}
void boolean_matrix(int Matrix[][10],int rows,int columns)
{
  int size=0;
  for(int x=0;x<rows;x++)
  {
    for(int y=0;y<columns;y++)
    {
      if(Matrix[x][y]==1)
      {
        int Maxsize=Regionsize(Matrix,x,y,rows,columns);
        if(Maxsize>size)
          size=Maxsize;
      }   
    }
  }
  printf("%d",size);
}
int main()
{
    int Matrix[5][10] = {
    {1, 0, 1, 1, 0, 0, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1, 0, 0, 1, 1}
  };


  int rows = sizeof(Matrix) / sizeof(Matrix[0]);
  int columns = sizeof(Matrix[0]) / sizeof(Matrix[0][0]);

  boolean_matrix(Matrix, rows, columns); 

  return 0;
}